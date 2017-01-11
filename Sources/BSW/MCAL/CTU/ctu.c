#include "MPC5643L.h"
#include "FlexPWM.h"
#include "Adc.h"
#include "ctu.h"

static void DualFifoChaChb(uint8_t cmd_no, uint8_t fifo, uint8_t cha, uint8_t chb)
{
	CTU.CLR_DCM[cmd_no].B.CIR = 0;//no ISR
	CTU.CLR_DCM[cmd_no].B.LC = 0;//Last command
	CTU.CLR_DCM[cmd_no].B.CMS = 1;//dual conv
	CTU.CLR_DCM[cmd_no].B.FIFO = fifo;//FIFOfifo
	CTU.CLR_DCM[cmd_no].B.CHB = chb;//ADC1_chb
	CTU.CLR_DCM[cmd_no].B.CHA = cha;//ADC0_cha	
}


static void SingleConvCmd(uint8_t cmd_no, uint8_t fifo, uint8_t su, uint8_t ch)
{	
	CTU.CLR_SCM[cmd_no].B.CIR = 0;//no ISR
	CTU.CLR_SCM[cmd_no].B.LC = 0;//Last command
	CTU.CLR_SCM[cmd_no].B.CMS = 0;//single conv
	CTU.CLR_SCM[cmd_no].B.FIFO = fifo;
	CTU.CLR_SCM[cmd_no].B.SU = su;//ADC1 or ADC1
	CTU.CLR_SCM[cmd_no].B.CH = ch;//
}

static inline
void dummy_command_dual(uint8_t cmd_no)
{
	CTU.CLR_DCM[cmd_no].B.CIR = 0;//no ISR
	CTU.CLR_DCM[cmd_no].B.LC = 1;//Last command 
	CTU.CLR_DCM[cmd_no].B.CMS = 1;//dual conv	
}

static void ConfigureCmdList(void)
{
	//Command list control registers
	CTU.CLCR1.B.T0INDEX = 0;/* Trigger 0 command list - first command address */
	CTU.CLCR1.B.T1INDEX = 2;/* Trigger 1 command list - first command address */
	//FIFO3 Phase current
	DualFifoChaChb(0,CTU_FIFO3,11,12);

	dummy_command_dual(1);
	
	//all ADC channel in dual-conv mode
	DualFifoChaChb(2,CTU_FIFO1,2,2);
	DualFifoChaChb(3,CTU_FIFO1,3,3);
	DualFifoChaChb(4,CTU_FIFO1,4,4);
	DualFifoChaChb(5,CTU_FIFO1,6,6);
	DualFifoChaChb(6,CTU_FIFO1,7,7);
	DualFifoChaChb(7,CTU_FIFO1,8,8); 
   
	SingleConvCmd(8, CTU_FIFO0, ADC_NO1, 0);
	SingleConvCmd(9, CTU_FIFO0, ADC_NO1, 1);
	SingleConvCmd(10, CTU_FIFO0, ADC_NO1, 5);
	
	dummy_command_dual(11);
}


static void ConfigureAdcCommand(void)
{
	//Trigger x Compare Register Value
	CTU.T0CR.R = 1;
	CTU.T1CR.R = 1;//600/120M=5us
	//Trigger Handler control registers
	CTU.THCR1.B.T0_E = 1;/* Trigger 0 enable */
	CTU.THCR1.B.T0_ADCE = 1;/* Trigger 0 ADC Command output enable */
	CTU.THCR1.B.T0_T1E = 1;/* Trigger 0 Timer1 output enable */
	CTU.THCR1.B.T0_T2E = 1;/* Trigger 0 Timer2 output enable */
	
	CTU.THCR1.B.T1_E = 1;/* Trigger 1 enable */
	CTU.THCR1.B.T1_ADCE = 1;/* Trigger 1 ADC Command output enable */
	
	ConfigureCmdList();
}



static void ConfigureFifo(void)
{
	CTU.CR.B.DMA_EN3 = 1;//Enable FIFO3 DMA 
	//CTU.CR.B.DMA_EN2 = 1;//Enable FIFO2 DMA 
	CTU.CR.B.DMA_EN1 = 1;//Enable FIFO1 DMA 
	CTU.CR.B.DMA_EN0 = 1;//Enable FIFO0 DMA 

	CTU.TH1.B.THRESHOLD3 = CTU_FIFO3_THRESHOLD-1;
	//CTU.TH1.B.THRESHOLD2 = CTU_FIFO2_THRESHOLD-1;
	CTU.TH1.B.THRESHOLD1 = CTU_FIFO1_THRESHOLD-1;
	CTU.TH1.B.THRESHOLD0 = CTU_FIFO0_THRESHOLD-1;	
}


static void PreprocessSome(void)
{
	//Clear error flag register
	CTU.CTUEFR.R = 0xFFFF;
	//Interrupt flag
	CTU.CTUIFR.R = 0xFFFF;
	//Interrupt enable, MRS_I MRS Interrupt Enable
	//CTU.CTUIR.B.MRS_IE = 1;
	//Control On time for external trigger
	//CTU.COTR.R = 120; //sec duration
  //CTU.STS.R |= 0xD;
}

static void Configure_Reload(void)
{
	//Compare modulo & reload value
	//CTU.TGSCCR.R = 2*FLEXPWM0_SUB012_HALF;//20160425 xyl modify,  counter compare register
	CTU.TGSCCR.R = 0xFFFF;//20160520 xyl modify 
	CTU.TGSCRR.R = 0;//TGS counter reload register,Counter Reload Value

	CTU.TGSISR.B.I14_RE = 1;/* eTimer1 Rising  Edge Enable */
	CTU.TGSISR.B.I0_RE = 1;/* PWM Reload Rising  Edge Enable */
	CTU.TGSCR.B.TGS_M  = 1;//SEQ mode
	CTU.TGSCR.B.MRS_SM  = 0;/* MRS Selection in Sequential Mode */
	// Cross Triggering Unit Control Register
	CTU.CTUCR.B.TGSISR_RE = 1;      	// TGS Input Selection Register Reload Enable
	CTU.CTUCR.B.GRE    = 1;				// General Reload Enable		
}


void ConfigureCTU(void) 
{
	ConfigureAdcCommand();	
	ConfigureFifo();
	PreprocessSome();
	Configure_Reload();
}
