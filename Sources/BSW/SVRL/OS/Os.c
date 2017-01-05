/*******************************************************************************
* include files                                                 
*******************************************************************************/
#include "Os.h"


/*******************************************************************************
* Defines                                                                
*******************************************************************************/

/*******************************************************************************
* Macros                                                                
*******************************************************************************/

/*******************************************************************************
* Global Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Local Constant definition                         
*******************************************************************************/

/*******************************************************************************
* Global Variables definition                         
*******************************************************************************/
boolean os_Alarm1ms;
boolean os_Alarm2ms;
boolean os_Alarm5ms;
boolean os_Alarm10ms;
boolean os_Alarm100ms;
osTime_MSecTickType os_Alarm1msStart;
osTime_MSecTickType os_Alarm2msStart;
osTime_MSecTickType os_Alarm5msStart;
osTime_MSecTickType os_Alarm10msStart;
osTime_MSecTickType  os_Alarm100msStart;
osTime_MSecTickType os_CurrentTBL;


/*******************************************************************************
* Local Variables definition                         
*******************************************************************************/

/*******************************************************************************
* Local Functions prototypes                         
*******************************************************************************/

/*******************************************************************************
* Extern function declaration                                                
*******************************************************************************/



/******************main Function*************************************/
void main(void)
{
  	uint32 t1, t2,t3,t4,t5,t6,t7,t8;		
	
	DisableAllInterrupts();
    OsTimer_Init();
    OSTrace_Init();
	SchM_BSW_Init();  
	SchM_ASW_Init();
	EnableAllInterrupts();
	


	
	//EnableWatchdog(); // start Watchdog !!!!!
	
    os_Alarm1msStart = Gpt_GetCurrentCnt();
    os_Alarm2msStart = Gpt_GetCurrentCnt();
	os_Alarm5msStart = Gpt_GetCurrentCnt();
	os_Alarm10msStart = Gpt_GetCurrentCnt();
	os_Alarm100msStart = Gpt_GetCurrentCnt();
	os_Alarm1ms  = FALSE;
	os_Alarm2ms  = FALSE;
	os_Alarm5ms  = FALSE;
	os_Alarm10ms = FALSE;
	os_Alarm100ms = FALSE;

	for(;;)
	{
	  if (os_Alarm1ms == FALSE)
		{	    	
			os_CurrentTBL = Gpt_GetCurrentCnt();
			t3 = (uint32)(os_CurrentTBL - os_Alarm1msStart);
			if(  t3 > ( OSTIMER_COUNT_1MS ) )
			{
				os_Alarm1ms = TRUE;
				os_Alarm1msStart = os_CurrentTBL;
			}
		}
	    if (os_Alarm1ms == TRUE)
	    {
				t3 = Gpt_GetCurrentCnt();
				SchM_Period1Ms();
				os_Alarm1ms = FALSE;
				t4 = Gpt_GetCurrentCnt();
				osTrace_ExcTime[TASK1MS].CurExcTime = (t4 - t3);	      
	    }
	    
	    if (os_Alarm10ms == FALSE)
	    {	    	
	    	os_CurrentTBL = Gpt_GetCurrentCnt();
	    	t1 = (uint32)(os_CurrentTBL - os_Alarm10msStart);
	    	if(  t1 > ( OSTIMER_COUNT_10MS ) )
	    	{
	    		os_Alarm10ms = TRUE;
	    		os_Alarm10msStart = os_CurrentTBL;
	    	}
	    }
	    if (os_Alarm10ms == TRUE)
	    {
	      t1 = Gpt_GetCurrentCnt();	      
	      SchM_Period10Ms();
	      os_Alarm10ms = FALSE;
	      t2 = Gpt_GetCurrentCnt();	      
	      osTrace_ExcTime[TASK10MS].CurExcTime = (t2 - t1);	      
	    }
	    
	    if (os_Alarm100ms == FALSE)
	    {	    	
	    	os_CurrentTBL = Gpt_GetCurrentCnt();
	    	t7 = (uint32)(os_CurrentTBL - os_Alarm100msStart);
	    	if(  t7 > ( OSTIMER_COUNT_100MS ) )
	    	{
	    		os_Alarm100ms = TRUE;
	    		os_Alarm100msStart = os_CurrentTBL;
	    	}
	    }
	    if (os_Alarm100ms == TRUE)
	    {
	      t7 = Gpt_GetCurrentCnt();
	      SchM_Period100Ms();
	      				
	      os_Alarm100ms = FALSE;
	      t8 = Gpt_GetCurrentCnt();	      
	      osTrace_ExcTime[TASK100MS].CurExcTime = (t8 - t7);	      
	    }
	    
	   
	    SchM_MainFunction();
	}	
}








