/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,Inc 2011   *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : eed_lowlevel.c                                        *
* DESCRIPTION   : This file consitutes of low level API's which         *
*                 will be called by high level and middle level API's   *
*                 to perform desired tasks.                             *
* DATE          : Nov 11, 2011                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES *********************************
 0.0.1          08.04.2010          FPT Team        Initial Version
 0.1.0          09.23.2010          FPT Team        Update comments
 0.2.0          09.29.2010          FPT Team        Add FSL_FlashEraseAbort function 
 0.3.0          01.19.2011          FPT Team        Remove FSL_FlashEraseAbort function,
                                                    Add FSL_AbortFunction function and
                                                    Update other functions according  
                                                    to the simplified algorithm.
 0.1.1          05.20.2011          FPT Team        Support fixed-length
                                                    data record.	
 0.1.2          08.05.2011          FPT Team        Mask off immediate bit in dataID to ignore MSB bit 
                                                    when read, delete and update cache table.   
 0.1.3			11.11.2011		    FPT Team		Update checking the CallBack pointer to function is NULL or not.
 0.1.4			11.19.2012			FPT Team		For fix-length record scheme, update FSL_SearchLatestRecordInBlock() 
													function to fix Callback function calling error and to recover successfully
													if having ECC in record status.
*************************************************************************/

#include "ee_types.h"
#include "ee_emulation.h"

void cRestoreEei(UINT32 value)
{
    /* Write MSR */
    asm("mtmsr r3\n\t");
}

UINT32 cReadAndClearEei(void)
{
    /* Read MSR */
    asm("mfmsr	r3\n\t" "wrteei 0 \n\t");
}

void FSL_ReadRecordHead(UINT32 address, DATA_RECORD_HEAD * pLocRecHead)
{
    DATA_RECORD_HEAD *pRH = (DATA_RECORD_HEAD *) (address);
    pLocRecHead->dataStatus = pRH->dataStatus;
    /*read dataID by mask off immediate bit*/
    if (pRH->dataID != 0xFFFF)
    {
        pLocRecHead->dataID = (pRH->dataID) & ~(IMMEDIATE_MASK);
    }
    else
    {
        pLocRecHead->dataID = (pRH->dataID);
    }  
#if (FIX_LENGTH == LENGTH_TYPE)
    pLocRecHead->dataSize = DATA_SIZE;
#else
	pLocRecHead->dataSize = pRH->dataSize;
#endif	
	
#if ((DATA_FLASH_OPT != FLASH_SELECT) && (VAR_LENGTH == LENGTH_TYPE))
    pLocRecHead->dwordData = pRH->dwordData;
    pLocRecHead->wordData = pRH->wordData;
#endif
}

UINT32 FSL_SearchRecordInBlock(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, UINT32 bufferAddress, UINT32 bufferSize, UINT16 startID, UINT32 * startAddrInBlock, UINT16 * nextStartID, void (*CallBack) (void))
{
    UINT32 returnCode;          /* return code */
    UINT32 endID;               /* define the data ID range */
    UINT32 index;               /* loop index */
    UINT32 temp;                /* temporary variable */
    UINT32 recordLength;        /* the length of the record */
    PROGRAMMABLE_TYPE status;   /* record status */
    DATA_RECORD_HEAD record;    /* local data record head structure */
    DATA_RECORD_HEAD *pRH;
    UINT8 eccInStatus_Flag;
    UINT32 temp_MSR, enable_MSR;    /* temporary space for MSR */

    /* Initialize the return code */
    returnCode = EE_OK;
    eccInStatus_Flag = FALSE;
    /* Calculate the boundary of the data ID range */
    endID = startID + bufferSize / WORD_SIZE;
    /* Calculate the end address of the specific block */
    temp = blockConf->blockStartAddr + blockConf->blockSize;
    /* Check the high voltage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* if any P/E operation in progress, return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }

    for (index = 0; index < NUMBER_OF_SEARCHING_RECORD_IN_BLOCK; index++)
    {
        /* callback service */
        if ((index % CALLBACK_SEARCHING_BYTES_NUMBER) == 0)
        {
            if (NULL_CALLBACK != CallBack)
            {
                CallBack();
            }
        }

        /* check the record address is within the block range */
        if (*startAddrInBlock > (temp - RECORD_HEAD_SIZE))
        {
            /* set the blank space pointer */
            blockConf->blankSpace = *startAddrInBlock;

            /* finish searching block */
            if (startID == 0xFFFF)
            {
                WRITE32(bufferAddress, *startAddrInBlock);
            }

            *startAddrInBlock = temp;
            break;
        }

        /* save old MSR */
        temp_MSR = cReadAndClearEei();
        enable_MSR = ENABLE_MSR;
        cRestoreEei(enable_MSR);
        /* Set ECC Error Module flag */
        eccErrorModule_Flag = EE_MODULE;
        /* assign data record pointer */
        FSL_ReadRecordHead(*startAddrInBlock, &record);
        /* Reset ECC Error Module flag */
        eccErrorModule_Flag = NONE;
        /* Enable interrupts */
        /* restore MSR */
        cRestoreEei(temp_MSR);

        /* check the record status type */
        status = record.dataStatus;

        if ((status == RECORD_STATUS_PROGRAM_COMPLETE) && (FALSE == eccErrorStatus_Flag))
        {
            /* this is valid record and check the ID */
            if ((record.dataID >= startID) && (record.dataID < endID))
            {
                WRITE32((bufferAddress + (record.dataID - startID) * WORD_SIZE), *startAddrInBlock);
            }
            else if ((record.dataID >= endID) && (record.dataID < *nextStartID))
            {
                /* the start ID for next call */
                *nextStartID = record.dataID;
            }
        }
        else if ((status == RECORD_STATUS_PROGRAM_IDSIZE) && (FALSE == eccErrorStatus_Flag))
        {
            /* that means this data record is not valid and ID&SIZE field is valid, skip this record */
        }
        else if ((status == RECORD_STATUS_DELETE) && (FALSE == eccErrorStatus_Flag))
        {
            /* check the ID */
            if ((record.dataID >= startID) && (record.dataID < endID))
            {
                /* delete found result */
                WRITE32((bufferAddress + (record.dataID - startID) * WORD_SIZE), 0xFFFFFFFF);
            }
            if (record.dataID == startID)
            {
                dataDeleted = TRUE;
            }
        }
        else if ((status == RECORD_STATUS_ERASED) && (FALSE == eccErrorStatus_Flag))
        {
            if (record.dataID == 0xFFFF)
            {
#if ((DATA_FLASH_OPT != FLASH_SELECT) && (VAR_LENGTH == LENGTH_TYPE))  
                if (record.dwordData != PROGRAMMABLE_DEL)
                {
                    *startAddrInBlock += RECORD_HEAD_SIZE;
                    continue;
                }
#endif  
                blockConf->blankSpace = *startAddrInBlock;
                /* end of searching operation */
                if (startID == 0xFFFF)
                {
                    WRITE32(bufferAddress, *startAddrInBlock);
                }
                *startAddrInBlock = temp;
                return (returnCode);
            }
            else
            {
#if(VAR_LENGTH == LENGTH_TYPE)
                *startAddrInBlock += RECORD_HEAD_SIZE;
#else   /* if(FIX_LENGTH == LENGTH_TYPE) */
                if (record.dataSize <= HEAD_DATA_SIZE)
                {
                    *startAddrInBlock += RECORD_HEAD_SIZE;
                }
                else
                {
                    if ((record.dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                        *startAddrInBlock += RECORD_HEAD_SIZE + ECC_SIZE * (((record.dataSize -HEAD_DATA_SIZE) / ECC_SIZE) + 1);
                    else
                        *startAddrInBlock += RECORD_HEAD_SIZE - HEAD_DATA_SIZE + record.dataSize;
                }
#endif
                continue;
            }
        }
        else
        {
            /* Save old MSR */
            temp_MSR = cReadAndClearEei();
            enable_MSR = ENABLE_MSR;
            cRestoreEei(enable_MSR);
            /* Set ECC Error Module flag */
            eccErrorModule_Flag = EE_MODULE;
            /* Reset ECC flag */
            eccErrorStatus_Flag = FALSE;
            /* Reset the record header data */
            record.dataStatus = PROGRAMMABLE_DEL;
            record.dataID = 0xFFFF;
            record.dataSize = 0xFFFF;
#if ((DATA_FLASH_OPT != FLASH_SELECT) && (VAR_LENGTH == LENGTH_TYPE))
            record.dwordData = PROGRAMMABLE_DEL;
            record.wordData = 0xFFFFFFFF;
#endif
            /* Read the record status */
            pRH = (DATA_RECORD_HEAD *) (*startAddrInBlock);
            record.dataStatus = pRH->dataStatus;

            if (TRUE == eccErrorStatus_Flag)
            {
                /* have ECC in record status */
                eccInStatus_Flag = TRUE;
                /* Reset ECC flag */
                eccErrorStatus_Flag = FALSE;
            }

            /* Read the record ID, Size and the word data */
            /* Read the record ID, and mask off immediate bit */
            record.dataID = (pRH->dataID) & ~(IMMEDIATE_MASK);
#if (VAR_LENGTH == LENGTH_TYPE)
            record.dataSize = pRH->dataSize;
#else	/* if(FIX_LENGTH == LENGTH_TYPE) */
			record.dataSize = DATA_SIZE;
#endif
            /* If ECC error is in the record status, the other does not have the ECC error */
            if (TRUE == eccInStatus_Flag)
            {
                if ((record.dataSize <= HEAD_DATA_SIZE) || (record.dataSize == 0xFFFF))
                {
                    recordLength = RECORD_HEAD_SIZE;
                }
                else
                {
                    /* Calculate recordLength */
                    if ((record.dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                        recordLength = RECORD_HEAD_SIZE + ECC_SIZE * ((record.dataSize - HEAD_DATA_SIZE) / ECC_SIZE + 1);
                    else
                        recordLength = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + record.dataSize;
                }
            }
            else
            {
                /* If ECC error is in the record ID/SIZE */
                if (TRUE == eccErrorStatus_Flag)
                {
#if(VAR_LENGTH == LENGTH_TYPE)
					recordLength = RECORD_HEAD_SIZE;
#else 	/* if(FIX_LENGTH == LENGTH_TYPE) */
                    if (record.dataSize <= HEAD_DATA_SIZE)
                    {
                        recordLength = RECORD_HEAD_SIZE;
                    }
                    else
                    {
                        if ((record.dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                            recordLength = RECORD_HEAD_SIZE + ECC_SIZE * (((record.dataSize -HEAD_DATA_SIZE) / ECC_SIZE) + 1);
                        else
                            recordLength = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + record.dataSize;
                    }
#endif
                }
            }
            /* Reset ECC Error Module flag */
            eccErrorModule_Flag = NONE;
            /* Enable interrupts */
            /* restore MSR */
            cRestoreEei(temp_MSR);

            /* If there is an ECC error in status or data ID */
            if ((TRUE == eccErrorStatus_Flag) || (TRUE == eccInStatus_Flag))
            {
                /* reset ECC Error Status Flag */
                eccErrorStatus_Flag = FALSE;

                /* Reset ECC flag in status */
                eccInStatus_Flag = FALSE;

                /* prepare for next data record */
                *startAddrInBlock = *startAddrInBlock + recordLength;
                continue;
            }
        }

		if (record.dataSize <= HEAD_DATA_SIZE)
        {
            recordLength = RECORD_HEAD_SIZE;
        }
        else
        {
            /* Calculate recordLength */
            if ((record.dataSize - HEAD_DATA_SIZE) % ECC_SIZE)
                recordLength = RECORD_HEAD_SIZE + ECC_SIZE * ((record.dataSize - HEAD_DATA_SIZE) / ECC_SIZE + 1);
            else
                recordLength = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + record.dataSize;
        }

        /* prepare for next data record */
        *startAddrInBlock = *startAddrInBlock + recordLength;
    }

    return (returnCode);
}

UINT32 FSL_SearchLatestRecordInBlock(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, UINT16 recordID, UINT32 * recordAddr, void (*CallBack) (void))
{
   UINT32 returnCode;          /* return code */
   DATA_RECORD_HEAD record;    /* local data record head structure */   
   UINT32 temp;                /* temporary variable */
   UINT32 temp_MSR, enable_MSR;
   UINT8 eccInStatus_Flag;
   UINT32 count;

    /* Initialize the return code */
    returnCode = EE_OK;
    eccInStatus_Flag = FALSE;    
    /* Calculate the end address of the specific block */
    *recordAddr = blockConf->blankSpace;
    /* Check the high voltage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* if any P/E operation in progress, return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }
    
    /* Store number of searched records for CallBack() service */
    count = 0;
	temp = DATA_SIZE;
	if(temp <= HEAD_DATA_SIZE)
		temp = RECORD_HEAD_SIZE;
	else 
	{
        if ((temp - HEAD_DATA_SIZE) % ECC_SIZE)
            temp = RECORD_HEAD_SIZE + ECC_SIZE * ((temp - HEAD_DATA_SIZE) / ECC_SIZE + 1);
        else
            temp = RECORD_HEAD_SIZE - HEAD_DATA_SIZE + temp;
	}
				
    while (*recordAddr > (blockConf->blockStartAddr + RECORD_OFFSET))
    {
        /*Point to start address of previous record */
        *recordAddr -= temp;
        
        /* CallBack service routine */
        if (0 == (count++ % CALLBACK_SEARCHING_BYTES_NUMBER))
         {
            if (NULL_CALLBACK != CallBack)
             {
               CallBack();
             }   
         }

        /* Reset eccErrorStatus_Flag*/
         eccErrorStatus_Flag = FALSE;
		 
		 /* save old MSR */
        temp_MSR = cReadAndClearEei();
        enable_MSR = ENABLE_MSR;
        cRestoreEei(enable_MSR);
        /* Set ECC Error Module flag */
        eccErrorModule_Flag = EE_MODULE;
        /* assign data record pointer */
        FSL_ReadRecordHead(*recordAddr, &record);
        /* Reset ECC Error Module flag */
        eccErrorModule_Flag = NONE;
        /* Enable interrupts */
        /* restore MSR */
        cRestoreEei(temp_MSR);
        
		/* Check eccErrorStatus_Flag, skip the ECC record in either record status or IDSIZE field */
		if (TRUE == eccErrorStatus_Flag)
        {
            continue;
        }
		
        if (recordID == record.dataID)
        {
            if (RECORD_STATUS_PROGRAM_COMPLETE == record.dataStatus)
            {
                return (returnCode);
            }
            else if (RECORD_STATUS_DELETE == record.dataStatus)
                {
					dataDeleted = TRUE;
                    return (EE_ERROR_DATA_NOT_FOUND); 
                }               
        }
      
    }
	return(EE_ERROR_DATA_NOT_FOUND);
}

UINT32 FSL_FlashProgramStart(UINT32 c90lcRegBase, UINT32 * dest, UINT16 * size, UINT32 * source)
{
    UINT32 counter;             /* Loop counter */
    UINT32 sourceIndex;         /* source address index */
    UINT32 temp;                /* temporary variable */
    PROGRAMMABLE_TYPE buffer[1];    /* internal source data buffer */

    /* Anything to program? */
    if (*size == 0)
    {
        return (EE_OK);
    }
    /* Check the high votage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* If any P/E operation in progress return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }
    /* Calculate the size to be programmed within the dword/word boundary */
    temp = *dest;
    temp = ((temp / PROGRAMMABLE_SIZE) + 1) * PROGRAMMABLE_SIZE - temp;

    /* There are remained data need programming */
    /* Padding for not alignment data */
    for (counter = 0; counter < (sizeof (buffer) / PROGRAMMABLE_SIZE); counter++)
    {
        buffer[counter] = CREATE_STATUS(ERASED_HIGH, ERASED_LOW);
    }
    /* Copy one page to page buffer */
    for (sourceIndex = 0; (sourceIndex < temp) && (*size > 0); sourceIndex++)
    {
        /* Copy data */
        WRITE8(((UINT32) buffer + sourceIndex), FSL_FlashRead8(*source));
        /* Update source data pointer */
        *source += 1;
        *size -= 1;
    }

    /* Set MCR PGM bit */
    SET32(c90lcRegBase, C90LC_MCR_PGM);
    /* Program data with one page */
    sourceIndex = 0;
#if (DATA_FLASH_OPT == FLASH_SELECT)
    WRITE32(*dest, buffer[sourceIndex]);
#else
    WRITE64(*dest, buffer[sourceIndex]);
#endif
    *dest += PROGRAMMABLE_SIZE;
    /* Set MCR EHV bit */
    SET32(c90lcRegBase, C90LC_MCR_EHV);
    return (EE_OK);
}

UINT32 FSL_FlashEraseStart(UINT32 c90lcRegBase, UINT32 interlockWriteAddress, UINT32 lowEnabledBlock, UINT32 midEnabledBlock, UINT32 highEnabledBlock)
{
    /* Check the high voltage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* If any P/E operation in progress return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }
    /* Set MCR ERS bit */
    SET32(c90lcRegBase, C90LC_MCR_ERS);
    /* Prepare low enabled blocks */
    lowEnabledBlock &= 0x0000FFFF;
    /* Prepare middle enabled blocks */
    midEnabledBlock &= 0xF;
    midEnabledBlock = midEnabledBlock << 16;
    /* Prepare high enabled blocks */
    highEnabledBlock &= 0x0FFFFFFF;

    /* Write the block selection registers */
    WRITE32((c90lcRegBase + C90LC_LMS), (lowEnabledBlock | midEnabledBlock));
    WRITE32((c90lcRegBase + C90LC_HBS), highEnabledBlock);
    /* Interlock write */
    WRITE32(interlockWriteAddress, 0xFFFFFFFF);
    /* Set MCR EHV bit */
    SET32(c90lcRegBase, C90LC_MCR_EHV);
    return (EE_OK);
}

UINT32 FSL_FlashCheckStatus(UINT32 c90lcRegBase)
{
    UINT32 returnCode;          /* return code */
    /* Initialize return code */
    returnCode = EE_OK;
    /* Check if MCR DONE is set */
    if (READ32(c90lcRegBase) & C90LC_MCR_DONE)
    {
        /* Check the operation status */
        if (!(READ32(c90lcRegBase) & C90LC_MCR_PEG))
        {
            /* high voltage operation failed */
            returnCode = EE_ERROR_PE_OPT;
        }
        /* End the high voltage operation */
        CLEAR32(c90lcRegBase, C90LC_MCR_EHV);
        /* Check for program operation */
        if (READ32(c90lcRegBase) & C90LC_MCR_PGM)
        {
            /* Finish the program operation */
            CLEAR32(c90lcRegBase, C90LC_MCR_PGM);
        }
        else
        {
            /* Finish the erase operation */
            CLEAR32(c90lcRegBase, C90LC_MCR_ERS);
        }
        return (returnCode);
    }
    return (EE_INFO_HVOP_INPROGRESS);
}

UINT32 FSL_DataVerify(UINT32 c90lcRegBase, BOOL blankCheck, UINT32 * dest, UINT32 * size, UINT32 * source, UINT32 * compareAddress, PROGRAMMABLE_TYPE * compareData, void (*CallBack) (void))
{
    UINT32 destIndex;           /* Destination address index */
    UINT32 counter;             /* Loop counter */
    UINT32 returnCode;          /* return code */
    UINT8 temp;                 /* temporary variable */
    PROGRAMMABLE_TYPE destData; /* dest data */
    PROGRAMMABLE_TYPE sourceData;   /* source data */

    /* Initialize return code */
    returnCode = EE_OK;
    /* Clear compareAddress and compareData arguments */
    *compareAddress = 0;
    *compareData = 0;
    /* check the high voltage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* if any P/E operation in progress, return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }
    /* Init sourceData, default is for blank checking */
    sourceData = CREATE_STATUS(ERASED_HIGH, ERASED_LOW);
    destIndex = 0;
    while ((destIndex < DATA_VERIFY_NUMBER) && (*size > 0))
    {
        /* CallBack service */
        if ((destIndex % CALLBACK_VERIFY_BYTES_NUMBER) == 0)
        {
			if (NULL_CALLBACK != CallBack)
			{
				CallBack();
			}
        }
        /* Get the data first */
        destData = READ_PROGRAMMABLE_SIZE(*dest);
        /* Check if it is blank check or data verification */
        if (!blankCheck)
        {
            /* Data verification */
            /* Read source data */
            sourceData = READ_PROGRAMMABLE_SIZE(*source);
            *source += PROGRAMMABLE_SIZE;
        }
        /* Check if the size is not dword/word length */
        temp = PROGRAMMABLE_SIZE;
        if (*size < temp)
        {
            /* fetch the correct data depending on the actual size, */
            for (counter = 0; counter < *size; counter++)
            {
                if (*(UINT8 *) ((UINT32) (&destData) + counter) != *(UINT8 *) ((UINT32) (&sourceData) + counter))
                {
                    /* if not match, set error return code */
                    returnCode = EE_ERROR_MISMATCH;
                    break;
                }
            }
            /* for end of the loop only */
            *size = temp;
        }
        else
        {
            /* compare the data against the Flash content */
            if (destData != sourceData)
            {
                /* if not match, set error return code */
                returnCode = EE_ERROR_MISMATCH;
            }
        }
        /* check return code */
        if (returnCode == EE_ERROR_MISMATCH)
        {
            /* data mismatch */
            *compareAddress = *dest;
            *compareData = destData;
            break;
        }
        /* update the dest */
        *dest += PROGRAMMABLE_SIZE;
        /* update the size */
        *size -= PROGRAMMABLE_SIZE;
        destIndex += PROGRAMMABLE_SIZE;
    }
    return (returnCode);
}

UINT32 FSL_FlashRead(UINT32 c90lcRegBase, UINT32 * dest, UINT32 * size, UINT32 * buffer, void (*CallBack) (void))
{
    UINT32 counter;             /* loop counter */
    /* check high voltage operation */
    if (READ32(c90lcRegBase) & (C90LC_MCR_ERS | C90LC_MCR_PGM))
    {
        /* if any P/E operation in progress, return error */
        return (EE_INFO_HVOP_INPROGRESS);
    }
    /* read data */
    for (counter = 0; (*size > 0) && (counter < DATA_READ_NUMBER); counter++)
    {
        /* callback service */
        if ((counter % CALLBACK_READ_BYTES_NUMBER) == 0)
        {
            if (NULL_CALLBACK != CallBack)
            {
                CallBack();
            }
        }
        WRITE8(*buffer, FSL_FlashRead8(*dest));
        (*dest) += 1;
        (*buffer) += 1;
        (*size) -= 1;
    }
    return (EE_OK);
}

/*exception handler*/
UINT32 EER_exception_handler(UINT32 return_address, UINT16 instruction)
{
/*if VLE is ON*/
#if (1 == VLE_ON)
    {
        if (eccErrorModule_Flag == EE_MODULE)
        {
            eccErrorStatus_Flag = TRUE;
            if ((instruction & 0x9000) == 0x1000)
            {
                // first 4 Bits have a value of 1,3,5,7
                return_address += 4;    // instruction was 32 bit
            }
            else
            {
                // first 4 Bits have a value of 0,2,4,6,8,9,A,B,C,D,E (and F, but F is reserved)
                return_address += 2;    // instruction was 16 bit
            }

        }
        else
        {
            /* do nothing */
            /* EER invoked from application other than EEE Driver */
        }
    }
/* IF VLE is off (BookE)*/
#else
    {
        if (eccErrorModule_Flag == EE_MODULE)
        {
            eccErrorStatus_Flag = TRUE;
            return_address += 4;
        }
        else
        {
            /* do nothing */
            /* EER invoked from application other than EEE Driver */
        }
    }
#endif
    return return_address;
}

UINT8 FSL_FlashRead8(UINT32 address)
{
    UINT8 readVariable;
    UINT32 temp_MSR, enable_MSR;
    EE_ModuleType tempFlag;

    tempFlag = eccErrorModule_Flag;
    /* save old MSR */
    temp_MSR = cReadAndClearEei();
    enable_MSR = ENABLE_MSR;
    cRestoreEei(enable_MSR);
    /* Set ECC Error Module flag */
    eccErrorModule_Flag = EE_MODULE;

    readVariable = READ8(address);

    /* Reset ECC Error Module flag */
    eccErrorModule_Flag = NONE;
    /* restore MSR */
    cRestoreEei(temp_MSR);
    eccErrorModule_Flag = tempFlag;
    return (readVariable);

}

UINT32 FSL_FlashRead32(UINT32 address)
{
    UINT32 readVariable;
    UINT32 temp_MSR, enable_MSR;
    EE_ModuleType tempFlag;

    tempFlag = eccErrorModule_Flag;
    /* save old MSR */
    temp_MSR = cReadAndClearEei();
    enable_MSR = ENABLE_MSR;
    cRestoreEei(enable_MSR);
    /* Set ECC Error Module flag */
    eccErrorModule_Flag = EE_MODULE;

    readVariable = READ32(address);

    /* Reset ECC Error Module flag */
    eccErrorModule_Flag = NONE;
    /* restore MSR */
    cRestoreEei(temp_MSR);
    eccErrorModule_Flag = tempFlag;
    return (readVariable);

}

UINT64 FSL_FlashRead64(UINT32 address)
{
    UINT64 readVariable;
    UINT32 temp_MSR, enable_MSR;
    EE_ModuleType tempFlag;

    tempFlag = eccErrorModule_Flag;
    /* save old MSR */
    temp_MSR = cReadAndClearEei();
    enable_MSR = ENABLE_MSR;
    cRestoreEei(enable_MSR);
    /* Set ECC Error Module flag */
    eccErrorModule_Flag = EE_MODULE;

    /* read flash */
    readVariable = READ64(address);

    /* Reset ECC Error Module flag */
    eccErrorModule_Flag = NONE;
    /* restore MSR */
    cRestoreEei(temp_MSR);
    eccErrorModule_Flag = tempFlag;
    return (readVariable);
}

UINT32 FSL_FlashReadStatus(BLOCK_CONFIG * blockConf, UINT32 c90lcRegBase, BLOCK_STATUS * blockStatus)
{
    UINT32 MCRValue;
    PROGRAMMABLE_TYPE data_info;

    MCRValue = READ32(c90lcRegBase + C90LC_MCR);
    if (MCRValue & (C90LC_MCR_PGM | C90LC_MCR_ERS))
    {
        return (EE_INFO_HVOP_INPROGRESS);
    }

    /* Reset eccErrorStatus_Flag variable */
    eccErrorStatus_Flag = FALSE;

    *blockStatus = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr);
    if ((*blockStatus == BLOCK_STATUS_ALTERNATIVE) && (eccErrorStatus_Flag == FALSE))
    {
        /* Do nothing */
    }
    else if ((*blockStatus == BLOCK_STATUS_COPY_START) && (eccErrorStatus_Flag == FALSE))
    {
        /* Read DATA_INFO field */
        data_info = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + DATA_INFO_OFFSET);
        if ((data_info != DATA_INFO) || (eccErrorStatus_Flag == TRUE))
        {
            *blockStatus = BLOCK_STATUS_UNKNOWN;
        }
    }
    else
    {
        /* Reset eccErrorStatus_Flag variable */
        eccErrorStatus_Flag = FALSE;

        /* Read DATA_INFO field */
        data_info = READ_PROGRAMMABLE_SIZE(blockConf->blockStartAddr + DATA_INFO_OFFSET);
        if ((data_info == DATA_INFO) && (eccErrorStatus_Flag == FALSE))
        {
            *blockStatus = BLOCK_STATUS_ACTIVE;
        }
        else
        {
            *blockStatus = BLOCK_STATUS_UNKNOWN;
        }
    }

    return (EE_OK);
}

BOOL FSL_AbortHVOP(UINT32 c90lcRegBase)
{
    BOOL returnCode;            /* return code */
    
    returnCode = FALSE;

    /* Check if MCR ERS is set */
    if (READ32(c90lcRegBase) & C90LC_MCR_ERS)
    {
    	/* End the high voltage operation */
    	CLEAR32(c90lcRegBase, C90LC_MCR_EHV);
    	
    	/* Wait for the DONE bit is set */
    	while (!(READ32(c90lcRegBase) & C90LC_MCR_DONE))
    	{
    	}
    	
    	/* Finish the erase operation */
        CLEAR32(c90lcRegBase, C90LC_MCR_ERS);
    	
        returnCode = TRUE;
    }
    
    return (returnCode);
}
