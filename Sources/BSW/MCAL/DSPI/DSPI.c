#include "DSPI.h"


void initDSPI_1(void) {
  DSPI_1.MCR.R = 0x80010001;     /* Configure DSPI_1 as master */
  //DSPI_1.CTAR[0].R = 0x780A7727; /* Configure CTAR0  */
  //DBR=0;FMSZ=0111;CPOL=0;CPHA=1;LSBFE=0;PCSSCK=00;PASC=00;PDT=00;
  //PBR=01(3);CSSCK=0000;ASC=0000;DT=0000;BR=0001; 10MHz
  DSPI_1.CTAR[0].R = 0x3A010001;// 8bit access
  DSPI_1.CTAR[1].R = 0x7A010001;//16bit access
  
  DSPI_1.MCR.B.HALT = 0x0;	     /* Exit HALT mode: go from STOPPED to RUNNING state*/
  
  /* MPC56xxP: Config pad as DSPI_1 CS0 output */
  SIU.PCR[5].B.PA = 1;	//01: Alternative Mode 1
  //SIU.PCR[5].B.OBE = 1;//Output Buffer Enable
  //SIU.PCR[5].B.IBE = 0;//Input Buffer Enable
  
  /* MPC56xxP: Config pad as DSPI_1 SCK output */
  SIU.PCR[6].B.PA = 1;	//01: Alternative Mode 1
  //SIU.PCR[6].B.OBE = 1;//Output Buffer Enable
  //SIU.PCR[6].B.IBE = 0;//Input Buffer Enable

  /* MPC56xxP: Config pad as DSPI_1 SOUT output */
  SIU.PCR[7].B.PA = 1;	//01: Alternative Mode 1
  //SIU.PCR[7].B.OBE = 1;//Output Buffer Enable
  //SIU.PCR[7].B.IBE = 0;//Input Buffer Enable

  /* MPC56xxP: Config pad as DSPI_1 SIN input */
  //SIU.PCR[8].B.PA = 1;	//01: Alternative Mode 1
  //SIU.PCR[8].B.OBE = 0;//Output Buffer Enable
  SIU.PCR[8].B.IBE = 1;//Input Buffer Enable
}

