#ifndef _EXC_H_
#define _EXC_H_


#define EXC_KI   2
#define EXC_KP   5
#define EXC_TH   2800




extern void EXCLoopInit(void);
extern void EXCLoop(void);
extern void EXCCurCalc(void);

extern uint8  EXC_CurReqIdx;
extern const uint16 EXC_SpdDIVVolt[20];










#endif