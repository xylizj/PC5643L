#include "MPC5643L.h"
#include "FlexPWM.h"
#include "Adc.h"

static void DualFifoChaChb(uint8_t cmd_no, uint8_t fifo, uint8_t cha, uint8_t chb)
{
	CTU.CLR_DCM[cmd_no].B.CIR = 0;//no ISR
	CTU.CLR_DCM[cmd_no].B.LC = 0;//Last command
	CTU.CLR_DCM[cmd_no].B.CMS = 1;//dual conv
	CTU.CLR_DCM[cmd_no].B.FIFO = fifo;//FIFOfifo
	CTU.CLR_DCM[cmd_no].B.CHB = chb;//ADC1_chb
	CTU.CLR_DCM[cmd_no].B.CHA = cha;//ADC0_cha	
}


static void Adc01DualCommonChan(uint8_t cmd_no, uint8_t fifo, uint8_t ch)
{
	CTU.CLR_DCM[cmd_no].B.CIR = 0;//no ISR
	CTU.CLR_DCM[cmd_no].B.LC = 0;//Last command
	CTU.CLR_DCM[cmd_no].B.CMS = 1;//dual conv
	CTU.CLR_DCM[cmd_no].B.FIFO = fifo;//FIFOfifo
	CTU.CLR_DCM[cmd_no].B.CHB = ch;//ADC1_ch
	CTU.CLR_DCM[cmd_no].B.CHA = ch;//ADC0_ch	
}

static void ConfigureCmdList(void)
{
	//Command list control registers
	CTU.CLCR1.B.T0INDEX = 0;/* Trigger 0 command list - first command address */
	CTU.CLCR1.B.T1INDEX = 4;/* Trigger 1 command list - first command address */
	//CTU.CLCR1.B.T2INDEX = 4;/* Trigger 2 command list - first command address */
	//Command list register
	//FIFO3 Phase current
	//dual
	DualFifoChaChb(0,3,14,13);
	//single	
	CTU.CLR_SCM[1].B.CIR = 0;//no ISR
	CTU.CLR_SCM[1].B.LC = 0;//Last command
	CTU.CLR_SCM[1].B.CMS = 0;//single conv
	CTU.CLR_SCM[1].B.FIFO = 3;//FIFO3
	CTU.CLR_SCM[1].B.SU = 1;//ADC1
	CTU.CLR_SCM[1].B.CH = 12;//ADC1_1 PhaseW

	//FIFO2 Exc current
	//single	
	CTU.CLR_SCM[2].B.CIR = 0;//no ISR
	CTU.CLR_SCM[2].B.LC = 0;//Last command
	CTU.CLR_SCM[2].B.CMS = 0;//single conv
	CTU.CLR_SCM[2].B.FIFO = 2;//FIFO2
	CTU.CLR_SCM[2].B.SU = 1;//ADC1
	CTU.CLR_SCM[2].B.CH = 1;//ADC1_1 PhaseW
	
	//dummy command
	//dual
	CTU.CLR_DCM[3].B.CIR = 0;//no ISR
	CTU.CLR_DCM[3].B.LC = 1;//Last command 
	CTU.CLR_DCM[3].B.CMS = 1;//dual conv
	
	//all ADC channel in dual-conv mode
	//FIFO1
	Adc01DualCommonChan(4,1,0); 
	Adc01DualCommonChan(5,1,1); 
	Adc01DualCommonChan(6,1,2); 
	Adc01DualCommonChan(7,1,3); 
	Adc01DualCommonChan(8,1,4); 
	Adc01DualCommonChan(9,1,5); 
	Adc01DualCommonChan(10,1,6); 
   //FIFO0
	Adc01DualCommonChan(11,0,7); 
	Adc01DualCommonChan(12,0,8); 
	DualFifoChaChb(13,0,11,12);
	DualFifoChaChb(14,0,13,14);
	DualFifoChaChb(15,0,10,15);
	DualFifoChaChb(16,0,15,10);
	//dummy command
	//dual
	CTU.CLR_DCM[17].B.CIR = 0;//no ISR
	CTU.CLR_DCM[17].B.LC = 1;//Last command 
	CTU.CLR_DCM[17].B.CMS = 1;//dual conv
}


static void ConfigureAdcCommand(void)
{
	//Trigger x Compare Register Value
	CTU.T0CR.R = 1;
	CTU.T1CR.R = 1;//600/120M=5us
	//CTU.T2CR.R = 600+240;//240/120M=2us
	//Trigger Handler control registers
	CTU.THCR1.B.T0_E = 1;/* Trigger 0 enable */
	CTU.THCR1.B.T0_ADCE = 1;/* Trigger 0 ADC Command output enable */
	CTU.THCR1.B.T0_T1E = 1;/* Trigger 0 Timer1 output enable */
	CTU.THCR1.B.T0_T2E = 1;/* Trigger 0 Timer2 output enable */
	
	CTU.THCR1.B.T1_E = 1;/* Trigger 1 enable */
	CTU.THCR1.B.T1_ADCE = 1;/* Trigger 1 ADC Command output enable */
	
	//CTU.THCR1.B.T2_E = 1;/* Trigger 2 enable */
	//CTU.THCR1.B.T2_ADCE = 1;/* Trigger 2 ADC Command output enable */
	
	ConfigureCmdList();
}



static void ConfigureFifo(void)
{
	CTU.CR.B.DMA_EN3 = 1;//Enable FIFO3 DMA 
	CTU.CR.B.DMA_EN2 = 1;//Enable FIFO2 DMA 
	CTU.CR.B.DMA_EN1 = 1;//Enable FIFO1 DMA 
	CTU.CR.B.DMA_EN0 = 1;//Enable FIFO0 DMA 

  //CTU.FCR.B.FIFO_OVERFLOW_EN0 = 1; // Enable FIFO OVERFLOW Interrupt request

	CTU.TH1.B.THRESHOLD3 = CTU_FIFO3_THRESHOLD-1;
	CTU.TH1.B.THRESHOLD2 = CTU_FIFO2_THRESHOLD-1;
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

	CTU.TGSISR.B.I13_RE = 1;/* eTimer0 Rising  Edge Enable */
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
