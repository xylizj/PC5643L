
#ifndef FLEXCAN_A_Init_H
#define FLEXCAN_A_Init_H


#include "MPC5643L.h"
#include "CAN_cfg.h"
#include "CAN_Msg.h"
#include "Siu.h"



#define CAN_IMASK2_INDEX  0
#define CAN_IMASK1_INDEX  1

#define CAN_IFLAG2_INDEX  0
#define CAN_IFLAG1_INDEX  1

#define CAN_MCR_MDIS      0x80000000U                     /* Module Disable (module disabled when 1) */
#define CAN_MCR_FRZ       0x40000000U                     /* Freeze enable (enable to enter freeze mode when HALT is set) */
#define CAN_MCR_FEN       0x20000000U                     /* FIFO mode enable */
#define CAN_MCR_HALT      0x10000000U                     /* Module Halt (module enters freeze mode when this bit is set providing the FRZ bit is set) */
#define CAN_MCR_NOTRDY    0x08000000U                     /* Module Not Ready (either disabled or in freeze mode) */
#define CAN_MCR_SOFTRST   0x02000000U                     /* Module Soft Reset (the bit remains set until reset is completed) */
#define CAN_MCR_FRZACK    0x01000000U                     /* Freeze Mode Acknowledge */
#define CAN_MCR_WRNEN     0x00200000U                     /* Warning interrupt enable (TWRNINT and RWRNINT flags generate an iterrupt if set) */
#define CAN_MCR_LPMACK    0x00100000U                     /* Module Disable Acknowledge */
#define CAN_MCR_SRXDIS    0x00020000U                     /* Self Rx Disable (module will receive its own Tx messages when cleared) */
#define CAN_MCR_BCC       0x00010000U                     /* Backwards Compatibility Configuration (individual message buffer masks are used when set, global & MB14,MB15 masks are used when cleared) */
#define CAN_MCR_LPRIOEN   0x00002000U                     /* Local Priority Enable (the PRIO field in Tx MB ID is used when set) */ 
#define CAN_MCR_AEN       0x00001000U                     /* Abort Enable (Tx abort is enabled when set) */
#define CAN_MCR_IDAM      0x00000300U                     /* ID acceptance mode for the FIFO mode */
#define CAN_MCR_IDAM32    0x00000000U                     /* ID acceptance mode: one standard or extended ID */
#define CAN_MCR_IDAM16    0x00000100U                     /* ID acceptance mode: two standard or partial extended IDs */
#define CAN_MCR_IDAM08    0x00000200U                     /* ID acceptance mode: four partial standard or extended IDs */
#define CAN_MCR_MAXMB     0x0000003FU                     /* Maximum number of MBs in use (field value plus 1) */
                                    
#define CAN_CTRL_PRESDIV  0xFF000000U                     /* clock divider (clock is divided by field value plus 1) */
#define CAN_CTRL_RJW      0x00C00000U                     /* resynchronization jump width (the width is field value plus 1 time quantum) */
#define CAN_CTRL_PSEG1    0x00380000U                     /* phase segment 1 (length of the segment is field value plus 1 time quantum) */
#define CAN_CTRL_PSEG2    0x00070000U                     /* phase segment 2 (length of the segment is field value plus 1 time quantum) */
#define CAN_CTRL_BOFFMSK  0x00008000U                     /* Bus Off Mask (bus off interrupt enabled when set) */
#define CAN_CTRL_ERRMSK   0x00004000U                     /* Error Mask (error interrupt enabled when set) */
#define CAN_CTRL_CLKSRC   0x00002000U                     /* Clock source selection (0=oscillator clock, 1=system clock) */
#define CAN_CTRL_LPB      0x00001000U                     /* Loop-Back mode (loop-back mode enabled when set) */
#define CAN_CTRL_TWRNMSK  0x00000800U                     /* Tx Warning interrupt enable (enabled when bit is set) */
#define CAN_CTRL_RWRNMSK  0x00000400U                     /* Rx Warning interrupt enable (enabled when bit is set) */
#define CAN_CTRL_SMP      0x00000080U                     /* Sampling mode (0=1 sample, 1=3 samples) */
#define CAN_CTRL_BOFFREC  0x00000040U                     /* Bus off recovery mode (0=automatic, 1=manual) */
#define CAN_CTRL_TSYN     0x00000020U                     /* Timer Synchronization (when set the free-running timer is reset each time a message is received into MB0) */
#define CAN_CTRL_LBUF     0x00000010U                     /* Lowest Buffer First (0=highest priority buffer transmitted first, 1=lowest numbered buffer transmitted first) */
#define CAN_CTRL_LOM      0x00000008U                     /* Listen only mode (listen only mode is enabled when bit is set) */
#define CAN_CTRL_PROPSEG  0x00000007U                     /* Propagation Segment (length of the segment is field value plus 1 time quantum) */
                                    
#define CAN_ESR_TWRNINT   0x00020000U                     /* Tx error warning interrupt flag (set when TXWRN becomes set while WRNEN is set) */
#define CAN_ESR_RWRNINT   0x00010000U                     /* Rx error warning interrupt flag (set when RXWRN becomes set while WRNEN is set) */
#define CAN_ESR_BIT1ERR   0x00008000U                     /* Recessive bit error (when set it indicates that at least one bit wans transmitted as recessive, but received as dominant) */
#define CAN_ESR_BIT0ERR   0x00004000U                     /* Dominant bit error (when set it indicates that at least one bit wans transmitted as dominant, but received as recessive) */
#define CAN_ESR_ACKERR    0x00002000U                     /* Acknowledge error (dominant acknowledge has been detected) */
#define CAN_ESR_CRCERR    0x00001000U                     /* CRC error detected */
#define CAN_ESR_FRMERR    0x00000800U                     /* Form error detected */
#define CAN_ESR_STFERR    0x00000400U                     /* Stuffing error detected */
#define CAN_ESR_TXWRN     0x00000200U                     /* Tx error warning flag (set when Tx error counter >=96) */
#define CAN_ESR_RXWRN     0x00000100U                     /* Rx error warning flag (set when Rx error counter >=96) */
#define CAN_ESR_IDLE      0x00000080U                     /* Can bus IDLE */
#define CAN_ESR_TXRX      0x00000040U                     /* Indicates type of activity when IDLE==0 (0=Rx, 1=Tx) */
#define CAN_ESR_FLTCONF   0x00000030U                     /* Fault state (00=error active, 01=error passive, 1x=bus off) */
#define CAN_ESR_BOFFINT   0x00000004U                     /* Bus off interrupt flag (set after the module enters bus off state) */
#define CAN_ESR_ERRINT    0x00000002U                     /* Error interrupt flag (set when at least one of the error bits (BIT1ERR..STFERR) is set) */

#define CAN_TIMEOUT_DURATION 0x0000FFFFU

/**********************  Function Prototype here *************************/

extern void CAN_Init(void);
extern uint8_t CAN_0_Transmit(vuint32_t id, uint8_t* data, uint8_t length);
//extern uint8_t CAN_0_Transmit(uint8_t index);
extern uint8_t CAN_A_XCP_Transmit(uint32_t id, uint8_t* data, uint8_t length);//added by xyl 2015.5.29
extern void CAN_0_Receive(void);












































#endif