/************************************************************************/
/* Author: xyl													*/
/* Date:   20150524											*/			
/************************************************************************/
#include "MPC5643L.h"
#include "dma.h"
#include "Adc.h"
#include "AD2S1210.h"



uint8_t ads1210_io_low[] = {0x00};
uint8_t ads1210_io_high[] = {0x01};
uint32_t spi01_push[]  = {0x10010000};//Continuous,NOT End of Queue 


void ConfigureDMA10_CTU_FIFO3(void)
{
	EDMA.SERQR.R = 10; //Enable request to channel
	 
	EDMA.CHANNEL[10].TCDWORD0_.B.SADDR = (uint32_t)(&(CTU.FRA[3].R));   // Source Address 	

	EDMA.CHANNEL[10].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo : no modulo features
	EDMA.CHANNEL[10].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
	EDMA.CHANNEL[10].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
	EDMA.CHANNEL[10].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
	EDMA.CHANNEL[10].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset

	EDMA.CHANNEL[10].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
	EDMA.CHANNEL[10].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
	EDMA.CHANNEL[10].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
	EDMA.CHANNEL[10].TCDWORD8_.B.NBYTES = CTU_FIFO3_DATA_BYTES;	//  Inner "minor" byte count 

	EDMA.CHANNEL[10].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

	EDMA.CHANNEL[10].TCDWORD16_.B.DADDR = (uint32_t) (RawVoltagesTable_FIFO3);   // Destination address 

	EDMA.CHANNEL[10].TCDWORD20_.B.CITER_E_LINK = 0;  //   no link on minor loop 
	EDMA.CHANNEL[10].TCDWORD20_.B.CITER_LINKCH = 0;  //   no link on minor loop                       
	EDMA.CHANNEL[10].TCDWORD20_.B.CITER = 1;	       //   iteration count
	EDMA.CHANNEL[10].TCDWORD20_.B.DOFF = 4;	       //  Signed destination address offset 

	EDMA.CHANNEL[10].TCDWORD24_.B.DLAST_SGA = -CTU_FIFO3_DATA_BYTES;//  Signed destination address adjust

	EDMA.CHANNEL[10].TCDWORD28_.B.BITER_E_LINK = 0;   //   no link on minor loop 
	//EDMA.CHANNEL[10].TCDWORD28_.B.BITER_LINKCH = 0;
	EDMA.CHANNEL[10].TCDWORD28_.B.BITER = 1;          //  iteration count 
	EDMA.CHANNEL[10].TCDWORD28_.B.BWC = 0;	        //  Bandwidth control :  No DMA Stalls 
	EDMA.CHANNEL[10].TCDWORD28_.B.MAJOR_LINKCH = 0;	//  No link on major loop
	EDMA.CHANNEL[10].TCDWORD28_.B.DONE = 0;	        //  Channel Done 
	EDMA.CHANNEL[10].TCDWORD28_.B.ACTIVE = 0;	        //  Channel Active
	EDMA.CHANNEL[10].TCDWORD28_.B.MAJOR_E_LINK = 0;   //  No link on major loop
	EDMA.CHANNEL[10].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
	EDMA.CHANNEL[10].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
	EDMA.CHANNEL[10].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
	EDMA.CHANNEL[10].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion

	EDMA.DCHPRI[10].R = 0x40;
	EDMA.DCHPRI[10].R |= 10;

  DMAMUX.CHCONFIG[10].B.ENBL = 0;
	DMAMUX.CHCONFIG[10].B.TRIG = 0;
	DMAMUX.CHCONFIG[10].B.SOURCE = 11;   // CTU FIFO3 threshold
	DMAMUX.CHCONFIG[10].B.ENBL = 1;//*/	
}



void ConfigureDMA9_CTU_FIFO2(void)
{
	EDMA.SERQR.R = 9; //Enable request to channel
	 
	EDMA.CHANNEL[9].TCDWORD0_.B.SADDR = (uint32_t) (&(CTU.FRA[2].R));   // Source Address 	

	EDMA.CHANNEL[9].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo : no modulo features
	EDMA.CHANNEL[9].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
	EDMA.CHANNEL[9].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
	EDMA.CHANNEL[9].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
	EDMA.CHANNEL[9].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset

	EDMA.CHANNEL[9].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
	EDMA.CHANNEL[9].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
	EDMA.CHANNEL[9].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
	EDMA.CHANNEL[9].TCDWORD8_.B.NBYTES = CTU_FIFO2_DATA_BYTES;	//  Inner "minor" byte count 

	EDMA.CHANNEL[9].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

	EDMA.CHANNEL[9].TCDWORD16_.B.DADDR = (uint32_t) (RawVoltagesTable_FIFO2_Array);   // Destination address 

	EDMA.CHANNEL[9].TCDWORD20_.B.CITER_E_LINK = 0;  //   no link on minor loop 
	EDMA.CHANNEL[9].TCDWORD20_.B.CITER_LINKCH = 0;  //   no link on minor loop                       
	EDMA.CHANNEL[9].TCDWORD20_.B.CITER = BITER_CNT;	       //   iteration count
	EDMA.CHANNEL[9].TCDWORD20_.B.DOFF = 4;	       //  Signed destination address offset 

	EDMA.CHANNEL[9].TCDWORD24_.B.DLAST_SGA = -CTU_FIFO2_DATA_BYTES*BITER_CNT;     //  Signed destination address adjust

	EDMA.CHANNEL[9].TCDWORD28_.B.BITER_E_LINK = 0;   //   no link on minor loop 
	//EDMA.CHANNEL[9].TCDWORD28_.B.BITER_LINKCH = 0;
	EDMA.CHANNEL[9].TCDWORD28_.B.BITER = BITER_CNT;          //  iteration count 
	EDMA.CHANNEL[9].TCDWORD28_.B.BWC = 0;	        //  Bandwidth control :  No DMA Stalls 
	EDMA.CHANNEL[9].TCDWORD28_.B.MAJOR_LINKCH = 0;	//  No link on major loop
	EDMA.CHANNEL[9].TCDWORD28_.B.DONE = 0;	        //  Channel Done 
	EDMA.CHANNEL[9].TCDWORD28_.B.ACTIVE = 0;	        //  Channel Active
	EDMA.CHANNEL[9].TCDWORD28_.B.MAJOR_E_LINK = 0;   //  No link on major loop
	EDMA.CHANNEL[9].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
	EDMA.CHANNEL[9].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
	EDMA.CHANNEL[9].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
	EDMA.CHANNEL[9].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion

	EDMA.DCHPRI[9].R = 0x40;
	EDMA.DCHPRI[9].R |= 9;

  DMAMUX.CHCONFIG[9].B.ENBL = 0;
	DMAMUX.CHCONFIG[9].B.TRIG = 0;
	DMAMUX.CHCONFIG[9].B.SOURCE = 10;   // CTU FIFO2 threshold
	DMAMUX.CHCONFIG[9].B.ENBL = 1;//*/	
}

/*
void ConfigureDMA8_CTU_FIFO1(void)
{
	EDMA.SERQR.R = 8; //Enable request to channel
	 
	EDMA.CHANNEL[8].TCDWORD0_.B.SADDR = (uint32_t) (&(CTU.FRA[1].R));   // Source Address 	

	EDMA.CHANNEL[8].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo : no modulo features
	EDMA.CHANNEL[8].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
	EDMA.CHANNEL[8].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
	EDMA.CHANNEL[8].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
	EDMA.CHANNEL[8].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset

	EDMA.CHANNEL[8].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.NBYTES = CTU_FIFO1_DATA_BYTES;	//  Inner "minor" byte count 

	EDMA.CHANNEL[8].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

	EDMA.CHANNEL[8].TCDWORD16_.B.DADDR = (uint32_t) (RawVoltagesTable_FIFO1);   // Destination address 

	EDMA.CHANNEL[8].TCDWORD20_.B.CITER_E_LINK = 0;  //   no link on minor loop 
	EDMA.CHANNEL[8].TCDWORD20_.B.CITER_LINKCH = 0;  //   no link on minor loop                       
	EDMA.CHANNEL[8].TCDWORD20_.B.CITER = 1;	       //   iteration count
	EDMA.CHANNEL[8].TCDWORD20_.B.DOFF = 4;	       //  Signed destination address offset 

	EDMA.CHANNEL[8].TCDWORD24_.B.DLAST_SGA = -CTU_FIFO1_DATA_BYTES;     //  Signed destination address adjust

	EDMA.CHANNEL[8].TCDWORD28_.B.BITER_E_LINK = 0;   //   no link on minor loop 
	//EDMA.CHANNEL[8].TCDWORD28_.B.BITER_LINKCH = 0;
	EDMA.CHANNEL[8].TCDWORD28_.B.BITER = 1;          //  iteration count 
	EDMA.CHANNEL[8].TCDWORD28_.B.BWC = 0;	        //  Bandwidth control :  No DMA Stalls 
	EDMA.CHANNEL[8].TCDWORD28_.B.MAJOR_LINKCH = 0;	//  No link on major loop
	EDMA.CHANNEL[8].TCDWORD28_.B.DONE = 0;	        //  Channel Done 
	EDMA.CHANNEL[8].TCDWORD28_.B.ACTIVE = 0;	        //  Channel Active
	EDMA.CHANNEL[8].TCDWORD28_.B.MAJOR_E_LINK = 0;   //  No link on major loop
	EDMA.CHANNEL[8].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
	EDMA.CHANNEL[8].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
	EDMA.CHANNEL[8].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
	EDMA.CHANNEL[8].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion

	EDMA.DCHPRI[8].R = 0x40;
	EDMA.DCHPRI[8].R |= 8;

  DMAMUX.CHCONFIG[8].B.ENBL = 0;
	DMAMUX.CHCONFIG[8].B.TRIG = 0;
	DMAMUX.CHCONFIG[8].B.SOURCE = 9;   // CTU FIFO1 threshold
	DMAMUX.CHCONFIG[8].B.ENBL = 1;//	
}*/


void ConfigureDMA8_CTU_FIFO1(void)
{
	EDMA.SERQR.R = 8; //Enable request to channel
	 
	EDMA.CHANNEL[8].TCDWORD0_.B.SADDR = (uint32_t) (&(CTU.FRA[1].R));   // Source Address 	

	EDMA.CHANNEL[8].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo : no modulo features
	EDMA.CHANNEL[8].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
	EDMA.CHANNEL[8].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
	EDMA.CHANNEL[8].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
	EDMA.CHANNEL[8].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset

	EDMA.CHANNEL[8].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
	EDMA.CHANNEL[8].TCDWORD8_.B.NBYTES = CTU_FIFO1_DATA_BYTES;	//  Inner "minor" byte count 

	EDMA.CHANNEL[8].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

	EDMA.CHANNEL[8].TCDWORD16_.B.DADDR = (uint32_t) (RawVoltagesTable_FIFO1_Array);   // Destination address 

	EDMA.CHANNEL[8].TCDWORD20_.B.CITER_E_LINK = 0;  //   no link on minor loop 
	EDMA.CHANNEL[8].TCDWORD20_.B.CITER_LINKCH = 0;  //   no link on minor loop                       
	EDMA.CHANNEL[8].TCDWORD20_.B.CITER = BITER_CNT;	       //   iteration count
	EDMA.CHANNEL[8].TCDWORD20_.B.DOFF = 4;	       //  Signed destination address offset 

	EDMA.CHANNEL[8].TCDWORD24_.B.DLAST_SGA = -CTU_FIFO1_DATA_BYTES*BITER_CNT;     //  Signed destination address adjust

	EDMA.CHANNEL[8].TCDWORD28_.B.BITER_E_LINK = 0;   //   no link on minor loop 
	//EDMA.CHANNEL[8].TCDWORD28_.B.BITER_LINKCH = 0;
	EDMA.CHANNEL[8].TCDWORD28_.B.BITER = BITER_CNT;          //  iteration count 
	EDMA.CHANNEL[8].TCDWORD28_.B.BWC = 0;	        //  Bandwidth control :  No DMA Stalls 
	EDMA.CHANNEL[8].TCDWORD28_.B.MAJOR_LINKCH = 0;	//  No link on major loop
	EDMA.CHANNEL[8].TCDWORD28_.B.DONE = 0;	        //  Channel Done 
	EDMA.CHANNEL[8].TCDWORD28_.B.ACTIVE = 0;	        //  Channel Active
	EDMA.CHANNEL[8].TCDWORD28_.B.MAJOR_E_LINK = 0;   //  No link on major loop
	EDMA.CHANNEL[8].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
	EDMA.CHANNEL[8].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
	EDMA.CHANNEL[8].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
	EDMA.CHANNEL[8].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion

	EDMA.DCHPRI[8].R = 0x40;
	EDMA.DCHPRI[8].R |= 8;

  DMAMUX.CHCONFIG[8].B.ENBL = 0;
	DMAMUX.CHCONFIG[8].B.TRIG = 0;
	DMAMUX.CHCONFIG[8].B.SOURCE = 9;   // CTU FIFO1 threshold
	DMAMUX.CHCONFIG[8].B.ENBL = 1;//*/		
}



void ConfigureDMA7_CTU_FIFO0(void)
{
	EDMA.SERQR.R = 7; //Enable request to channel
	 
	EDMA.CHANNEL[7].TCDWORD0_.B.SADDR = (uint32_t) (&(CTU.FRA[0].R));   // Source Address 	

	EDMA.CHANNEL[7].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo : no modulo features
	EDMA.CHANNEL[7].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
	EDMA.CHANNEL[7].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
	EDMA.CHANNEL[7].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
	EDMA.CHANNEL[7].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset

	EDMA.CHANNEL[7].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
	EDMA.CHANNEL[7].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
	EDMA.CHANNEL[7].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
	EDMA.CHANNEL[7].TCDWORD8_.B.NBYTES = CTU_FIFO0_DATA_BYTES;	//  Inner "minor" byte count 

	EDMA.CHANNEL[7].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

	EDMA.CHANNEL[7].TCDWORD16_.B.DADDR = (uint32_t) (RawVoltagesTable_FIFO0_Array);   // Destination address 

	EDMA.CHANNEL[7].TCDWORD20_.B.CITER_E_LINK = 0;  //   no link on minor loop 
	EDMA.CHANNEL[7].TCDWORD20_.B.CITER_LINKCH = 0;  //   no link on minor loop                       
	EDMA.CHANNEL[7].TCDWORD20_.B.CITER = BITER_CNT;	       //   iteration count
	EDMA.CHANNEL[7].TCDWORD20_.B.DOFF = 4;	       //  Signed destination address offset 

	EDMA.CHANNEL[7].TCDWORD24_.B.DLAST_SGA = -CTU_FIFO0_DATA_BYTES*BITER_CNT;     //  Signed destination address adjust

	EDMA.CHANNEL[7].TCDWORD28_.B.BITER_E_LINK = 0;   //   no link on minor loop 
	//EDMA.CHANNEL[7].TCDWORD28_.B.BITER_LINKCH = 0;
	EDMA.CHANNEL[7].TCDWORD28_.B.BITER = BITER_CNT;          //  iteration count 
	EDMA.CHANNEL[7].TCDWORD28_.B.BWC = 0;	        //  Bandwidth control :  No DMA Stalls 
	EDMA.CHANNEL[7].TCDWORD28_.B.MAJOR_LINKCH = 0;	//  No link on major loop
	EDMA.CHANNEL[7].TCDWORD28_.B.DONE = 0;	        //  Channel Done 
	EDMA.CHANNEL[7].TCDWORD28_.B.ACTIVE = 0;	        //  Channel Active
	EDMA.CHANNEL[7].TCDWORD28_.B.MAJOR_E_LINK = 0;   //  No link on major loop
	EDMA.CHANNEL[7].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
	EDMA.CHANNEL[7].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
	EDMA.CHANNEL[7].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
	EDMA.CHANNEL[7].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion

	EDMA.DCHPRI[7].R = 0x40;
	EDMA.DCHPRI[7].R |= 7;

  DMAMUX.CHCONFIG[7].B.ENBL = 0;
	DMAMUX.CHCONFIG[7].B.TRIG = 0;
	DMAMUX.CHCONFIG[7].B.SOURCE = 8;   // CTU FIFO0 threshold
	DMAMUX.CHCONFIG[7].B.ENBL = 1;//*/		
}










void ConfigureDMA15_ADS1210_Ioctl_low(void)
{
	 EDMA.CHANNEL[15].TCDWORD0_.B.SADDR = (uint32_t) (ads1210_io_low);   // Source Address 	
   
   EDMA.CHANNEL[15].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[15].TCDWORD4_.B.SSIZE = 0;	    //  Source transfer size : 8 Bits 
   EDMA.CHANNEL[15].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[15].TCDWORD4_.B.DSIZE = 0;	    //  Destination transfer size : 8 Bits 
   EDMA.CHANNEL[15].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[15].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[15].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[15].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[15].TCDWORD8_.B.NBYTES = 1;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[15].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[15].TCDWORD16_.B.DADDR = (uint32_t)(&(SIU.GPDO[84].R));    // Destination address 
   
   EDMA.CHANNEL[15].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[15].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[15].TCDWORD20_.B.CITER = 1;	       //   iteration count
   EDMA.CHANNEL[15].TCDWORD20_.B.DOFF = 0;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[15].TCDWORD24_.B.DLAST_SGA = 0;     //  Signed destination address adjust
   
   EDMA.CHANNEL[15].TCDWORD28_.B.BITER = 1;          // iteration count 
   //EDMA.CHANNEL[15].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[15].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[15].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[15].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[15].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[15].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[15].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[15].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[15].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[15].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[15].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[15].R = 0x40;
	EDMA.DCHPRI[15].R |= 15;

	DMAMUX.CHCONFIG[15].B.ENBL = 0;	
	DMAMUX.CHCONFIG[15].B.TRIG = 0;

	EDMA.SERQR.R = 15; //Enable request to channel

	DMAMUX.CHCONFIG[15].B.SOURCE = 16;//eTimer_1 req0
	DMAMUX.CHCONFIG[15].B.ENBL = 1;		
}


void ConfigureDMA3_ADS1210_Ioctl_high(void)
{
	 EDMA.CHANNEL[3].TCDWORD0_.B.SADDR = (uint32_t) (ads1210_io_high);   // Source Address 	
   
   EDMA.CHANNEL[3].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[3].TCDWORD4_.B.SSIZE = 0;	    //  Source transfer size : 8 Bits 
   EDMA.CHANNEL[3].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[3].TCDWORD4_.B.DSIZE = 0;	    //  Destination transfer size : 8 Bits 
   EDMA.CHANNEL[3].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[3].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[3].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[3].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[3].TCDWORD8_.B.NBYTES = 1;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[3].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[3].TCDWORD16_.B.DADDR = (uint32_t)(&(SIU.GPDO[84].R));    // Destination address 
   
   EDMA.CHANNEL[3].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[3].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[3].TCDWORD20_.B.CITER = 1;	       //   iteration count
   EDMA.CHANNEL[3].TCDWORD20_.B.DOFF = 0;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[3].TCDWORD24_.B.DLAST_SGA = 0;     //  Signed destination address adjust
   
   EDMA.CHANNEL[3].TCDWORD28_.B.BITER = 1;          // iteration count 
   //EDMA.CHANNEL[3].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[3].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[3].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[3].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[3].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[3].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[3].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[3].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[3].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[3].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[3].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[3].R = 0x40;
	EDMA.DCHPRI[3].R |= 3;

	DMAMUX.CHCONFIG[3].B.ENBL = 0;	
	DMAMUX.CHCONFIG[3].B.TRIG = 0;

	EDMA.SERQR.R = 3; //Enable request to channel

	DMAMUX.CHCONFIG[3].B.SOURCE = 17;//eTimer_1 req1
	DMAMUX.CHCONFIG[3].B.ENBL = 1;		
}


void ConfigureDMA14_ADS1210_Push(void)
{
	 EDMA.CHANNEL[14].TCDWORD0_.B.SADDR = (uint32_t) (spi01_push);   // Source Address 	
   
   EDMA.CHANNEL[14].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[14].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
   EDMA.CHANNEL[14].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[14].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
   EDMA.CHANNEL[14].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[14].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[14].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[14].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[14].TCDWORD8_.B.NBYTES = 4;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[14].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[14].TCDWORD16_.B.DADDR = (uint32_t)(&(DSPI_1.PUSHR.R));    // Destination address 
   
   EDMA.CHANNEL[14].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[14].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[14].TCDWORD20_.B.CITER = 1;	       //   iteration count
   EDMA.CHANNEL[14].TCDWORD20_.B.DOFF = 0;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[14].TCDWORD24_.B.DLAST_SGA = 0;     //  Signed destination address adjust
   
   EDMA.CHANNEL[14].TCDWORD28_.B.BITER = 1;          // iteration count 
   //EDMA.CHANNEL[14].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[14].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[14].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[14].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[14].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[14].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[14].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[14].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[14].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[14].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[14].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[14].R = 0x40;
	EDMA.DCHPRI[14].R |= 14;

	DMAMUX.CHCONFIG[14].B.ENBL = 0;	
	DMAMUX.CHCONFIG[14].B.TRIG = 0;

	EDMA.SERQR.R = 14; //Enable request to channel

	DMAMUX.CHCONFIG[14].B.SOURCE = 14;//eTimer_0
	DMAMUX.CHCONFIG[14].B.ENBL = 1;		
}



void ConfigureDMA13_ADS1210_Pop(void)
{
	 EDMA.CHANNEL[13].TCDWORD0_.B.SADDR = (uint32_t) (&DSPI_1.POPR.R);   // Source Address 	
   
   EDMA.CHANNEL[13].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[13].TCDWORD4_.B.SSIZE = 2;	    //  Source transfer size : 32 Bits 
   EDMA.CHANNEL[13].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[13].TCDWORD4_.B.DSIZE = 2;	    //  Destination transfer size : 32 Bits 
   EDMA.CHANNEL[13].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[13].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[13].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[13].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[13].TCDWORD8_.B.NBYTES = 4;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[13].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[13].TCDWORD16_.B.DADDR = (uint32_t)(&SID_m_ct_PositionRaw);    // Destination address 
   
   EDMA.CHANNEL[13].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[13].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[13].TCDWORD20_.B.CITER = 1;	       //   iteration count
   EDMA.CHANNEL[13].TCDWORD20_.B.DOFF = 0;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[13].TCDWORD24_.B.DLAST_SGA = 0;     //  Signed destination address adjust
   
   EDMA.CHANNEL[13].TCDWORD28_.B.BITER = 1;          // iteration count 
   //EDMA.CHANNEL[13].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[13].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[13].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[13].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[13].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[13].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[13].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[13].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[13].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[13].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[13].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[13].R = 0x40;
	EDMA.DCHPRI[13].R |= 13;

	DMAMUX.CHCONFIG[13].B.ENBL = 0;	
	DMAMUX.CHCONFIG[13].B.TRIG = 0;

	EDMA.SERQR.R = 13; //Enable request to channel

	DMAMUX.CHCONFIG[13].B.SOURCE = 15;//eTimer_0
	DMAMUX.CHCONFIG[13].B.ENBL = 1;		
}


extern uint16_t   SID_m_ct_eTimer0Ch0Capt1;

void ConfigureDMA12_eTimer0Ch0(void)
{
	EDMA.CHANNEL[12].TCDWORD0_.B.SADDR = (uint32_t) (&ETIMER_0.CHANNEL[0].CAPT1.R);   // Source Address 	
   
   EDMA.CHANNEL[12].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[12].TCDWORD4_.B.SSIZE = 1;	    //  Source transfer size : 16 Bits 
   EDMA.CHANNEL[12].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[12].TCDWORD4_.B.DSIZE = 1;	    //  Destination transfer size : 16 Bits 
   EDMA.CHANNEL[12].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[12].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[12].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[12].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[12].TCDWORD8_.B.NBYTES = 2;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[12].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[12].TCDWORD16_.B.DADDR = (uint32_t)(&SID_m_ct_eTimer0Ch0Capt1);    // Destination address 
   
   EDMA.CHANNEL[12].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[12].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[12].TCDWORD20_.B.CITER = 1;	       //   iteration count
   EDMA.CHANNEL[12].TCDWORD20_.B.DOFF = 0;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[12].TCDWORD24_.B.DLAST_SGA = 0;     //  Signed destination address adjust
 
   EDMA.CHANNEL[12].TCDWORD28_.B.BITER = 1;          // iteration count 
   //EDMA.CHANNEL[13].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[12].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[12].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[12].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[12].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[12].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[12].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[12].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[12].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[12].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[12].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[12].R = 0x40;
	EDMA.DCHPRI[12].R |= 12;

	DMAMUX.CHCONFIG[12].B.ENBL = 0;	
	DMAMUX.CHCONFIG[12].B.TRIG = 0;

	EDMA.SERQR.R = 12; //Enable request to channel

	DMAMUX.CHCONFIG[12].B.SOURCE = 14;//eTimer_0 Channel 0,, Request 0 Select Register (DREQ0)
	DMAMUX.CHCONFIG[12].B.ENBL = 1;			
}

extern uint16_t   SID_m_ct_eTimer0Ch1Capt1[2];

void ConfigureDMA11_eTimer0Ch1(void)
{
	EDMA.CHANNEL[11].TCDWORD0_.B.SADDR = (uint32_t) (&ETIMER_0.CHANNEL[1].CNTR.R);   // Source Address 	
   
   EDMA.CHANNEL[11].TCDWORD4_.B.SMOD  = 0;	    //  Source address modulo
   EDMA.CHANNEL[11].TCDWORD4_.B.SSIZE = 1;	    //  Source transfer size : 16 Bits 
   EDMA.CHANNEL[11].TCDWORD4_.B.DMOD  = 0;	    //  Destination address modulo	
   EDMA.CHANNEL[11].TCDWORD4_.B.DSIZE = 1;	    //  Destination transfer size : 16 Bits 
   EDMA.CHANNEL[11].TCDWORD4_.B.SOFF  = 0;	    //  Signed source address offset
   
   EDMA.CHANNEL[11].TCDWORD8_.B.SMLOE = 0;	    //  disable source minor loop offset
   EDMA.CHANNEL[11].TCDWORD8_.B.DMLOE = 0;	    //  disable desti minor loop offset
   EDMA.CHANNEL[11].TCDWORD8_.B.MLOFF = 0;	    //  minor loop offset
   EDMA.CHANNEL[11].TCDWORD8_.B.NBYTES = 2;	//  Inner "minor" byte count 
   
   EDMA.CHANNEL[11].TCDWORD12_.B.SLAST =  0;	    //  last Signed source address adjust                  

   EDMA.CHANNEL[11].TCDWORD16_.B.DADDR = (uint32_t)(SID_m_ct_eTimer0Ch1Capt1);    // Destination address 
   
   EDMA.CHANNEL[11].TCDWORD20_.B.CITER_E_LINK = 0;  //link on minor loop 
   EDMA.CHANNEL[11].TCDWORD20_.B.CITER_LINKCH = 0; //link on ch15                       
   EDMA.CHANNEL[11].TCDWORD20_.B.CITER = 2;	       //   iteration count
   EDMA.CHANNEL[11].TCDWORD20_.B.DOFF = 2;	       //  Signed destination address offset 
   
   EDMA.CHANNEL[11].TCDWORD24_.B.DLAST_SGA = -2*2;     //  Signed destination address adjust
 
   EDMA.CHANNEL[11].TCDWORD28_.B.BITER = 2;          // iteration count 
   //EDMA.CHANNEL[13].TCDWORD28_.B.BITER |= (15<<9);
   EDMA.CHANNEL[11].TCDWORD28_.B.BITER_E_LINK = 0;   //no link on minor loop 
   EDMA.CHANNEL[11].TCDWORD28_.B.BWC = 0;	        // bandwidth control :  No DMA Stalls 
   EDMA.CHANNEL[11].TCDWORD28_.B.DONE = 0;	        // Channel Done 
   EDMA.CHANNEL[11].TCDWORD28_.B.ACTIVE = 0;	        // Channel Active
   EDMA.CHANNEL[11].TCDWORD28_.B.MAJOR_LINKCH = 0;	// Link to channel 4 on major loop
   EDMA.CHANNEL[11].TCDWORD28_.B.MAJOR_E_LINK = 0;   //No Link
   EDMA.CHANNEL[11].TCDWORD28_.B.E_SG = 0;	    //  Disable Scatter/Gather
   EDMA.CHANNEL[11].TCDWORD28_.B.D_REQ = 0;	    //  TCD still enabled when done  
   EDMA.CHANNEL[11].TCDWORD28_.B.INT_HALF = 0;	//  No interrupt on minor loop count
   EDMA.CHANNEL[11].TCDWORD28_.B.INT_MAJ = 0;    //  Interrupt on major loop completion
	
	EDMA.DCHPRI[11].R = 0x40;
	EDMA.DCHPRI[11].R |= 11;

	DMAMUX.CHCONFIG[11].B.ENBL = 0;	
	DMAMUX.CHCONFIG[11].B.TRIG = 0;

	EDMA.SERQR.R = 11; //Enable request to channel

	DMAMUX.CHCONFIG[11].B.SOURCE = 15;//eTimer_0 Channel 1,, Request 1 Select Register (DREQ1)
	DMAMUX.CHCONFIG[11].B.ENBL = 1;			
}