#include "VFB.h"
#include "EXC.h"
#include "FlexPWM.h"
#include "Adc.h"
#include "SchM.h"


//abs(4096*SPD_ct/VOLT_ct)
const uint16 EXC_SpdDIVVolt[20] = 
{
	16087,8143,6784,5881,5099,4504,4033,3684,3407,3167,2957,2764,2670,2516,2438,2294,2104,2040,1966,1854
};
//         0  1  2   3   4   5   6   7   8    9  10  11  12  13  14  15  16  17   18   19
//Cur_ct //0,50,100,150,200,250,300,350,400,450,500,550,600,650,700,800,900,1000,1200,1600
const uint16 EXC_CurReq[20] =
{
	0,62,124,186,248,310,372,434,496,559,621,683,745,807,869,993,1117,1241,1489,1986
};
//800+ need rewrite
const uint16 EXC_PWMVal[20] =
{
	0,3200,4100,4960,5800,6700,7600,8400,9200,9900,10800,11900,12900,13900,14900,17000,18500,20000,23000,40000
};

uint8  EXC_CurReqIdx;
uint8  EXC_CurReqIdx_OV;
uint8  EXC_CurReqIdx_OV_EN;



int32_t  EXC_I_PWMVAL;
int32_t  EXC_P_PWMVAL;
int32_t  EXC_PI_PWMVAL;
int16_t  EXC_Err_PWMVAL;



//uint8  EXC_CurReqIdx_OV;
//uint8  EXC_CurReqIdx_OV_EN;



void EXCCurCalc(void)
{
	uint32   Tmp_AbsSpdDIVVolt;
	int32_t  Tmp_SpdDIVVolt;
	int32_t  Tmp_Spd;
	uint8    Tmp_i;
	 
	
	if (SID_m_ct_V48Raw >= 885)//15V//30V--1770
	{
		Tmp_Spd = ((int32_t)SID_m_ct_VelocityRaw)<<12;
		Tmp_SpdDIVVolt = Tmp_Spd/SID_m_ct_V48Raw;
		if (Tmp_SpdDIVVolt < 0)
		{
			Tmp_AbsSpdDIVVolt = (uint16)(-Tmp_SpdDIVVolt);
		}
	    else
	    {
	    	Tmp_AbsSpdDIVVolt = (uint16)(Tmp_SpdDIVVolt);
	    }
	    for (Tmp_i = 0;Tmp_i <15;Tmp_i ++)//20,for test lim 15
	    {
	    	if (Tmp_i >= 14)//19,for test lim 14
	    	{
	    	   EXC_CurReqIdx = 14;//20,for test lim 14
	    	   break; 	
	    	}
	    	if (Tmp_AbsSpdDIVVolt > EXC_SpdDIVVolt[Tmp_i + 1])
	    	{
	    		EXC_CurReqIdx = Tmp_i; 
	    	}
	    }	    
	}
	else
	{
		EXC_CurReqIdx = 0;
	}
	if (EXC_CurReqIdx_OV_EN)
	{
		EXC_CurReqIdx = EXC_CurReqIdx_OV;
	}
	 
}


void EXCLoop(void)
{
    uint16 Tmp_PWMVal;
    uint16 Tmp_TH;
    uint16 Tmp_ct_V48Raw;
        
	if (EXC_CurReqIdx == 0)
	{
		SetFlexPWM0Sub3_val2(0);
	}
	else
	{
		EXC_Err_PWMVAL = (int16_t)(EXC_CurReq[EXC_CurReqIdx] - SID_m_ct_CurExcRaw);
		EXC_P_PWMVAL = EXC_KP*EXC_Err_PWMVAL;
		EXC_I_PWMVAL += EXC_KI*EXC_Err_PWMVAL/2;
		EXC_PI_PWMVAL = EXC_P_PWMVAL + EXC_I_PWMVAL;
		Tmp_ct_V48Raw = SID_m_ct_V48Raw;
		if (Tmp_ct_V48Raw < 885)//15V//30V--1770
		{
			Tmp_ct_V48Raw = 885;//15V//30V--1770
		}
		Tmp_PWMVal = EXC_PWMVal[EXC_CurReqIdx]*2955/Tmp_ct_V48Raw;
		Tmp_TH = EXC_TH*2955/Tmp_ct_V48Raw;
		/*if (  (EXC_PI_PWMVAL > (Tmp_PWMVal + Tmp_TH))
			||(Tmp_PWMVal > (EXC_PI_PWMVAL + Tmp_TH)))
		{
			SetFlexPWM0Sub3_val2(Tmp_PWMVal);
			EXC_I_PWMVAL = Tmp_PWMVal;
		}
		else*/
		{
			SetFlexPWM0Sub3_val2(((uint16)EXC_PI_PWMVAL));
		}
	}
	
}


void EXCLoopInit(void)
{	
    EXC_CurReqIdx = 18;
    EXC_CurReqIdx_OV_EN = 0;
	EXC_I_PWMVAL = 0;
	SetFlexPWM0Sub3_val2(0);
}


