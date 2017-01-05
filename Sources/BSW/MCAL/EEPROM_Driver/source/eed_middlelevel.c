/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,Inc 2012   *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : eed_middlelevel.c                                     *
* DESCRIPTION   : This file consitutes of middle level API's which      *
*                 will be called by high level API's to perform         *
*                 desired tasks.                                        *
* DATE          : Jan 19, 2012                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
0.0.1      	08.04.2010      FPT Team        Initial Version
0.1.0      	09.23.2010      FPT Team        Update comments
0.2.0      	09.30.2010      FPT Team        Update FSL_SearchActiveBlock funtion
                                            to fix bug: "DON'T check eeErrorStatus_Flag
                                            after calling FSL_FlashReadStatus for
                                            block with ECC error in it's status"
0.3.0      	01.19.2011      FPT Team        Remove FSL_SearchActiveBlock, FSL_InitEEBlock,
                                            FSL_CheckFreeSpace functions,
                                            Add	FSL_EraseEEBlock function and 
                                            Update other functions according
                                            to the simplified algorithm.
0.1.1      	05.20.2011      FPT Team        Support fixed-length
                                            data record.
0.1.2       08.05.2011     	FPT Team        Mask off immediate bit in dataID to ignore MSB bit 
                                            when read, delete and update cache table.  
0.1.3       10.05.2011     	FPT Team        Fix bug regarding to re-erase operation handling in 
                                            FSL_EraseEEBlock().        
0.1.4		11.11.2011	   	FPT Team		Update checking the CallBack pointer to function is NULL or not.
0.1.5		12.13.2011	   	FPT Team	    Update FSL_CopyDataRecord function at the condition to update blank space
                                            when DFO is selected.
0.1.6       01.19.2012     	FPT Team        Corrected the number of re-erase,
                                            Updated FSL_BlockSwapping function
                                            to speed up swapping
0.1.7		02.07.2012	   	FPT Team		Fix bug in swapping function.											
0.1.8		11.19.2012		FPT Team		Fix bug in FSL_BlockSwapping to update data record in Cache table
											after brownout when swapping occurs.
*************************************************************************/

#include "ee_types.h"
#include "ee_emulation.h"

UINT32 FSL_BlockSwapping(EEPROM_CONFIG * eepromConfig, void (*CallBack) (void))
{
    BLOCK_STATUS blockStatus;   /* block status */
    UINT32 counter;             /* the loop counter */
    UINT32 alternativeBlock;    /* the alternative block index */
    UINT32 sourceBlockIndex;
    UINT16 dataID;
    UINT16 dataID_temp;
    UINT16 dataSize;
    UINT32 i,j;
    UINT32 recordAddress;
    UINT32 recordAddress_temp;
    UINT32 recordSize;
    UINT32 temp;
    DATA_RECORD_HEAD recordHead;
    BLOCK_CONFIG *tempActiveBlock[NUMBER_OF_ACTIVE_BLOCKS + 1]; /* Array of ACTIVE and COPY_START blocks */
    BLOCK_CONFIG *blockConf;
    BLOCK_CONFIG *sourceBlock;  /* the source (active) block configuration pointer */
    BLOCK_CONFIG *destBlock;    /* the destination (alternative) block configuration pointer */
    UINT32 c90lcRegBase;
    UINT32 returnCode;
    BOOL found_Flag;
	UINT16 numItemInCache; /* number of ID can be stored in cache */

    /* Initialize the returnCode */
    returnCode = EE_OK;
    
    /* Initialize the tempActiveBlock array */
    for (i = 0; i < NUMBER_OF_ACTIVE_BLOCKS; i++)
    {
        tempActiveBlock[i] = 0;
    }

    /* Find the index of ALTERNATIVE block */
    counter = eepromConfig->activeBlockIndex;
    alternativeBlock = (counter + 1) % (eepromConfig->numberOfBlock);

    /* Find the oldest ACTIVE block */
    counter = alternativeBlock;
    do
    {
        counter = (counter + 1) % (eepromConfig->numberOfBlock);
        /* get the block offset */
        blockConf = eepromConfig->flashBlocks[counter];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
        returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
        if (returnCode != EE_OK)
        {
            return (EE_INFO_HVOP_INPROGRESS);
        }
    }
    while ((BLOCK_STATUS_ALTERNATIVE == blockStatus) || (BLOCK_STATUS_COPY_START == blockStatus));

    /* assign source and dest blocks */
    sourceBlockIndex = counter;
    sourceBlock = eepromConfig->flashBlocks[sourceBlockIndex];
    destBlock = eepromConfig->flashBlocks[alternativeBlock];

    /* store the block configuration of all the active blocks in local array */
    i = 0;
    do
    {
        /* store active blocks configuration in temp buffer based on age */
        tempActiveBlock[i] = eepromConfig->flashBlocks[counter];
        counter = (counter + 1) % (eepromConfig->numberOfBlock);
        /* get the block offset */
        blockConf = eepromConfig->flashBlocks[counter];
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
        returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
        if (returnCode != EE_OK)
        {
            return (EE_INFO_HVOP_INPROGRESS);
        }
        i++;
    }
    while (BLOCK_STATUS_ACTIVE == blockStatus);

    /* Check the dest block is ALTERNATIVE or not */
    blockConf = destBlock;
    GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);
    returnCode = FSL_FlashReadStatus(blockConf, c90lcRegBase, &blockStatus);
    if (returnCode != EE_OK)
    {
        return (EE_INFO_HVOP_INPROGRESS);
    }

    if (BLOCK_STATUS_ALTERNATIVE == blockStatus)
    {
        /* Set the block to COPY_START */
        returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr, BLOCK_STATUS_COPY_START, CallBack);
        if (returnCode != EE_OK)
        {
            return (returnCode);
        }

        /* Write DATA_INFO */
        returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr + DATA_INFO_OFFSET, DATA_INFO, CallBack);
        if (returnCode != EE_OK)
        {
            return (returnCode);
        }
    }
    else if (BLOCK_STATUS_COPY_START == blockStatus)
    {
        /* Do Nothing */
    }
    else
    {
        return (EE_ERROR_BLOCK_STATUS);
    }

    /* Find the blank space by search a dataID = 0xFFFF */
    returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, 0xFFFF, &temp, CallBack);
    if (returnCode != EE_OK)
    {
        return (returnCode);
    }

    /* Add destBlock into the tempActiveBlock array */
    tempActiveBlock[i] = destBlock;

    /* Check if there is internal data */
    if (blockSwap_Flag == TRUE)
    {
        do
        {
            /* Check the free space */
            if (tempInternalSwap > (destBlock->blockStartAddr + destBlock->blockSize - destBlock->blankSpace))
            {
                return (EE_ERROR_NO_ENOUGH_SPACE);
            }

            returnCode = FSL_CopyDataRecord(blockConf, c90lcRegBase, dataIDInternalSwap, dataSizeInternalSwap, sourceInternalSwap, destBlock->blankSpace, CallBack);
            if (returnCode == EE_OK)
            {
                /* check if the cache table is enabled */
                if (eepromConfig->cacheEnable)
                {
                    /* check if it is needed to update the cache table */
                    /*mask of immediate bit before update cache*/
                    dataIDInternalSwap &= ~(IMMEDIATE_MASK);
                    FSL_UpdateCacheTable(eepromConfig->cTable, dataIDInternalSwap, destBlock->blankSpace);
                }

                /* update the blank pointer first (add the data size) */
                destBlock->blankSpace += tempInternalSwap;
            }
            else if (returnCode == EE_ERROR_PE_OPT)
            {
                /* Re-write the record into a different position */
            }
            else
            {
                /* unlock the write lock */
                eepromConfig->blockWriteFlag = FALSE;
                return (returnCode);
            }
        }
        while (returnCode == EE_ERROR_PE_OPT);
    }

    /* Reuse "counter" variable to calculate number of id in Swap Cache */
    counter = swap_Cache.size / CTABLE_ITEM_SIZE;
    
    /* Calculate number of id in Cache */
    if (eepromConfig->cacheEnable)
        numItemInCache = (UINT16)(eepromConfig->cTable->tableSize / CTABLE_ITEM_SIZE);
    else 
        numItemInCache = 0;

    /* start copy data from source to dest */
    for (dataID = 0; dataID < 0x8000;)
    {
        /* Determine blockConf as source block */
        blockConf = sourceBlock;
        GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

        /* If cache is enabled, Search in the cache first */
        if ((numItemInCache != 0) && (blockSwap_Flag == TRUE))
        {
            /* Check all IDs in the Cache */
            for (i = 0; i < numItemInCache; i++)
            {
                /* read record address from cache and check if this record ID belongs to oldest active block */
				/* it means this record ID is not in current active block or not be internal data as well */
				/* So, this record ID should be copied to ALTERNATIVE block */
				recordAddress = READ32(eepromConfig->cTable->tableStartAddress + i*CTABLE_ITEM_SIZE);
                if ((blockConf->blockStartAddr <= recordAddress) && 
				   ((blockConf->blockStartAddr + blockConf->blockSize) > recordAddress))
                {
                    /* Read record data and determine record size */
                    FSL_ReadRecordHead(recordAddress, &recordHead);
                    dataSize = recordHead.dataSize;
                    
                    if (dataSize <= HEAD_DATA_SIZE)
                    {
                        recordSize = RECORD_HEAD_SIZE;
                    }
                    else
                    {
                        /* Calculate recordSize */
                        if ((dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                            recordSize = RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize - HEAD_DATA_SIZE) / ECC_SIZE + 1);
                        else
                            recordSize = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + dataSize;
                    }

                    /* start copying. If this action fails, it will re-write this record until sucessfully */
					do
                    {
                        /* Check the free space */
                        if (recordSize > (destBlock->blockStartAddr + destBlock->blockSize - destBlock->blankSpace))
                        {
                            return (EE_ERROR_NO_ENOUGH_SPACE);
                        }

                        /* Source data in buffer FLASH */
                        writeInternal_Flag = FALSE;
                        GET_C90LCREGBASE(eepromConfig, destBlock->blockStartAddr, c90lcRegBase);
                        #if(FIX_LENGTH == LENGTH_TYPE)
                        recordAddress += PROGRAMMABLE_SIZE + DATAID_SIZE;
                        #else
                        recordAddress += DWORD_SIZE;
                        #endif
                        returnCode = FSL_CopyDataRecord(destBlock, c90lcRegBase, i, dataSize, recordAddress, destBlock->blankSpace, CallBack);
                        if (returnCode == EE_OK)
                        {
                            /* check if the cache table is enabled */
                            if (eepromConfig->cacheEnable)
                            {
                                /* check if it is needed to update the cache table */
                                FSL_UpdateCacheTable(eepromConfig->cTable, i, destBlock->blankSpace);
                            }

                            /* Update Blank space for the dest block */
                            destBlock->blankSpace += recordSize;
                        }
                        else if (returnCode == EE_ERROR_PE_OPT)
                        {
                            /* Re-write the record into a different position */
                        }
                        else
                        {
                            /* unlock the write lock */
                            eepromConfig->blockWriteFlag = FALSE;
                            return (returnCode);
                        }
                    }
                    while (returnCode == EE_ERROR_PE_OPT);
                }
            }
            /* finish copying from cache. Need to determine start dataID to be buffering in swap cache */
			/* So, swap cache will include the record ID which were not in cache */
            dataID = numItemInCache;
			/* Reset numItemInCache to avoid searching in cache loop from the second time */
            numItemInCache = 0;
        }

        /* Initialize swap cache */
        for (i = 0; i < counter; i++)
        {
            WRITE32((swap_Cache.startAddress + i*CTABLE_ITEM_SIZE), 0xFFFFFFFF);
        }
        /* backup dataID to be searched in swap cache before being updated in FSL_RecordBuffering() function */
        dataID_temp = dataID;
        
        /* Fill all record ID which were not in cache but in old active block to swap_Cache */
		/* The number of ID stored in swap_Cache will depend on size of this swap_Cache */
        returnCode = FSL_RecordBuffering(blockConf, 
                                         c90lcRegBase, 
                                         swap_Cache.startAddress, 
                                         swap_Cache.size, 
                                         &dataID, 
                                         CallBack);
                                         
        if (returnCode != EE_OK)    /* High Voltage in progress */
        {
            return (returnCode);
        }
        else
        {
            /* Check all IDs in Swap Cache */
            for (i = 0; i < counter; i++)
            {
                /* record ID must be increased by one for each scan to be searched all IDs in swap cache from top to bottom */
				/* Note that: do not increase record ID at the first time */
				if (i != 0)
				{
					dataID_temp += 1;
				}
				recordAddress = READ32(swap_Cache.startAddress + i*CTABLE_ITEM_SIZE);
                /* if record ID is in swap cache, need to check if it is in tempActiveBlock blocks as well.*/
				/* if no, this record should be copied to new block */
				if (recordAddress != 0xFFFFFFFF)
                {   
                    found_Flag = FALSE;
					/* Search the dataID in the tempActiveBlock array */
					for (j = 1; j < (NUMBER_OF_ACTIVE_BLOCKS + 1); j++)
					{
						blockConf = tempActiveBlock[j];
						GET_C90LCREGBASE(eepromConfig, blockConf->blockStartAddr, c90lcRegBase);

						returnCode = FSL_SearchInBlock(blockConf, c90lcRegBase, dataID_temp, &recordAddress_temp, CallBack);
						if (returnCode == EE_OK)    /* If found the dataID in the block */
						{
							found_Flag = TRUE;
							break;
						}
						else if (returnCode == EE_ERROR_DATA_NOT_FOUND)
						{
							/* If not found the dataID in the block, continue search the next block */
							continue;
						}
						else    /* High Voltage in progress */
						{
							return (returnCode);
						}
					}

                    /* If found the dataID in the block, continue search the next dataID */
                    if (found_Flag == TRUE)
                    {
                        continue;
                    }

                    /* If not found the dataID in the array, write the record into the dest block */
                    /* Read record head of the founded record */
                    FSL_ReadRecordHead(recordAddress, &recordHead);
                    dataSize = recordHead.dataSize;
                    
                    if (dataSize <= HEAD_DATA_SIZE)
                    {
                        recordSize = RECORD_HEAD_SIZE;
                    }
                    else
                    {
                        /* Calculate recordSize */
                        if ((dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                            recordSize = RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize - HEAD_DATA_SIZE) / ECC_SIZE + 1);
                        else
                            recordSize = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + dataSize;
                    }

                    do
                    {
                        /* Check the free space */
                        if (recordSize > (destBlock->blockStartAddr + destBlock->blockSize - destBlock->blankSpace))
                        {
                            return (EE_ERROR_NO_ENOUGH_SPACE);
                        }

                        /* Source data in buffer FLASH */
                        writeInternal_Flag = FALSE;
                        GET_C90LCREGBASE(eepromConfig, destBlock->blockStartAddr, c90lcRegBase);
                        #if(FIX_LENGTH == LENGTH_TYPE)
                        recordAddress += PROGRAMMABLE_SIZE + DATAID_SIZE;
                        #else
                        recordAddress += DWORD_SIZE;
                        #endif
                        returnCode = FSL_CopyDataRecord(destBlock, c90lcRegBase, dataID_temp, dataSize, recordAddress, destBlock->blankSpace, CallBack);
                        if (returnCode == EE_OK)
                        {
                            /* check if the cache table is enabled */
                            if (eepromConfig->cacheEnable)
                            {
                                /* check if it is needed to update the cache table */
                                FSL_UpdateCacheTable(eepromConfig->cTable, dataID_temp, destBlock->blankSpace);
                            }

                            /* Update Blank space for the dest block */
                            destBlock->blankSpace += recordSize;
                        }
                        else if (returnCode == EE_ERROR_PE_OPT)
                        {
                            /* Re-write the record into a different position */
                        }
                        else
                        {
                            /* unlock the write lock */
                            eepromConfig->blockWriteFlag = FALSE;
                            return (returnCode);
                        }
                    }
                    while (returnCode == EE_ERROR_PE_OPT);

                }
                else 
                {
                    continue;
                }
            }
        }
    }

    /* Set activeBlockIndex to the COPY_START block */
    eepromConfig->activeBlockIndex = alternativeBlock;

    /* Erase the source block */
    GET_C90LCREGBASE(eepromConfig, sourceBlock->blockStartAddr, c90lcRegBase);

    /* Backup erase cycle and the block is erased */
    erasingCycleInternal = READ_PROGRAMMABLE_SIZE(sourceBlock->blockStartAddr + ERASE_CYCLE_OFFSET) + 1;
    blockConfInternal = sourceBlock;
    c90lcRegBaseInternal = c90lcRegBase;

    returnCode = FSL_EraseEEBlock(c90lcRegBase, sourceBlock, CallBack);
    if (returnCode != EE_OK)
    {
        return (returnCode);
    }

    return (returnCode);
}

UINT32 FSL_SearchInBlock(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, UINT16 dataID, UINT32 * expDataInBlock, void (*CallBack) (void))
{
    UINT16 nextStartID;         /* dummy variable */
    UINT32 temp;                /* temporary variable */
    UINT32 returnCode;          /* the return code */
    UINT32 startAddrInBlock;    /* the data record address */

    /* search the data from the block start to end */
    /* address will point to the record status field */
    startAddrInBlock = blockConf->blockStartAddr + RECORD_OFFSET;
    /* calculate the end address of the specific block */
    temp = blockConf->blockStartAddr + blockConf->blockSize;

    /* initialize the expected data address */
    *expDataInBlock = 0xFFFFFFFF;

    while (startAddrInBlock < temp)
    {
        /* need go through entire block */
        returnCode = FSL_SearchRecordInBlock(blockConf, c90lcRegBase, (UINT32) expDataInBlock, WORD_SIZE, dataID, &startAddrInBlock, &nextStartID, CallBack);
        if (returnCode != EE_OK)
        {
            /* error record status */
            /* save the error record address */
            *expDataInBlock = startAddrInBlock;
            return (returnCode);
        }
    }

    /* check if the expected data is ever found */
    if (*expDataInBlock == 0xFFFFFFFF)
    {
        /* never found in this block */
        return (EE_ERROR_DATA_NOT_FOUND);
    }
    else
    {
        return (EE_OK);
    }
}


UINT32 FSL_RecordBuffering(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, UINT32 bufferAddress, UINT32 bufferSize, UINT16 * startID, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return code */
    UINT32 temp;                /* temporary variable */
    UINT32 startAddrInBlock;    /* the local data record pointer */
    UINT16 nextStartID;         /* the start ID for next time */

    /* address will point to the record status field */
    startAddrInBlock = blockConf->blockStartAddr + RECORD_OFFSET;
    /* calculate the end address of the specific block */
    temp = blockConf->blockStartAddr + blockConf->blockSize;
    /* initialize the next ID */
    nextStartID = 0xFFFF;

    while (startAddrInBlock < temp)
    {
        /* need go through entire block */
        returnCode = FSL_SearchRecordInBlock(blockConf, c90lcRegBase, bufferAddress, bufferSize, *startID, &startAddrInBlock, &nextStartID, CallBack);
        if (returnCode != EE_OK)
        {
            /* error record status */
            return (returnCode);
        }
    }

    /* assign start ID for next time */
    *startID = nextStartID;

    return (EE_OK);
}

UINT32 FSL_ProgramWord(UINT32 c90lcRegBase, UINT32 dest, UINT32 data, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return Code */
    UINT16 size = 0;            /* data size */
    UINT32 address;             /* data buffer address */

    /* Set the programmed data size */
    size = WORD_SIZE;
    /* Assign the data buffer address */
    address = (UINT32) (&data);

    /* Program the status field */
    returnCode = FSL_FlashProgramStart(c90lcRegBase, &dest, &size, &address);
    if (returnCode != EE_OK)
    {
        return (EE_INFO_HVOP_INPROGRESS);
    }
    /* Check the high voltage status */
    while (1)
    {
        if (NULL_CALLBACK != CallBack)
        {
            CallBack();
        }
        returnCode = FSL_FlashCheckStatus(c90lcRegBase);
        if (returnCode == EE_OK)
        {
            break;
        }
        else if (returnCode == EE_ERROR_PE_OPT)
        {
            break;
        }
    }

    /* Reset ECC flag */
    eccErrorStatus_Flag = FALSE;

    /* Check the programmed data against the source data */
    if ((FSL_FlashRead32(dest - WORD_SIZE) != data) || (eccErrorStatus_Flag == TRUE))
    {
        returnCode = EE_ERROR_PE_OPT;
    }

    return (returnCode);
}

UINT32 FSL_ProgramDoubleWord(UINT32 c90lcRegBase, UINT32 dest, UINT64 data, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return Code */
    UINT16 size = 0;            /* data size */
    UINT32 address;             /* data buffer address */

    /* Set the programmed data size */
    size = DWORD_SIZE;
    /* Assign the data buffer address */
    address = (UINT32) (&data);

    /* Program the status field */
    returnCode = FSL_FlashProgramStart(c90lcRegBase, &dest, &size, &address);
    if (returnCode != EE_OK)
    {
        return (EE_INFO_HVOP_INPROGRESS);
    }

    /* Check the high voltage status */
    while (1)
    {
        if (NULL_CALLBACK != CallBack)
        {
            CallBack();
        }
        returnCode = FSL_FlashCheckStatus(c90lcRegBase);
        if (returnCode == EE_OK)
        {
            break;
        }
        else if (returnCode == EE_ERROR_PE_OPT)
        {
            break;
        }
    }

    /* Reset ECC flag */
    eccErrorStatus_Flag = FALSE;

    /* Check the programmed data against the source data */
    if ((FSL_FlashRead64(dest - DWORD_SIZE) != data) || (eccErrorStatus_Flag == TRUE))
    {
        returnCode = EE_ERROR_PE_OPT;
    }

    return (returnCode);
}

UINT32 FSL_CopyDataRecord(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, UINT16 dataID, UINT16 dataSize, UINT32 source, UINT32 dest, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return code */
    UINT32 destBak;             /* Backup of dest */
    UINT32 sourceBak;           /* Backup of source */
    UINT32 dataSizeBak;         /* Backup of data size */
    PROGRAMMABLE_TYPE failData; /* used for program verification for Cflash */
    PROGRAMMABLE_TYPE buffer[1];    /* data buffer */
    UINT32 counter;

#if(FIX_LENGTH == LENGTH_TYPE)
	dataSize = DATA_SIZE;
#endif
    /* Save record start address */
    dataSizeBak = dataSize;

#if (DATA_FLASH_OPT != FLASH_SELECT)
#if (VAR_LENGTH == LENGTH_TYPE)
    /* Prepare data to program into the Dword field */
    buffer[0] = CREATE_STATUS(ERASED_HIGH, ERASED_LOW);
    for (counter = 0; (dataSize > 0) && (counter < 8); dataSize--, counter++)
    {
        /* Copy the first 8 data */
        WRITE8(((UINT32) (&buffer) + counter), FSL_FlashRead8(source));
        /* Update source data pointer */
        source++;
    }

    /* Program the first 8 bytes data */
    returnCode = FSL_ProgramDoubleWord(c90lcRegBase, dest + DWORD_SIZE, (UINT64) buffer[0], CallBack);
    if (returnCode != EE_OK)
    {
        if (returnCode == EE_ERROR_PE_OPT)
        {
        	/* reset ECC Error Flag */
        	eccErrorStatus_Flag = FALSE;
        	
        	if ((FSL_FlashRead64(dest + DWORD_SIZE) == PROGRAMMABLE_DEL) && (eccErrorStatus_Flag == FALSE))
        	{
        		return (EE_ERROR_PE_OPT);
        	}
            /* Update blank space */
            blockConf->blankSpace += RECORD_HEAD_SIZE;
        }
        return (returnCode);
    }
    /* Prepare ID, Size and some data field */
    buffer[0] = CREATE_STATUS(ACTIVE_HIGH, ERASED_LOW);
    /* Calculate start address of the rest of data */
    if (FALSE == writeInternal_Flag)
    {
        source += WORD_SIZE;
    }

    /* Add ID, Size field to buffer */
    buffer[0] = ((UINT64) dataID << 48) | ((UINT64) dataSizeBak << 32) | buffer[0];
    /* Fill data into last word (12 bytes) */
    for (counter = 4; (dataSize > 0) && (counter < 8); dataSize--, counter++)
    {
        /* Copy the 8th to 11th byte data */
        WRITE8(((UINT32) (&buffer) + counter), FSL_FlashRead8(source));
        /* Update source data pointer */
        source++;
    }
	destBak = dest + PAGE_SIZE;
#else /* FIX LENGTH == LENGTH_TYPE */
	/* Prepare ID, Size and some data field */
    buffer[0] = CREATE_STATUS(0x0000FFFF, ERASED_LOW);
    /* Add ID field to buffer */
    buffer[0] = ((UINT64) dataID << 48) | buffer[0];
    /* Fill data into last word (6 bytes) */
    for (counter = 2; (dataSize > 0) && (counter < 8); dataSize--, counter++)
    {
        /* Copy 6 byte data */
        WRITE8(((UINT32) (&buffer) + counter), FSL_FlashRead8(source));
        /* Update source data pointer */
        source++;
    }
	destBak = dest + PROGRAMMABLE_SIZE;
#endif
    /* Program ID, Size and some data field */	
    returnCode = FSL_ProgramDoubleWord(c90lcRegBase, destBak, (UINT64) buffer[0], CallBack);
    if (returnCode != EE_OK)
    {	
    	if (returnCode == EE_ERROR_PE_OPT)
    	{
    		/* reset ECC Error Flag */
        	eccErrorStatus_Flag = FALSE;
        	
    		if ((FSL_FlashRead64(destBak) == PROGRAMMABLE_DEL) && (eccErrorStatus_Flag == FALSE))
        	{
        		return (EE_ERROR_PE_OPT);
        	}			
			/* Update blank space */
#if(VAR_LENGTH == LENGTH_TYPE)
        	blockConf->blankSpace += RECORD_HEAD_SIZE;
#else	/* if(FIX_LENGTH == LENGTH_TYPE) */
			if (dataSize % ECC_SIZE)
            	blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        	else
            	blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;
#endif
    	}    		
        return (returnCode);
    }

#if (VAR_LENGTH == LENGTH_TYPE)
    /* Prepare data in DWORD that follow the IDSIZE field */
    buffer[0] = CREATE_STATUS(ERASED_HIGH, ERASED_LOW);
    for (counter = 0; (dataSize > 0) && (counter < 8); dataSize--, counter++)
    {
        /* Copy the first 12 to 19 bytes data */
        WRITE8(((UINT32) (&buffer) + counter), FSL_FlashRead8(source));
        /* Update source data pointer */
        source++;
    }

    /* Program a DWORD that follow the IDSIZE field */
    returnCode = FSL_ProgramDoubleWord(c90lcRegBase, (dest + (PAGE_SIZE + DWORD_SIZE)), (UINT64) buffer[0], CallBack);
    if (returnCode != EE_OK)
    {
        /* Update blank space */
        blockConf->blankSpace += RECORD_HEAD_SIZE;

        return (returnCode);
    }
#endif
    /* Update the record status to PROGRAM_IDSIZE */
    returnCode = FSL_ProgramDoubleWord(c90lcRegBase, dest, RECORD_STATUS_PROGRAM_IDSIZE, CallBack);
    if (returnCode != EE_OK)
    {
        /* the skipping size must be ECC_SIZE alignment */
        if (returnCode == EE_INFO_HVOP_INPROGRESS)
        {
        	/* Update blank space */
            blockConf->blankSpace += RECORD_HEAD_SIZE;
        } 
        else	/* returnCode = EE_ERROR_PE_OPT */
        {
        	if (dataSize % ECC_SIZE)
            	blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        	else
            	blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;
        }
        return (returnCode);
    }

    /* Update dest */
    dest += RECORD_HEAD_SIZE;

#else /* Select DATA_FLASH_OPT */
    
#if (VAR_LENGTH == LENGTH_TYPE)
	/* Add ID and Size field to buffer */
    buffer[0] = CREATE_STATUS(DELETE_HIGH, DELETE_LOW);
    buffer[0] = ((UINT32) dataID << 16) | dataSizeBak | buffer[0];
#else
	/* Add ID and 2 byte data to buffer */
	buffer[0] = CREATE_STATUS(DELETE_HIGH, ERASED_LOW);	
    buffer[0] = ((UINT32) dataID << 16) | buffer[0];	
	/* Fill data into last word (2 bytes) */
    for (counter = 2; (dataSize > 0) && (counter < 4); dataSize--, counter++)
    {
        /* Copy 2 byte data */
        WRITE8(((UINT32) (&buffer) + counter), FSL_FlashRead8(source));
        /* Update source data pointer */
        source++;
    }	
#endif
    /* Program ID, Size and some data field */
    returnCode = FSL_ProgramWord(c90lcRegBase, (dest + WORD_SIZE), (UINT32) buffer[0], CallBack);
    if (returnCode != EE_OK)
    {
    	if (returnCode == EE_ERROR_PE_OPT)
        {
			/* reset ECC Error Flag */
        	eccErrorStatus_Flag = FALSE;
        	
    		if ((FSL_FlashRead32(dest + WORD_SIZE) == PROGRAMMABLE_DEL) && (eccErrorStatus_Flag == FALSE))
        	{
        		return (EE_ERROR_PE_OPT);
        	}
			
        	/* Update blank space */
#if(VAR_LENGTH == LENGTH_TYPE)
        	blockConf->blankSpace += RECORD_HEAD_SIZE;
#else	/* if(FIX_LENGTH == LENGTH_TYPE) */
			if (dataSize % ECC_SIZE)
            	blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        	else
            	blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;
#endif
        }
        return (returnCode);
    }

    /* Updata the record status to PROGRAM_IDSIZE */
    returnCode = FSL_ProgramWord(c90lcRegBase, dest, RECORD_STATUS_PROGRAM_IDSIZE, CallBack);
    if (returnCode != EE_OK)
    {
        /* the skipping size must be ECC_SIZE alignment */
        if (returnCode == EE_INFO_HVOP_INPROGRESS)
        {
        	/* Update blank space */
            blockConf->blankSpace += RECORD_HEAD_SIZE;
        } 
        else	/* returnCode = EE_ERROR_PE_OPT */
        {
        	if (dataSize % ECC_SIZE)
            	blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        	else
            	blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;
        }
        return (returnCode);
    }

    /* Update dest */
    dest += RECORD_HEAD_SIZE;
#endif                          /* End of DATA_FLASH_OPT != FLASH_SELECT */

    /* Save remained data size */
    destBak = dest;
    dataSizeBak = dataSize;
    sourceBak = source;

    while (dataSize > 0)
    {
        /* start program */
        returnCode = FSL_FlashProgramStart(c90lcRegBase, &dest, &dataSize, &source);
        if (returnCode != EE_OK)
        {
            return (EE_INFO_HVOP_INPROGRESS);
        }
        /* check status and end operation */
        while (1)
        {
            if (NULL_CALLBACK != CallBack)
						{
							CallBack();
						}

            returnCode = FSL_FlashCheckStatus(c90lcRegBase);
            if (returnCode == EE_OK)
            {
                break;
            }
            else if (returnCode == EE_ERROR_PE_OPT)
            {
                break;
            }
        }
    }

    /* Verify the programmed data, use counter variable as failAddr */
    dest = destBak;             /* back up destBak */
    dataSize = (UINT16)dataSizeBak;     /* back up dataSizeBak */
    returnCode = FSL_DataVerify(c90lcRegBase, FALSE, &destBak, &dataSizeBak, &sourceBak, &counter, &failData, CallBack);
    if (returnCode != EE_OK)
    {
    	if (returnCode == EE_ERROR_MISMATCH)
    		returnCode = EE_ERROR_PE_OPT;
    
        if (dataSize % ECC_SIZE)
            blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        else
            blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;

        return (returnCode);
    }

    /* data programmed complete and update the status field to PROGRAM_COMPLETE */
    returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, (dest - RECORD_HEAD_SIZE), RECORD_STATUS_PROGRAM_COMPLETE, CallBack);
    if (returnCode != EE_OK)
    {
        if (dataSize % ECC_SIZE)
            blockConf->blankSpace += RECORD_HEAD_SIZE + ECC_SIZE * ((dataSize / ECC_SIZE) + 1);
        else
            blockConf->blankSpace += RECORD_HEAD_SIZE + dataSize;

        return (returnCode);
    }

    return (EE_OK);
}

BOOL FSL_UpdateCacheTable(CACHE_TABLE * cTable, UINT16 dataID, UINT32 newValue)
{
    UINT32 temp;

    /* get the maximum data ID number in cache table */
    temp = cTable->tableSize / CTABLE_ITEM_SIZE;
    /* check if it is in the cache table */
    if (dataID >= temp)
    {
        /* data should not be in the cache table */
        return (FALSE);
    }
    /* insert the data ID into the cache table */
    temp = cTable->tableStartAddress;

    /* update the cache table item with new value */
    WRITE32((temp + CTABLE_ITEM_SIZE * dataID), newValue);

    return (TRUE);
}

UINT32 FSL_SearchInTable(CACHE_TABLE * cTable, UINT16 dataID, UINT32 * expDataAddress)
{
    UINT32 counter;             /* loop counter */

    /* check if the data ID is in the cache table ID range */
    counter = cTable->tableSize / CTABLE_ITEM_SIZE;
    if (dataID >= counter)
    {
        /* data ID is out of range */
        return (EE_ERROR_NOT_IN_CACHE);
    }
    /* fetch the required data record address */
    *expDataAddress = READ32(cTable->tableStartAddress + dataID * CTABLE_ITEM_SIZE);
    if (*expDataAddress == 0xFFFFFFFF)
    {
        /* no data found */
        return (EE_ERROR_DATA_NOT_FOUND);
    }
    else
    {
        /* data found */
        return (EE_OK);
    }
}

UINT32 FSL_EraseEEBlock(UINT32 c90lcRegBase, BLOCK_CONFIG * blockConf, void (*CallBack) (void))
{
    UINT32 returnCode;          /* the return code */
    UINT32 ebHigh;              /* enabled blocks for high space Flash block */
    UINT32 ebMiddle;            /* enabled blocks for middle space Flash block */
    UINT32 ebLow;               /* enabled blocks for low space Flash block */
    UINT32 dest;                /* blank checking destination address */
    UINT32 size;                /* blank checking size */
    UINT32 source;
    UINT32 failedAddr;
    UINT32 i;
    PROGRAMMABLE_TYPE failedData;

    returnCode = EE_OK;

    switch (blockConf->blockSpace)
    {
    case LOW_ADDRESS_SPACE:
        ebLow = blockConf->enabledBlock;
        break;

    case MID_ADDRESS_SPACE:
        ebMiddle = blockConf->enabledBlock;
        break;

    case HIGH_ADDRESS_SPACE:
        ebHigh = blockConf->enabledBlock;
        break;

    default:
        return (EE_ERROR_BLOCK_CONFIG);
    }

    /* check if selected block belongs to bank 1 */
    if ((ebLow & 0x00FF) == 0)
    {
        ebLow >>= 8;
    }

    i = MAX_REERASE + 1;
    do
    {
        returnCode = FSL_FlashEraseStart(c90lcRegBase, blockConf->blockStartAddr, ebLow, ebMiddle, ebHigh);
        if (returnCode != EE_OK)
        {
            return (EE_INFO_HVOP_INPROGRESS);
        }

        if (FALSE == blockSwap_Flag)
        {
            /* check status and end operation */
            while (1)
            {
                if (NULL_CALLBACK != CallBack)
				{
					CallBack();
				}

                returnCode = FSL_FlashCheckStatus(c90lcRegBase);
                if (returnCode == EE_OK)
                {
                    break;
                }
                else if (returnCode == EE_ERROR_PE_OPT)
                {
                    break;
                }
            }
            /* blank check and update block status */
            /* blank check */
            dest = blockConf->blockStartAddr;
            size = blockConf->blockSize;
            while (size)
            {
                /* perform blank check */
                returnCode = FSL_DataVerify(c90lcRegBase, TRUE, &dest, &size, &source, &failedAddr, &failedData, CallBack);
                if (returnCode != EE_OK)
                {
                    i--;
                    break;
                }
            }

            if (returnCode == EE_OK)
            {
                /* program the increased erasing cycles back */
                returnCode = WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, blockConf->blockStartAddr + ERASE_CYCLE_OFFSET, erasingCycleInternal, CallBack);
                if (returnCode != EE_OK)
                {
                    return (returnCode);
                }
            }
        }
        else
        {
            eraseStatus_Flag = ERASE_INPROGRESS;
        }
    }
    while ((returnCode != EE_OK) && (i > 0));

    return (returnCode);
}
