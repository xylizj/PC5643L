#ifndef __CLOCKMODES_H_
#define __CLOCKMODES_H_

#define CGM_ACXSC_IRC16  0
#define CGM_ACXSC_FMPLL0 4
#define CGM_ACXSC_FMPLL1_120 5
#define CGM_ACXSC_FMPLL1_80  8

#define CGM_SELCTL_IRC16   0
#define CGM_SELCTL_XOSC    1
#define CGM_SELCTL_PLL0    2
#define CGM_SELCTL_PLL1_80 3

#define ME_F_RESET_MODE 0
#define ME_TEST_MODE    1
#define ME_SAFE_MODE    2
#define ME_DRUN_MODE    3
#define ME_RUN0_MODE    4
#define ME_RUN1_MODE    5
#define ME_RUN2_MODE    6
#define ME_RUN3_MODE    7
#define ME_HALT0_MODE   8
#define ME_STOP0_MODE   A
#define ME_D_RESET_MODE F  

#define FCCU_CFK_KEY 	0x618B7A50
#define FCCU_NCFK_KEY 	0xAB3498FE 

#define DBGm 	0 
#define DBGzzz 	0x40 

#define LPPC0 	0
#define LPPC1 	8
#define LPPC2 	16
#define LPPC3 	24
#define LPPC4 	32
#define LPPC5 	40
#define LPPC6 	48
#define LPPC7 	56

#define RUNPC0 	0
#define RUNPC1 	1
#define RUNPC2 	2
#define RUNPC3 	3
#define RUNPC4 	4
#define RUNPC5 	5
#define RUNPC6 	6
#define RUNPC7 	7

extern void ConfigAuxilliaryClocks(void);
extern void ConfigPeripherals(void);
extern void ConfigFMPLLs(void);
extern void InitializeModesAndClock(void);
















#endif




