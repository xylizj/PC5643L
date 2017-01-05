/*******************************************************************************
*
*  FILE
*     Std_Types.h
*
*  DESCRIPTION
*     Provision of Standard Types  
*      
*       
*  COPYRIGHT
*     (c)Copyright 2008, Wuhan Eureka Control System Co., Ltd. 
*     All rights reserved.
*
*  AUTHOR
*    Gu Bin
*
*  VERSION
*    0.31
*
*******************************************************************************/

/*******************************************************************************
*                      Revision  History 
*                              
*   V0.31   20.11.2008  Gu Bin:  consider the byte order for struct type 
*                                  bit32, bit16
*******************************************************************************/

#ifndef __STD_TYPES_H__ 
#define __STD_TYPES_H__ 

/*******************************************************************************
**                      Include Section                                       **                                                                            **
*******************************************************************************/

#include "Compiler.h"                   /* mapping compiler specific keywords */
#include "Platform_Types.h"             /* platform specific type definitions */

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*
  File version information
*/
#define STD_MAJOR_VERSION  2
#define STD_MINOR_VERSION  3
#define STD_PATCH_VERSION  0


/*******************************************************************************
**                      Global Data Types                                     **  
*******************************************************************************/

#  if (CPU_BIT_ORDER == LSB_FIRST )
struct bits8
{
  bittype  b0:1;  /* LSB-Bits (lower adr!) */
  bittype  b1:1;
  bittype  b2:1;
  bittype  b3:1;
  bittype  b4:1;
  bittype  b5:1;
  bittype  b6:1;
  bittype  b7:1;  /* MSB-Bits (higher address) unused */
};
 
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)

struct bits16 
{
  bittype  b10:1; /* higher adr */
  bittype  b11:1;
  bittype  b12:1;
  bittype  b13:1;
  bittype  b14:1;
  bittype  b15:1;
  bittype  b16:1;
  bittype  b17:1;

  bittype  b0:1;  /* lower adr */
  bittype  b1:1;
  bittype  b2:1;
  bittype  b3:1;
  bittype  b4:1;
  bittype  b5:1;
  bittype  b6:1;
  bittype  b7:1;
};

struct bits32 
{
  bittype  b30:1; /* higher adr */
  bittype  b31:1;
  bittype  b32:1;
  bittype  b33:1;
  bittype  b34:1;
  bittype  b35:1;
  bittype  b36:1;
  bittype  b37:1;

  bittype  b20:1; /* mid high adr */
  bittype  b21:1;
  bittype  b22:1;
  bittype  b23:1;
  bittype  b24:1;
  bittype  b25:1;
  bittype  b26:1;
  bittype  b27:1;

  bittype  b10:1; /* mid low adr */
  bittype  b11:1;
  bittype  b12:1;
  bittype  b13:1;
  bittype  b14:1;
  bittype  b15:1;
  bittype  b16:1;
  bittype  b17:1;
    
  bittype  b0:1;  /* lower adr */
  bittype  b1:1;
  bittype  b2:1;
  bittype  b3:1;
  bittype  b4:1;
  bittype  b5:1;
  bittype  b6:1;
  bittype  b7:1;
};

#else
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
 
struct bits16 
{
  bittype  b0:1;  /* lower adr */
  bittype  b1:1;
  bittype  b2:1;
  bittype  b3:1;
  bittype  b4:1;
  bittype  b5:1;
  bittype  b6:1;
  bittype  b7:1;

  bittype  b10:1; /* higher adr */
  bittype  b11:1;
  bittype  b12:1;
  bittype  b13:1;
  bittype  b14:1;
  bittype  b15:1;
  bittype  b16:1;
  bittype  b17:1;
};

struct bits32 
{
  bittype  b0:1;  /* lower adr */
  bittype  b1:1;
  bittype  b2:1;
  bittype  b3:1;
  bittype  b4:1;
  bittype  b5:1;
  bittype  b6:1;
  bittype  b7:1;

  bittype  b10:1; /* mid low adr */
  bittype  b11:1;
  bittype  b12:1;
  bittype  b13:1;
  bittype  b14:1;
  bittype  b15:1;
  bittype  b16:1;
  bittype  b17:1;

  bittype  b20:1; /* mid high adr */
  bittype  b21:1;
  bittype  b22:1;
  bittype  b23:1;
  bittype  b24:1;
  bittype  b25:1;
  bittype  b26:1;
  bittype  b27:1;

  bittype  b30:1; /* higher adr */
  bittype  b31:1;
  bittype  b32:1;
  bittype  b33:1;
  bittype  b34:1;
  bittype  b35:1;
  bittype  b36:1;
  bittype  b37:1;
};
#else
#error " Byteorder unknown"
# endif  /* LOW_BYTE_FIRST */
#endif  /* HIGH_BYTE_FIRST */
# else /* MSB_FIRST */
#  if (CPU_BIT_ORDER == MSB_FIRST )
struct bits8         
{
  bittype  b7:1;  /* MSB-Bits (Higher addr!) */
  bittype  b6:1;
  bittype  b5:1;
  bittype  b4:1;
  bittype  b3:1;
  bittype  b2:1;
  bittype  b1:1;
  bittype  b0:1;  /* LSB-Bits (higher address) unused */
};

#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)

struct bits16 
{
  bittype  b17:1;  /* higher adr */
  bittype  b16:1;
  bittype  b15:1;
  bittype  b14:1;
  bittype  b13:1;
  bittype  b12:1;
  bittype  b11:1;
  bittype  b10:1;

  bittype  b7:1;   /* lower adr */
  bittype  b6:1;
  bittype  b5:1;
  bittype  b4:1;
  bittype  b3:1;
  bittype  b2:1;
  bittype  b1:1;
  bittype  b0:1;
};

struct bits32 
{
  bittype  b37:1;  /* higher adr */
  bittype  b36:1;
  bittype  b35:1;
  bittype  b34:1;
  bittype  b33:1;
  bittype  b32:1;
  bittype  b31:1;
  bittype  b30:1;

  bittype  b27:1;  /* mid high adr */
  bittype  b26:1;
  bittype  b25:1;
  bittype  b24:1;
  bittype  b23:1;
  bittype  b22:1;
  bittype  b21:1;
  bittype  b20:1;
  
  bittype  b17:1;  /* mid low adr */
  bittype  b16:1;
  bittype  b15:1;
  bittype  b14:1;
  bittype  b13:1;
  bittype  b12:1;
  bittype  b11:1;
  bittype  b10:1;
      
  bittype  b7:1;   /* lower adr */
  bittype  b6:1;
  bittype  b5:1;
  bittype  b4:1;
  bittype  b3:1;
  bittype  b2:1;
  bittype  b1:1;
  bittype  b0:1;
};

#else  /* HIGH_BYTE_FIRST */
#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)

struct bits16 
{
  bittype  b7:1;   /* lower adr */
  bittype  b6:1;
  bittype  b5:1;
  bittype  b4:1;
  bittype  b3:1;
  bittype  b2:1;
  bittype  b1:1;
  bittype  b0:1;

  bittype  b17:1;  /* higher adr */
  bittype  b16:1;
  bittype  b15:1;
  bittype  b14:1;
  bittype  b13:1;
  bittype  b12:1;
  bittype  b11:1;
  bittype  b10:1;
};


struct bits32 
{
  bittype  b7:1;   /* lower adr */
  bittype  b6:1;
  bittype  b5:1;
  bittype  b4:1;
  bittype  b3:1;
  bittype  b2:1;
  bittype  b1:1;
  bittype  b0:1;

  bittype  b17:1;  /* mid low adr */
  bittype  b16:1;
  bittype  b15:1;
  bittype  b14:1;
  bittype  b13:1;
  bittype  b12:1;
  bittype  b11:1;
  bittype  b10:1;

  bittype  b27:1;  /* mid high adr */
  bittype  b26:1;
  bittype  b25:1;
  bittype  b24:1;
  bittype  b23:1;
  bittype  b22:1;
  bittype  b21:1;
  bittype  b20:1;

  bittype  b37:1;  /* higher adr */
  bittype  b36:1;
  bittype  b35:1;
  bittype  b34:1;
  bittype  b33:1;
  bittype  b32:1;
  bittype  b31:1;
  bittype  b30:1;
};

#else
#error "Byteorder unknow"
# endif /* LOW_BYTE_FIRST */
#endif /* HIGH_BYTE_FIRST */

#  else
#  error "Bitorder unknown "
#  endif /* MSB_FIRST */
# endif  /* LSB_FIRST */



/* for OSEK compliance this typedef has been added */
#ifndef STATUSTYPEDEFINED 
  #define STATUSTYPEDEFINED 

  typedef unsigned char StatusType; 
  #define E_OK    0

#endif

/*
  The Std_ReturnType may be used with the following values:
  E_OK:     0
  E_NOT_OK: 1
*/
typedef uint8 Std_ReturnType;
#define E_NOT_OK  1


#define STD_HIGH    1  /* Physical state 5V or 3.3V */
#define STD_LOW     0  /* Physical state 0V         */

#define STD_ACTIVE  1  /* Logical state active      */
#define STD_IDLE    0  /* Logical state idle        */

#define STD_ON  		1  /* Logical state active      */
#define STD_OFF    	0  /* Logical state idle        */
/*--------------------------------------------------------------------*/
/*  type definitions                                                  */
/*--------------------------------------------------------------------*/



/*! 64 bits basic type */
typedef struct {
  uint32 hw; /*!< most significant double  */
  uint32 lw; /*!< least significant double */
}
QWORD;

/*!
  two bytes structure
*/

typedef struct {
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint8 lb; /*!< least significant uint8 */
  uint8 mb; /*!< most significant uint8  */
# else
  uint8 mb; /*!< most significant uint8  */
  uint8 lb; /*!< least significant uint8 */
# endif /* _BIG_ENDIAN */
}
DBYTE;
/*!
  two uint8 structure for machine independent word conversion
*/

typedef union {
  uint16  wc; /*!< word             */
  DBYTE bc; /*!< two single bytes */
}
WBYTE;
/*!
  four bytes structure
*/

typedef struct {
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint8 b0; /*!< low word / least significant uint8  */
  uint8 b1; /*!< low word / most significant uint8   */
  uint8 b2; /*!< high word / least significant uint8 */
  uint8 b3; /*!< high word / most significant uint8  */
# else
  uint8 b3; /*!< high word / most significant uint8  */
  uint8 b2; /*!< high word / least significant uint8 */
  uint8 b1; /*!< low word / most significant uint8   */
  uint8 b0; /*!< low word / least significant uint8  */
# endif /* _BIG_ENDIAN == 1 */
}
FOURBYTE;


typedef struct {
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint16 w0; /*!< low word / least significant uint8  */
  uint16 w1; /*!< low word / most significant uint8   */
# else
  uint16 w1; /*!< low word / most significant uint8   */
  uint16 w0; /*!< low word / least significant uint8  */
# endif /* _BIG_ENDIAN == 1 */
}
DWORD;

/*!
  four uint8 structure for machine independent long conversion
*/
typedef union {
  uint32 dw;
  DWORD w;     /*!< long value          */
  FOURBYTE fb;  /*!< splitted long value */
}
QBYTE;

typedef union
{
	uint16	wData;
	DBYTE Bytes;
}CWORD;

/* Converted long word structure */		
typedef union
{
	uint32	lData;
	FOURBYTE Bytes;
	struct bits32   bits;
}CLONG;

typedef struct
{
   uint16 vendorID;
   uint8 moduleID;
   uint8 sw_major_version;
   uint8 sw_minor_version;
   uint8 sw_patch_version;
}Std_VersionInfoType;
#endif  /* STD_TYPES_H */
