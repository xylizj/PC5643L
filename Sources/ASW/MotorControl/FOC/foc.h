#ifndef _FOC_H_
#define _FOC_H_

#include "Std_Types.h"
#include "typedefs.h"
#include "SWLIBS_Typedefs.h"
#include "SWLIBS_Defines.h"

#include "MPC5643L.h"


#include "GDFLIB_FilterIIR1.h"

#include "GFLIB_Cos.h"
#include "GFLIB_Sin.h"
#include "GFLIB_Ramp.h"
#include "GFLIB_ControllerPIrAW.h"
#include "GFLIB_ControllerPIpAW.h"
#include "GFLIB_Sqrt.h"

#include "GMCLIB_Clark.h"
#include "GMCLIB_Park.h"
#include "GMCLIB_ParkInv.h"
#include "GMCLIB_ElimDcBusRip.h"
#include "GMCLIB_SvmStd.h"

#define  MAX_PHASE_CUR   300000 //mA

#define  D_CUR_ERR_DEADZONE   0 //mA
#define  Q_CUR_ERR_DEADZONE   0 //mA

#define  MAX_DC_VOLT     60000  //mV

#define D_VOLTAGE_REQ_THREHOLD (((1000<<14)/MAX_DC_VOLT)<<17)//10V
#define Q_VOLTAGE_REQ_THREHOLD (((2000<<14)/MAX_DC_VOLT)<<17)//3V


//#define CURRENT_OPEN_LOOP


typedef struct{
    uint16    s16sub0;
    uint16    s16sub1;
    uint16    s16sub2;
    uint16    s16sub3;
}FLEXPWM_VAL_COMPL;


extern sint32 s32_hMDRV_thRotEl;
extern SWLIBS_2Syst   stc_hMDRV_thSinCos;
extern SWLIBS_2Syst   stc_hMDRV_iAlBeFbck;
extern SWLIBS_2Syst   stc_hMDRV_iDQFbck;
extern SWLIBS_2Syst   stc_hMDRV_iDQReqZC;
extern SWLIBS_2Syst   stc_hMDRV_iDQReq;
extern SWLIBS_2Syst   stc_hMDRV_iDQErr;

extern SWLIBS_2Syst   stc_hMDRV_uDQLimit; 
extern SWLIBS_2Syst   stc_hMDRV_uDQReq;
extern SWLIBS_2Syst   stc_hMDRV_uAlBeReq;
extern SWLIBS_2Syst   stc_hMDRV_uAlBeReqDCB;

extern SWLIBS_3Syst   stc_hMDRV_uABC;
extern sint32 s32_hMDRV_svmSector;


extern FLEXPWM_VAL_COMPL   stc_hMDRV_pwmAbc; 
  
extern GFLIB_CONTROLLER_PIAW_R_T_F32  stc_hMDRV_dAxisPI;
extern GFLIB_CONTROLLER_PIAW_R_T_F32  stc_hMDRV_qAxisPI;



extern GDFLIB_FILTER_IIR1_T_F32 Clb_stc_hMDRV_dAxisZC; 

extern GDFLIB_FILTER_IIR1_T_F32 Clb_stc_hMDRV_qAxisZC;


extern GMCLIB_ELIMDCBUSRIP_T_F32 stc_hMDRV_elimDcbRip;

extern sint16 FlexPWM_INIT_sub0;

extern void focFastLoopInit(void);
extern boolean focFastLoop(void);
extern void CurD_Req_Ramp(void);
extern void CurQ_Req_Ramp(void);






//#define PN_MEASURE_PI_Q
//#define PN_MEASURE_PI_D

#ifdef PN_MEASURE_PI_Q
#ifdef PN_MEASURE_PI_D
#undef PN_MEASURE_PI_D
#endif
#endif


//#define PI_PAR_CHECK

#ifdef PI_PAR_CHECK
#undef PN_MEASURE_PI_Q
#undef PN_MEASURE_PI_D
#endif





#endif