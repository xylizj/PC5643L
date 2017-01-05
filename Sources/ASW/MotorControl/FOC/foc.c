#include "VFB.h"
#include "foc.h"
#include "isr.h"

sint32 s32_hMDRV_thRotEl;

sint32 s32_hMDRV_thRotEl_Cor;

SWLIBS_2Syst   stc_hMDRV_thSinCos;
SWLIBS_2Syst   stc_hMDRV_iAlBeFbck;
SWLIBS_2Syst   stc_hMDRV_iDQFbck;
SWLIBS_2Syst   stc_hMDRV_iDQFbck_debug;
SWLIBS_2Syst   stc_hMDRV_iDQReqZC;
SWLIBS_2Syst   stc_hMDRV_iDQReq;
SWLIBS_2Syst   stc_hMDRV_iDQErr;

tFrac32 Udc_limit;
SWLIBS_2Syst   stc_hMDRV_uDQLimit;

uint8_t cur_req_d_ov_en;
int32_t cur_req_d_ov;


uint8_t cur_req_q_ov_en;
int32_t cur_req_q_ov;


uint8_t volt_q_ov_en;
int16_t volt_q_ov;
 

//uint8_t Clb_stc_hMDRV_dAxisSlwPI_OV_EN;

//SWLIBS_2Syst   stc_hMDRV_uDQReq_CAL;


SWLIBS_2Syst   stc_hMDRV_uDQReq;
SWLIBS_2Syst   stc_hMDRV_uAlBeReq;
SWLIBS_2Syst   stc_hMDRV_uAlBeReqDCB;

SWLIBS_3Syst   stc_hMDRV_uABC;
sint32 s32_hMDRV_svmSector;


FLEXPWM_VAL_COMPL   stc_hMDRV_pwmAbc; 
  

GFLIB_CONTROLLER_PIAW_R_T  stc_hMDRV_dAxisPI;
GFLIB_CONTROLLER_PIAW_R_T  stc_hMDRV_qAxisPI;



//GDFLIB_FILTER_IIR1_T_F32 Clb_stc_hMDRV_dAxisZC = {{FRAC32(0.270906873811F),FRAC32(0.0F),FRAC32(-0.729093126189F)},{FRAC32(0.0)},{FRAC32(0.0)}}; 

//GDFLIB_FILTER_IIR1_T_F32 Clb_stc_hMDRV_qAxisZC = {{FRAC32(0.270906873811F),FRAC32(0.0F),FRAC32(-0.729093126189F)},{FRAC32(0.0)},{FRAC32(0.0)}};


GMCLIB_ELIMDCBUSRIP_T stc_hMDRV_elimDcbRip;

sint16 FlexPWM_INIT_sub0;

SWLIBS_3Syst  adc_iAbcFbck;
tFrac32  adc_UdcbMeaRaw;


GFLIB_RAMP_T stc_hMDRV_iDReq_Ramp = 
{
	(tFrac32)FRAC32(0),//f32State; /*!< Ramp state value. */
	(tFrac32)FRAC32(0.001),//f32RampUp; /*!< Ramp up increment coefficient. */
	(tFrac32)FRAC32(0.001)//f32RampDown; /*!< Ramp down increment (decrement) coefficient. */
};

GFLIB_RAMP_T stc_hMDRV_iQReq_Ramp = 
{
	(tFrac32)FRAC32(0),//f32State; /*!< Ramp state value. */
	(tFrac32)FRAC32(0.001),//f32RampUp; /*!< Ramp up increment coefficient. */
	(tFrac32)FRAC32(0.001)//f32RampDown; /*!< Ramp down increment (decrement) coefficient. */
};


/*GFLIB_CONTROLLER_PIAW_R_T Clb_stc_hMDRV_dAxisSlwPI = 
{
    FRAC32(+0.017077260),
    FRAC32(-0.016199925),
    0x00000000,
    0x00000000,      
    (FRAC32(0.25)),//f32UpperLimit
    (FRAC32(-0.25)),//f32LowerLimit
    0,	
};

GFLIB_CONTROLLER_PIAW_R_T Clb_stc_hMDRV_qAxisSlwPI = 
{
    FRAC32(+0.042923662),
    FRAC32(-0.041399869),
    0x00000000,
    0x00000000,
    (FRAC32(0.25)),
    (FRAC32(-0.25)),
    0,	
};*/

//F0=291Hz, W0=2*PI*F0
//0.707
//Rs=0.018R
//Td=0.0038s,Tq=0.0066s
GFLIB_CONTROLLER_PIAW_R_T stc_hMDRV_dAxisPI = 
{
     FRAC32(0.176459837918323),
    FRAC32(-0.152156924041081),
    0x00000000,
    0x00000000,      
    (FRAC32(0.25)),//f32UpperLimit
    (FRAC32(-0.25)),//f32LowerLimit
    0,	
};

GFLIB_CONTROLLER_PIAW_R_T stc_hMDRV_qAxisPI = 
{
     FRAC32(0.768166237113402),
    FRAC32(-0.624583762886598),
    0x00000000,
    0x00000000,
    (FRAC32(0.25)),
    (FRAC32(-0.25)),
    1,	
};




GFLIB_CONTROLLER_PIAW_P_T dAxisPI_P = 
{
    FRAC32(0.75),//tFrac32   f32PropGain;        /*!< Proportional Gain, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    FRAC32(0),//tFrac32   f32IntegGain;       /*!< Integral Gain, fractional format normalized to fit into  (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    2,//tS16      s16PropGainShift;   /*!< Proportional Gain Shift, integer format [-31, 31]. */
    0,//tS16      s16IntegGainShift;  /*!< Integral Gain Shift, integer format [-31, 31]. */
    FRAC32(-1),//tFrac32   f32LowerLimit;      /*!< Lower Limit of the controller, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    FRAC32(1),//tFrac32   f32UpperLimit;      /*!< Upper Limit of the controller, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    0,//tFrac32   f32IntegPartK_1;    /*!< State variable integral part at step k-1. */
    0,//tFrac32   f32InK_1;           /*!< State variable input error at step k-1. */
    0,//tU16      u16LimitFlag;       /*!< Limitation flag, if set to 1, the controller output has reached either the UpperLimit or LowerLimit. */
};


GFLIB_CONTROLLER_PIAW_P_T qAxisPI_P = 
{
    FRAC32(0.75),//tFrac32   f32PropGain;        /*!< Proportional Gain, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    FRAC32(0),//tFrac32   f32IntegGain;       /*!< Integral Gain, fractional format normalized to fit into  (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    2,//tS16      s16PropGainShift;   /*!< Proportional Gain Shift, integer format [-31, 31]. */
    0,//tS16      s16IntegGainShift;  /*!< Integral Gain Shift, integer format [-31, 31]. */
    FRAC32(-1),//tFrac32   f32LowerLimit;      /*!< Lower Limit of the controller, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    FRAC32(1),//tFrac32   f32UpperLimit;      /*!< Upper Limit of the controller, fractional format normalized to fit into (-2\f$^{31}\f$, 2\f$^{31}\f$-1). */
    0,//tFrac32   f32IntegPartK_1;    /*!< State variable integral part at step k-1. */
    0,//tFrac32   f32InK_1;           /*!< State variable input error at step k-1. */
    0,//tU16      u16LimitFlag;       /*!< Limitation flag, if set to 1, the controller output has reached either the UpperLimit or LowerLimit. */
};

sint32 iDFbck;
sint32 iQFbck;

sint32 ud_correct;
sint32 uq_correct;


void focFastLoopInit(void)
{
    /*value init.*/
    s32_hMDRV_thRotEl = 0;
    stc_hMDRV_thSinCos.f32Arg1 = 0;
    stc_hMDRV_thSinCos.f32Arg2 = 0;
    
    stc_hMDRV_iDQReqZC.f32Arg1 = 0;
    stc_hMDRV_iDQReqZC.f32Arg2 = 0;
    
    stc_hMDRV_iDQErr.f32Arg1 = 0;
    stc_hMDRV_iDQErr.f32Arg2 = 0;
    
    stc_hMDRV_uDQLimit.f32Arg1 = 0;
    stc_hMDRV_uDQLimit.f32Arg2 = 0;
    
    stc_hMDRV_uDQReq.f32Arg1 = 0;
    stc_hMDRV_uDQReq.f32Arg2 = 0;
    
    s32_hMDRV_svmSector = 0;
    stc_hMDRV_uABC.f32Arg1 = 0;
    stc_hMDRV_uABC.f32Arg2 = 0;
    stc_hMDRV_uABC.f32Arg3 = 0; 
    
    stc_hMDRV_pwmAbc.s16sub0 = 0;
    stc_hMDRV_pwmAbc.s16sub1 = 0; 
    stc_hMDRV_pwmAbc.s16sub2 = 0;
    /*dc bus voltage ripple compensation ,*/
    stc_hMDRV_elimDcbRip.f32ModIndex    = FRAC32(0.866025403784439); /*sqrt(3)/2 =0.866025403784439  */
    stc_hMDRV_elimDcbRip.f32ArgDcBusMsr = 0;  
			
	FlexPWM_INIT_sub0 = (sint16)(-1*(mcPWM_A.SUBMOD[0].INIT.R));  
}


sint32 iDReq_Desired;
sint32 iQReq_Desired;

uint8_t cur_d_ramp_dis;
uint8_t cur_q_ramp_dis;

sint32 iD_ActualReq;
sint32 iQ_ActualReq;

void CurD_Req_Ramp(void)
{
	//if(cur_q_ramp_dis == 1)
	if(1)//20160701 for PI ZN 
	{
		if(cur_req_d_ov_en==1)
		{
			iD_ActualReq = cur_req_d_ov*7158;
		}
		else
		{
			iD_ActualReq = 0;
		}
	}
	else
	{		
		if(cur_req_d_ov_en==1)
		{
			iDReq_Desired = cur_req_d_ov*7158;
			iD_ActualReq = GFLIB_Ramp((iDReq_Desired),&(stc_hMDRV_iDReq_Ramp),F32);//iD;
		}
		else
		{
			iDReq_Desired = 0;
			iD_ActualReq = 0;
		}
	}
}

void CurQ_Req_Ramp(void)
{
	//if(cur_q_ramp_dis == 1)
	if(1)//20160630 for PI ZN 
	{
		if((cur_req_q_ov_en==2) || (cur_req_q_ov_en==1))
		{
			if(cur_req_q_ov > 50000)		
			{
				cur_req_q_ov = 50000;	
			}
			if(cur_req_q_ov < -50000)		
			{
				cur_req_q_ov = -50000;	
			}
			
			iQ_ActualReq = cur_req_q_ov*7158;
		}
		else
		{
			iQ_ActualReq = 0;
		}
	}
	else
	{		
		if((cur_req_q_ov_en==2) || (cur_req_q_ov_en==1))
		{
			if(cur_req_q_ov > 50000)		
			{
				cur_req_q_ov = 50000;	
			}
			if(cur_req_q_ov < -50000)		
			{
				cur_req_q_ov = -50000;	
			}
			iQReq_Desired = cur_req_q_ov*7158;
			iQ_ActualReq = GFLIB_Ramp((iQReq_Desired),&(stc_hMDRV_iQReq_Ramp),F32);
		}
		else
		{
			iQReq_Desired = 0;
			iQ_ActualReq = 0;
		}
	}
}

/************************************************************
 * input: 
 *     s32_hMDRV_thRotEl: elec angle of motor rotor
 *         type: sint32 ,fixdt(1,2^31,0) ,range:[-1,1)
 *     adc_iAbcFbck : Three phases current feedback 
 *         type:SWLIBS_3Syst_F32 ,  Unit: A
 *     adc_UdcbMeaRaw: Voltage of Udc
 *         type:tFrac32  ,Unit: V
 *     stc_hMDRV_iDQReq: request D,Q current
 *         type:tFrac32  ,Unit: A
 * output:
 *     stc_hMDRV_pwmAbc : count value of VAL3 of PWMA,B,C
 *              VAL2 = -VAL3         
 *     stc_hMDRV_uABC : frequency duty of PWM A,B,C
 *         type:tFrac32  ,Unit: %
 ************************************************************/
boolean focFastLoop(void)
{
	adc_iAbcFbck.f32Arg1 = -(SID_m_i_CurPhaseU);
	adc_iAbcFbck.f32Arg2 = -(SID_m_i_CurPhaseV);
	adc_iAbcFbck.f32Arg3 = (SID_m_i_CurPhaseU+SID_m_i_CurPhaseV);
	adc_UdcbMeaRaw = (SID_m_u_V48);

	stc_hMDRV_iDQReq.f32Arg1 = iD_ActualReq;
	stc_hMDRV_iDQReq.f32Arg2 = iQ_ActualReq;
  
  #ifdef PN_MEASURE_PI_Q//Q PI Parameter Measure
	stc_hMDRV_iDQReq.f32Arg1 = 0;
	#endif
	
	#ifdef PN_MEASURE_PI_D//d PI Parameter Measure
	stc_hMDRV_iDQReq.f32Arg2 = 0;
  #endif
  
	s32_hMDRV_thRotEl = SID_m_phi_RotPos;

	stc_hMDRV_thSinCos.f32Arg1 = GFLIB_Sin(s32_hMDRV_thRotEl);
	stc_hMDRV_thSinCos.f32Arg2 = GFLIB_Cos(s32_hMDRV_thRotEl);

	GMCLIB_Clark(&stc_hMDRV_iAlBeFbck,&adc_iAbcFbck,F32);  
	GMCLIB_Park(&stc_hMDRV_iDQFbck,&stc_hMDRV_thSinCos,&stc_hMDRV_iAlBeFbck,F32); 

	iDFbck = stc_hMDRV_iDQFbck.f32Arg1;//20160620 for record
	iQFbck = stc_hMDRV_iDQFbck.f32Arg2;

	stc_hMDRV_iDQErr.f32Arg1 = MLIB_SubSat(stc_hMDRV_iDQReq.f32Arg1,stc_hMDRV_iDQFbck.f32Arg1);
	stc_hMDRV_iDQErr.f32Arg2 = MLIB_SubSat(stc_hMDRV_iDQReq.f32Arg2,stc_hMDRV_iDQFbck.f32Arg2);
	#ifdef PN_MEASURE_PI_Q
	stc_hMDRV_iDQErr.f32Arg1 = 0;
	#endif
	#ifdef PN_MEASURE_PI_D
	stc_hMDRV_iDQErr.f32Arg2 = 0;
	#endif
	
	Udc_limit  = MLIB_Mul_F32F16F16(FRAC16(0.51961),(tFrac16)(adc_UdcbMeaRaw>>16));//(adc_UdcbMeaRaw>>10)*532;
	stc_hMDRV_uDQLimit.f32Arg1  = Udc_limit;

	stc_hMDRV_dAxisPI.f32UpperLimit   = stc_hMDRV_uDQLimit.f32Arg1;             /* Set ud upper limit.  */
	stc_hMDRV_dAxisPI.f32LowerLimit   = MLIB_Neg_F32(stc_hMDRV_dAxisPI.f32UpperLimit);/* Set ud lower limit.  */

	stc_hMDRV_uDQReq.f32Arg1  = GFLIB_ControllerPIrAW(stc_hMDRV_iDQErr.f32Arg1,&stc_hMDRV_dAxisPI); /*calculate the ud */

	#ifdef PN_MEASURE_PI_D
	stc_hMDRV_uDQReq.f32Arg1  = GFLIB_ControllerPIpAW(stc_hMDRV_iDQErr.f32Arg1,&dAxisPI_P); /*calculate the ud */
	#endif
	
	#ifdef PN_MEASURE_PI_Q //actually no need here
	stc_hMDRV_uDQReq.f32Arg1  = 0;//20160629 add for ZN Q PI Parameter Measure
	#endif

	stc_hMDRV_uDQLimit.f32Arg2 = GFLIB_Sqrt(MLIB_Abs(MLIB_SubSat(\
	       MLIB_Mul_F32F16F16((tFrac16)Udc_limit,(tFrac16)Udc_limit),\
	       MLIB_Mul_F32F16F16((tFrac16)(stc_hMDRV_uDQReq.f32Arg1>>16),(tFrac16)(stc_hMDRV_uDQReq.f32Arg1>>16)))));

	stc_hMDRV_qAxisPI.f32UpperLimit   = stc_hMDRV_uDQLimit.f32Arg2;
	stc_hMDRV_qAxisPI.f32LowerLimit   = MLIB_Neg_F32(stc_hMDRV_qAxisPI.f32UpperLimit);

	stc_hMDRV_uDQReq.f32Arg2   = GFLIB_ControllerPIrAW(stc_hMDRV_iDQErr.f32Arg2,&stc_hMDRV_qAxisPI);

	#ifdef PN_MEASURE_PI_Q
	stc_hMDRV_uDQReq.f32Arg2   = GFLIB_ControllerPIpAW(stc_hMDRV_iDQErr.f32Arg2,&qAxisPI_P);//20160701 add for ZN q PI Parameter Measure
	#endif
	
	#ifdef PN_MEASURE_PI_D //actually no need here
	stc_hMDRV_uDQReq.f32Arg2  = 0;//20160701 add for ZN D PI Parameter Measure
	#endif
	
	if(stc_hMDRV_uDQReq.f32Arg2 >= Q_VOLTAGE_REQ_THREHOLD)
	{
		stc_hMDRV_uDQReq.f32Arg2 = Q_VOLTAGE_REQ_THREHOLD;
	}
	else if (stc_hMDRV_uDQReq.f32Arg2 <= -Q_VOLTAGE_REQ_THREHOLD)
	{
		stc_hMDRV_uDQReq.f32Arg2 = -Q_VOLTAGE_REQ_THREHOLD;
	} 

	if(stc_hMDRV_uDQReq.f32Arg1 >= D_VOLTAGE_REQ_THREHOLD)
	{
		stc_hMDRV_uDQReq.f32Arg1 = D_VOLTAGE_REQ_THREHOLD;
	}
	else if (stc_hMDRV_uDQReq.f32Arg1 <= -D_VOLTAGE_REQ_THREHOLD)
	{
		stc_hMDRV_uDQReq.f32Arg1 = -D_VOLTAGE_REQ_THREHOLD;
	} 
	//correct angle with speed
	stc_hMDRV_thSinCos.f32Arg1 = GFLIB_Sin(angle_c);
	stc_hMDRV_thSinCos.f32Arg2 = GFLIB_Cos(angle_c);  

	GMCLIB_ParkInv(&stc_hMDRV_uAlBeReq,&stc_hMDRV_thSinCos,&stc_hMDRV_uDQReq); /* calculate the uAlpah and uBeta */

	stc_hMDRV_elimDcbRip.f32ArgDcBusMsr  = adc_UdcbMeaRaw;

	GMCLIB_ElimDcBusRip(&stc_hMDRV_uAlBeReqDCB,&stc_hMDRV_uAlBeReq,&stc_hMDRV_elimDcbRip);

	s32_hMDRV_svmSector  = GMCLIB_SvmStd(&stc_hMDRV_uABC,&stc_hMDRV_uAlBeReqDCB);

	stc_hMDRV_pwmAbc.s16sub0 = (tU16)(MLIB_Mul((tFloat)FlexPWM_INIT_sub0,stc_hMDRV_uABC.f32Arg1));
	stc_hMDRV_pwmAbc.s16sub1 = (tU16)(MLIB_Mul((tFloat)FlexPWM_INIT_sub0,stc_hMDRV_uABC.f32Arg2));
	stc_hMDRV_pwmAbc.s16sub2 = (tU16)(MLIB_Mul((tFloat)FlexPWM_INIT_sub0,stc_hMDRV_uABC.f32Arg3));

	return TRUE; 	
}