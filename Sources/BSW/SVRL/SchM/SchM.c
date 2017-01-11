/*******************************************************************************
*
*  FILE
*     SchM.c
*
*  DESCRIPTION
*     BSW Scheduler 
*      
*       
*  COPYRIGHT
*     
*     All rights reserved.
*
*  AUTHOR
*   
*
*  VERSION
*    1.0.0
*
*******************************************************************************/

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "MPC5643L.h"
#include "clocks_modes.h"
#include "pbridge.h"
#include "xbar.h"
#include "Exceptions.h"
#include "INTCInterrupts.h"

#include "mcu.h"
#include "siu.h"
#include "Gpt.h"	
#include "PIT.h"

#include "CAN_Msg.h"
#include "CAN_Init.h"

#include "flexPWM.h"
#include "ctu.h"
#include "Adc.h"
#include "dma.h"
#include "eTimer.h"
#include "isr.h"

#include "DSPI.h"
#include "AD2S1210.h"

#include "foc.h"



#include "ee.h"

#include "VFB.h"

#include "SchM.h"





volatile uint32_t RawVoltagesTable_FIFO3[CTU_FIFO3_THRESHOLD];
//volatile uint32_t RawVoltagesTable_FIFO2_Array[BITER_CNT][CTU_FIFO2_THRESHOLD];
volatile uint32_t RawVoltagesTable_FIFO1_Array[BITER_CNT][CTU_FIFO1_THRESHOLD];
volatile uint32_t RawVoltagesTable_FIFO0_Array[BITER_CNT][CTU_FIFO0_THRESHOLD];



/*******************************************************************************
* NAME:             SchM_Init
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      Initialize all BSW modules  
*******************************************************************************/
void SchM_BSW_Init(void)
{
 	ConfigurePBridge();				// Configure Access rights from DMA to Peripheral Bridge access
	ConfigureXBAR();				// Configure Priorities and Park options of crossbar
	InitializeModesAndClock();    /* Initialize mode entries and system clock */
	disableWatchdog();      /* Disable watchdog */

	Ioa_Init();
		
	#ifdef USE_CAN_0
	//Diag_InitTP();
	CAN_InitMsg();
	CAN_Init(); 
		#ifdef USE_XCP
		Xcp_Init();
		#endif
	#endif
	
	#if 0 //20161128 xyl comment
	/*initDSPI_1();
	initAD2S1210();
	delay_us(25000);
	ConfigureDMA15_ADS1210_Ioctl_low();
	ConfigureDMA3_ADS1210_Ioctl_high();
	ConfigureDMA14_ADS1210_Push();
	ConfigureDMA13_ADS1210_Pop();*/
	#endif

	#if 1
	PWM_PadConfig();
	ConfigureFlexPWM0Sub0();
	ConfigureFlexPWM0Sub1();
	ConfigureFlexPWM0Sub2();
	//FlexPWM0Sub3(0);
	LaunchFlexPWM0_modules012();
	#endif


	#if 1	
	ConfigureCTU();
	ConfigureDMA10_CTU_FIFO3();
	//ConfigureDMA9_CTU_FIFO2();
	ConfigureDMA8_CTU_FIFO1();
	ConfigureDMA7_CTU_FIFO0();
	Adc_Init();
  	#endif
    	
	Gpt_Init();	
	Gpt_StartTimer();
	
	eTimer1_Init();
	
	eTimer0_Encode_Init();
	ConfigureDMA11_eTimer0Ch1();
	//ConfigureDMA12_eTimer0Ch0();//*/
	
	
	#ifdef USE_INTC
	EXCEP_InitExceptionHandlers();
	INTC_InstallINTCInterruptHandler(eTimer_1_TC5IR_Isr, 173, 2);
	INTC.CPR.B.PRI = 0;	
	INTC_InitINTCInterrupts();
	#endif
	
	//SIU.GPDO[22].R=1;//三相驱动使能，高电平有效	
}


/*******************************************************************************
* NAME:             SchM_ASW_Init
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call ASW Init
*******************************************************************************/
void SchM_ASW_Init(void)
{
	//SetFlexPWM0Sub3_val2(3200/2);//

	//focFastLoopInit();
}
/*******************************************************************************
* NAME:             SchM_MainFunction
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call BSW MainFunctions
*******************************************************************************/
void SchM_MainFunction(void)
{
	#ifdef USE_CAN_0
	CAN_0_Receive();
	#ifdef USE_XCP
	Xcp_Background();
	#endif
	#endif
}

/*******************************************************************************
* NAME:             SchM_Period5MS
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call Periodically per 50ms 
*******************************************************************************/
void SchM_Period1Ms(void)
{	
	#ifdef USE_CAN_0
	CANTxRx_Timer();
	CANTxRx_State();
	#endif
	
	//Ioa_Input();
	EncodePosGet();
	Enc_SpdMeas();
}

/*******************************************************************************
* NAME:             SchM_Period10MsOne
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call Periodically per 10ms 
*******************************************************************************/
void SchM_Period2Ms(void)
{
	
}

/*******************************************************************************
* NAME:             SchM_Period10MsTwo
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call Periodically per 10ms 

*******************************************************************************/
void SchM_Period10Ms(void)
{
	//Ioa_Input();
	#ifdef USE_XCP
	Xcp_Service(0); 	
	#endif

	Adc_GetValue_10ms();
	//SafetyControl();
	/*if (SID_m_ct_V48Raw > 3546)
	{
		SID_m_u_V48 = (SInt32)(605552 * 3546 );
	}
	else
	{
		SID_m_u_V48 = (SInt32)(605552 * SID_m_ct_V48Raw );
	}*/

	//CurD_Req_Ramp();//20160622
	//CurQ_Req_Ramp();
}

/*******************************************************************************
* NAME:             SchM_Period100MS
* CALLED BY:        Application
* PRECONDITIONS:
* INPUT PARAMETERS: Void
* RETURN VALUES:    Void
* DESCRIPTION:      call Periodically per 100ms 
*******************************************************************************/
extern void Xcp_DataHandle(void);

extern GFLIB_CONTROLLER_PIAW_R_T stc_hMDRV_dAxisPI;
extern GFLIB_CONTROLLER_PIAW_R_T stc_hMDRV_qAxisPI;

sint32 d_cc1_OV;
sint32 d_cc2_OV;
uint16_t d_N_Shift;

sint32 q_cc1_OV;
sint32 q_cc2_OV;
uint16_t q_N_Shift;

uint8_t dq_cc_OV_EN;

extern GFLIB_CONTROLLER_PIAW_P_T dAxisPI_P;
extern GFLIB_CONTROLLER_PIAW_P_T qAxisPI_P;


uint8_t sch_1000ms_en;

static uint8_t sch_100ms_cnt;
static uint8_t cur_req_q_cnt;

extern uint8_t cur_req_d_ov_en;
extern int32_t cur_req_d_ov;
extern uint8_t cur_req_q_ov_en;
extern int32_t cur_req_q_ov;

#define CUR_REQ_0_CNT 90
#define CUR_REQ_NON_0_CNT 10


void SchM_Period100Ms(void)
{
	#ifdef USE_XCP
	static uint8_t xcp_service_cnt2;
	
	Xcp_Service(1);
	xcp_service_cnt2++;
	if(xcp_service_cnt2 >= 5)
	{
		xcp_service_cnt2 = 0;
		Xcp_Service(2);	
	}
		
	Xcp_DataHandle();
	#endif
	
	Ioa_Output();
}


