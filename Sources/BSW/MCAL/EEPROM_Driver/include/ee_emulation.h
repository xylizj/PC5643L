/************************************************************************
* (c) Copyright Freescale Semiconductor & STMicroelectronics,Inc 2012   *
*                        All Rights Reserved                            *
*************************************************************************

*************************************************************************
*                                                                       *
*                EEPROM Emulation driver for C90lc                      *
*                                                                       *
* FILE NAME     : ee_emulation.h                                        *
* DESCRIPTION   : This file consitutes of defines, structures and       *
*                 declaration of global variables as extern.            *
* DATE          : Jan 19, 2012                                          *
* AUTHOR        : FPT Team                                              *
* E-mail        : b33626@freescale.com                                  *
*                                                                       *
*************************************************************************/

/******************************* CHANGES ********************************
 0.0.1    08.04.2010        FPT Team      Initial Version
 0.1.0    09.23.2010        FPT Team      Update comments
 0.2.0    09.29.2010        FPT Team	  All function prototype:
 										  FSL_AbortFunction & FSL_FlashEraseAbort 
 0.3.0	  01.19.2011		FPT Team	  Update defines, macros and declarations 
										  according to the simplified algorithm.
 0.1.1    05.20.2011        FPT Team      Support fixed-length
                                          data record.
 0.1.2    01.19.2012        FPT Team      Added definition for SWAP_CACHE data type                                            										  
*************************************************************************/

#ifndef _EE_EMULATION_H_
#define _EE_EMULATION_H_

#include "ee_types.h"
#include "user_cfg.h"

/*User Configurable Macros*/
/* Define flash select */
#define CODE_FLASH							0
#define DATA_FLASH							1
#define DATA_FLASH_OPT					2  /* Data flash optimize */
#if ((DATA_FLASH != FLASH_SELECT) && (DATA_FLASH_OPT != FLASH_SELECT))
#error "This version supports Data Flash or Optimized Data Flash only!!!"
#endif

/* Select length type */
#define FIX_LENGTH				0
#define VAR_LENGTH				1

#define BANK_NUMBER				1

#if (DATA_FLASH_OPT == FLASH_SELECT)
	typedef	UINT32					BLOCK_STATUS;
	typedef	UINT32					PROGRAMMABLE_TYPE;
#else
	typedef	UINT64					BLOCK_STATUS;
    typedef	UINT64					PROGRAMMABLE_TYPE;
#endif

/*******************************************************************
| defines and macros (scope: module-local)
|------------------------------------------------------------------*/
/* macros for scheduling */
#define NUMBER_OF_SEARCHING_RECORD_IN_BLOCK     0x2000
#define DATA_VERIFY_NUMBER                      0x5000
#define DATA_READ_NUMBER                        0x5000

/* macros for CallBack period controlling */
#define CALLBACK_READ_BYTES_NUMBER              0x0020
#define CALLBACK_SEARCHING_BYTES_NUMBER         0x001A
#define CALLBACK_VERIFY_BYTES_NUMBER            0x0020
#define CALLBACK_FILL_BUFFER                    0x0060

#define ENABLE_MSR                              0x00208200

#define IMMEDIATE_MASK							0x8000
/*******************************************************************
| typedefs and structures (scope: module-local)
|------------------------------------------------------------------*/
/* structure declaration*/
#if ((DATA_FLASH == FLASH_SELECT) || (CODE_FLASH == FLASH_SELECT))
#if (VAR_LENGTH == LENGTH_TYPE)
	typedef struct
	{
		UINT64  dataStatus;                 /* the data record status */
		UINT64  dwordData;				    /* first 8 bytes of record */
		UINT16  dataID;                     /* the unique data ID */
		UINT16  dataSize;                   /* the data size */
		UINT32  wordData;                   /* the first 4 bytes data */
	}DATA_RECORD_HEAD;
#else
	typedef struct
	{
		UINT64  dataStatus;                 /* the data record status */		
		UINT16  dataID;                     /* the unique data ID */
		UINT16  dataSize;                   /* the data size */
	}DATA_RECORD_HEAD;
#endif /* LENGTH_TYPE */	
#else
	typedef struct
	{
		UINT32  dataStatus;                 /* the data record status */
		UINT16  dataID;                     /* the unique data ID */
		UINT16  dataSize;                   /* the data size */
	}DATA_RECORD_HEAD;
#endif

typedef struct
{
	UINT32  enabledBlock;               	/* the block bit map in specific space */
  UINT32  blockStartAddr;             	/* the block start address */
  UINT32  blockSize;                  	/* the block size */
  UINT32  blankSpace;                 	/* the address pointer to the blank space */
  UINT8   blockSpace;                 	/* the space (low, middle or high) for the block */
}BLOCK_CONFIG;

typedef struct
{
    UINT32  tableStartAddress;          	/* the start address of cache table */
    UINT32  tableSize;                  	/* the size of cache table in byte */
}CACHE_TABLE;

typedef struct
{
    UINT32  startAddress;          	        /* the start address of cache table */
    UINT32  size;                       	/* the size of cache table in byte */
}SWAP_CACHE;

typedef struct
{
  UINT32          	numberOfBlock;      /* the number of blocks used for emulation */
  UINT32          	activeBlockIndex;   /* the active block index */
  volatile UINT32     blockWriteFlag;     /* the writing flag of the blocks */
	UINT32  			c90lcRegBase;       /* the register base address for C90LC */
  BOOL            	cacheEnable;        /* the flag to enable/disable the cache table */
  CACHE_TABLE*    	cTable;             /* the cache table structure */
  BLOCK_CONFIG**  	flashBlocks;        /* the block configuration array pointer */
}EEPROM_CONFIG;

typedef enum
{
  NONE = 0,
  EE_MODULE = 1,
  OTHER_MODULE = 2
}EE_ModuleType;

typedef enum
{
  ERASE_NOTSTARTED=0,
  ERASE_DONE = 1,
  ERASE_FAIL = 2,
  ERASE_INPROGRESS = 3,
  ERASE_SWAPERROR = 4
}EE_EraseType;

/*******************************************************************
| external declarations
|------------------------------------------------------------------*/
/* Flag to keep track of ECC Error Status */
extern UINT8 volatile eccErrorStatus_Flag;
/* Flag to keep track of ECC Error Module */
extern volatile EE_ModuleType eccErrorModule_Flag;
/* structure to store block configuration during erase */
extern BLOCK_CONFIG* blockConfInternal;
/* Flag to keep track of Block Swapping */
extern UINT8 blockSwap_Flag;
/* Variable to store C90LC Register Base */
extern UINT32 c90lcRegBaseInternal;
/* Variable to store erasing cycles */
extern PROGRAMMABLE_TYPE erasingCycleInternal;
/* Flag to keep track of Erase State */
extern EE_EraseType eraseStatus_Flag;
/* Variable to store size of the data record */
extern UINT32 tempInternalSwap;
/* Variable to store DataID */
extern UINT16 dataIDInternalSwap;
/* Variable to store Data Size */
extern UINT16 dataSizeInternalSwap;
/* Variable to store source address while swap */
extern UINT32 sourceInternalSwap;
/* Flag to keep track whether the record is deleted or not */
extern BOOL dataDeleted;
/* Flag specifies data record source come from FLASH(writeInternal_Flag = FALSE) 
   or buffer in RAM (writeInternal_Flag = TRUE) */
extern BOOL writeInternal_Flag;
/* Cache for swapping */
extern SWAP_CACHE swap_Cache;

/*******************************************************************
| defines and macros (scope: module-local)
|------------------------------------------------------------------*/
/* return code definition*/
#define EE_OK                        0x00000000
#define EE_FIRST_TIME_INITIALIZATION 0x00000001
#define EE_INFO_HVOP_INPROGRESS      0x00000002
#define EE_ERROR_WRITE_IN_PROGRESS   0x00000020
#define EE_ERROR_PE_OPT              0x00000040
#define EE_ERROR_MISMATCH            0x00000080
#define EE_ERROR_BLOCK_STATUS        0x00000100
#define EE_ERROR_RECORD_STATUS       0x00000200
#define EE_ERROR_BLOCK_CONFIG        0x00000400
#define EE_ERROR_DATA_NOT_FOUND      0x00000800
#define EE_ERROR_NOT_IN_CACHE        0x00001000
#define EE_ERROR_NO_ENOUGH_SPACE     0x00002000

/* address space macro*/
#define LOW_ADDRESS_SPACE           0x01
#define MID_ADDRESS_SPACE           0x02
#define HIGH_ADDRESS_SPACE          0x03
		
/* Offsets of C90LC Control Registers*/
#define C90LC_MCR                   0x0000         /* Module Configuration Register */
#define C90LC_LML                   0x0004         /* Low/Mid Address Sapce Block Locking Register */
#define C90LC_HBL                   0x0008         /* High Address Sapce Block Locking Register */
#define C90LC_SLL                   0x000C         /* Secondary Low/Mid Address Space Block Locking Register */
#define C90LC_LMS                   0x0010         /* Low/Mid Address Space Block Select Register */
#define C90LC_HBS                   0x0014         /* High Address Space Block Select Register */

#define C90LC_MCR_DONE              0x00000400     /* State Machine Status */
#define C90LC_MCR_PEG               0x00000200     /* Program/Erase Good */
#define C90LC_MCR_PGM               0x00000010     /* Program */
#define C90LC_MCR_ERS               0x00000004     /* Erase */
#define C90LC_MCR_EHV               0x00000001     /* Enable High Voltage */

#define C90LC_MCR_EER               0x00008000     /* ECC Event Error */
#define C90LC_MCR_RWE               0x00004000     /* Read While Write Event Error */

#define PFB_CR                		0x001C         /* PFBIU Configuration Register for port 0 */
#define PFB_CR_BFEN        			0x00000001     /* PFBIU Line Read Buffers Enable */

/* read and write macros*/
#define WRITE8(address, value)      (*(VUINT8*)(address) = (value))
#define READ8(address)              ((UINT8)(*(VUINT8*)(address)))
#define SET8(address, value)        (*(VUINT8*)(address) |= (value))
#define CLEAR8(address, value)      (*(VUINT8*)(address) &= ~(value))

#define WRITE16(address, value)     (*(VUINT16*)(address) = (value))
#define READ16(address)             ((UINT16)(*(VUINT16*)(address)))
#define SET16(address, value)       (*(VUINT16*)(address) |= (value))
#define CLEAR16(address, value)     (*(VUINT16*)(address) &= ~(value))

#define WRITE32(address, value)     (*(VUINT32*)(address) = (value))
#define READ32(address)             ((UINT32)(*(VUINT32*)(address)))
#define SET32(address, value)       (*(VUINT32*)(address) |= (value))
#define CLEAR32(address, value)     (*(VUINT32*)(address) &= ~(value))

#define WRITE64(address, value)     (*(VUINT64*)(address) = (value))
#define READ64(address)             ((UINT64)(*(VUINT64*)(address)))
#define SET64(address, value)       (*(VUINT64*)(address) |= (value))
#define CLEAR64(address, value)     (*(VUINT64*)(address) &= ~(value))


/* macro for 64-bit data comparison*/
#define CREATE_WORD64(high, low)    (VUINT64)((VUINT64)(high) << 32 | (low))
#define CREATE_WORD32(high, low)	(VUINT32)((VUINT32)(high) << 16 | (low))

#if (DATA_FLASH_OPT == FLASH_SELECT)
	#define CREATE_STATUS(high, low)	CREATE_WORD32(high, low)
	#define READ_STATUS(address)		READ32(address)	
#else
	#define CREATE_STATUS(high, low)	CREATE_WORD64(high, low)
	#define READ_STATUS(address)		READ64(address)
#endif

#define NULL_CALLBACK				(void*)0xFFFFFFFF

#if (2 == BANK_NUMBER)
	#define START_LAS_BANK1				0x00040000      /* Start address of LAS bank 1 */
	#define END_LAS_BANK1				0x0007FFFF
	#define REGBASE_OFFSET_BANK1    	0x00028000      /* BANK1 register base offset */
#endif	
		
#if (DATA_FLASH_OPT == FLASH_SELECT)
	/* data record status state */
	#define ERASED_HIGH                     0xFFFF
	#define ERASED_LOW                      0xFFFF
	#define PROGRAM_IDSIZE_HIGH             0xFF00
	#define PROGRAM_IDSIZE_LOW              0xFF00
	#define PROGRAM_COMPLETE_HIGH           0xFF00
	#define PROGRAM_COMPLETE_LOW            0x0000
	#define DELETE_HIGH                     0x0000
	#define DELETE_LOW                      0x0000
	/* block status state */
	#define ALTERNATIVE_HIGH                0xFFFF
	#define ALTERNATIVE_LOW                 0xFFFF
	#define COPY_START_HIGH                 0x0000
	#define COPY_START_LOW                  0xFFFF
	#define ACTIVE_HIGH                     0x0000
	#define ACTIVE_LOW                      0x0000
	#define UNKNOWN_HIGH					0xAAAA
	#define UNKNOWN_LOW						0xAAAA	
#else
	/* data record status state */
	#define ERASED_HIGH                     0xFFFFFFFF
	#define ERASED_LOW                      0xFFFFFFFF
	#define PROGRAM_IDSIZE_HIGH             0xFFFF0000
	#define PROGRAM_IDSIZE_LOW              0xFFFF0000
	#define PROGRAM_COMPLETE_HIGH           0xFFFF0000
	#define PROGRAM_COMPLETE_LOW            0x00000000
	#define DELETE_HIGH                     0x00000000
	#define DELETE_LOW                      0x00000000
	/* block status state */
	#define ALTERNATIVE_HIGH                0xFFFFFFFF
	#define ALTERNATIVE_LOW                 0xFFFFFFFF
	#define COPY_START_HIGH                 0x00000000
	#define COPY_START_LOW                  0xFFFFFFFF
	#define ACTIVE_HIGH                     0x00000000
	#define ACTIVE_LOW                      0x00000000
	#define UNKNOWN_HIGH					0xAAAAAAAA
	#define UNKNOWN_LOW						0xAAAAAAAA
#endif

/* data record status state */
#define RECORD_STATUS_ERASED            CREATE_STATUS(ERASED_HIGH, ERASED_LOW)
#define RECORD_STATUS_PROGRAM_IDSIZE    CREATE_STATUS(PROGRAM_IDSIZE_HIGH, PROGRAM_IDSIZE_LOW)
#define RECORD_STATUS_PROGRAM_COMPLETE  CREATE_STATUS(PROGRAM_COMPLETE_HIGH, PROGRAM_COMPLETE_LOW)
#define RECORD_STATUS_DELETE            CREATE_STATUS(DELETE_HIGH, DELETE_LOW)
/* block status state */
#define BLOCK_STATUS_ALTERNATIVE        CREATE_STATUS(ALTERNATIVE_HIGH, ALTERNATIVE_LOW)
#define BLOCK_STATUS_COPY_START         CREATE_STATUS(COPY_START_HIGH, COPY_START_LOW)
#define BLOCK_STATUS_ACTIVE             CREATE_STATUS(ACTIVE_HIGH, ACTIVE_LOW)
#define DATA_INFO												BLOCK_STATUS_COPY_START
#define BLOCK_STATUS_UNKNOWN						CREATE_STATUS(UNKNOWN_HIGH, UNKNOWN_LOW)
	
/* const definition */
#define DATAID_SIZE                 2
#define CTABLE_ITEM_SIZE            4

#if(DATA_FLASH_OPT == FLASH_SELECT)
	#define ECC_SIZE									4
	#define PROGRAMMABLE_SIZE       	4
	#define RECORD_HEAD_SIZE					8 /* Change from HEAD_SIZE to RECORD_HEAD_SIZE */
	
	#if (VAR_LENGTH == LENGTH_TYPE)	
	#define HEAD_DATA_SIZE						0
	#else	
	#define HEAD_DATA_SIZE						2
	#endif
	
	#define ERASE_CYCLE_OFFSET		PROGRAMMABLE_SIZE
	#define PROGRAMMABLE_DEL		BLOCK_STATUS_ALTERNATIVE
	#define DATA_INFO_OFFSET		(ERASE_CYCLE_OFFSET + PROGRAMMABLE_SIZE)
    #define READ_PROGRAMMABLE_SIZE(address) FSL_FlashRead32(address)
    #define WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, address, source, CallBack) FSL_ProgramWord(c90lcRegBase, address, source, CallBack)
    #define GET_C90LCREGBASE(eepromConfig, address, c90lcRegBase) (c90lcRegBase = eepromConfig->c90lcRegBase)
    
#else /* FLASH_SELECT == DATA_FLASH or CODE_FLASH */
	#define ECC_SIZE								16
	#define PROGRAMMABLE_SIZE       8
	
	#if (VAR_LENGTH == LENGTH_TYPE)
	#define RECORD_HEAD_SIZE				32 /* Change from HEAD_SIZE to RECORD_HEAD_SIZE */
	#define HEAD_DATA_SIZE					20
	#else
	#define RECORD_HEAD_SIZE				16 
	#define HEAD_DATA_SIZE					6
	#endif
	
	#define ERASE_CYCLE_OFFSET		(2*PROGRAMMABLE_SIZE)
	#define PROGRAMMABLE_DEL		BLOCK_STATUS_ALTERNATIVE
	#define DATA_INFO_OFFSET		(ERASE_CYCLE_OFFSET + PROGRAMMABLE_SIZE)	
    #define READ_PROGRAMMABLE_SIZE(address) FSL_FlashRead64(address)
    #define WRITE_PROGRAMMABLE_SIZE(c90lcRegBase, address, source, CallBack) FSL_ProgramDoubleWord(c90lcRegBase, address, source, CallBack)
    
#if (2 == BANK_NUMBER)
    #define GET_C90LCREGBASE(eepromConfig, address, c90lcRegBase)	\
		if( ( address >= START_LAS_BANK1 ) && ( address <= END_LAS_BANK1 ) )  \
    	{   \
    		c90lcRegBase = eepromConfig->c90lcRegBase + REGBASE_OFFSET_BANK1;   \
    	}else \
    	{ \
    		c90lcRegBase = eepromConfig->c90lcRegBase; \
    	}
#else
	#define GET_C90LCREGBASE(eepromConfig, address, c90lcRegBase)	(c90lcRegBase = eepromConfig->c90lcRegBase)
#endif /*(2 == BANK_NUMBER)*/
#endif /*(DATA_FLASH_OPT == FLASH_SELECT)*/

#define RECORD_OFFSET				(DATA_INFO_OFFSET + PROGRAMMABLE_SIZE)

#define WORD_SIZE                   4
#define DWORD_SIZE                  8
#define PAGE_SIZE                   16

/*******************************************************************
| function prototypes (scope: module-local)
|------------------------------------------------------------------*/
/* function declarations */
/* flash driver functions */
UINT32 FSL_FlashProgramStart (UINT32 c9lcRegBase, UINT32* dest, UINT16* size, UINT32* source);
UINT32 FSL_FlashEraseStart (UINT32 c9lcRegBase, UINT32 interlockWriteAddress, UINT32 lowEnabledBlock, UINT32 midEnabledBlock, UINT32 highEnabledBlock);
UINT32 FSL_FlashCheckStatus (UINT32 c9lcRegBase);
UINT32 FSL_DataVerify (UINT32 c9lcRegBase, BOOL blankCheck, UINT32* dest, UINT32* size, UINT32* source, UINT32 *compareAddress, PROGRAMMABLE_TYPE *compareData, void(*CallBack)(void));
UINT32 FSL_FlashRead (UINT32 c9lcRegBase, UINT32* dest, UINT32* size, UINT32* buffer, void(*CallBack)(void));

/* low level functions */
UINT32 FSL_FlashReadStatus(BLOCK_CONFIG* blockConf, UINT32 c90lcRegBase, BLOCK_STATUS* blockStatus);
UINT32 FSL_SearchRecordInBlock (BLOCK_CONFIG* blockConf, UINT32 c9lcRegBase, UINT32 bufferAddress, UINT32 bufferSize, UINT16 startID, UINT32* startAddrInBlock, UINT16* nextStartID, void(*CallBack)(void));
UINT32 FSL_SearchLatestRecordInBlock (BLOCK_CONFIG* blockConf, UINT32 c9lcRegBase, UINT16 recordID, UINT32 *recordAddr, void(*CallBack)(void));
UINT8 FSL_FlashRead8(UINT32 address);
UINT32 FSL_FlashRead32(UINT32 address);
UINT64 FSL_FlashRead64(UINT32 address);
void FSL_ReadRecordHead(UINT32 address, DATA_RECORD_HEAD *pLocRecHead);
UINT32 EER_exception_handler(UINT32 return_address, UINT16 instruction);
void cRestoreEei(UINT32 );
UINT32 cReadAndClearEei(void);
BOOL FSL_AbortHVOP(UINT32 c90lcRegBase);

/* middle level functions */
UINT32 FSL_SearchInTable (CACHE_TABLE* cTable, UINT16 dataID, UINT32* expDataAddress);
UINT32 FSL_SearchInBlock (BLOCK_CONFIG* blockConf, UINT32 c9lcRegBase, UINT16 dataID, UINT32* expDataInBlock, void(*CallBack)(void));
UINT32 FSL_RecordBuffering (BLOCK_CONFIG* blockConf, UINT32 c9lcRegBase, UINT32 bufferAddress, UINT32 bufferSize, UINT16* startID, void(*CallBack)(void));
UINT32 FSL_ProgramWord (UINT32 c9lcRegBase, UINT32 address, UINT32 data, void(*CallBack)(void));
UINT32 FSL_ProgramDoubleWord (UINT32 c9lcRegBase, UINT32 address, UINT64 data, void(*CallBack)(void));
UINT32 FSL_CopyDataRecord (BLOCK_CONFIG* blockConf, UINT32 c9lcRegBase, UINT16 dataID, UINT16 dataSize, UINT32 source, UINT32 dest, void(*CallBack)(void));
BOOL FSL_UpdateCacheTable(CACHE_TABLE* cTable, UINT16 dataID, UINT32 newValue);
UINT32 FSL_BlockSwapping(EEPROM_CONFIG* eepromConfig, void(*CallBack)(void));
UINT32 FSL_EraseEEBlock(UINT32 c9lcRegBase, BLOCK_CONFIG* blockConf, void(*CallBack)(void));

/* high level functions */
UINT32 FSL_InitEeprom(EEPROM_CONFIG* eepromConfig, void(*CallBack)(void));
UINT32 FSL_ReadEeprom(EEPROM_CONFIG* eepromConfig, UINT16 dataID, UINT16 dataSize, UINT32 source, void(*CallBack)(void));
UINT32 FSL_WriteEeprom (EEPROM_CONFIG* eepromConfig, UINT16 dataID, UINT16 dataSize, UINT32 source, void(*CallBack)(void));
UINT32 FSL_DeleteRecord(EEPROM_CONFIG* eepromConfig, UINT16 dataID, void(*CallBack)(void));
UINT32 FSL_RemoveEeprom(EEPROM_CONFIG* eepromConfig, void(*CallBack)(void));
UINT32 FSL_ReportEepromStatus(EEPROM_CONFIG* eepromConfig, PROGRAMMABLE_TYPE* erasingCycles, UINT32* blankAddress, void(*CallBack)(void));
void FSL_MainFunction( EEPROM_CONFIG* eepromConfig, void(*CallBack)(void) );

#endif /*_EE_EMULATION_H_*/
