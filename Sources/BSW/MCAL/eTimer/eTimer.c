#include "MPC5643L.h"
#include "eTimer.h"


/********************************************************************/
void eTimer0_Init(void)
{
    /********************************
    //below are CHANNEL
    ETIMER_0.CHANNEL[0].COMP1.R=0;
    ETIMER_0.CHANNEL[0].COMP2.R=0;
    //ETIMER_0.CHANNEL[0].CAPT1.R;//read only
    //ETIMER_0.CHANNEL[0].CAPT2.R;//read only
    ETIMER_0.CHANNEL[0].LOAD.R=0;
    //ETIMER_0.CHANNEL[0].HOLD.R//read only
    ETIMER_0.CHANNEL[0].CNTR.R=0;
    ETIMER_0.CHANNEL[0].CTRL1.R=0;
    ETIMER_0.CHANNEL[0].CTRL2.R=0;
    ETIMER_0.CHANNEL[0].CTRL3.R=0;
    //ETIMER_0.CHANNEL[0].STS.R
    ETIMER_0.CHANNEL[0].INTDMA.R=0;    
    ETIMER_0.CHANNEL[0].CMPLD1.R=0;    
    ETIMER_0.CHANNEL[0].CMPLD2.R=0;    
    ETIMER_0.CHANNEL[0].CCCTRL.R=0;
    //below are TIMER
    ETIMER_0.ENBL.R=0;        
    ETIMER_0.DREQ0.R=0;
    ETIMER_0.DREQ1.R=0;
    *******************************/
    //CHANNEL 1 aux0 trigger delay 5us gen a rising edge,a DMA req, for pop
    ETIMER_0.CHANNEL[1].COMP1.R=600;
    ETIMER_0.CHANNEL[1].COMP2.R=700;//not used never comp
    //ETIMER_0.CHANNEL[1].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[1].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_0.CHANNEL[1].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_0.CHANNEL[1].CTRL2.R=0x0005;
    //ETIMER_0.CHANNEL[1].CTRL3.R=0;
    ETIMER_0.CHANNEL[1].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_0.CHANNEL[1].CMPLD1.R=0;//Init cnt    
    //ETIMER_0.CHANNEL[1].CMPLD2.R=0;    
    ETIMER_0.CHANNEL[1].CCCTRL.R=0x1800;
    
    
    //CHANNEL 2 T3 trigger delay 10us gen a rising edge
    ETIMER_0.CHANNEL[2].COMP1.R=1200;
    ETIMER_0.CHANNEL[2].COMP2.R=1500;//not used never comp
    ETIMER_0.CHANNEL[2].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[2].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:T3
    ETIMER_0.CHANNEL[2].CTRL1.R=0xD853;
    //set on comp,clr on init
    ETIMER_0.CHANNEL[2].CTRL2.R=0x0005;
    //ETIMER_0.CHANNEL[2].CTRL3.R=0;
    //ETIMER_0.CHANNEL[2].INTDMA.R=0;    
    //ETIMER_0.CHANNEL[2].CMPLD1.R=0;    
    //ETIMER_0.CHANNEL[2].CMPLD2.R=0;    
    //ETIMER_0.CHANNEL[2].CCCTRL.R=0;
    
    //CHANNEL 3 count 10 aux0 rising edge gen a rising edge
    ETIMER_0.CHANNEL[3].COMP1.R=4;
    ETIMER_0.CHANNEL[3].COMP2.R=4;//
    ETIMER_0.CHANNEL[3].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[3].CNTR.R=0;
    //count pri rising edge;pri:aux0;repeat;count until comp;count up
    ETIMER_0.CHANNEL[3].CTRL1.R=0x2840;
    //toggle output using alter comp reg    
    ETIMER_0.CHANNEL[3].CTRL2.R=0x0004;
    //ETIMER_0.CHANNEL[3].CTRL3.R=0;
    //ETIMER_0.CHANNEL[3].INTDMA.R=0;    
    //ETIMER_0.CHANNEL[3].CMPLD1.R=0;    
    //ETIMER_0.CHANNEL[3].CMPLD2.R=0;    
    //ETIMER_0.CHANNEL[3].CCCTRL.R=0;    
    
    //CHANNEL 4 aux0 trigger delay 2us gen a rising edge,a DMA req,for push
    ETIMER_0.CHANNEL[4].COMP1.R=240;
    ETIMER_0.CHANNEL[4].COMP2.R=300;//not used never comp
    //ETIMER_0.CHANNEL[4].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[4].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_0.CHANNEL[4].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_0.CHANNEL[4].CTRL2.R=0x0005;
    //ETIMER_0.CHANNEL[4].CTRL3.R=0;
    ETIMER_0.CHANNEL[4].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_0.CHANNEL[4].CMPLD1.R=0;//Init cnt    
    //ETIMER_0.CHANNEL[4].CMPLD2.R=0;    
    ETIMER_0.CHANNEL[4].CCCTRL.R=0x1800;    

    //CHANNEL 5 aux0 trigger delay 15us gen a rising edge
    ETIMER_0.CHANNEL[5].COMP1.R=1800;
    ETIMER_0.CHANNEL[5].COMP2.R=2000;//not used never comp
    ETIMER_0.CHANNEL[5].LOAD.R=0;//init cnt
    //ETIMER_0.CHANNEL[5].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_0.CHANNEL[5].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_0.CHANNEL[5].CTRL2.R=0x0005;
    //ETIMER_0.CHANNEL[5].CTRL3.R=0;
    ETIMER_0.CHANNEL[5].INTDMA.R=0x0001;//TCF INT ENABLE   STS.TCF 
    //ETIMER_0.CHANNEL[5].CMPLD1.R=0;//Init cnt    
    //ETIMER_0.CHANNEL[5].CMPLD2.R=0;    
    //ETIMER_0.CHANNEL[5].CCCTRL.R=0;
        
    //below are TIMER
    ETIMER_0.ENBL.R=0x003E;        
    ETIMER_0.DREQ0.R=0x8012;
    ETIMER_0.DREQ1.R=0x8006;       
}





void eTimer1_Init(void)
{    /********************************
    //below are CHANNEL
    ETIMER_1.CHANNEL[0].COMP1.R=0;
    ETIMER_1.CHANNEL[0].COMP2.R=0;
    //ETIMER_1.CHANNEL[0].CAPT1.R;//read only
    //ETIMER_1.CHANNEL[0].CAPT2.R;//read only
    ETIMER_1.CHANNEL[0].LOAD.R=0;
    //ETIMER_1.CHANNEL[0].HOLD.R//read only
    ETIMER_1.CHANNEL[0].CNTR.R=0;
    ETIMER_1.CHANNEL[0].CTRL1.R=0;
    ETIMER_1.CHANNEL[0].CTRL2.R=0;
    ETIMER_1.CHANNEL[0].CTRL3.R=0;
    //ETIMER_1.CHANNEL[0].STS.R
    ETIMER_1.CHANNEL[0].INTDMA.R=0;    
    ETIMER_1.CHANNEL[0].CMPLD1.R=0;    
    ETIMER_1.CHANNEL[0].CMPLD2.R=0;    
    ETIMER_1.CHANNEL[0].CCCTRL.R=0;
    //below are TIMER
    ETIMER_1.ENBL.R=0;        
    ETIMER_1.DREQ0.R=0;
    ETIMER_1.DREQ1.R=0;
    *******************************/
    //CHANNEL 4 aux0 no delay trigger gen a rising edge,a DMA req,for io low
    ETIMER_1.CHANNEL[4].COMP1.R=0;
    ETIMER_1.CHANNEL[4].COMP2.R=100;//not used never comp
    //ETIMER_1.CHANNEL[4].LOAD.R=0;//init cnt
    //ETIMER_1.CHANNEL[4].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_1.CHANNEL[4].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[4].CTRL2.R=0x0005;
    //ETIMER_1.CHANNEL[4].CTRL3.R=0;
    ETIMER_1.CHANNEL[4].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_1.CHANNEL[4].CMPLD1.R=0;//Init cnt    
    //ETIMER_1.CHANNEL[4].CMPLD2.R=0;    
    ETIMER_1.CHANNEL[4].CCCTRL.R=0x1800;    

    //CHANNEL 5 aux0 delay 1.2us trigger gen a rising edge,a DMA req,for io high
    ETIMER_1.CHANNEL[5].COMP1.R=144;
    ETIMER_1.CHANNEL[5].COMP2.R=200;//not used never comp
    //ETIMER_1.CHANNEL[5].LOAD.R=0;//init cnt
    //ETIMER_1.CHANNEL[5].CNTR.R=0;
    //sec source trigger pri count til comp;pri:IPBUS/1;repeat;count until comp;count up;sec:aux0
    ETIMER_1.CHANNEL[5].CTRL1.R=0xD848;
    //set on comp,clr on init
    ETIMER_1.CHANNEL[5].CTRL2.R=0x0005;
    //ETIMER_1.CHANNEL[4].CTRL3.R=0;
    ETIMER_1.CHANNEL[5].INTDMA.R=0x1000;//CMPLD1 DMA ENABLE    
    ETIMER_1.CHANNEL[5].CMPLD1.R=0;//Init cnt    
    //ETIMER_1.CHANNEL[5].CMPLD2.R=0;    
    ETIMER_1.CHANNEL[5].CCCTRL.R=0x1800;


    //below are TIMER
    ETIMER_1.ENBL.R=0x0030;        
    ETIMER_1.DREQ0.R=0x8012;
    ETIMER_1.DREQ1.R=0x8016;
 }

