#include "MPC5643L.h"
#include "xbar.h"

/****************************************************************************/
/* void ConfigureXBAR(void)			 								    	*/
/****************************************************************************/
/* Desc: Set priorities of DMA masters for each slave port					*/
/*       Set Parking option of DMA masters for each slave port				*/
/*																			*/ 
/****************************************************************************/
void ConfigureXBAR(void) 
{
	//Priority for Flash slave port
	MAX.SLAVE_PORT[0].MPR.R   = 0x76543210;   // CoreInst > CoreData > DMA > FR
	MAX.SLAVE_PORT[0].SGPCR.R = 0x00000000;   // Fixed priority / Park on coreInst
	//Priority for SRAM slave port
	MAX.SLAVE_PORT[2].MPR.R   = 0x76543012;   // DMA > CoreData > CoreInst > FR
	MAX.SLAVE_PORT[2].SGPCR.R = 0x00000002;   // Fixed priority / Park on DMA
	//Priority for Pbridge slave port
	MAX.SLAVE_PORT[7].MPR.R   = 0x76543012;   //DMA > CoreData > CoreInst > FR
	MAX.SLAVE_PORT[7].SGPCR.R = 0x00000002;   // Fixed priority / Park on coreInst
	
}
