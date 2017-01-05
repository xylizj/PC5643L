/*******************************************************************************
*
*  FILE
*     Ioa_Types.h
*
*  DESCRIPTION
*     The data type definition Header file for IO abstraction
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
*    0.01
*
*******************************************************************************/

#ifndef _IOA_TYPES_H_
#define _IOA_TYPES_H_

/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Std_Types.h"

/*******************************************************************************
* Defines                                                                
*******************************************************************************/
/* Named constants for Stateflow: '<S6>/On_Off_Valve_Diag' */
#define IN_Defect                      (1)
#define IN_Defect_ShortToGround        (1)
#define IN_Defect_ShortToPower         (2)
#define IN_NO_ACTIVE_CHILD_n           (0)
#define IN_Try                         (3)
#define IN_Valve_Off                   (2)
#define IN_Valve_On                    (3)
#define IN_Wait                        (4)
#define IN_WaitToHeal                  (5)

/* Named constants for Stateflow: '<S5>/Lamp_Diag' */
#define IN_Lamp_OFF                    (1)
#define IN_Lamp_On                     (2)
#define IN_NON_DEF                     (3)
#define IN_Short_To_Ground             (4)
#define IN_Short_To_Power              (5)

#define IOA_DEF_STG                        1U
#define IOA_DEF_STP                        2U
#define IOA_NON_DEF                        0U

#define IOA_STS_HIGH                    1
#define IOA_STS_LOW                     0


/*#define SWT_ON							0
#define SWT_OFF							1
*/

#define IN_Switch_OFF					1
#define IN_Switch_OFF_Debouncing		2
#define IN_Switch_ON					3
#define IN_Switch_ON_Debouncing			4


typedef struct {
  uint8 VlvDrv_DefSts;               /* '<S6>/On_Off_Valve_Diag' */
  boolean VlvDrv_ShutDwn;            /* '<S6>/On_Off_Valve_Diag' */
} rtB_On_OFF_Vlv_Diag;

/* Block states (auto storage) for system '<S1>/On_OFF_Vlv_Diag' */
typedef struct {
  uint16 counter;                    /* '<S6>/On_Off_Valve_Diag' */
  uint16 is_Defect : 3;                /* '<S6>/On_Off_Valve_Diag' */
  uint16 is_c6_Eureka_Library : 2;     /* '<S6>/On_Off_Valve_Diag' */
  uint16 is_active_c6_Eureka_Library : 1;/* '<S6>/On_Off_Valve_Diag' */
} rtDW_On_OFF_Vlv_Diag;

/* Block signals for system '<S1>/Lmp_Diag' */
typedef struct {
  uint8 Lmp_DefSts;                  /* '<S5>/Lamp_Diag' */
} rtB_Lmp_Diag;

/* Block states (auto storage) for system '<S1>/Lmp_Diag' */
typedef struct {
  uint16 is_c2_Eureka_Library : 3;     /* '<S5>/Lamp_Diag' */
  uint16 is_active_c2_Eureka_Library : 1;/* '<S5>/Lamp_Diag' */
} rtDW_Lmp_Diag;




/* Block states (auto storage) for system '<S266>/IO_Debouncing' */
typedef struct {
	boolean swtDeb;
} rtB_IO_Debouncing_Check;

typedef struct {
	boolean is_active;
	uint8	check_step;
	uint16	localTimer;
} IO_Debouncing_Check_Type;



/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Variables declaration                         
*******************************************************************************/

/*******************************************************************************
* Global functions declaration                         
*******************************************************************************/



#endif /* #ifndef _IOA_TYPES_H_ */