/*******************************************************************************
*
*  FILE
*     ComStack_Types.h
*
*  DESCRIPTION
*     Data type for Communication Stack 
*      
*       
*  COPYRIGHT
*     
*     All rights reserved.
*
*  AUTHOR
*    
*
*  VERSION
*    1.00
*
*******************************************************************************/

#ifndef _COMSTACK_TYPES_H_
#define _COMSTACK_TYPES_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/

#include "Std_Types.h"                  /* standard AUTOSAR types             */


/*******************************************************************************
*                      Global Data Types (ECU dependent)                    
*******************************************************************************/

typedef uint16  PduIdType;     /* Type of PDU ID.
                                    Allowed ranges: uint8 .. uint16 */
typedef uint16  PduLengthType; /* Type of PDU Length.
                                    Allowed ranges: uint8 .. uint32 */

typedef uint8   NotifResultType;


typedef struct                        
{
  uint32*        SduDataPtr;
  PduLengthType SduLength;
}PduInfoType;                        /* Basic information about a PDU of any type*/



typedef enum
{
  BUFREQ_OK       = 0,
  BUFREQ_E_NOT_OK = 1,
  BUFREQ_E_BUSY   = 2,
  BUFREQ_E_OVFL   = 3
}BufReq_ReturnType;


#define NTFRSLT_OK            0
#define NTFRSLT_E_NOT_OK      1
#define NTFRSLT_E_TIMEOUT_A   2


#endif /* _COMSTACK_TYPES_H_ */
