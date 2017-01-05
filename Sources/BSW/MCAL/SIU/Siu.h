#ifndef _SIU_H_
#define _SIU_H_

#include "Std_Types.h"
#include "Siu_Cfg.h"

extern void Siu_Init(void);
extern void Siu_Out(uint16 ch,boolean val);
extern boolean Siu_ReadDI(uint16 ch);


#define SIU_PAD_CONFIG(index, cfg)           (SIU.PCR[index].R =(uint16)cfg)

















#endif/*_SIU_H_*/


