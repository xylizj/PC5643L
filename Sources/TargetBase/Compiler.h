/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Compiler.h                                                    **
**                                                                            **
**  Copyright (C) none (open standard)                                        **
**                                                                            **
**  TARGET    : S12X                                                          **
**                                                                            **
**  COMPILER  : Metrowerks 5.0.28                                             **
**                                                                            **
**  PROJECT   : AUTOSAR Demonstrator R2, BMW Standard Core 6                  **
**                                                                            **
**  AUTHOR    : Christoph Mueller-Albrecht                                    **
**                                                                            **
**  PURPOSE   : Provider of compiler specific (non-ANSI) keywords.            **
**              All mappings of keywords which are  not standardized and/or   **
**              compiler specific shall be placed  and organized in this      **
**              compiler specific header. The file is  needed to decouple     **
**              the code of all standard core components from compiler        **
**              topics and thus enhance portability.                          **
**                                                                            **
**  REMARKS   : Version control and support provided by BMW Group             **
**              AUTOSAR SWS Compiler Abstraction version: 0.9.6               **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** fer          Robert Feist               BMW Group                          **
** cma          Christoph Mueller-Albrecht BMW Group                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.0:  27.03.2006, cma  : AUTOSAR Compiler Abstraction V0.9.6 implemented
 *                             based on MICRON input
 * V2.0.0:  10.03.2005, fer  : defines ROM_MEM, _STATIC_ and NULL_PTR added
 *                             block comments added (**), released
 */

#ifndef COMPILER_H 
#define COMPILER_H  

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Compiler_Cfg.h"    /* Module specific memory and pointer classes    */


/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*
 * File version information
 */
#define COMPILER_MAJOR_VERSION  2
#define COMPILER_MINOR_VERSION  1
#define COMPILER_PATCH_VERSION  0


/*
 * Compiler abstraction symbols
 */
#define ROM_MEM   const
#define _STATIC_  static

#ifndef NULL_PTR
   #define NULL_PTR  ((void *)0)                       
#endif


/* AUTOMATIC used for the declaration of local pointers */
#define AUTOMATIC

/* used as an empty memory class */
#define TYPEDEF

#define IOA_CODE
#define IIC_CODE	

//added by xyl 2015.5.26
/*****************************************************************
*           DCM                               
******************************************************************/
#define DCM_CODE
#define DCM_CODE_NEAR 

#define DCM_CONST     

#define DCM_VAR       

#define DCM_APPL_DATA 
/*****************************************************************
*           DEM                               
******************************************************************/
#define DEM_CODE
#define DEM_CODE_NEAR 

#define DEM_CONST     

#define DEM_VAR       

#define DEM_APPL_DATA 

#define DEM_VAR_FAR     


/* Type definition of pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
#define P2FUNC(rettype, ptrclass, fctname) rettype (* ptrclass fctname)

/* Type definition of const pointers to functions
   rettype     return type of the function
   ptrclass    defines the classification of the pointer's distance
   fctname     function name respectivly name of the defined type
 */
#define CONSTP2FUNC(rettype, ptrclass, fctname) rettype (* const ptrclass fctname)

/* The compiler abstraction shall define the FUNC macro for the declaration and
   definition of functions, that ensures correct syntax of function declarations
   as required by a specific compiler. - used for API functions
   rettype     return type of the function
   memclass    classification of the function itself
 */
#define FUNC(type, memclass) type memclass

/* Pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype memclass * ptrclass

/* Pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype memclass * ptrclass

/* Const pointer to variable data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype memclass * const ptrclass

/* Const pointer to constant data
   ptrtype     type of the referenced data
   memclass    classification of the pointer's variable itself
   ptrclass    defines the classification of the pointer's distance
 */
#define CONSTP2CONST(ptrtype, memclass, ptrclass) const ptrtype memclass * const ptrclass

/* ROM constant
   type        type of the constant
   memclass    classification of the constant
 */
#define CONST(type, memclass) const type memclass 

/* RAM variables
   type        type of the variable
   memclass    classification of the variable
 */
#define VAR(type, memclass) type memclass


/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

                                
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/


/*******************************************************************************
**                      Global Function Prototypes                            **
*******************************************************************************/
/*--------------------------------------------------------------------*/
/*!  \brief Macro substitutions of ansi c memory management
            NOTE: If a compiler do not support memory management
                  these macros must be replaced against own           */
/*--------------------------------------------------------------------*/
/*! substitute memory copy */
# define MemCpy(a, b, c)    memcpy(a, b, c)
/*! substitute memory set */
# define MemSet(a, b, c)    memset(a, b, c)
/*! substitute memory compare */
# define MemCmp(a, b, c)    memcmp(a, b, c)

#endif /* COMPILER_H */
