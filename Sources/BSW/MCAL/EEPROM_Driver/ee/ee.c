/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics, 2012      *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : ee_demo.c                                             *
* DESCRIPTION   : This file consitutes of high level API's which user   *
*                 application needs to call for performing EEPROM       *
*                 emulation.                                            *
* DATE          : Jan 19, 2012                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES ********************************
 0.0.1   08.09.2010		FPT Team	Initial Version
 0.1.0   09.23.2010		FPT Team	Update comments
 0.2.0	 01.19.2011		FPT Team	Update demo code according to the simplified algorithm
 0.1.1   05.20.2011   FPT Team  Support fixed-length data record.  
 0.1.2   01.19.2012   FPT Team  Added swap cache
 0.3.0	 08.07.2015		XYL       Add some function, ee_demo.c to ee.c                                    
*************************************************************************/

#include "ee_types.h"
#include "ee_emulation.h"
#include "ee.h"

#define CACHE_SIZE_BYTE		    0x40
#define	BUFFER_INIT_VALUE	    0xFF
#define SWAP_CACHE_SIZE_BYTE    0x30

/* Source buffer */
UINT8  srcBuffer[BUFFER_SIZE_BYTE];

/* Read buffer */
UINT8  readBuffer[BUFFER_SIZE_BYTE];

/* cache table*/
UINT8 table[CACHE_SIZE_BYTE];

/* Swap cache */
UINT8 swap_cache[SWAP_CACHE_SIZE_BYTE];

/* cache table configuration*/
CACHE_TABLE g_cTable =
{
    (UINT32)table,      /* cache start address */
    sizeof(table)       /* cache size */
};
SWAP_CACHE swap_Cache =
{
    (UINT32)swap_cache,      /* cache start address*/
    sizeof(swap_cache)       /* cache size*/
};
/* block 0 configuration*/
BLOCK_CONFIG blockConf0 =
{
    LOW_BLOCK0_MASK,                           /* enabledBlock */
    MAIN_ARRAY_BASE + LOW_BLOCK0_OFFSET,       /* start */
    LOW_BLOCK0_SIZE,                           /* size */
    0x00000000,                                /* blank pointer */
    LOW_ADDRESS_SPACE                          /* address space */
};

/* block 1 configuration*/
BLOCK_CONFIG blockConf1 =
{
    LOW_BLOCK1_MASK,                           /* enabledBlock*/
    MAIN_ARRAY_BASE + LOW_BLOCK1_OFFSET,       /* start*/
    LOW_BLOCK1_SIZE,                           /* size*/
    0x00000000,                                /* blank pointer*/
    LOW_ADDRESS_SPACE                          /* address space*/
};

/* block 2 configuration*/
BLOCK_CONFIG blockConf2 =
{
    LOW_BLOCK2_MASK,                           /* enabledBlock */
    MAIN_ARRAY_BASE + LOW_BLOCK2_OFFSET,       /* start */
    LOW_BLOCK2_SIZE,                           /* size */
    0x00000000,                                /* blank pointer */
    LOW_ADDRESS_SPACE                          /* address space */
};

/* block configuration array */
BLOCK_CONFIG* blockConfig[3] =
{
    &blockConf0,        /* block 0 structure address */
    &blockConf1,        /* block 1 structure address */
    &blockConf2         /* block 2 structure address */
};
/* EEPROM configuration */
//cache table is not enabled, no need, cause Storage operation is not frequent 
//comment by xyl
EEPROM_CONFIG eepromConf =
{
    NUMBER_OF_ACTIVE_BLOCKS+1,/* number of blocks          */
    0,                /* active block index        */
    0,                /* write lock flag           */
    C90LC_REG_BASE,   /* C90LC base address        */
    FALSE,            /* use cache table           */
    &g_cTable,          /* cache table               */
    blockConfig       /* block configuration array */
};

/* EEPROM configuration pointer*/
EEPROM_CONFIG* eepromConfigOfUser = &eepromConf;


static void Delay(void);
static void EmptyCallBack(void);


/***********************************************************************
*
*	 Author						:	XYL
*  Description      : initialize EEPROM, cacheEnable false, 
*  Arguments        : void
*  Return Value     : void
*
***********************************************************************/
void ee_InitEeprom(void)
{
	/* unprotect low and middle blocks*/
  /* write the passwords*/
  WRITE32(C90LC_REG_BASE + C90LC_LML, 0xA1A11111);
  WRITE32(C90LC_REG_BASE + C90LC_SLL, 0xC3C33333);

  /* set lock registers for unlocking all low and middle blocks except Shadow */
  WRITE32(C90LC_REG_BASE + C90LC_LML, C90LC_LML_SLOCK);
  WRITE32(C90LC_REG_BASE + C90LC_SLL, C90LC_SLL_SSLOCK);

  #if (EE_TEST > 0)
  /* Erase selected blocks*/
  FSL_RemoveEeprom(eepromConfigOfUser, EmptyCallBack);
  #endif
  //eepromConfig->cacheEnable = TRUE;
  /* initialize EEPROM*/
  FSL_InitEeprom(eepromConfigOfUser, EmptyCallBack);       	
}





/***********************************************************************
*
*	 Author						:	XYL
*  Description      : write record
*  Arguments        : void
*  Return Value     : void
*
***********************************************************************/
void ee_WriteRecord(UINT8 *dataPtr, UINT16	dataSize)
{
  UINT16	lastMaxRecordID;
  UINT16	i;
	
  #if (EE_TEST > 0)
  for (i = 0; i < BUFFER_SIZE_BYTE; i++)
  {
    ((UINT8 *)srcBuffer)[i] = (UINT8)i;
  }
  #endif
  
  /* Record data greater than the small data potion in record header
     and smaller than BUFFER_SIZE_BYTE */
	#if (FIX_LENGTH == LENGTH_TYPE)
	dataSize = DATA_SIZE;
	#endif

	lastMaxRecordID = ee_SearceIdTable(readBuffer,dataSize); 
	if(NUMBER_OF_SEARCHING_RECORD_IN_BLOCK <= (UINT16)(lastMaxRecordID+1)) //0xFFFF+1隐式转换为0x10000（32位）   
		lastMaxRecordID = DATA_ID_0;
	FSL_WriteEeprom(eepromConfigOfUser, lastMaxRecordID+1, dataSize, (UINT32)(dataPtr), WriteRecordConfirmCallBack);
	/* Delay for waiting for the High Voltage operation(Erase during swap) to finish */
	Delay(); 

	//read back to test
	#if (EE_TEST > 0)
	FSL_ReadEeprom(eepromConfigOfUser, lastMaxRecordID+1, dataSize, (UINT32)(readBuffer), WriteRecordConfirmCallBack);
	#endif
	
		/**************************************************************************
    *            Test block Swapping with Cache Table enabled                 *
    **************************************************************************/ 
		#if (EE_TEST > 0)
	  {
	    UINT32 temp;
			UINT16 recordID;
			/* Fill up 2 blocks */
	    /* Check blank space */
	    recordID = 0;
	    temp = dataSize + RECORD_HEAD_SIZE;
	    while((blockConf1.blockStartAddr + blockConf1.blockSize - blockConf1.blankSpace)>=temp)   	
	    {
				/* Keep writing till there is a swap*/
				FSL_WriteEeprom(eepromConfigOfUser, recordID, dataSize , (UINT32)(srcBuffer), EmptyCallBack);       
				recordID++;
				if(recordID > 10)
				{
				    recordID = 1;
				}         
	    }
	    
	    /* Write one more data record to cause block swapping */
	    recordID = 11;
	    FSL_WriteEeprom(eepromConfigOfUser, recordID, dataSize, (UINT32)(srcBuffer), EmptyCallBack);
			/* Delay for waiting for the High Voltage operation(Erase during swap) to finish */
	    Delay();
	  }
		#endif
		
		#if (EE_TEST > 0)
	  {
	    UINT32 temp;
			UINT16 recordID;
			/* Fill up 2 blocks */
	    /* Check blank space */
	    recordID = 0;
	    temp = dataSize + RECORD_HEAD_SIZE;
	    while((blockConf2.blockStartAddr + blockConf2.blockSize - blockConf2.blankSpace)>=temp)   	
	    {
				/* Keep writing till there is a swap*/
				FSL_WriteEeprom(eepromConfigOfUser, recordID, dataSize , (UINT32)(srcBuffer), EmptyCallBack);       
				recordID++;
				if(recordID > 10)
				{
				    recordID = 1;
				}         
	    }
	    
	    /* Write one more data record to cause block swapping */
	    recordID = 11;
	    FSL_WriteEeprom(eepromConfigOfUser, recordID, dataSize, (UINT32)(srcBuffer), EmptyCallBack);
			/* Delay for waiting for the High Voltage operation(Erase during swap) to finish */
	    Delay();
	  }
		#endif
}




/***********************************************************************
*
*	 Author						:	XYL
*  Description      : waiting for the High Voltage operation(Erase during swap) to finish
*  Arguments        : void
*  Return Value     : void
*
***********************************************************************/
void Delay(void)
{   
  while (eraseStatus_Flag == ERASE_INPROGRESS)
	{
		FSL_MainFunction(eepromConfigOfUser, EmptyCallBack);
	}
}


void EmptyCallBack(void)
{
}

/***********************************************************************
*
*	 Author						:	XYL
*  Description      : for debug
*  Arguments        : void
*  Return Value     : void
*
***********************************************************************/
void WriteRecordConfirmCallBack(void)
{
	CAN_0_Transmit(0x18FFFFFF,(UINT8*)readBuffer, 8);
}

/***********************************************************************
*
*	 Author						:	XYL
*  Description      : find the max id that have been WRITTEN
*  Arguments        : dataID,*recordAddr.
                              recordAddr is the address the given ID where it is.
*  Return Value     : max id
*
***********************************************************************/

UINT16 ee_SearceIdTable(UINT8  *readPtr, UINT16 dataSize)
{
  UINT16 id;

#if (FIX_LENGTH == LENGTH_TYPE)
  dataSize = DATA_SIZE;
#endif
  for(id=DATA_ID_0; id<=NUMBER_OF_SEARCHING_RECORD_IN_BLOCK; id++)
  {
    if (EE_OK != FSL_ReadEeprom(eepromConfigOfUser, id, dataSize,(UINT32)(readBuffer), EmptyCallBack))
    {
       FSL_ReadEeprom(eepromConfigOfUser, id-1, dataSize,(UINT32)(readPtr), EmptyCallBack);
       break;
    }
  }
  
  return (id-1);
}
