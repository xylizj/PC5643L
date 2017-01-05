#ifndef _USER_CFG_
#define _USER_CFG_



/* User Configurable Macros */
#define NUMBER_OF_ACTIVE_BLOCKS  	2//DFLASH 4(sector)*16KB 
#define MAX_REERASE					1

/* Select VLE mode */
#ifndef VLE_ON
	#define VLE_ON                  1
#endif /* VLE_ON */

//add by xyl
#define EE_TEST 0

/* Select a Flash type */

#ifndef FLASH_SELECT
#define FLASH_SELECT				DATA_FLASH
#endif

#ifndef LENGTH_TYPE
#define LENGTH_TYPE					FIX_LENGTH//VAR_LENGTH//
#endif

#if FIX_LENGTH == LENGTH_TYPE
#define	DATA_SIZE		8//0x50 
#endif



#endif /* end of _USER_CFG_ */