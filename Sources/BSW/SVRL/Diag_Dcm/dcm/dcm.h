
#ifndef DCM_H
#define DCM_H

#include "diag.h"
#include "dem.h"
#include "dcm_cbk.h"



// PidServices_<PID>
typedef Std_ReturnType (*Dcm_CallbackGetPIDValueFncType)(uint8 *dataValueBuffer);
// InfoTypeServices_<INFOTYPENUMBER>
typedef Std_ReturnType (*Dcm_CallbackGetInfoTypeValueFncType)(uint8 *dataValueBuffer);

typedef Std_ReturnType (*Dcm_CallbackGetPIDFreezeframeDataFncType)(uint8 *dataValueBuffer);

typedef struct {
	uint8							DspPidIdentifier;	// (1)	/** @req DCM627 */
	uint8							DspPidSize; 		// (1)	/** @req DCM628 */
	Dcm_CallbackGetPIDValueFncType	DspGetPidValFnc;	// (1)	/** @req DCM629 */
	boolean						DspIsFreezeframePid;
	Dcm_CallbackGetPIDFreezeframeDataFncType DspGetPidFreezeframeDataFnc;
	boolean							Arc_EOL;
} Dcm_DspPidType; /** @req DCM626 */


typedef struct {
	uint8								DspVehInfoType;			// (1)	/** @req DCM631 */
	uint8								DspVehInfoSize;			// (1)	/** @req DCM632 */
	uint8								DspVehInfoNumberOfDataItems;
	Dcm_CallbackGetInfoTypeValueFncType	DspGetVehInfoTypeFnc;	// (1)	/** @req DCM633 */
	boolean Arc_EOL;
} Dcm_DspVehInfoType; /** @req DCM630 */




//extern uint32_t Gpt_GetCurrentCnt();
extern void Dcm_SetNegResponse(uint8_t errorCode);





/* -- Functon Declar of OBD -- */
extern void ObdRequestCurrentPowertrainDiagnosticData(void);
extern void DspObdRequsetPowertrainFreezeFrameData(void);
extern void Dcm_ApplReadEmissionConfirmedDTC(void);
extern void Dcm_ApplClrEmmisionDigInfo(void);
extern void Dcm_ApplReadEmissionDTCDuringCurrentOrLastCycle(void);
extern void DspObdRequestvehicleinformation(void);





#endif /* #ifndef DCM_H */
