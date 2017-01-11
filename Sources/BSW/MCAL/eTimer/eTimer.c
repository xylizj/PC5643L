#include "MPC5643L.h"
#include "eTimer.h"
#include "Siu.h"



static void eTimer1_Ch2_Init(void)
{    //CHANNEL 2 T3 trigger delay 10us gen a rising edge
    ETIMER_1.CHANNEL[2].COMP1.R=1200;
    ETIMER_1.CHANNEL[2].COMP2.R=1500;//not used never comp
    ETIMER_1.CHANNEL[2].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[2].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:T3
    ETIMER_1.CHANNEL[2].CTRL1.R=0xD853;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[2].CTRL2.R=0x0005;
    //ETIMER_1.CHANNEL[2].CTRL3.R=0;
    //ETIMER_1.CHANNEL[2].INTDMA.R=0;    
    //ETIMER_1.CHANNEL[2].CMPLD1.R=0;    
    //ETIMER_1.CHANNEL[2].CMPLD2.R=0;    
    //ETIMER_1.CHANNEL[2].CCCTRL.R=0;
}

static void eTimer1_Ch3_Init(void)
{
    //CHANNEL 3 count 10 aux0 rising edge gen a rising edge
    ETIMER_1.CHANNEL[3].COMP1.R=4;
    ETIMER_1.CHANNEL[3].COMP2.R=4;//
    ETIMER_1.CHANNEL[3].LOAD.R=0;//init cnt
    //ETIMER_1.CHANNEL[3].CNTR.R=0;
    //count pri rising edge;pri:aux0;repeat;count until comp;count up
    ETIMER_1.CHANNEL[3].CTRL1.R=0x2840;
    //toggle output using alter comp reg    
    ETIMER_1.CHANNEL[3].CTRL2.R=0x0004;
    //ETIMER_1.CHANNEL[3].CTRL3.R=0;
    //ETIMER_1.CHANNEL[3].INTDMA.R=0;    
    //ETIMER_1.CHANNEL[3].CMPLD1.R=0;    
    //ETIMER_1.CHANNEL[3].CMPLD2.R=0;    
    //ETIMER_1.CHANNEL[3].CCCTRL.R=0;    	
}


static void eTimer1_Ch5_Init(void)
{
    //CHANNEL 5 aux0 trigger delay 15us gen a rising edge
    ETIMER_1.CHANNEL[5].COMP1.R=1800;
    ETIMER_1.CHANNEL[5].COMP2.R=2000;//not used never comp
    ETIMER_1.CHANNEL[5].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[5].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_1.CHANNEL[5].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[5].CTRL2.R=0x0005;
    //ETIMER_0.CHANNEL[5].CTRL3.R=0;
    ETIMER_1.CHANNEL[5].INTDMA.R=0x0001;//TCF INT ENABLE   STS.TCF 
    //ETIMER_1.CHANNEL[5].CMPLD1.R=0;//Init cnt    
    //ETIMER_1.CHANNEL[5].CMPLD2.R=0;    
    //ETIMER_1.CHANNEL[5].CCCTRL.R=0;
	
}


void eTimer1_Init(void)
{
    eTimer1_Ch2_Init();
    eTimer1_Ch3_Init();
    eTimer1_Ch5_Init();       
        
    //below are TIMER
    ETIMER_1.ENBL.R=0x003E;        
    ETIMER_1.DREQ0.R=0x8012;
    ETIMER_1.DREQ1.R=0x8006;       
}


/*static void eTimer1_Ch4_Init(void)
{
    //CHANNEL 4 aux0 no delay trigger gen a rising edge,a DMA req,for io low
    ETIMER_1.CHANNEL[4].COMP1.R=0;
    ETIMER_1.CHANNEL[4].COMP2.R=100;//not used never comp
    //ETIMER_1.CHANNEL[4].LOAD.R=0;//init cnt
    //ETIMER_1.CHANNEL[4].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_1.CHANNEL[4].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[4].CTRL2.R=0x0005;
    //ETIMER_1.CHANNEL[4].CTRL3.R=0;
    ETIMER_1.CHANNEL[4].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_1.CHANNEL[4].CMPLD1.R=0;//Init cnt    
    //ETIMER_1.CHANNEL[4].CMPLD2.R=0;    
    ETIMER_1.CHANNEL[4].CCCTRL.R=0x1800;    
	
}

static void eTimer1_Ch5_Init(void)
{
    //CHANNEL 5 aux0 delay 1.2us trigger gen a rising edge,a DMA req,for io high
    ETIMER_1.CHANNEL[5].COMP1.R=144;
    ETIMER_1.CHANNEL[5].COMP2.R=200;//not used never comp
    //ETIMER_1.CHANNEL[5].LOAD.R=0;//init cnt
    //ETIMER_1.CHANNEL[5].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_1.CHANNEL[5].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[5].CTRL2.R=0x0005;
    //ETIMER_1.CHANNEL[4].CTRL3.R=0;
    ETIMER_1.CHANNEL[5].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_1.CHANNEL[5].CMPLD1.R=0;//Init cnt    
    //ETIMER_1.CHANNEL[5].CMPLD2.R=0;    
    ETIMER_1.CHANNEL[5].CCCTRL.R=0x1800;	
}


void eTimer1_Init(void)
{
	eTimer1_Ch4_Init();
	eTimer1_Ch5_Init();
    //below are TIMER
    ETIMER_1.ENBL.R=0x0030;        
    ETIMER_1.DREQ0.R=0x8012;
    ETIMER_1.DREQ1.R=0x8016;
 }*/



/* Number of encoder edges per mechanical revolution */
#define ENC_NU_EDGES_REV        (48*4)
uint16_t   SID_m_ct_eTimer0Ch0Capt1;
uint16_t   SID_m_ct_eTimer0Ch1Capt1[2];
uint16_t   SID_m_ct_PhaseB;
uint16_t   SID_m_n_MechRPS;
uint32_t   SID_m_ct_PosRaw;
int32_t 	SID_m_phi_RotPos;

static void eTimer0_Ch0_Init(void)
{
	ETIMER_0.CHANNEL[0].CTRL1.B.CNTMODE = 0b010;//Count rising and falling edges of primary source
		
	ETIMER_0.CHANNEL[0].CTRL1.B.PRISRC = 0b00000;//The primary timer source is timer input 0 (encoder Phase A) 		
	//ETIMER_0.CHANNEL[0].CTRL1.B.SECSRC = 0b00001;//The secondary timer source is timer input 1 (encoder Phase B)
	ETIMER_0.CHANNEL[0].CTRL1.B.LENGTH = 0b1;//1 = Count until compare,then reinitialize

	ETIMER_0.CHANNEL[0].COMP1.R = ENC_NU_EDGES_REV - 1;
	ETIMER_0.CHANNEL[0].COMP2.R = -(ENC_NU_EDGES_REV - 1);
	ETIMER_0.CHANNEL[0].LOAD.R = 0;//init cnt
	ETIMER_0.CHANNEL[0].CNTR.R = 0;

	ETIMER_0.CHANNEL[0].CCCTRL.B.CMPMODE = 0b10;
	/*COMP1 register is used when the counter is counting up.
	  COMP2 register is used when the counter is counting down.*/
	ETIMER_0.CHANNEL[0].CCCTRL.B.CPT1MODE = 0b11;//Capture any edge
	ETIMER_0.CHANNEL[0].CCCTRL.B.CPT2MODE = 0b00;//Disabled

	ETIMER_0.CHANNEL[0].INTDMA.B.ICF1DE = 1;//Input Capture 1 Flag DMA Enable
}


 
 //Speed measurement
static void eTimer0_Ch1_Init(void)
{
	/*Determines a count of the rising edges of the primary source, 
		where the counter is updated according to the primary input signals*/
	ETIMER_0.CHANNEL[1].CTRL1.B.CNTMODE = 0b001;//Count rising edges of primary source	
	ETIMER_0.CHANNEL[1].CTRL1.B.PRISRC = 0b11010;//The primary timer source, the IP bus clock is divided by a prescaler, 4.  		
	ETIMER_0.CHANNEL[1].CTRL1.B.SECSRC = 0b00001;//The secondary timer source is timer input 1 (encoder Phase B)
	ETIMER_0.CHANNEL[1].CTRL1.B.LENGTH = 0b0;//0 = Continue counting to roll over

	ETIMER_0.CHANNEL[1].CCCTRL.B.CPT1MODE = 0b01;//Capture rising edge
	//ETIMER_0.CHANNEL[1].CCCTRL.B.CPT2MODE = 0b11;//Capture any edge
	ETIMER_0.CHANNEL[1].INTDMA.B.ICF1DE = 1;//Input Capture 1 Flag DMA Enable
	//ETIMER_0.CHANNEL[1].INTDMA.B.ICF2DE = 1;//Input Capture 2 Flag DMA Enable

	ETIMER_0.CHANNEL[1].CCCTRL.B.ARM = 0b1;//1 = Input capture operation as specified by the CPT1MODE and CPT2MODE bits is enabled.
}



 //Position detection using encoder
/*static void eTimer1_Ch3_Init(void)
{
	ETIMER_1.CHANNEL[3].CTRL1.B.CNTMODE = 0b100;//Quadrature count mode, usesprimary and secondary sources
		
	ETIMER_1.CHANNEL[3].CTRL1.B.PRISRC = 0b00000;//The primary timer source is timer input 0 (encoder Phase A) 		
	ETIMER_1.CHANNEL[3].CTRL1.B.SECSRC = 0b00001;//The secondary timer source is timer input 1 (encoder Phase B)
	ETIMER_1.CHANNEL[3].CTRL1.B.LENGTH = 0b1;//1 = Count until compare,then reinitialize

	///ETIMER_1.CHANNEL[3].COMP1.R = ENC_NU_EDGES_REV - 1;
	//ETIMER_1.CHANNEL[3].COMP2.R = -(ENC_NU_EDGES_REV - 1);
	ETIMER_1.CHANNEL[3].LOAD.R = 0;//init cnt
	ETIMER_1.CHANNEL[3].CNTR.R = 0;

	ETIMER_1.CHANNEL[3].CCCTRL.B.CMPMODE = 0b10;
}*/

static inline eTimer0_PAD_Config(void) 
{
	SIU.PSMI[35].B.PADSEL = 0;//eTimer_0  ETC[0] PAD select
	SIU_PAD_CONFIG(0, eTimer_0_ETC_CONFIG);
	
	SIU.PSMI[36].B.PADSEL = 0;//eTimer_0  ETC[1] PAD select
	SIU_PAD_CONFIG(1, eTimer_0_ETC_CONFIG);

	SIU.PSMI[37].B.PADSEL = 0;//eTimer_0  ETC[2] PAD select
	SIU_PAD_CONFIG(2, eTimer_0_ETC_CONFIG);

	SIU.PSMI[7].B.PADSEL = 1;//eTimer_0  ETC[4] PAD select
	SIU_PAD_CONFIG(43, eTimer_0_ETC_CONFIG);
}


void eTimer0_Encode_Init(void)
{
	//eTimer0_Ch0_Init();	
	eTimer0_Ch1_Init();
	ETIMER_0.ENBL.R=0x0002;//channel 1
    ETIMER_0.DREQ0.R=0;
    ETIMER_0.DREQ1.R=0x8004;//Request 1, CAPT1 DMA read request
    
    eTimer0_PAD_Config();	  	
}



void EncodePosGet(void)
{
	int16_t cnt;
	
	cnt = ETIMER_0.CHANNEL[0].CNTR.R;
	if(cnt > (ENC_NU_EDGES_REV - 1))
	{
		cnt = ENC_NU_EDGES_REV - 1;
	}
	else if(cnt < (-(ENC_NU_EDGES_REV - 1)))
	{
		cnt = -(ENC_NU_EDGES_REV - 1);
	}
	SID_m_ct_PosRaw = cnt;
	//SID_m_phi_RotPos = SID_m_ct_PositionRaw/ENC_NU_EDGES_REV*(1<<30) = SID_m_ct_PositionRaw*(1<<30)/192 = (SID_m_ct_PositionRaw*(1<<22)/192)*(1<<8) = (SID_m_ct_PositionRaw*(1<<22)/3)*(1<<2);
	SID_m_phi_RotPos = (SID_m_ct_PosRaw*(1<<22)/3)*(1<<2);
	//SID_m_phi_RotPos = SID_m_phi_RotPos*4;
	
	//MLIB_Mul_F32F16F16(FRAC16(0.5),(tFrac16)(SID_m_phi_RotPos));
	//MLIB_ShR_F16(f16In1, u16In2);
}


void Enc_SpdMeas(void)
{
	if(SID_m_ct_eTimer0Ch1Capt1[1] > SID_m_ct_eTimer0Ch1Capt1[0])
	{
		SID_m_ct_PhaseB = SID_m_ct_eTimer0Ch1Capt1[1] - SID_m_ct_eTimer0Ch1Capt1[0];
	}
	else
	{
		SID_m_ct_PhaseB = 0xFFFF - SID_m_ct_eTimer0Ch1Capt1[0] + SID_m_ct_eTimer0Ch1Capt1[1];		
	}
	//(120000000/128/48/SID_m_ct_PhaseB)*(1<<15)
	SID_m_n_MechRPS = (uint16_t)(6400000/SID_m_ct_PhaseB);
}
