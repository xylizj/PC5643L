#include "MPC5643L.h"
#include "pbridge.h"

/****************************************************************************/
/* void ConfigurePBridge(void)			 								    */
/****************************************************************************/
/* Desc: configure Peripheral bridge to allow DMA to access ADC1-CTU-eTimer	*/
/****************************************************************************/
void ConfigurePBridge(void) 
{
	//PBRIDGE.MPROT0_7.R   = 0x77700000;  //Core & DMA trusted for write/read - FR not trusted
	PBRIDGE.MPROT0_7.R   = 0x77777777;//All Master Can go through Peripheral bridge
	
//PBRIDGE.OPACR32_39.R = 0x75F5FF57;  //ADC0-eTIMER1 fully protected
										//ADC1-CTU-eTimer0: write accesses allowed by supervisor	
	//20160424 XYL MODIFY
	//PBRIDGE.OPACR32_39.R = 0x55F5FF57;  //eTIMER1 fully protected
										//ADC0-ADC1-CTU-eTimer0: write accesses allowed by supervisor




	PBRIDGE.PACR0_7.R    	= 0x0;  
  PBRIDGE.PACR8_15.R   	= 0x0; 
  PBRIDGE.PACR16_23.R  	= 0x0; 
 
  PBRIDGE.OPACR0_7.R   	= 0x0; 
  PBRIDGE.OPACR16_23.R 	= 0x0;
  PBRIDGE.OPACR24_31.R 	= 0x0;
  PBRIDGE.OPACR32_39.R 	= 0x0;
  PBRIDGE.OPACR40_47.R 	= 0x0;
  PBRIDGE.OPACR48_55.R		= 0x0;
  PBRIDGE.OPACR56_63.R 	= 0x0;
  PBRIDGE.OPACR64_71.R 	= 0x0;
  PBRIDGE.OPACR80_87.R 	= 0x0;
  PBRIDGE.OPACR88_95.R 	= 0x0;										
}
