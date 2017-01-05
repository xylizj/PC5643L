/*******************************************************************************
*
*  FILE
*     Platform_types.h
*
*  DESCRIPTION
*     Conform to AUTOSAR 
*     This is the only type should be used in BSW 
* 
*     *_least shall have at least the size given b the type name, but the types
*     shall be implemented in the way that the best performance on the specfic 
*     platform is achieved. "Best performance" is defined in the context as "
*     least processor cycles for variable access as possible" Ex. on a 32 bits
*     MCU, uint8_least is mapped to unsigned long (32 bits) because access to 
*     this type  requires less processor cycle than unsigned char (8 bits)   
*  
*     Note: *_least shall only be used with a local scope inside a module. they
*     are not allowed to be used within the API of a module. 
*
*     Note: It is not allowed to use rollover mechanisms during counting and 
*     shifting. Ex. Maximum loop count = 124 when uint8_least, Switch case 
*     arguments (maximum number of states = 17 when use uint8_least.     
*       
*  COPYRIGHT
*     (c)Copyright 2009, Wuhan Eureka Control System Co., Ltd. 
*     All rights reserved.
*
*  AUTHOR
*    Gu Bin
*
*  VERSION
*    0.01
*
*******************************************************************************/

#ifndef __PLATFORM_TYPES_H__ 
#define __PLATFORM_TYPES_H__ 

#include "MPC5643L.h"

/*******************************************************************************
* include files                                                 
*******************************************************************************/


/*******************************************************************************
* Defines                                                                
*******************************************************************************/
/* 
  CPU register type width
*/
#define CPU_TYPE_8        8                        
#define CPU_TYPE_16       16                        
#define CPU_TYPE_32       32  

/* 
  Bit order definition
*/
#define MSB_FIRST         0                 /* Big endian bit ordering        */
#define LSB_FIRST         1                 /* Little endian bit ordering     */

/* 
  Byte order definition
*/
#define HIGH_BYTE_FIRST   0                 /* Big endian byte ordering       */
#define LOW_BYTE_FIRST    1                 /* Little endian byte ordering    */

/* 
  Word order definition
*/
#define HIGH_WORD_FIRST   0                 /* Big endian word ordering       */
#define LOW_WORD_FIRST    1                 /* Little endian word ordering    */


/*
  Platform type and endianess definitions for MPC5554
*/
#define CPU_TYPE            CPU_TYPE_32
#define CPU_BIT_ORDER       MSB_FIRST
#define CPU_BYTE_ORDER      HIGH_BYTE_FIRST 

/*******************************************************************************
* Types                                                                
*******************************************************************************/

typedef unsigned char       boolean;  

typedef signed char         sint8;          
typedef unsigned char       uint8;          
typedef signed short        sint16;        
typedef unsigned short      uint16;         
/*typedef signed int          sint32;         
typedef unsigned int        uint32;  
typedef unsigned long       uint64;       */
//20160524 xyl
typedef signed long int          sint32;         
typedef unsigned long int        uint32;  
typedef unsigned long long      uint64;       


typedef unsigned long       uint8_least;
typedef unsigned long       uint16_least;
typedef unsigned long       uint32_least;         
typedef signed long         sint8_least;
typedef signed long         sint16_least;
typedef signed long         sint32_least;         

typedef float				float32;
typedef double 				float64;

typedef unsigned char 	    bittype; 	


#ifndef TRUE   
 #define TRUE      1
#endif

#ifndef FALSE                                        
 #define FALSE     0
#endif


/* Extended Definition of Types */

#if (CPU_BIT_ORDER == LSB_FIRST )  
  typedef struct 
  {
    bittype  Bit0:1;  /* LSB-Bits (lower adr!) */
    bittype  Bit1:1;
    bittype  Bit2:1;
    bittype  Bit3:1;
    bittype  Bit4:1;
    bittype  Bit5:1;
    bittype  Bit6:1;
    bittype  Bit7:1;  /* MSB-Bits (higher address)  */
  }Bits8Type;
#else
  typedef struct         
  {
    bittype  Bit7:1;  /* MSB-Bits (higher address)  */
    bittype  Bit6:1;  /* LSB-Bits (lower adr!) */
    bittype  Bit5:1;
    bittype  Bit4:1;
    bittype  Bit3:1;
    bittype  Bit2:1;
    bittype  Bit1:1;
    bittype  Bit0:1;
  }Bits8Type;  
#endif /* #if (CPU_BIT_ORDER == LSB_FIRST )*/  

#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
  #if (CPU_BIT_ORDER == LSB_FIRST)
    typedef struct 
    {
      bittype  Bit8:1; /* higher address */
      bittype  Bit9:1;
      bittype  Bit10:1;
      bittype  Bit11:1;
      bittype  Bit12:1;
      bittype  Bit13:1;
      bittype  Bit14:1;
      bittype  Bit15:1;   

      bittype  Bit0:1;  /* lower adr */
      bittype  Bit1:1;
      bittype  Bit2:1;
      bittype  Bit3:1;
      bittype  Bit4:1;
      bittype  Bit5:1;
      bittype  Bit6:1;
      bittype  Bit7:1;  
    }Bits16Type;
  #else
    typedef struct 
    {
      bittype  Bit15:1;  /* higher adr */
      bittype  Bit14:1;
      bittype  Bit13:1;
      bittype  Bit12:1;
      bittype  Bit11:1;
      bittype  Bit10:1;
      bittype  Bit9:1;
      bittype  Bit8:1;  
      
      bittype  Bit7:1; /* lower address */
      bittype  Bit6:1;
      bittype  Bit5:1;
      bittype  Bit4:1;
      bittype  Bit3:1;
      bittype  Bit2:1;
      bittype  Bit1:1;
      bittype  Bit0:1;   
    }Bits16Type;  
  #endif /* #if (CPU_BIT_ORDER == LSB_FIRST)*/
#else
  #if (CPU_BIT_ORDER == LSB_FIRST) 
    typedef struct 
    {
      bittype  Bit0:1;  /* lower adr */
      bittype  Bit1:1;
      bittype  Bit2:1;
      bittype  Bit3:1;
      bittype  Bit4:1;
      bittype  Bit5:1;
      bittype  Bit6:1;
      bittype  Bit7:1;

      bittype  Bit8:1; /* higher adr */
      bittype  Bit9:1;
      bittype  Bit10:1;
      bittype  Bit11:1;
      bittype  Bit12:1;
      bittype  Bit13:1;
      bittype  Bit14:1;
      bittype  Bit15:1;
    }Bits16Type; 
  #else
    typedef struct 
    {
      bittype  Bit7:1; /* lower address */
      bittype  Bit6:1;
      bittype  Bit5:1;
      bittype  Bit4:1;
      bittype  Bit3:1;
      bittype  Bit2:1;
      bittype  Bit1:1;
      bittype  Bit0:1; 
      
      bittype  Bit15:1;  /* higher adr */
      bittype  Bit14:1;
      bittype  Bit13:1;
      bittype  Bit12:1;
      bittype  Bit11:1;
      bittype  Bit10:1;
      bittype  Bit9:1;
      bittype  Bit8:1;  
    }Bits16Type;    
  #endif      
#endif /* #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) */  

#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
  #if (CPU_BIT_ORDER == LSB_FIRST)
   typedef struct 
    {
      bittype  Bit24:1; /* higher adr */
      bittype  Bit25:1;
      bittype  Bit26:1;
      bittype  Bit27:1;
      bittype  Bit28:1;
      bittype  Bit29:1;
      bittype  Bit30:1;
      bittype  Bit31:1;
      
      bittype  Bit16:1; /* mid high adr */
      bittype  Bit17:1;
      bittype  Bit18:1;
      bittype  Bit19:1;
      bittype  Bit20:1;
      bittype  Bit21:1;
      bittype  Bit22:1;
      bittype  Bit23:1;

      bittype  Bit8:1; /* mid lower adr */
      bittype  Bit9:1;
      bittype  Bit10:1;
      bittype  Bit11:1;
      bittype  Bit12:1;
      bittype  Bit13:1;
      bittype  Bit14:1;
      bittype  Bit15:1;

      bittype  Bit0:1;  /* lower adr */
      bittype  Bit1:1;
      bittype  Bit2:1;
      bittype  Bit3:1;
      bittype  Bit4:1;
      bittype  Bit5:1;
      bittype  Bit6:1;
      bittype  Bit7:1;
    }Bits32Type;
  #else
   typedef struct 
    {
      bittype  Bit31:1; /* higher adr */
      bittype  Bit30:1;
      bittype  Bit29:1;
      bittype  Bit28:1;
      bittype  Bit27:1;
      bittype  Bit26:1;
      bittype  Bit25:1;
      bittype  Bit24:1;
      
      bittype  Bit23:1; /* mid high adr */
      bittype  Bit22:1;
      bittype  Bit21:1;
      bittype  Bit20:1;
      bittype  Bit19:1;
      bittype  Bit18:1;
      bittype  Bit17:1;
      bittype  Bit16:1;

      bittype  Bit15:1; /* mid lower adr */
      bittype  Bit14:1;
      bittype  Bit13:1;
      bittype  Bit12:1;
      bittype  Bit11:1;
      bittype  Bit10:1;
      bittype  Bit9:1;
      bittype  Bit8:1;

      bittype  Bit7:1;  /* lower adr */
      bittype  Bit6:1;
      bittype  Bit5:1;
      bittype  Bit4:1;
      bittype  Bit3:1;
      bittype  Bit2:1;
      bittype  Bit1:1;
      bittype  Bit0:1;
    }Bits32Type;  
  #endif /* #if (CPU_BIT_ORDER == LSB_FIRST)*/
#else /* #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) */
  #if (CPU_BIT_ORDER == LSB_FIRST) 
   typedef struct 
    {
      bittype  Bit0:1;  /* lower adr */
      bittype  Bit1:1;
      bittype  Bit2:1;
      bittype  Bit3:1;
      bittype  Bit4:1;
      bittype  Bit5:1;
      bittype  Bit6:1;
      bittype  Bit7:1;

      bittype  Bit8:1; /* mid lower adr */
      bittype  Bit9:1;
      bittype  Bit10:1;
      bittype  Bit11:1;
      bittype  Bit12:1;
      bittype  Bit13:1;
      bittype  Bit14:1;
      bittype  Bit15:1;

      bittype  Bit16:1; /* mid high adr */
      bittype  Bit17:1;
      bittype  Bit18:1;
      bittype  Bit19:1;
      bittype  Bit20:1;
      bittype  Bit21:1;
      bittype  Bit22:1;
      bittype  Bit23:1;

      bittype  Bit24:1; /* higher adr */
      bittype  Bit25:1;
      bittype  Bit26:1;
      bittype  Bit27:1;
      bittype  Bit28:1;
      bittype  Bit29:1;
      bittype  Bit30:1;
      bittype  Bit31:1;
    }Bits32Type; 
  #else
   typedef struct 
    {
      bittype  Bit7:1;  /* lower adr */
      bittype  Bit6:1;
      bittype  Bit5:1;
      bittype  Bit4:1;
      bittype  Bit3:1;
      bittype  Bit2:1;
      bittype  Bit1:1;
      bittype  Bit0:1;     

      bittype  Bit15:1; /* mid lower adr */
      bittype  Bit14:1;
      bittype  Bit13:1;
      bittype  Bit12:1;
      bittype  Bit11:1;
      bittype  Bit10:1;
      bittype  Bit9:1;
      bittype  Bit8:1;

      bittype  Bit23:1; /* mid high adr */
      bittype  Bit22:1;
      bittype  Bit21:1;
      bittype  Bit20:1;
      bittype  Bit19:1;
      bittype  Bit18:1;
      bittype  Bit17:1;
      bittype  Bit16:1;

      bittype  Bit31:1; /* higher adr */
      bittype  Bit30:1;
      bittype  Bit29:1;
      bittype  Bit28:1;
      bittype  Bit27:1;
      bittype  Bit26:1;
      bittype  Bit25:1;
      bittype  Bit24:1;      
    }Bits32Type;  
  #endif      
#endif /* #if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) */  




typedef struct 
{
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint8 LowByte; /*!< least significant uint8 */
  uint8 HighByte; /*!< most significant uint8  */
# else
  uint8 HighByte; /*!< most significant uint8  */
  uint8 LowByte; /*!< least significant uint8 */
# endif /* _BIG_ENDIAN */
}TwoBytesType;

typedef struct 
{
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint8 Byte0; 
  uint8 Byte1; 
  uint8 Byte2; 
  uint8 Byte3;
# else
  uint8 Byte3; 
  uint8 Byte2;
  uint8 Byte1; 
  uint8 Byte0;
# endif 
}FourBytesType;

typedef struct 
{
# if (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
  uint16 LowWord; /*!< low word / least significant uint8  */
  uint16 HighWord; /*!< low word / most significant uint8   */
# else
  uint16 HighWord; /*!< low word / most significant uint8   */
  uint16 LowWord; /*!< low word / least significant uint8  */
# endif /* _BIG_ENDIAN == 1 */
}TwoWordsType;

typedef union 
{
  uint16  WORD; 
  TwoBytesType Bytes; 
}OneWordUnionType;

typedef union 
{
  uint32 Long;
  TwoWordsType Words;     /*!< long value          */
  FourBytesType Bytes;  /*!< splitted long value */
  Bits32Type Bits;
}OneLongUnionType;

#endif /* __PLATFORM_TYPES_H__ */