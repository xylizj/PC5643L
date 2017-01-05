/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,Inc 2011   *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : eed_highlevel.c                                       *
* DESCRIPTION   : This file consitutes of high level API's which user   *
*                 application needs to call for performing EEPROM       *
*                 emulation.                                            *
* DATE          : May 20, 2011                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
 0.0.1  	08.04.2010      FPT Team    Initial Version
 0.1.0   	09.23.2010      FPT Team    Update comments
 0.2.0   	09.29.2010      FPT Team    Add FSL_AbortFunction function,
										Update FSL_ReadEeprom, FSL_WriteEeprom
										to stop Read, Write opertion if there is
										an ongoing erase operation in one Flash Block,
										Add calling CallBack funtion when 
										FSL_FlashCheckStatus returns EE_INFO_HVOP_INPROGRESS
 0.3.0	 	01.19.2011		FPT Team	Remove FSL_AbortFunction function,
										Update other functions according to
										the simplified algorithm.
 0.1.1      05.20.2011      FPT Team    Support fixed-length
                                        data record.	
 0.1.2      08.05.2011      FPT Team    Mask off immediate bit in dataID to ignore MSB bit 
                                        when read, delete and update cache table.
                                        Move Initialize cache table to the beginning of InitEeprom()
0.1.3		11.19.2012		FPT Team	Fix bug in FSL_InitEeprom to update data record in Cache table
										after brownout when swapping occurs.
*************************************************************************/

#include "ee_types.h"
#include "ee_emulation.h"

/*******************************************************************
| global variable definitions (scope: module-local)
|------------------------------------------------------------------*/
/* Flag to keep track of ECC Error Status*/
UINT8 volatile eccErrorStatus_Flag = FALSE;

/* Flag to keep track of ECC Error Module*/
volatile EE_ModuleType eccErrorModule_Flag = NONE;

/* Flag to keep track of Erase State*/
EE_EraseType eraseStatus_Flag = ERASE_NOTSTARTED;

/* structure to store block configuration during erase*/
BLOCK_CONFIG *blockConfInternal;

/* Flag to keep track of Block Swapping*/
UINT8 blockSwap_Flag = FALSE;

/*Variable to store C90FL Register Base*/
UINT32 c90lcRegBaseInternal;

/*Variable to store erasing cycles*/
PROGRAMMABLE_TYPE erasingCycleInternal;

/*Variable to store size of the data record*/
UINT32 tempInternalSwap;

/*Variable to store DataID*/
UINT16 dataIDInternalSwap;

/*Variable to store Data Size*/
UINT16 dataSizeInternalSwap;

/*Variable to store source address while swap*/
UINT32 sourceInternalSwap;

/* Flag to keep track whether the record is deleted or not*/
BOOL dataDeleted = FALSE;

/* Flag specifies data record source come from FLASH(writeInternal_Flag = FALSE)
   or buffer in RAM (writeInternal_Flag = TRUE) */
BOOL writeInternal_Flag = FALSE;

UINT32 FSL_InitEeprom(EEPROM_CONFIG * eepromConfig, void (*CallBack) (void))
{
    BLOCK_STATUS blockStatus;   /* block status */
    UINT32 c90lcRegBase;
    UINT32 returnCode;
    UINT32 temp;
    UINT32 counter;
    UINT32 activeBlockIndex;    /* Store index of ACTIVE block */
    UINT32 copyBlockIndex;      /* Store index of COPY_START block */
    UINT32 numberOfActiveBlock; /* Store number of ACTIVE block */
    BLOCK_CONFIG *blockConf;
    UINT32 ec_index;            /* Store index of block that need checked erase cycle */
    BOOL firstInit_Flag;        /* Keep track of the first Init EEE */
    UINT32 bufferAddress;       /* store buffer address */
    UINT32 bufferSize;          /* store buffer size */
    UINT16 startID;             /* store the start ID */
    PROGRAMMABLE_TYPE erasingCycle;
    UINT32 faildAddr;
    PROGRAMMABLE_TYPE faildData;
    UINT32 size;
    UINT32 dest;

    /* Initialize some local variables */
    returnCode = EE_OK;
    firstInit_Flag = FALSE;
    startID = 0;

    numberOfActiveBlock = 0;
    activeBlockIndex = 0xFFFFFFFF;
    copyBlockIndex = 0xFFFFFFFF;
    ec_index = 0xFFFFFFFF;
    temp = 0xFFFFFFFF;
    /* initialize the cache table pointer */
    if (eepromConfig->cacheEnable)
    {
        for (counter = 0; counter < ((eepromConfig->cTable->tableSize) / 4); counter++)
        {
            /* Fill all cache table entries with 0xFFFFFFFF */
            FSL_UpdateCacheTable(eepromConfig->cTable, (UINT16) counter, 0xFFFFFFFF);
        }
    }

    /* check the write lock of the Flash */
    if (eepromConfig->blockWriteFlag)
    {
        /* If a write operation is already in progress, no write operation is permitted */
        return (EE_ERROR_WRITE_IN_PROGRESS);
    }
    else
    {
        /* Set the write lock flag */
        eepromConfig->blockWriteFlag = TRUE;
    }

    /* Find activeBlockIndex, copyBlockIndex and numberOfActiveBlock */
    for (counter = 0; counter < eepromConfig->numberOfBlock; counter++)
    {
        /* Get block configuration instant */
        blockConf = eepromConfig->flashBlocks[counter];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

        /* Read block status */
        returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
        if (returnCode != EE_OK)
        {
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (EE_INFO_HVOP_INPROGRESS);
        }

        if (blockStatus == BLOCK_STATUS_ACTIVE)
        {
            /* Save this block as active one */
            activeBlockIndex = temp;
            temp = counter;

            /* Increase numberOfActiveBlock */
            numberOfActiveBlock++;
        }
        else if (blockStatus == BLOCK_STATUS_COPY_START)
        {
            /* This is the active block */
            copyBlockIndex = counter;
        }
        else if (blockStatus == BLOCK_STATUS_ALTERNATIVE)
        {
            /* Do Nothing */
        }
        else                    /* Unknown Status */
        {
            /* Erase the block but don't write erase cycle */
            erasingCycleInternal = PROGRAMMABLE_DEL;
            returnCode = FSL_EraseEEBlock(c90lcRegBase, blockConf, CallBack);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;

                return (returnCode);
            }
        }
    }

    /* Set the activeBlockIndex */
    if (numberOfActiveBlock < 2)
    {
        activeBlockIndex = temp;
    }
    else
    {
        if (temp == ((activeBlockIndex + 1) % eepromConfig->numberOfBlock))
        {
            activeBlockIndex = temp;
        }
    }

    /* Find the block that need checked Erase Cycle */
    if (copyBlockIndex != 0xFFFFFFFF)
    {
        if (copyBlockIndex >= NUMBER_OF_ACTIVE_BLOCKS)
        {
            ec_index = copyBlockIndex - NUMBER_OF_ACTIVE_BLOCKS;
        }
        else
        {
            ec_index = (copyBlockIndex + eepromConfig->numberOfBlock) - NUMBER_OF_ACTIVE_BLOCKS;
        }

        /* Get erase cycle of block that follow the block need checked Erase Cycle */
        temp = (ec_index + 1) % eepromConfig->numberOfBlock;
        blockConf = eepromConfig->flashBlocks[temp];

        if (ec_index == (eepromConfig->numberOfBlock - 1))
        {
            erasingCycleInternal = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET);
        }
        else
        {
            erasingCycleInternal = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET) + 1;
        }
    }
    else if (activeBlockIndex != 0xFFFFFFFF)
    {
        ec_index = (activeBlockIndex + 1) % eepromConfig->numberOfBlock;

        if (ec_index > 0)
        {
            temp = ec_index - 1;
        }
        else                    /* ec_index = 0 */
        {
            temp = eepromConfig->numberOfBlock - 1;
        }

        blockConf = eepromConfig->flashBlocks[temp];

        if (ec_index == 0)
        {
            erasingCycleInternal = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET) + 1;
        }
        else
        {
            erasingCycleInternal = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET);
        }
    }

    /* If not found any ACTIVE and COPY_START block - The first time */
    if ((copyBlockIndex == 0xFFFFFFFF) && (activeBlockIndex == 0xFFFFFFFF))
    {
        erasingCycleInternal = 1;

        /* Format all blocks */
        for (temp = 0; temp < eepromConfig->numberOfBlock; temp++)
        {
            blockConf = eepromConfig->flashBlocks[temp];
            GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

            returnCode = FSL_EraseEEBlock(c90lcRegBase, blockConf, CallBack);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;

                return (returnCode);
            }
        }

        /* Set the first block to ACTIVE */
        blockConf = eepromConfig->flashBlocks[0];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
        returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr, BLOCK_STATUS_ACTIVE, CallBack);
        if (returnCode != EE_OK)
        {
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;

            return (returnCode);
        }

        /* Write DATA_INFO to the ACTIVE block */
        returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr + DATA_INFO_OFFSET, DATA_INFO, CallBack);
        if (returnCode != EE_OK)
        {
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;

            return (returnCode);
        }

        firstInit_Flag = TRUE;

        /* Set activeBlockIndex in the eepromConfig */
        activeBlockIndex = 0;
    }
    else if (copyBlockIndex != 0xFFFFFFFF)  /* There is a COPY_START block */
    {
        if (numberOfActiveBlock == NUMBER_OF_ACTIVE_BLOCKS)
        {
            /* Update activeBlockIndex for the EEPROM config */
            eepromConfig->activeBlockIndex = activeBlockIndex;

			blockSwap_Flag = FALSE;
			
			/* Call FSL_BlockSwapping to continue the swapping */
            returnCode = FSL_BlockSwapping(eepromConfig, CallBack);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;

                return (returnCode);
            }
        }

        /* Set activeBlockIndex in the eepromConfig */
        activeBlockIndex = copyBlockIndex;
    }

    /* Check erase cycle */
    if (ec_index != 0xFFFFFFFF)
    {
        /* Set the blockConf to block that need checked Erase Cycle */
        blockConf = eepromConfig->flashBlocks[ec_index];
        /* Get the register base */
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

        /* Reset eccErrorStatus_Flag variable */
        eccErrorStatus_Flag = FALSE;
        /* Read Erase Cycle to verify ECC */
        erasingCycle = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET);

        if ((eccErrorStatus_Flag == FALSE) && (erasingCycle == PROGRAMMABLE_DEL))
        {
            size = blockConf->blockSize;
            dest = blockConf->blockStartAddr;
            returnCode = FSL_DataVerify(c90lcRegBase, TRUE, &dest, &size, (UINT32 *) & counter, &faildAddr, &faildData, CallBack);
            if (returnCode != EE_OK)
            {
                returnCode = FSL_EraseEEBlock(c90lcRegBase, blockConf, CallBack);
                if (returnCode != EE_OK)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (returnCode);
                }
            }
            else if (returnCode == EE_OK)
            {
                /* Write erase cycle into the block */
                returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, (blockConf->blockStartAddr + ERASE_CYCLE_OFFSET), erasingCycleInternal, CallBack);
                if (returnCode != EE_OK)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (returnCode);
                }
            }
        }
        else if ((eccErrorStatus_Flag == TRUE) || (erasingCycle != erasingCycleInternal))
        {
            /* Continue erase the oldest ACTIVE block */
            returnCode = FSL_EraseEEBlock(c90lcRegBase, blockConf, CallBack);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (returnCode);
            }

            /* Reset ECC flag */
            eccErrorStatus_Flag = FALSE;
        }
    }

    /* Set activeBlockIndex in the eepromConfig */
    eepromConfig->activeBlockIndex = activeBlockIndex;

    if (copyBlockIndex != 0xFFFFFFFF)
    {
        /* Set the blockConf to ACTIVE block */
        blockConf = eepromConfig->flashBlocks[activeBlockIndex];
        /* Get the register base */
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

        /* Set the COPY_START block to ACTIVE */
        returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr, BLOCK_STATUS_ACTIVE, CallBack);
        if (returnCode != EE_OK)
        {
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (returnCode);
        }
    }

    /* Get blank space of all blocks */
    for (counter = 0; counter < eepromConfig->numberOfBlock; counter++)
    {
        /* Get block configuration instant */
        blockConf = eepromConfig->flashBlocks[counter];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

        returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, 0xFFFF, &temp, CallBack);
        if (returnCode != EE_OK)
        {
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (returnCode);
        }
    }

    /* Initialize the cache table */
    if (eepromConfig->cacheEnable)
    {       
        bufferAddress = eepromConfig->cTable->tableStartAddress;
        bufferSize = eepromConfig->cTable->tableSize;

        if (activeBlockIndex >= NUMBER_OF_ACTIVE_BLOCKS)
        {
            counter = activeBlockIndex - NUMBER_OF_ACTIVE_BLOCKS;
        }
        else
        {
            counter = (activeBlockIndex + eepromConfig->numberOfBlock) - NUMBER_OF_ACTIVE_BLOCKS;
        }

        for (temp = 0; temp < NUMBER_OF_ACTIVE_BLOCKS; temp++)
        {
            counter = (counter + 1) % (eepromConfig->numberOfBlock);

            /* Set the blockConf to ACTIVE block */
            blockConf = eepromConfig->flashBlocks[counter];
            /* Get the register base */
            GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

            returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (EE_INFO_HVOP_INPROGRESS);
            }

            if (blockStatus == BLOCK_STATUS_ACTIVE)
            {
                /* Reset startID */
                startID = 0;
                /* Fill the Cache */
                returnCode = FSL_RecordBuffering(blockConf, c90lcRegBase, bufferAddress, bufferSize, &startID, CallBack);
                if (returnCode == EE_INFO_HVOP_INPROGRESS)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (EE_INFO_HVOP_INPROGRESS);
                }
            }
        }
    }

    /* Unlock the write lock */
    eepromConfig->blockWriteFlag = FALSE;

    /* If dataDeleted flag is set, reset it */
    if (TRUE == dataDeleted)
    {
        dataDeleted = FALSE;
    }

    if (firstInit_Flag == TRUE)
    {
        return (EE_FIRST_TIME_INITIALIZATION);
    }

    return (returnCode);
}

UINT32 FSL_ReadEeprom(EEPROM_CONFIG * eepromConfig, UINT16 dataID, UINT16 dataSize, UINT32 source, void (*CallBack) (void))
{
    BOOL foundFlag;             /* Data found flag */
    UINT32 size;                /* Reading size */
    UINT32 temp;                /* temporary local variable */
    UINT32 buffer;              /* reading buffer */
    UINT32 returnCode;          /* return code */
    UINT32 returnCode_temp;
    UINT32 recordAddr;          /* data record address */
    UINT32 c90lcRegBase;        /* local c90lc register base address */
    UINT32 blockIndex;          /* index variable */
    UINT32 i;
    BLOCK_STATUS blockStatus;   /* Block status */
    BLOCK_CONFIG *blockConf;    /* local block congiguration pointer */

    returnCode = EE_OK;

    /* Init the found flag */
    foundFlag = FALSE;
    /*mask of immediate bit*/
    if (dataID != 0xFFFF)
    {
        dataID &= ~(IMMEDIATE_MASK);
    }
     /* check the write lock of the FlashEE */
     if (eepromConfig->blockWriteFlag)
     {
         /* a write operation is already in progress */
         /* no write operation is permitted */
         return (EE_ERROR_WRITE_IN_PROGRESS);
     }

    /* Check if cache table is enabled */
    if (eepromConfig->cacheEnable)
    {
        /* Search the cache table first */
        returnCode = FSL_SearchInTable(eepromConfig->cTable, dataID, &recordAddr);
        if (returnCode == EE_OK)
        {
            /* Data record address is in the cache table */
            foundFlag = TRUE;
            /* Get register base */
            GET_C90LCREGBASE(eepromConfig, recordAddr, c90lcRegBase);
        }
    }

    /* Data is not found in enabled cache table or cache is disabled */
    /* Search data in block */
    if (!foundFlag)
    {
        /* Have to search the data record in the active block */
        /* Find the active block */
        blockConf = eepromConfig->flashBlocks[eepromConfig->activeBlockIndex];

        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
        /* Call FSL_SearchInBlock to find the data record to specified */
#if(VAR_LENGTH == LENGTH_TYPE)
        returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);        
#else /* FIX_LENGTH == LENGTH_TYPE */
        returnCode = FSL_SearchLatestRecordInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#endif
        if (returnCode == EE_OK)
        {
            /* Data record address is in the active cluster */
            foundFlag = TRUE;
        }

        /* If the data is not found in the current active block, search the other active blocks */
        if ((foundFlag == FALSE) && (TRUE != dataDeleted))
        {
            blockIndex = eepromConfig->activeBlockIndex;
            for (i = 0; i < (NUMBER_OF_ACTIVE_BLOCKS - 1); i++)
            {
                if (blockIndex > 0)
                {
                    blockIndex--;
                }
                else
                {
                    /* Pointer to the last block of all the block */
                    blockIndex = eepromConfig->numberOfBlock - 1;
                }

                blockConf = eepromConfig->flashBlocks[blockIndex];
                /* Specified block is in DFlash or CFlash's bank0 */
                GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
                /* Check high voltage operation */
                returnCode_temp = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
                if (returnCode_temp != EE_OK)
                {
                    return (EE_INFO_HVOP_INPROGRESS);
                }

                /* If the block status is active search for the data ID */
                if (blockStatus == BLOCK_STATUS_ACTIVE)
                {
#if(VAR_LENGTH == LENGTH_TYPE)
                    returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#else /* if(FIX_LENGTH == LENGTH_TYPE) */
					returnCode = FSL_SearchLatestRecordInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#endif
                    if (returnCode == EE_OK)
                    {
                        foundFlag = TRUE;
                        break;
                    }
                }
            }
        }

        /* Reset dataDeleted Flag */
        if (TRUE == dataDeleted)
        {
            dataDeleted = FALSE;
        }
        /* if the data record is still not found return */
        if (!foundFlag)
        {
            return (returnCode);
        }
    }


#if 1
    /* Already get the data record address and fetch it */
    /* Get the data ID and size */
#if(VAR_LENGTH == LENGTH_TYPE)
#if (DATA_FLASH_OPT != FLASH_SELECT)
    recordAddr += PAGE_SIZE;
#else
    recordAddr += WORD_SIZE;
#endif
    temp = WORD_SIZE;
    buffer = (UINT32) (&size);
    returnCode = FSL_FlashRead(c90lcRegBase, &recordAddr, &temp, &buffer, CallBack);
    if (returnCode != EE_OK)
    {
        return (returnCode);
    }

    /* Get data size */
    size = size & 0xFFFF;
    if ((UINT16) size > dataSize)
    {
        size = (UINT32) dataSize;
    }

    /* Read the Doubleword data */
#if (DATA_FLASH_OPT != FLASH_SELECT)
    /* Set dest address to the data region in first page */
    recordAddr = recordAddr - (DWORD_SIZE + WORD_SIZE);
    /* Read the data to buffer */
    /* If the data do not fit in the first page need to read two time */
    if (size > DWORD_SIZE)
    {
        /* Read data in the same page with status */
        temp = DWORD_SIZE;
        returnCode = FSL_FlashRead(c90lcRegBase, &recordAddr, &temp, &source, CallBack);
        if (returnCode != EE_OK)
        {
            return (returnCode);
        }
        size -= DWORD_SIZE;
        /* Skip the ID and Size field */
        recordAddr += WORD_SIZE;
    }
#endif
#else  /* if(FIX_LENGTH == LENGTH_TYPE) */
	recordAddr +=  PROGRAMMABLE_SIZE + DATAID_SIZE;
	size = DATA_SIZE;
	if (size > (UINT32)dataSize)
	{
		size = (UINT32)dataSize;
	}
#endif
  /* Read the remaining data ro buffer */
  returnCode = FSL_FlashRead(c90lcRegBase, &recordAddr, &size, &source, CallBack);
  if (returnCode != EE_OK)
  {
      return (returnCode);
  }
#endif

  return (EE_OK);
}

UINT32 FSL_ReportEepromStatus(EEPROM_CONFIG * eepromConfig, PROGRAMMABLE_TYPE * erasingCycles, UINT32 * blankAddress, void (*CallBack) (void))
{
    UINT32 returnCode;          /* Return code */
    UINT32 counter;             /* Loop counter */
    UINT32 number;              /* Number of the Flash blocks */
    BLOCK_STATUS blockStatus;   /* Block status */
    UINT32 c90lcRegBase;        /* local c90lc register base address */
    BLOCK_CONFIG *blockConf;    /* local block ocnfiguration pointer */
    UINT32 MCRValue;            /* content of C90LC_MCR register */

    returnCode = EE_OK;

    /* check the write lock of the FlashEE */
    if (eepromConfig->blockWriteFlag)
    {
        /* a write operation is already in progress */
        /* no write operation is permitted */
        return (EE_ERROR_WRITE_IN_PROGRESS);
    }

    /* check the block status */
    /* get the total number of Flash blocks used for emulation */
    number = eepromConfig->numberOfBlock;

    for (counter = 0; counter < number; counter++)
    {
        /* get block config */
        blockConf = eepromConfig->flashBlocks[counter];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
        returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
        if (returnCode != EE_OK)
        {
            return (EE_INFO_HVOP_INPROGRESS);
        }

        /* check the block status */
        if (!((blockStatus == BLOCK_STATUS_COPY_START) || (blockStatus == BLOCK_STATUS_ACTIVE) || (blockStatus == BLOCK_STATUS_ALTERNATIVE)))
        {
            /* error status */
            return (EE_ERROR_BLOCK_STATUS);
        }
    }

    /* get the active block */
    blockConf = eepromConfig->flashBlocks[eepromConfig->activeBlockIndex];
    /* get the erasing cycles */
    GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

    MCRValue = READ32(c90lcRegBase + C90LC_MCR);
    if (MCRValue & (C90LC_MCR_PGM | C90LC_MCR_ERS))
    {
        return (EE_INFO_HVOP_INPROGRESS);
    }

    *erasingCycles = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + ERASE_CYCLE_OFFSET);

    /* check the active block data records */
    /* go throuch the block to check the data record status with reserved data ID (0xFFFF) */
    returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, 0xFFFF, blankAddress, CallBack);
    /* if dataDeleted flag is set, reset it */
    /* this flag is only needed for a read */
    if (TRUE == dataDeleted)
    {
        dataDeleted = FALSE;
    }

    return (EE_OK);
}

UINT32 FSL_DeleteRecord(EEPROM_CONFIG * eepromConfig, UINT16 dataID, void (*CallBack) (void))
{
    BOOL searchFlag;            /* Search in block flag */
    UINT32 recordAddr;          /* record address */
    UINT32 returnCode;          /* return code */
    UINT32 returnCode_temp;
    BLOCK_CONFIG *blockConf;    /* local block configuration pointer */
    UINT32 blockIndex;          /* index variable */
    UINT8 i;
    UINT32 c90lcRegBase;
    BLOCK_STATUS blockStatus;   /* block staus */


    /* Initialize the return code */
    returnCode = EE_OK;
    searchFlag = TRUE;
    /*mask of immediate bit*/
    if (dataID != 0xFFFF)
    {
        dataID &= ~(IMMEDIATE_MASK);
    }
    /* check the write lock of the FlashEE */
    if (eepromConfig->blockWriteFlag)
    {
        /* a write operation is already in progress */
        /* no write operation is permitted */
        return (EE_ERROR_WRITE_IN_PROGRESS);
    }
    else
    {
        /* set the write lock flag */
        eepromConfig->blockWriteFlag = TRUE;
    }

    /* Try to delete the data in cache table firstly */
    if (eepromConfig->cacheEnable)
    {
        /* Find it in cache table */
        returnCode = FSL_SearchInTable(eepromConfig->cTable, dataID, &recordAddr);
        if (returnCode == EE_OK)
        {
            /* Data location can fetch from cache */
            /* Need not search in block */
            searchFlag = FALSE;
            /* Update the data location in cache */
            FSL_UpdateCacheTable(eepromConfig->cTable, dataID, 0xFFFFFFFF);
        }
    }

    if (searchFlag == TRUE)
    {
        /* Have to search the data record in the active block */
        /* Find the active block */
        blockConf = eepromConfig->flashBlocks[eepromConfig->activeBlockIndex];

        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
#if(VAR_LENGTH == LENGTH_TYPE)
        returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#else /* if(FIX_LENGTH == LENGTH_TYPE) */
		returnCode = FSL_SearchLatestRecordInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#endif
        if (returnCode == EE_OK)
        {
            /* Found in the active block */
            searchFlag = FALSE;
        }
		if ((searchFlag == TRUE) && (TRUE != dataDeleted))
        {
            blockIndex = eepromConfig->activeBlockIndex;
            for (i = 0; i < (NUMBER_OF_ACTIVE_BLOCKS - 1); i++)
            {
                if (blockIndex > 0)
                {
                    blockIndex--;
                }
                else
                {
                    /* Pointer to the last block of all the block */
                    blockIndex = eepromConfig->numberOfBlock - 1;
                }
                blockConf = eepromConfig->flashBlocks[blockIndex];

                GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

                /* Check high voltage operation */
                returnCode_temp = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
                if (returnCode_temp != EE_OK)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (EE_INFO_HVOP_INPROGRESS);
                }

                /* If the block status is active search for the data ID */
                if (blockStatus == BLOCK_STATUS_ACTIVE)
                {
#if(VAR_LENGTH == LENGTH_TYPE)
					returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#else	/* if(FIX_LENGTH == LENGTH_TYPE) */
					returnCode = FSL_SearchLatestRecordInBlock(blockConf, c90lcRegBase, dataID, &recordAddr, CallBack);
#endif
                    if (returnCode == EE_OK)
                    {
                        searchFlag = FALSE;
                        break;
                    }                   
                }
            }
        }
		/* Reset dataDeleted Flag */
        if (TRUE == dataDeleted)
        {
            dataDeleted = FALSE;
        }
        /* if the data record is still not found return */
        if (searchFlag)
        {
			/* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (returnCode);
        }		
    }

    if (0xFFFFFFFF == recordAddr)
    {
        eepromConfig->blockWriteFlag = FALSE;
        return (EE_ERROR_DATA_NOT_FOUND);
    }

    /* Get register base */
    GET_C90LCREGBASE(eepromConfig, recordAddr, c90lcRegBase);
    /* update the record status to DELETED */
    returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, recordAddr, RECORD_STATUS_DELETE, CallBack);
    if (returnCode != EE_OK)
    {
        /* unlock the write lock */
        eepromConfig->blockWriteFlag = FALSE;
        return (returnCode);
    }

    /* release the write lock */
    eepromConfig->blockWriteFlag = FALSE;
    /* if dataDeleted flag is set, reset it */
    /* this flag is only needed for a read */
    if (TRUE == dataDeleted)
    {
        dataDeleted = FALSE;
    }

    return (returnCode);
}

UINT32 FSL_RemoveEeprom(EEPROM_CONFIG * eepromConfig, void (*CallBack) (void))
{
    UINT32 counter;             /* Loop counter */
    UINT32 returnCode;          /* Return code */
    UINT32 ebHigh;              /* enabled blocks for high space flash block */
    UINT32 ebMiddle;            /* enabled blocks for middle space flash block */
    UINT32 ebLow_bk0;           /* enabled blocks for low space flash bank 0 or DFlash */
    UINT32 dest;                /* blank checking destination address */
    UINT32 size;                /* blank checking size */
    UINT32 source;              /* dummy variable */
    UINT32 temp;                /* local temporary variable */
    UINT32 failedAddr;          /* failed address */
    UINT32 c90lcRegBase;        /* local c90lc register base address */
    UINT32 tempInterlock_bk0;   /* Interlockwrite address point to flash bank 0 */
    BLOCK_STATUS failedData;    /* failed data */
#if (BANK_NUMBER > 1)
    UINT32 tempInterlock_bk1;   /* Interlockwrite address point to flash bank 1 */
    UINT32 ebLow_bk1;           /* enabled blocks for low space flash bank 1 */
#endif
    UINT8 bankErased_Flag;       /* flag to indicate which flash bank erase is done */
    BLOCK_CONFIG *blockConf;    /* local block configuration pointer */

    /* check the write lock of the FlashEE */
    if (eepromConfig->blockWriteFlag)
    {
        /* a write operation is already in progress */
        /* no write operation is permitted */
        return (EE_ERROR_WRITE_IN_PROGRESS);
    }
    else
    {
        /* set the write lock flag */
        eepromConfig->blockWriteFlag = TRUE;
    }

    /* Initialize enabled block */
    ebLow_bk0 = ebMiddle = ebHigh = 0;
#if (BANK_NUMBER > 1)
    ebLow_bk1 = 0;
#endif

    /* Chose the blocks for eeprom emulation */
    for (counter = 0; counter < eepromConfig->numberOfBlock; counter++)
    {
        /* Get block configuration */
        blockConf = eepromConfig->flashBlocks[counter];
        /* Check the address space */
        switch (blockConf->blockSpace)
        {
        case LOW_ADDRESS_SPACE:
            {
#if (BANK_NUMBER > 1)
                if ((START_LAS_BANK1 <= blockConf->blockStartAddr) && (END_LAS_BANK1 > blockConf->blockStartAddr))
                {
                    ebLow_bk1 |= blockConf->enabledBlock;
                    tempInterlock_bk1 = blockConf->blockStartAddr;
                    break;
                }
#endif
                ebLow_bk0 |= blockConf->enabledBlock;
                tempInterlock_bk0 = blockConf->blockStartAddr;
                break;
            }
        case MID_ADDRESS_SPACE:
            ebMiddle |= blockConf->enabledBlock;
            break;
        case HIGH_ADDRESS_SPACE:
            ebHigh |= blockConf->enabledBlock;
            break;
        default:
            /* unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (EE_ERROR_BLOCK_CONFIG);
        }
    }

    /* Erase the selected blocks */
    bankErased_Flag = 0;
    if ((ebLow_bk0) || (ebMiddle) || (ebHigh))
    {
        c90lcRegBase = eepromConfig->c90lcRegBase;
        /* erse bank 0 or DFlash */
        returnCode = FSL_FlashEraseStart(c90lcRegBase, tempInterlock_bk0, ebLow_bk0, ebMiddle, ebHigh);
        if (returnCode != EE_OK)
        {
            /* Unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (returnCode);
        }
        bankErased_Flag |= 0x01;
    }

#if (BANK_NUMBER > 1)
    if ((ebLow_bk1) || (ebMiddle) || (ebHigh))
    {
        c90lcRegBase = eepromConfig->c90lcRegBase + REGBASE_OFFSET_BANK1;
        /* Erase blank 1 */
        ebLow_bk1 >>= 8;
        returnCode = FSL_FlashEraseStart(c90lcRegBase, tempInterlock_bk1, ebLow_bk1, ebMiddle, ebHigh);
        if (returnCode != EE_OK)
        {
            /* Unlock the write lock */
            eepromConfig->blockWriteFlag = FALSE;
            return (returnCode);
        }
        bankErased_Flag |= 0x02;
    }

#endif
    /* Check status and end operation */
    while (1)
    {
        /* bank erase done? */
        if (!bankErased_Flag)
        {
            break;
        }
        if (NULL_CALLBACK != CallBack)
        {
            CallBack();
        }
        /* Bank 0 or DFlash is erasing => check its status */
        if (0x01 == (bankErased_Flag & 0x01))
        {
            returnCode = FSL_FlashCheckStatus(eepromConfig->c90lcRegBase);
            if (returnCode == EE_OK)
            {
                bankErased_Flag &= ~0x01;
            }
            else if (returnCode == EE_ERROR_PE_OPT)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (returnCode);
            }
        }
#if (BANK_NUMBER > 1)
        /* Bank 1 is erasing => check its status */
        if (0x02 == (bankErased_Flag & 0x02))
        {
            returnCode = FSL_FlashCheckStatus(eepromConfig->c90lcRegBase + REGBASE_OFFSET_BANK1);
            if (returnCode == EE_OK)
            {
                bankErased_Flag &= ~0x02;
            }
            else if (returnCode == EE_ERROR_PE_OPT)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (returnCode);
            }
        }
#endif
    }
    /* bank check */
    for (counter = 0; counter < eepromConfig->numberOfBlock; counter++)
    {
        /* Get the block configuration */
        blockConf = eepromConfig->flashBlocks[counter];
        c90lcRegBase = eepromConfig->c90lcRegBase;
        /* Get dest and size */
        dest = blockConf->blockStartAddr;
        size = blockConf->blockSize;
        /* Calculate the end address */
        temp = dest + size;
#if (BANK_NUMBER > 1)
        if ((START_LAS_BANK1 < dest) && (END_LAS_BANK1 > dest))
        {
            c90lcRegBase = eepromConfig->c90lcRegBase + REGBASE_OFFSET_BANK1;
        }
#endif
        while (dest < temp)
        {
            returnCode = FSL_DataVerify(c90lcRegBase, TRUE, &dest, &size, &source, &failedAddr, &failedData, CallBack);
            if (returnCode != EE_OK)
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (EE_ERROR_PE_OPT);
            }
        }
    }
    /* unlock the write lock */
    eepromConfig->blockWriteFlag = FALSE;
    return (returnCode);
}

UINT32 FSL_WriteEeprom(EEPROM_CONFIG * eepromConfig, UINT16 dataID, UINT16 dataSize, UINT32 source, void (*CallBack) (void))
{
    UINT32 recordAddr;          /* Variable to store record address */
    UINT32 temp;                /* Temporary variable */
    UINT32 returnCode;          /* return code */
    UINT8 swapFlag;             /* flag to keep track of swap */
    UINT32 counter;             /* counter variable */
    BLOCK_CONFIG *blockConf;    /* blockConf configuration */
    UINT8 i;                    /* index variable */
    UINT8 activeCount;          /* variable to keep active block count */
    UINT32 c90lcRegBase;
    BLOCK_STATUS blockStatus;   /* block status */
    BOOL eraseAbort_Flag;

    /* Initialize local variables */
    returnCode = EE_OK;
    eraseAbort_Flag = FALSE;
    swapFlag = FALSE;
    activeCount = 0;

#if(FIX_LENGTH == LENGTH_TYPE)
	dataSize = DATA_SIZE;
#endif
    /* Check the write lock */
    if (eepromConfig->blockWriteFlag)
    {
        /* a write operation is already in progress, no write operation is permitted */
        return (EE_ERROR_WRITE_IN_PROGRESS);
    }
    else
    {
        /* set the write lock flag */
        eepromConfig->blockWriteFlag = TRUE;
    }

    /* Check whether there is enough blank space for data record */
    /* Get the data length including status, ID, size and data field */	
		if (dataSize <= HEAD_DATA_SIZE)
    {
        temp = RECORD_HEAD_SIZE;
    }
    else
    {
        /* Calculate recordLength */
        if ((dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
            temp = RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize - HEAD_DATA_SIZE) / ECC_SIZE + 1);
        else
            temp = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + dataSize;
    }
    /* Set blockConf to current ACTIVE block */
    blockConf = eepromConfig->flashBlocks[eepromConfig->activeBlockIndex];
    GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

    do
    {
        /* Compare against the avaible space in current active block */
        if ((blockConf->blockStartAddr + blockConf->blockSize - blockConf->blankSpace) < temp)
        {
            /* Get the number of ACTIVE block */
            for (i = 0; i < eepromConfig->numberOfBlock; i++)
            {
                /* Get the next block detail */
                blockConf = eepromConfig->flashBlocks[i];
                GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
                returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
                if (returnCode != EE_OK)    /* returnCode = EE_INFO_HVOP_INPROGRESS */
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    /* There is being a Swapping, so return no enough space */
                    return (EE_ERROR_NO_ENOUGH_SPACE);
                }
                if (BLOCK_STATUS_ACTIVE == blockStatus)
                {
                    /* increment activeCount */
                    activeCount++;
                }
                else if (BLOCK_STATUS_COPY_START == blockStatus)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    /* The Swapping and erasing the oldest ACTIVE block completed, but the oldest ACTIVE block has not been writen Erase Cycle and the COPY_START block has not been make to ACTIVE */
                    return (EE_ERROR_NO_ENOUGH_SPACE);
                }
            }

            /* There is extra AlTERNATIVE which can be made ACTIVE, No swap required */
            if (activeCount < NUMBER_OF_ACTIVE_BLOCKS)
            {
                /* Check blankspace for all possible active blocks*/
								/*Will stop checking if found a block having enough space to write or return EE_ERROR_NO_ENOUGH_SPACE */				
								while(activeCount < NUMBER_OF_ACTIVE_BLOCKS)
                {
                    counter = (eepromConfig->activeBlockIndex + 1) % (eepromConfig->numberOfBlock);

                    /* Program the next block to ACTIVE */
                    blockConf = eepromConfig->flashBlocks[counter];
                    GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
                    returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr, BLOCK_STATUS_ACTIVE, CallBack);
                    if (returnCode != EE_OK)
                    {
                        /* unlock the write lock */
                        eepromConfig->blockWriteFlag = FALSE;
                        return (returnCode);
                    }

                    /* Write DATA_INFO to the ACTIVE block */
                    returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr + DATA_INFO_OFFSET, DATA_INFO, CallBack);
                    if (returnCode != EE_OK)
                    {
                        /* unlock the write lock */
                        eepromConfig->blockWriteFlag = FALSE;
                        return (returnCode);
                    }
                    /* Set the next active block in block configuration */
                    eepromConfig->activeBlockIndex = counter;
                    activeCount ++;
                    /* Update blank Space */
                    blockConf->blankSpace = blockConf->blockStartAddr + RECORD_OFFSET;
                    if ((blockConf->blockStartAddr + blockConf->blockSize - blockConf->blankSpace) < temp)
                    {
                        if (NUMBER_OF_ACTIVE_BLOCKS == activeCount)
                        {
                            /* unlock the write lock */
                            eepromConfig->blockWriteFlag = FALSE;
                            /*scan all possible active blocks and no block found*/
                            return (EE_ERROR_NO_ENOUGH_SPACE);
                        }
                    }
                    else
                    {
                        /* if found a block having enough space to write, exit the loop */
                        break;
                    }
                }
            }
            else
            {
                /* No enough space for data record, Perform block swapping */
                swapFlag = TRUE;
                sourceInternalSwap = source;
                dataIDInternalSwap = dataID;
                dataSizeInternalSwap = dataSize;
                tempInternalSwap = temp;
                blockSwap_Flag = TRUE;
                returnCode = FSL_BlockSwapping(eepromConfig, CallBack);
                blockSwap_Flag = FALSE;
                if (returnCode != EE_OK)
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (returnCode);
                }
            }
        }

        if (swapFlag == FALSE)
        {
            /* Have enough space for this record */
            /* source data is buffer RAM */
            writeInternal_Flag = TRUE;
            /* Set blockConf to current ACTIVE block */
            blockConf = eepromConfig->flashBlocks[eepromConfig->activeBlockIndex];
            /* Save current blank pointer */
            recordAddr = blockConf->blankSpace;

            GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
            
            /* Copy one data record to free space in the active block */
            returnCode = FSL_CopyDataRecord(blockConf, c90lcRegBase, dataID, dataSize, source, recordAddr, CallBack);
            if (returnCode == EE_OK)
            {
                /* Check if the cache table is enabled */
                if (eepromConfig->cacheEnable)
                {
                    /*mask of immediate bit*/
                    dataID &= ~(IMMEDIATE_MASK);
                    /* Check if it is need to upadte the cache table */
                    FSL_UpdateCacheTable(eepromConfig->cTable, dataID, recordAddr);
                }
                /* Update the blank pointer first (add the data size) */
                blockConf->blankSpace += temp;
            }
            else if (returnCode == EE_ERROR_PE_OPT)
            {
                /* Re-write the record into a different position */
            }
            else if (returnCode == EE_INFO_HVOP_INPROGRESS)
            {
                /* Check the ID immediate */
                if (dataID & IMMEDIATE_MASK)
                {
                    eraseAbort_Flag = FSL_AbortHVOP(c90lcRegBaseInternal);
                    if (eraseAbort_Flag == FALSE)
                    {
                    	/* unlock the write lock */
                    	eepromConfig->blockWriteFlag = FALSE;
                    	return (returnCode);	
                    }
                }
                else
                {
                    /* unlock the write lock */
                    eepromConfig->blockWriteFlag = FALSE;
                    return (returnCode);
                }
            } 
            else	/* returnCode = EE_ERROR_MISMATCH */
            {
            	/* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (returnCode);
            }
        }
    }
    while ((returnCode == EE_ERROR_PE_OPT) || ((eraseAbort_Flag == TRUE) && (returnCode == EE_INFO_HVOP_INPROGRESS)));  /* End of do-while loop */

    /* Check erase abort flag */
    if (eraseAbort_Flag == TRUE)
    {
        /* set blockSwap_Flag to avoid update erase cycle */
        blockSwap_Flag = TRUE;
        /* Resume erase the aborted block erasing */
        FSL_EraseEEBlock(c90lcRegBaseInternal, blockConfInternal, CallBack);
        /* Reset blockSwap_Flag */
        blockSwap_Flag = FALSE;
    }

    /* unlock the write lock */
    eepromConfig->blockWriteFlag = FALSE;

    /* if dataDeleted flag is set, reset it */
    /* this flag is only needed for a read */
    if (TRUE == dataDeleted)
    {
        dataDeleted = FALSE;
    }
    return (returnCode);
}

void FSL_MainFunction(EEPROM_CONFIG * eepromConfig, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return Code */
    UINT32 faildAddr;           /* local variable used in data verify */
    UINT32 dest;                /* blank checking destination address */
    UINT32 size;                /* blank checking size */
    UINT32 counter;
    UINT32 c90lcRegBase;
    PROGRAMMABLE_TYPE faildData;    /* failed data */
    BLOCK_CONFIG *blockConf;
    static UINT32 erase_num = MAX_REERASE;

    returnCode = EE_OK;
    counter = 0;
    /* Check status and end operation */
    if (ERASE_INPROGRESS == eraseStatus_Flag)
    {
        returnCode = FSL_FlashCheckStatus(c90lcRegBaseInternal);
        if (returnCode == EE_OK)
        {
            eraseStatus_Flag = ERASE_DONE;
        }
        else if (returnCode == EE_ERROR_PE_OPT)
        {
            eraseStatus_Flag = ERASE_FAIL;
        }
        else
        {
            eraseStatus_Flag = ERASE_INPROGRESS;
        }

        if ((ERASE_DONE == eraseStatus_Flag) || (eraseStatus_Flag == ERASE_FAIL))
        {
            /* Blank check and update block status */
            dest = blockConfInternal->blockStartAddr;
            size = blockConfInternal->blockSize;
            while (size)
            {
                /* Perform blank check */
                /* use counter as a temp variable for source data */
                returnCode = FSL_DataVerify(c90lcRegBaseInternal, TRUE, &dest, &size, (UINT32 *) & counter, &faildAddr, &faildData, CallBack);
                if (returnCode != EE_OK)
                {
                    /* error during data verify */
                    eraseStatus_Flag = ERASE_INPROGRESS;

                    if (erase_num > 0)
                    {
                        /* set blockSwap_Flag to avoid update erase cycle */
                        blockSwap_Flag = TRUE;
                        /* Erase the block again */
                        FSL_EraseEEBlock(c90lcRegBaseInternal, blockConfInternal, CallBack);
                        /* Reset blockSwap_Flag */
                        blockSwap_Flag = FALSE;
                        erase_num--;
                    }
                    else
                    {
                        eraseStatus_Flag = ERASE_SWAPERROR;
                    }
                    break;
                }
                else
                {
                    erase_num = MAX_REERASE;
                    break;
                }
            }

            if (ERASE_DONE == eraseStatus_Flag)
            {
                /* Program the increased erasing cycle back */
                returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBaseInternal, blockConfInternal->blockStartAddr + ERASE_CYCLE_OFFSET, erasingCycleInternal, CallBack);
                if (returnCode != EE_OK)
                {
                    /* error during programming erase cycles */
                    eraseStatus_Flag = ERASE_SWAPERROR;
                }

                if (eraseStatus_Flag != ERASE_SWAPERROR)
                {
                    /* Reset flag */
                    eraseStatus_Flag = ERASE_NOTSTARTED;
                    /* Set blank space pointer */
                    blockConfInternal->blankSpace = blockConfInternal->blockStartAddr + RECORD_OFFSET;
                }

                /* Set the COPY_START block to ACTIVE block */
                counter = eepromConfig->activeBlockIndex;
                blockConf = eepromConfig->flashBlocks[counter];
                GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
                returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr, BLOCK_STATUS_ACTIVE, CallBack);
                if (returnCode != EE_OK)
                {
                    /* error during programming block status */
                    eraseStatus_Flag = ERASE_SWAPERROR;
                }
            }
        }
    }

    /* if dataDeleted flag is set, reset it */
    /* this flag is only needed for a read */
    if (TRUE == dataDeleted)
    {
        dataDeleted = FALSE;
    }
}
