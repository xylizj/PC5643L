#ifndef _SIU_CFG_H_
#define _SIU_CFG_H_

/*******SIU Config********/
/* Fields used for all ports  */
/* -------------------------  */
/* PA field - port assignment */
#define FS_GPIO_IO_FUNCTION           0x0000
#define FS_GPIO_ALTERNATE_FUNCTION1   0x0400 /* == FS_GPIO_ALTERNATE_FUNCTION */
#define FS_GPIO_ALTERNATE_FUNCTION2   0x0800 
#define FS_GPIO_ALTERNATE_FUNCTION3   0x0C00
#define FS_ADC_FUNCTION               0x2000

/* OBE, IBE fields - output/input buffer enable */
#define FS_GPIO_OUTPUT_BUFFER_ENABLE 0x0200
#define FS_GPIO_INPUT_BUFFER_ENABLE  0x0100
#define FS_GPIO_OUTPUT_MODE          0x0200
#define FS_GPIO_INPUT_MODE           0x0100
#define FS_GPIO_READBACK_ENABLE      0x0100
#define FS_GPIO_READBACK_DISABLE     0x0000


/* Fields used for Input       */
/* -------------------------   */

/* WPE and WPS fields - treated as 1 field for weak pull configuration */
#define FS_GPIO_WEAK_PULL_UP      0x0003
#define FS_GPIO_WEAK_PULL_DOWN    0x0002
#define FS_GPIO_WEAK_PULL_DISABLE 0x0000


/* Fields used for Output      */
/* -------------------------   */

/* ODE field - output drain control */
#define  FS_GPIO_OUTPUT_DRAIN_ENABLE  0x0000
#define  FS_GPIO_OPEN_DRAIN_ENABLE    0x0020


/* SRC field - slew rate control */
#define FS_GPIO_SLOW_SLEW_RATE          0x0000
#define FS_GPIO_MEDIUMorFAST_SLEW_RATE  0x0004


/******************************************/
/* Fields used for PSMIn(n = 0~31)*/
#define FS_PSMI0_CAN1RX_PCR35     0x0
#define FS_PSMI0_CAN1RX_PCR43     0x1
#define FS_PSMI0_CAN1RX_PCR95     0x2

#define FS_PSMI1_CAN2RX_PCR73     0x0
#define FS_PSMI1_CAN2RX_PCR89     0x1

#define FS_PSMI2_CAN3RX_PCR36     0x0
#define FS_PSMI2_CAN3RX_PCR73     0x1
#define FS_PSMI2_CAN3RX_PCR89     0x2

#define FS_PSMI3_CAN4RX_PCR35     0x0
#define FS_PSMI3_CAN4RX_PCR43     0x1
#define FS_PSMI3_CAN4RX_PCR95     0x2

#define FS_PSMI4_CAN5RX_PCR64     0x0
#define FS_PSMI4_CAN5RX_PCR97     0x1

#define FS_PSMI5_SCK_0_PCR14      0x0
#define FS_PSMI5_SCK_0_PCR15      0x1

#define FS_PSMI6_CS0_0_PCR14      0x0
#define FS_PSMI6_CS0_0_PCR15      0x1
#define FS_PSMI6_CS0_0_PCR27      0x2

#define FS_PSMI7_SCK_1_PCR34      0x0
#define FS_PSMI7_SCK_1_PCR68      0x1
#define FS_PSMI7_SCK_1_PCR114     0x2

#define FS_PSMI8_SIN_1_PCR36      0x0
#define FS_PSMI8_SIN_1_PCR66      0x1
#define FS_PSMI8_SIN_1_PCR112     0x2

#define FS_PSMI9_CS0_1_PCR435     0x0
#define FS_PSMI9_CS0_1_PCR61      0x1
#define FS_PSMI9_CS0_1_PCR69      0x2
#define FS_PSMI9_CS0_1_PCR115     0x3

#define FS_PSMI10_SCK_2_PCR46     0x0
#define FS_PSMI10_SCK_2_PCR78     0x1
#define FS_PSMI10_SCK_2_PCR105    0x2

#define FS_PSMI11_SIN_2_PCR44     0x0
#define FS_PSMI11_SIN_2_PCR76     0x1

#define FS_PSMI12_CS0_2_PCR47     0x0
#define FS_PSMI12_CS0_2_PCR79     0x1
#define FS_PSMI12_CS0_2_PCR82     0x2
#define FS_PSMI12_CS0_2_PCR104    0x3

#define FS_PSMI13_E1UC3_PCR3      0x0
#define FS_PSMI13_E1UC3_PCR27     0x1

#define FS_PSMI14_E0CU4_PCR4      0x0
#define FS_PSMI14_E0CU4_PCR28     0x1

#define FS_PSMI15_E0CU5_PCR5      0x0
#define FS_PSMI15_E0CU5_PCR29     0x1

#define FS_PSMI16_E0CU6_PCR6      0x0
#define FS_PSMI16_E0CU6_PCR30     0x1

#define FS_PSMI17_E0CU7_PCR7      0x0
#define FS_PSMI17_E0CU7_PCR31     0x1

#define FS_PSMI18_E0CU10_PCR10    0x0
#define FS_PSMI18_E0CU10_PCR80    0x1

#define FS_PSMI19_E0CU11_PCR11    0x0
#define FS_PSMI19_E0CU11_PCR80    0x1

#define FS_PSMI20_E0CU12_PCR44    0x0
#define FS_PSMI20_E0CU12_PCR82    0x1

#define FS_PSMI21_E0CU13_PCR45    0x0
#define FS_PSMI21_E0CU13_PCR83    0x1

#define FS_PSMI22_E0CU14_PCR46    0x0
#define FS_PSMI22_E0CU14_PCR84    0x1

#define FS_PSMI23_E0CU22_PCR70    0x0
#define FS_PSMI23_E0CU22_PCR72    0x1
#define FS_PSMI23_E0CU22_PCR85    0x2

#define FS_PSMI24_E0CU23_PCR71    0x0
#define FS_PSMI24_E0CU23_PCR73    0x1
#define FS_PSMI24_E0CU23_PCR86    0x2

#define FS_PSMI25_E0CU24_PCR60    0x0
#define FS_PSMI25_E0CU24_PCR106   0x1

#define FS_PSMI26_E0CU25_PCR61    0x0
#define FS_PSMI26_E0CU25_PCR107   0x1

#define FS_PSMI27_E0CU26_PCR62    0x0
#define FS_PSMI27_E0CU26_PCR108   0x1

#define FS_PSMI28_E0CU27_PCR63    0x0
#define FS_PSMI28_E0CU27_PCR109   0x1

#define FS_PSMI29_SCL_PCR11       0x0
#define FS_PSMI29_SCL_PCR19       0x1

#define FS_PSMI30_SDA_PCR10       0x0
#define FS_PSMI30_SDA_PCR18       0x1

#define FS_PSMI31_LIN3RX_PCR8     0x0
#define FS_PSMI31_LIN3RX_PCR75    0x1

/* DIO pad set */
#define GPIO_DO_NP_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_OUTPUT_MODE
                        	
#define GPIO_DI_NP_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_INPUT_MODE
                        
#define GPIO_DO_PU_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_OUTPUT_MODE+\
                        	FS_GPIO_WEAK_PULL_UP
                        		
#define GPIO_DI_PU_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_INPUT_MODE+\
                        	FS_GPIO_WEAK_PULL_UP
                        	
#define GPIO_DO_PD_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_OUTPUT_MODE+\
                        	FS_GPIO_WEAK_PULL_DOWN
                        	
#define GPIO_DI_PD_CONFIG   FS_GPIO_IO_FUNCTION+\
                        	FS_GPIO_INPUT_MODE+\
                        	FS_GPIO_WEAK_PULL_DOWN                        	                        
/* EMIOS pad set */

#define EMIOS_DO_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1 + \
  							FS_GPIO_OUTPUT_BUFFER_ENABLE

/* AD pad set */
#define AD_PAD_CONFIG 		   FS_ADC_FUNCTION
                                  
/* IIC pad set */
#define IIC_SDA_PAD_CONFIG	FS_GPIO_ALTERNATE_FUNCTION2+FS_GPIO_OUTPUT_MODE+\
							FS_GPIO_INPUT_MODE+FS_GPIO_OPEN_DRAIN_ENABLE+FS_GPIO_WEAK_PULL_UP
#define IIC_SCL_PAD_CONFIG	FS_GPIO_ALTERNATE_FUNCTION2+\
							FS_GPIO_OUTPUT_MODE+FS_GPIO_INPUT_MODE+FS_GPIO_OPEN_DRAIN_ENABLE+FS_GPIO_WEAK_PULL_UP


/*#define IIC_SDA_PAD_CONFIG	FS_GPIO_ALTERNATE_FUNCTION2+\
							FS_GPIO_OUTPUT_MODE+\
							FS_GPIO_INPUT_MODE+\
							FS_GPIO_MEDIUMorFAST_SLEW_RATE	

#define IIC_SCL_PAD_CONFIG	FS_GPIO_ALTERNATE_FUNCTION2+\
							FS_GPIO_OUTPUT_MODE+\
							FS_GPIO_MEDIUMorFAST_SLEW_RATE	*/


/* SPI pad set */
#define SPI0_SOUT_CONFIG   FS_GPIO_ALTERNATE_FUNCTION1+\
                           FS_GPIO_OUTPUT_MODE+\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI0_SIN_CONFIG    FS_GPIO_IO_FUNCTION+\
                           FS_GPIO_INPUT_MODE+\
                           FS_GPIO_WEAK_PULL_UP

#define SPI0_SCK_CONFIG    FS_GPIO_ALTERNATE_FUNCTION1 + \
                           FS_GPIO_OUTPUT_BUFFER_ENABLE+\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI0_CS0_CONFIG    FS_GPIO_ALTERNATE_FUNCTION1 + \
                           FS_GPIO_OUTPUT_BUFFER_ENABLE +\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI1_SOUT_CONFIG   FS_GPIO_ALTERNATE_FUNCTION2+\
                           FS_GPIO_OUTPUT_MODE+\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI1_SIN_CONFIG    FS_GPIO_IO_FUNCTION+\
                           FS_GPIO_INPUT_MODE+\
                           FS_GPIO_WEAK_PULL_UP

#define SPI1_SCK_CONFIG    FS_GPIO_ALTERNATE_FUNCTION2 + \
                           FS_GPIO_OUTPUT_MODE+\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI1_CS0_CONFIG    FS_GPIO_ALTERNATE_FUNCTION2 + \
                           FS_GPIO_OUTPUT_BUFFER_ENABLE +\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE
                           
#define SPI1_CS1_CONFIG    FS_GPIO_ALTERNATE_FUNCTION1 + \
                           FS_GPIO_OUTPUT_BUFFER_ENABLE +\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE  
                                                   
#define SPI1_CS2_CONFIG    FS_GPIO_ALTERNATE_FUNCTION1 + \
                           FS_GPIO_OUTPUT_BUFFER_ENABLE +\
                           FS_GPIO_MEDIUMorFAST_SLEW_RATE 

/* CAN pad set */
#define CAN0_TX_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1 + \
						   FS_GPIO_OUTPUT_BUFFER_ENABLE + \
						   FS_GPIO_OPEN_DRAIN_ENABLE    + \
						   FS_GPIO_MEDIUMorFAST_SLEW_RATE
						   
#define CAN0_RX_CONFIG     FS_GPIO_IO_FUNCTION  +\
						   FS_GPIO_INPUT_BUFFER_ENABLE
						   
#define CAN1_TX_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1 + \
						   FS_GPIO_OUTPUT_BUFFER_ENABLE + \
						   FS_GPIO_OPEN_DRAIN_ENABLE    + \
						   FS_GPIO_MEDIUMorFAST_SLEW_RATE
						   
#define CAN1_RX_CONFIG     FS_GPIO_IO_FUNCTION  +\
						   FS_GPIO_INPUT_BUFFER_ENABLE
						   
/* LIN pad set */
#define LIN0_TX_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1

#define LIN0_RX_CONFIG     FS_GPIO_IO_FUNCTION  +\
						   FS_GPIO_INPUT_BUFFER_ENABLE+\
						   FS_GPIO_WEAK_PULL_UP	
						   
#define LIN1_TX_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1

#define LIN1_RX_CONFIG     FS_GPIO_IO_FUNCTION  +\
						   FS_GPIO_INPUT_BUFFER_ENABLE+\
						   FS_GPIO_WEAK_PULL_UP	

/* eTimer_0 pad set */
#define eTimer_0_ETC_CONFIG     FS_GPIO_ALTERNATE_FUNCTION1 + \
						   FS_GPIO_INPUT_BUFFER_ENABLE


/* DIO set and get value */
#define SET_STATUS(index)                (SIU.GPDO[index].R=1)
#define RESET_STATUS(index)              (SIU.GPDO[index].R=0)
#define GET_STATUS(index)                (SIU.GPDI[index].R)
#define SET_OUTPUT(index,cfg)            (SIU.GPDO[index].R=cfg)

#define CONFIG_GPIO(index, cfg)          (SIU.PCR[index].R =(uint16_t)cfg)
#define CONFIG_PSMI(index, cfg)          (SIU.PSMI[index].B.PADSEL=cfg)

/*******SIU Config********/

#endif

/*********************CAN Config Pad***************************/
#define CAN0_TX                  16
#define CAN0_RX                  17
#define CAN0_Sleep               89  // NCV7340 STB pin Mode control PIN

#define CAN1_TX                  42
#define CAN1_RX                  43  // PSMI0 = 1
#define CAN1_Sleep               102 // NCV7340 STB pin Mode control PIN

/*********************AD Config Pad****************************/
#define FED_V_DIG_AIRVALVE_PAD_NUM        	20  //PB[4] GPI[0]  
#define FED_ANA_10V_PAD_NUM        			21  //PB[5] GPI[1]  
#define FED_ANA_V24IN_PAD_NUM			    22  //PB[6] GPI[2]
#define FED_ANA_SENSORPWR_PAD_NUM     		23  //PB[7] GPI[3]
#define SIG_ANA_PIPETEMP_PAD_NUM     		48  //PD[0] GPI[4]
#define SIG_ANA_CATALYSTSINTEMP_PAD_NUM     49  //PD[1] GPI[5]
#define SIG_ANA_CATALYSTSOUTTEMP_PAD_NUM	50  //PD[2] GPI[6]
#define FED_ANA_VCC_PAD_NUM     			51  //PD[3] GPI[7]
#define SIG_ANA_AIRPRESSURE2_PAD_NUM		52  //PD[4] GPI[8]
#define SIG_ANA_AIRPRESSURE_PAD_NUM			53  //PD[5] GPI[9]
#define SIG_ANA_PUMPTEMP_PAD_NUM			54  //PD[6] GPI[10]
#define SIG_ANA_TANKLEVEL_PAD_NUM			55  //PD[7] GPI[11]
#define SIG_ANA_TANKTEMP_PAD_NUM			56  //PD[8] GPI[12]
#define SIG_ANA_SHELLTEMP_PAD_NUM			57  //PD[9] GPI[13]
#define FED_I_DIG_PIPEHEAT_PAD_NUM			58  //PD[10] GPI[14]
#define FED_I_DIG_RSV_PAD_NUM				59  //PD[11] GPI[15]

#define FED_I_DIG_TANKHEAT_PAD_NUM			24  //PB[8] ANS[0]
#define FED_I_PTC1_PAD_NUM     				25  //PB[9] ANS[1]
#define FED_I_DIG_AIRVALVE_PAD_NUM			26  //PB[10] ANS[2]
#define FED_I_PTC2_PAD_NUM     				27  //PB[11] ANS[3]
#define FED_V_PTC1_PAD_NUM					60	//ANS[4]
#define FED_V_PTC2_PAD_NUM					61	//ANS[5]
#define FED_V_DIG_SCRTANKHEAT_PAD_NUM		62	//ANS[6]
#define FED_V_DIG_RSV_PAD_NUM				63	//ANS[7]
/********************SPI Config Pad****************************/

/********************IIC Config Pad****************************/
#define IIC_SDA_PAD_NUM						10
#define IIC_SCL_PAD_NUM						11

/*******************LIN Config Pad*****************************/

/******************DIO Config Pad*******************************/
#define O_S_SysPWRCtrl_PAD_NUM		99
#define Buzzer_Ctrl_PAD_NUM			103
#define O_SPD_CTRL_PAD_NUM			51
#define Relay_Ctrl_PAD_NUM			55




//!<========Output=======
//三相驱动使能，高电平有效
#define CTL_PHASE_DRV_ENABLE_PAD_NUM		22
#define CTL_PHASE_DRV_FAULT_RESET_PAD_NUM		88

/* Sensor Supply Control  */
//为高传感器电源供电；为低不供电。
#define O_S_SENSORPWRCTRL_PAD_NUM 		1

//尿素罐加热控制：为高进行加热；为低不加热。
#define CTL_DIG_TANKHEAT_PAD_NUM 		2

//空气阀控制：为高对空气阀供电；为低不供电。
#define CTL_DIG_AIRVALVE_PAD_NUM 		3

//保留，高边输出：为高输出高电压；为低高阻。
#define CTL_DIG_RSV_PAD_NUM				4

//尿素管道加热控制：为高进行加热；为低不加热。
#define CTL_DIG_PIPEHEAT_PAD_NUM		5

//扭矩控制输出：为高，输出低；为低，高阻态。
#define CTL_DIG_TQOUT_PAD_NUM			7

//调试用指示灯，输出低电平点亮。
#define O_S_REDIND_PAD_NUM				65
#define O_S_GREENIND_PAD_NUM			76

//PTC1加热控制输出，为高PTC1输出高，为低PTC1关断（高阻）
#define O_SW_PTC1_PAD_NUM				69
//PTC2加热控制输出，为高PTC2输出高，为低PTC2关断（高阻）
#define O_SW_PTC2_PAD_NUM				70
//!<========================Output=================================

//!<========================Input==================================
//扭矩输出状态监测：为高则扭矩输出状态为低；为低则扭矩输出状态为高。
#define FED_DIG_TQOUT_PAD_NUM			45
//T15点火信号状态监测：为低说明T15为高（点火）；为高说明T15为低。
#define FED_DIG_STARTON_PAD_NUM			46
//O_Dig_PipeHeat状态监测：检测到高电平，O_Dig_PipeHeat输出低（高阻）；
//检测到低电平，O_Dig_PipeHeat输出高（电池电源）。
#define FED_V_DIG_PIPEHEAT_PAD_NUM		47
//压力开关状态监测：
#define I_S_LIQPRESSURE_PAD_NUM			64
//!<========================Input==================================

//!<========================Input Output==================================
//O_Dig_Rsv和O_Dig_PipeHeat状态监测和故障恢复时复位O_Dig_Rsv和O_Dig_PipeHeat
#define FR_STBY2_PAD_NUM				66
//PTC1和PTC2状态监测和故障恢复时复位PTC1和PTC2加热
#define FR_STBY1_PAD_NUM				67
//O_Dig_SCRTankHeat和O_Dig_AirValve状态监测和故障恢复时复位O_Dig_SCRTankHeat和O_Dig_AirValve
#define FR_STBY3_PAD_NUM				68
//!<========================Input Output==================================



#define I_S_EXCFLT_PAD_NUM			95
#define I_S_PHASEFLT_PAD_NUM			87





































