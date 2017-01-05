#include "dcm.h"


void Dcm_SetNegResponse(Dcm_NegativeResponseCodeType errorCode)
{            
  diag_tx_buff[0] = 0x7f;
  diag_tx_buff[1] = diag_rx_buff[0];
  diag_tx_buff[2] = errorCode;
  tx_state.data_length = 0x03;
}


//==============================================================//
//																															//
//								xyl add 2015-7-28															//								//
//																															//
//==============================================================//

const Dcm_DspPidType DspPidList[] = 
{
	{
			/*.DspPidIdentifier =*/ 0x00,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x01,
			/*.DspPidSize = */4,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID01,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x02,
			/*.DspPidSize = */4,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x04,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID04,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPID04FreezeData,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x05,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID05,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPID05FreezeData,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x0B,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID0B,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPID0BFreezeData,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x0C,
			/*.DspPidSize = */2,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID0C,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPID0CFreezeData,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x0D,
			/*.DspPidSize = */2,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID0D,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPID0DFreezeData,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x0F,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID0F,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0x1C,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ Dem_ApplGetPID1C,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	
	
	{
			/*.DspPidIdentifier =*/ 0xE0,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspPidIdentifier =*/ 0xE1,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE1FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE2,
			/*.DspPidSize = */4,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE2FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE3,
			/*.DspPidSize = */2,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE3FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE4,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE4FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE5,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE5FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE6,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE6FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE7,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE7FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE8,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE8FreezeData,
			/*.Arc_EOL =*/  FALSE
	},
	{
			/*.DspPidIdentifier =*/ 0xE9,
			/*.DspPidSize = */1,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  TRUE,
			/*.DspGetPidFreezeframeDataFnc =*/ Dem_ApplGetPIDE9FreezeData,
			/*.Arc_EOL =*/  FALSE
	},


	{
			/*.DspPidIdentifier =*/ 0xFF,
			/*.DspPidSize = */0,
			/*.DspGetPidValFnc =*/ NULL,
			/*.DspIsFreezeframePid =*/  FALSE,
			/*.DspGetPidFreezeframeDataFnc =*/ NULL,
			/*.Arc_EOL =*/  TRUE
	},	
};



static boolean lookupPid(uint8 pidId,const Dcm_DspPidType **PidPtr)
{
	boolean pidFound = FALSE;
	const Dcm_DspPidType *dspPid = (Dcm_DspPidType *)(&DspPidList[0]);

	if(dspPid != NULL)
	{
		while ((dspPid->DspPidIdentifier != pidId) && (FALSE == dspPid->Arc_EOL))
		{
			dspPid++;
		}
		if (FALSE == dspPid->Arc_EOL)
		{
			pidFound = TRUE;
			*PidPtr = dspPid;
		}
	}

	return pidFound;
}


static boolean Dcm_SetAvailabilityPidValue(uint8 Pid,uint32 *Data)
{
	uint8 shift;
	uint32 pidData = 0;
	uint32 temp;
	boolean setOk = TRUE;
	const Dcm_DspPidType *dspPid = DspPidList;

	if(dspPid != NULL)
	{
		while (FALSE == dspPid->Arc_EOL)
		{
			if((dspPid->DspPidIdentifier >= (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MIN)) && (dspPid->DspPidIdentifier <= (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MAX)))
			{
				shift = dspPid->DspPidIdentifier - Pid;
				temp = (uint32)1 << (AVAIL_TO_SUPPORTED_PID_OFFSET_MAX - shift);
				pidData |= temp;
			}
			/*else if(dspPid->DspPidIdentifier > (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MAX))
			{
				pidData |= (uint32)1;
			}*/
			dspPid++;
		}
	}
	else
	{
		setOk = FALSE;
	}

	if(0 == pidData)
	{
		setOk = FALSE;
	}
	(*Data) = pidData;
	
	return setOk;
}

Std_ReturnType Dcm_GetFreezeFramePids(uint8 Pid,uint32 *Data)
{
	uint8 shift;
	uint32 pidData = 0;
	uint32 temp;
	boolean setOk = TRUE;
	const Dcm_DspPidType *dspPid = DspPidList;

	if(dspPid != NULL)
	{
		while (FALSE == dspPid->Arc_EOL)
		{
			if(TRUE == dspPid->DspIsFreezeframePid)
			{
				if((dspPid->DspPidIdentifier >= (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MIN)) && (dspPid->DspPidIdentifier <= (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MAX)))
				{
					shift = dspPid->DspPidIdentifier - Pid;
					temp = (uint32)1 << (AVAIL_TO_SUPPORTED_PID_OFFSET_MAX - shift);
					pidData |= temp;
				}
				/*else if(dspPid->DspPidIdentifier > (Pid + AVAIL_TO_SUPPORTED_PID_OFFSET_MAX))
				{
					pidData |= (uint32)1;
				}*/
			}
			dspPid++;
		}
	}
	else
	{
		setOk = FALSE;
	}

	if(0 == pidData)
	{
		setOk = FALSE;
	}
	(*Data) = pidData;
	
	return setOk;
}

void ObdRequestCurrentPowertrainDiagnosticData(void)
{
	uint16 i;
	uint16 pidNum;
	uint16 flag;
	uint8 requestPid[MAX_REQUEST_PID_NUM];
	const Dcm_DspPidType *sourcePidPtr = NULL;
	uint16 txLength = SID_LEN;//主要是用来判断是否会大于配置的长度
	uint16 txPos = SID_LEN;
	uint32 DATA = 0;
	uint16 findPid = 0;
	uint8 txBuffer[8];//?????
	uint8 responseCode = NEG_ACK_NONE;
	
	pidNum = rx_state.data_length - SID_LEN;
	
	if((rx_state.data_length >= OBD_REQ_MESSAGE_LEN_ONE_MIN) && (rx_state.data_length <= OBD_REQ_MESSAGE_LEN_MAX))
	{
		i = pidNum;
		flag = 0;
		while(i > 0)
		{
			requestPid[i-1] = diag_rx_buff[i];
			if(((requestPid[i-1] & DCM_FORMAT_LOW_MASK) == 0) && ((((requestPid[i-1] & DCM_FORMAT_HIGH_MASK) >> HALF_BYTE) & LEAST_BIT_MASK) == 0))
			{
				flag++;													/*used to judge if the message is valid, if flag != 0 or Pidnum, invalid*/
			}
			i--;
		}//while
		
		for(i = 0;i < pidNum;i++)                                        /*figure out the txLength to be sent*/
		{
			/*situation of supported Pids*/
			if(TRUE == lookupPid(requestPid[i],&sourcePidPtr))
			{
				txLength += PID_LEN + sourcePidPtr->DspPidSize;
			}
			/*situation of availability Pids*/
			else if(((requestPid[i] & DCM_FORMAT_LOW_MASK) == 0) && ((((requestPid[i] & DCM_FORMAT_HIGH_MASK) >> HALF_BYTE) & LEAST_BIT_MASK) == 0))
			{
				txLength += PID_LEN + SUPPRTED_PIDS_DATA_LEN;
			}
		}
		
		diag_tx_buff[0] = 0x40+SID_REQUEST_CURRENT_POWERTRAIN_DIAGNOSTIC_DATA;
		
		if(pidNum == flag)					/*check if all the request PIDs are the 0x00...0xE0 format*/
		{
			for(i = 0;i < pidNum;i++)		/*Check the PID configuration,find which PIDs were configured for 0x00,0x20,0x40 respectively,and fill in the pduTxBuffer,and count the txLength*/
			{
				if(TRUE == Dcm_SetAvailabilityPidValue(requestPid[i],&DATA))
				{						
					diag_tx_buff[txPos] = requestPid[i];
					txPos++;
					/*take every byte of uint32 DATA,and fill in txbuffer*/
					diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_THREE_BYTES)) >> OFFSET_THREE_BYTES);
					txPos++;
					diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_TWO_BYTES)) >> OFFSET_TWO_BYTES);
					txPos++;
					diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_ONE_BYTE)) >> OFFSET_ONE_BYTE);
					txPos++;
					diag_tx_buff[txPos] = (uint8)((DATA) & OBD_DATA_LSB_MASK);
					txPos++;
				}
				else if(PIDZERO == requestPid[i])
				{
					diag_tx_buff[txPos] = requestPid[i];
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
				}
				else
				{
					findPid++;
				}
			}
		}
		else if(0 == flag)							/*check if all the request PIDs are the supported PIDs,like 0x01,0x02...*/
		{
			for(i = 0;i < pidNum;i++)
			{
				if(TRUE == lookupPid(requestPid[i],&sourcePidPtr))
				{
					//if(E_OK == sourcePidPtr->DspGetPidValFnc(txBuffer))
					if(NULL != sourcePidPtr->DspGetPidValFnc && E_OK == sourcePidPtr->DspGetPidValFnc(txBuffer))
					{
						diag_tx_buff[txPos] = requestPid[i];
						txPos++;
						(void)memcpy((uint8*)(&(diag_tx_buff[txPos])),txBuffer,sourcePidPtr->DspPidSize);
						txPos += sourcePidPtr->DspPidSize;
					}
					else
					{
						responseCode = DCM_E_CONDITIONSNOTCORRECT;
						break;
					}
				}
				else
				{
					findPid++;
				}
			}
		}
		else
		{
			responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}

		if(pidNum == findPid)
		{
			responseCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}
	else
	{
		responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	
	if(DCM_E_POSITIVERESPONSE == responseCode)
	{
		tx_state.data_length = txPos;
		diag_tx_buff[0] = SID_REQUEST_CURRENT_POWERTRAIN_DIAGNOSTIC_DATA+0x40;
	}
	else
	{
     Dcm_SetNegResponse(responseCode);	
	}
	
	Diag_TPTransmit();    
}



Std_ReturnType Dcm_GetOBDFreezeFrameData(uint8 PID, uint8* buffer, uint8* BufSize)
{
  uint8 index;
  const Dcm_DspPidType *sourcePidPtr = NULL;
   
	buffer[0]= 0x00;
  * BufSize = (1);

	index = dem_MemEntryNextEmpty;
	if(index>0)//before this, PID02 must be done to check if FreezeFrame exist
	{
		if(TRUE == lookupPid(PID,&sourcePidPtr))
		{
			if(NULL != sourcePidPtr->DspGetPidFreezeframeDataFnc && E_OK == sourcePidPtr->DspGetPidFreezeframeDataFnc(buffer))
			{
				* BufSize = sourcePidPtr->DspPidSize;
				return E_OK;
			}
		}
	}
	
  return E_NOT_OK;   
}


void DspObdRequsetPowertrainFreezeFrameData(void)
{
	uint16 i ;
	uint8 size;
	uint16 j = 0;
	uint16 flag = 0;
	uint16 findPid = 0;
	uint32 dtc = 0;
	uint16 txPos = SID_LEN;
	uint16 txLength = SID_LEN;
	//uint8 PidArray[DCM_MAX_PID_NUM_IN_FF];
	uint8 requestPid[DCM_MAX_PID_NUM_IN_FF];
	uint8 requestFFNum[DCM_MAX_PID_NUM_IN_FF];
	uint16 messageLen = rx_state.data_length;
	const Dcm_DspPidType *sourcePidPtr = NULL;
	Dcm_NegativeResponseCodeType responseCode = DCM_E_POSITIVERESPONSE;
	
	if((messageLen >= OBD_REQ_MESSAGE_LEN_TWO_MIN) && (messageLen <= OBD_REQ_MESSAGE_LEN_MAX) && (((messageLen - 1) % 2) == 0))
	{
		uint16 pidNum = ((messageLen - SID_LEN) >> 1);// divide by 2
		/*find out PID and FFnum*/
		for(i = 0;i < pidNum;i++)
		{
			requestPid[i] = diag_rx_buff[j + 1];
			if(((requestPid[i] & DCM_FORMAT_LOW_MASK) == 0) && ((((requestPid[i] & DCM_FORMAT_HIGH_MASK) >> HALF_BYTE) & LEAST_BIT_MASK) == 0))
			{
				flag++;													/*used to judge if the message is valid, if flag != 0 or Pidnum, invalid*/
			}
			requestFFNum[i] = diag_rx_buff[j + 2];
			j += 2;
		}
		/*count txLength*/
		for(i = 0;i < pidNum;i++)
		{
			if(requestPid[i] == OBD_SERVICE_TWO)
			{
				txLength += PID_LEN + FF_NUM_LEN + OBD_DTC_LEN;
			}
			else if(((requestPid[i] & DCM_FORMAT_LOW_MASK) == 0) && ((((requestPid[i] & DCM_FORMAT_HIGH_MASK) >> HALF_BYTE) & LEAST_BIT_MASK) == 0))
			{
				txLength += PID_LEN + SUPPRTED_PIDS_DATA_LEN;
			}
			else if(TRUE == lookupPid(requestPid[i],&sourcePidPtr))
			{
				txLength += PID_LEN + FF_NUM_LEN + sourcePidPtr->DspPidSize;
			}
		}
		
		if(pidNum == flag)					/*check if all the request PIDs are the 0x00...0xE0 format*/
		{
			for(i = 0;i < pidNum;i++)		/*Check the PID configuration,find which PIDs were configured for 0x00,0x20,0x40 respectively,and fill in the pduTxBuffer,and count the txLength*/
			{
				size = DCM_MAX_PID_NUM_IN_FF;//only one
				if(requestFFNum[i] == RECORD_NUM)
				{
					uint32 DATA = 0;
					if(TRUE == Dcm_GetFreezeFramePids(requestPid[i],&DATA))					
					{						
						diag_tx_buff[txPos] = requestPid[i];
						txPos++;
						/*take every byte of uint32 DATA,and fill in txbuffer*/
						diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_THREE_BYTES)) >> OFFSET_THREE_BYTES);
						txPos++;
						diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_TWO_BYTES)) >> OFFSET_TWO_BYTES);
						txPos++;
						diag_tx_buff[txPos] = (uint8)(((DATA) & (OBD_DATA_LSB_MASK << OFFSET_ONE_BYTE)) >> OFFSET_ONE_BYTE);
						txPos++;
						diag_tx_buff[txPos] = (uint8)((DATA) & OBD_DATA_LSB_MASK);
						txPos++;
					}
					else if(PIDZERO == requestPid[i])
					{
						diag_tx_buff[txPos] = requestPid[i];
						txPos++;
						diag_tx_buff[txPos] = DATAZERO;
						txPos++;
						diag_tx_buff[txPos] = DATAZERO;
						txPos++;
						diag_tx_buff[txPos] = DATAZERO;
						txPos++;
						diag_tx_buff[txPos] = DATAZERO;
					}
					else
					{
						findPid++;
					}
				}
				else//only Frame 0x00 supported
				{
					responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
					break;
				}
			}
		}
		else if(0 == flag)							/*check if all the request PIDs are the supported PIDs,like 0x01,0x02...*/
		{
				for(i = 0;i < pidNum;i++)
				{
					if(requestFFNum[i] == RECORD_NUM)
					{
						uint8 bufSize = 0;
						if(requestPid[i] == OBD_SERVICE_TWO)//PID=0x02表示查询引起冻结帧存储的DTC
						{
							if(E_OK == Dem_GetDTCOfOBDFreezeFrame(requestFFNum[i],&dtc))
							{
								diag_tx_buff[txPos] = requestPid[i];
								txPos++;
								diag_tx_buff[txPos] = requestFFNum[i];
								txPos++;
								diag_tx_buff[txPos] = (uint8)(((dtc) & (OBD_DATA_LSB_MASK << OFFSET_THREE_BYTES)) >> OFFSET_THREE_BYTES);
								txPos++;
								diag_tx_buff[txPos] = (uint8)(((dtc) & (OBD_DATA_LSB_MASK << OFFSET_TWO_BYTES)) >> OFFSET_TWO_BYTES);
								txPos++;
							}
							/*if the DTC did not cause the stored FF,DTC of 0x0000 should be returned*/
							else
							{
								diag_tx_buff[txPos] = requestPid[i];
								txPos++;
								diag_tx_buff[txPos] = requestFFNum[i];
								txPos++;
								diag_tx_buff[txPos] = 0x00;
								txPos++;
								diag_tx_buff[txPos] = 0x00;
								txPos++;
							}
						}
						else
						{
							diag_tx_buff[txPos] = requestPid[i];
							txPos++;
							diag_tx_buff[txPos] = requestFFNum[i];
							txPos++;
							bufSize = (uint8)(512 - txPos);							
							//if(E_OK == Dem_GetOBDFreezeFrameData(requestPid[i],(uint8*)&(diag_tx_buff[txPos]),&bufSize))
							if(E_OK == Dcm_GetOBDFreezeFrameData(requestPid[i],(uint8*)&(diag_tx_buff[txPos]),&bufSize))
							{
								txPos += bufSize;
							}
							else
							{
								txPos -= 2;
								findPid++;
							}
						}
					}
					else
					{
						responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
						break;
					}
				}
		}
		else
		{
			responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}
		if(pidNum == findPid)
		{
			responseCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}//
	else
	{
		responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}
	
	if(DCM_E_POSITIVERESPONSE == responseCode)
	{
		tx_state.data_length = txPos;
		diag_tx_buff[0] = SID_REQUEST_POWERTRAIN_FREEZE_FRAME_DATA+0x40;
	}
	else
	{
     Dcm_SetNegResponse(responseCode);	
	}
	Diag_TPTransmit();    
}



void Dcm_ApplReadEmissionConfirmedDTC(void)
{
  uint8* buffer = (uint8*)(&diag_tx_buff[1]);
  
  tx_state.data_length = 1;//SID_LEN
  tx_state.data_length += Dem_ReqEmRelatedDTC(buffer);
  diag_tx_buff[0] = SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES+0x40;
  Diag_TPTransmit();  
}

void Dcm_ApplClrEmmisionDigInfo(void)
{
  tx_state.data_length = 1;//SID_LEN
  Dem_TestClrFault(1,0);
  diag_tx_buff[0] = SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES+0x40;
  Diag_TPTransmit();  
}


//SID 07
void Dcm_ApplReadEmissionDTCDuringCurrentOrLastCycle(void)
{
  uint8* buffer = (uint8*)(&diag_tx_buff[1]);
  
  tx_state.data_length = 1;//SID_LEN
  tx_state.data_length += Dem_ReqEmRelatedDTC(buffer);//TODO!! Need impelement
  diag_tx_buff[0] = SID_REQUEST_EMISSION_RELATED_DIAGNOSTIC_TROUBLE_CODES_DETECTED_DURING_CURRENT_OR_LAST_COMPLETED_DRIVING_CYCLE+0x40;
  Diag_TPTransmit();  
}



const Dcm_DspVehInfoType DspVehInfoList[] = 
{
	{
			/*.DspVehInfoType =*/ 0x00,
			/*.DspVehInfoSize = */1,
			/*DspVehInfoNumberOfDataItems = */1,
			/*.DspGetVehInfoTypeFnc =*/ NULL,//ToDo!!!
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspVehInfoType =*/ 0x02,//VIN
			/*.DspVehInfoSize = */OBD_VIN_LENGTH,
			/*DspVehInfoNumberOfDataItems = */1,
			/*.DspGetVehInfoTypeFnc =*/ Dem_ApplInfoType02,
			/*.Arc_EOL =*/  FALSE
	},	
	{
			/*.DspVehInfoType =*/ 0x04,//CALID
			/*.DspVehInfoSize = */OBD_CALID_LENGTH,
			/*DspVehInfoNumberOfDataItems = */1,
			/*.DspGetVehInfoTypeFnc =*/ Dem_ApplInfoType02,
			/*.Arc_EOL =*/  FALSE
	},	

	{
			/*.DspVehInfoType =*/ 0xFF,
			/*.DspVehInfoSize = */0,
			/*DspVehInfoNumberOfDataItems = */0,
			/*.DspGetVehInfoTypeFnc =*/ NULL,
			/*.Arc_EOL =*/  TRUE
	}	
};


static boolean lookupInfoType(uint8 InfoType, const Dcm_DspVehInfoType **InfoTypePtr)
{
	const Dcm_DspVehInfoType *dspVehInfo = DspVehInfoList;
	boolean InfoTypeFound = FALSE;

	while ((dspVehInfo->DspVehInfoType != InfoType) && ((dspVehInfo->Arc_EOL) == FALSE))
	{
		dspVehInfo++;
	}
	if ((dspVehInfo->Arc_EOL) == FALSE)
	{
		InfoTypeFound = TRUE;
		*InfoTypePtr = dspVehInfo;
	}

	return InfoTypeFound;
}



static boolean Dem_SetAvailabilityInfoTypeValue(uint8 InfoType,uint32 *DATABUF)
{
	uint8 shift;
	uint32 databuf = 0;
	uint32 temp;
	boolean setInfoTypeOk = TRUE;
	const Dcm_DspVehInfoType *dspVehInfo = (Dcm_DspVehInfoType *)(&DspVehInfoList[0]);

	if(dspVehInfo != NULL)
	{
		//here a bug in original source code! comment by xyl 
		while (/*(dspVehInfo->DspVehInfoType != FALSE) &&  */((dspVehInfo->Arc_EOL) == FALSE))
		{
			if((dspVehInfo->DspVehInfoType >= (InfoType + AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MIN)) && (dspVehInfo->DspVehInfoType <= (InfoType + AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MAX)))
			{
				shift = dspVehInfo->DspVehInfoType - InfoType;
				temp = (uint32)1 << (AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MAX - shift);	  		
				databuf |= temp;									
			}
			/*else if( dspVehInfo->DspVehInfoType > (InfoType + AVAIL_TO_SUPPORTED_INFOTYPE_OFFSET_MAX))
			{
				databuf |= (uint32)0x01;
			}*/
			dspVehInfo++;
    }

		if(databuf == 0)
		{
			setInfoTypeOk = FALSE;
		}
	}
	else
	{
		setInfoTypeOk = FALSE;
	}

	(*DATABUF) = databuf;

	return setInfoTypeOk;
}



void DspObdRequestvehicleinformation(void)
{
	uint8 i ;
	uint8 flag = 0;
	uint8 requestInfoType[MAX_REQUEST_VEHINFO_NUM];
	uint16 txPos = SID_LEN;
	uint32 DATABUF;
	uint8 txBuffer[PID_BUFFER_SIZE];
	uint8 findNum = 0;
	uint16 InfoTypeNum = rx_state.data_length - SID_LEN;
	const Dcm_DspVehInfoType *sourceVehInfoPtr = NULL;
	Dcm_NegativeResponseCodeType responseCode = DCM_E_POSITIVERESPONSE;

	if((rx_state.data_length >= OBD_REQ_MESSAGE_LEN_ONE_MIN) && (rx_state.data_length <= OBD_REQ_MESSAGE_LEN_MAX ))
	{
		i = (uint8)InfoTypeNum;
		while(i > 0)
		{
			requestInfoType[i - 1] = diag_rx_buff[i];
			if(((requestInfoType[i - 1] & DCM_FORMAT_LOW_MASK) == 0 )&&((((requestInfoType[i - 1] & DCM_FORMAT_HIGH_MASK) >> HALF_BYTE) & LEAST_BIT_MASK) == 0))
			{
				flag++;
			}
			i--;
		}

		if(InfoTypeNum == flag)					/*check if all the request PIDs are the 0x00...0xE0 format*/
		{
			for(i = 0;i < InfoTypeNum;i++)		/*Check the PID configuration,find which PIDs were configured for 0x00,0x20,0x40 respectively,and fill in the pduTxBuffer,and count the txLength*/
			{
				if(TRUE == Dem_SetAvailabilityInfoTypeValue(requestInfoType[i] ,&DATABUF))
				{
					diag_tx_buff[txPos] = requestInfoType[i];
					txPos++;
					/*take every byte of uint32 DTC,and fill in txbuffer*/
					diag_tx_buff[txPos] = (uint8)((DATABUF & (OBD_DATA_LSB_MASK << OFFSET_THREE_BYTES)) >> OFFSET_THREE_BYTES);
					txPos++;
					diag_tx_buff[txPos] = (uint8)((DATABUF & (OBD_DATA_LSB_MASK << OFFSET_TWO_BYTES)) >> OFFSET_TWO_BYTES);
					txPos++;
					diag_tx_buff[txPos] = (uint8)((DATABUF & (OBD_DATA_LSB_MASK << OFFSET_ONE_BYTE)) >> OFFSET_ONE_BYTE);
					txPos++;
					diag_tx_buff[txPos] = (uint8)(DATABUF & OBD_DATA_LSB_MASK);
					txPos++;
				}
				else if(INFOTYPE_ZERO == requestInfoType[i])
				{
					diag_tx_buff[txPos] = requestInfoType[i];
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
					txPos++;
					diag_tx_buff[txPos] = DATAZERO;
				}
				else
				{
					findNum++;
				}
			}
		}
		else if(flag == 0)             /*check if all the request PIDs are the supported VINs,like 0x01,0x02...*/
		{
			if(rx_state.data_length == OBD_REQ_MESSAGE_LEN_ONE_MIN)
			{
				if(TRUE == lookupInfoType(requestInfoType[i] ,&sourceVehInfoPtr ))
				{
					if (NULL != sourceVehInfoPtr->DspGetVehInfoTypeFnc)
					{
						if (sourceVehInfoPtr->DspGetVehInfoTypeFnc(txBuffer) != E_OK) 
						{
							if( requestInfoType[i] == 0x02 )	/* Special for read VIN fail,  customer's requirement*/
							{
								uint8 j;
								for( j = 0; j < (OBD_VIN_LENGTH*sourceVehInfoPtr->DspVehInfoNumberOfDataItems);j++)
								{
									txBuffer[j] = 0xff;
								}
							}
							else
							{
								responseCode = DCM_E_CONDITIONSNOTCORRECT;
							}
						}	
					}
					else
					{
						responseCode = DCM_E_CONDITIONSNOTCORRECT;
					}
		
					diag_tx_buff[txPos] = requestInfoType[i];
					txPos++;
					diag_tx_buff[txPos] = sourceVehInfoPtr->DspVehInfoNumberOfDataItems;
					txPos++;
					(void)memcpy((uint8*)(&(diag_tx_buff[txPos])),txBuffer,(sourceVehInfoPtr->DspVehInfoSize * (sourceVehInfoPtr->DspVehInfoNumberOfDataItems)));
					txPos += (sourceVehInfoPtr->DspVehInfoSize * (sourceVehInfoPtr->DspVehInfoNumberOfDataItems)) ;
					/*if(txPos >= ((pduTxData->SduLength)))
					{
						responseCode = DCM_E_REQUESTOUTOFRANGE;
					}*///masked by xyl 2015-8-7
				}
				else
				{
					findNum++;
				}
			}
			else
			{
				responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
			}
	 	}
		else
		{
			responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
		}

		if(findNum == InfoTypeNum)
		{
			responseCode = DCM_E_REQUESTOUTOFRANGE;
		}
	}
	else
	{
		responseCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
	}

	if(DCM_E_POSITIVERESPONSE == responseCode)
	{
		tx_state.data_length = txPos;
		diag_tx_buff[0] = SID_REQUEST_VEHICLE_INFORMATION+0x40;
	}
	else
	{
		Dcm_SetNegResponse(responseCode);
	}

	Diag_TPTransmit();
}
//!< xyl add 2015-7-28		THE END !!
//!<==============================================================================
