#ifndef _AD2S1210_H_
#define _AD2S1210_H_

#include "MPC5643L.h"
#include "DSPI.h"

#define AOD_reg_swt_RslvCS        SIU.GPDO[85].R
#define AOD_reg_swt_RslvSample    SIU.GPDO[84].R
#define AOD_reg_swt_RslvA0        SIU.GPDO[19].R
#define AOD_reg_swt_RslvA1        SIU.GPDO[94].R
#define AOD_reg_swt_RslvRst       SIU.GPDO[18].R

#define AOD_reg_swt_V10En         SIU.GPDO[86].R

#define SID_m_swt_RslvDOSRaw      !(SIU.GPDI[14].R)
#define SID_m_swt_RslvLOTRaw      !(SIU.GPDI[15].R)

#define	POSITIONMSB		        0x80
#define	POSITIONLSB				0x81
#define	VELOCITYMSB				0x82
#define	VELOCITYLSB				0x83
#define	LOSTHRES				0x88
#define	DOSORTHRES				0x89
#define	DOSMISTHRES				0x8A
#define	DOSRSTMXTHRES			0x8B
#define	DOSRSTMITHRES			0x8C
#define	LOTHITHRES				0x8D
#define	LOTLOTHRES				0x8E
#define	EXFREQUENCY				0x91
#define	CONTROL					0x92
#define	SOFTRESET				0xF0
#define	FAULT					0xFF
#define POS_VEL					0x00  //address


extern  uint8_t initAD2S1210(void);
extern  void    GetMotorPos(void);
extern  void    ReadMotorPos(void);
extern  void    GetMotorVel(void);
extern  void    ReadMotorVel(void);
extern  uint8_t AD2S1210FaultClear(void);

extern  int16_t    SID_m_ct_VelocityRaw;
extern  uint32_t   SID_m_ct_PositionRaw;
extern  uint8_t    SID_m_swt_VelValid;
extern  uint8_t    SID_m_swt_PosValid;



#endif