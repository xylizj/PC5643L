/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Compiler_Cfg.h                                                **
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
**  PURPOSE   : Configuration file for memory and pointer classes             **
**              Each module can define those classes as macros and pass       **
**              to the compiler abstraction macros defined in Compiler.h      **
**                                                                            **
**  REMARKS   : Version control and support provided by BMW Group             **
**              AUTOSAR SWS Compiler Abstraction version: 0.9.6               **
**                                                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Company                            **
** --------     -------------------------  ---------------------------------- **
** cma          Christoph Mueller-Albrecht BMW Group                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*
 * V2.1.0:  27.03.2006, cma  : Initial revision based on MICRON input
 */

#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

#include <string.h>

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/


/*******************************************************************************
**                      Configuration data                                    **
*******************************************************************************/
/*
 * The following memory and pointer classes can be configured per module.
 * Those defines are passed to the compiler abstraction macros in Compiler.h
 *
 * Note:
 * module internal functions (statics) that get into one section
 * (together with API) shall fit into one page, if __near
 */

/* -------------------------------------------------------------------------- */
/*            OS (Operating System)                                           */
/* -------------------------------------------------------------------------- */
#define OS_VECTORTABLE  



#endif /* COMPILER_CFG_H */
