/************************************************************************/
/* File Name:      Cfg_Sysclk.h
/* Description:    config the hardware, include pll, ad, dio, spi, pwm
/*                  
/* Comments:           
/*
/* Version     Date           Author           Remark
/* -------  ----------   --------------   ------------------------------      
/*
/************************************************************************/

#ifndef _MCU_CFG_H_
#define _MCU_CFG_H_

#include "Std_Types.h"

/******************************************/
/**       system clock configration      **/
/******************************************/
#define OSC_CLK     40000       /* unit: Khz */
#define SYS_CLK     120000      /* unit: KHz */
#define PLL_NDIV    64         /* range: 32~96, */
#define PLL_IDF     0          /* 0000~1110, range:1~15 */
#define PLL_ODF     2          /* 00/01/10/11-->2/4/8/16*/

/* f(sys)=f(ref)*PLL_NDIV/(PLL_IDF*PLL_ODF) 
		 =8M * 64/(1 * 8) = 64M */

/***** System clock *****/

#define MCU_BUS_FREQ   60U




#endif