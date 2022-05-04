/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <main.hh>
#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SevenSegmentX2.hh"
#include "tim.h"
#include "SingleDCMotor.hh"
#include "VoltageMeter.hh"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = { .name = "defaultTask",
		.stack_size = 128 * 4, .priority = (osPriority_t) osPriorityNormal, };
/* Definitions for displayTask */
osThreadId_t displayTaskHandle;
const osThreadAttr_t displayTask_attributes = { .name = "displayTask",
		.stack_size = 1024 * 4, .priority = (osPriority_t) osPriorityLow1, };
/* Definitions for driveTask */
osThreadId_t driveTaskHandle;
const osThreadAttr_t driveTask_attributes = { .name = "driveTask", .stack_size =
		2048 * 4, .priority = (osPriority_t) osPriorityLow1, };
/* Definitions for btTask */
osThreadId_t btTaskHandle;
const osThreadAttr_t btTask_attributes = { .name = "btTask", .stack_size = 2048
		* 4, .priority = (osPriority_t) osPriorityLow, };
/* Definitions for btTx */
osMessageQueueId_t btTxHandle;
const osMessageQueueAttr_t btTx_attributes = { .name = "btTx" };
/* Definitions for btRx */
osMessageQueueId_t btRxHandle;
const osMessageQueueAttr_t btRx_attributes = { .name = "btRx" };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void startDefaultTask(void *argument);
void startDisplayTask(void *argument);
void startDriveTask(void *argument);
void startBtTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* USER CODE BEGIN RTOS_MUTEX */
	/* add mutexes, ... */
	/* USER CODE END RTOS_MUTEX */

	/* USER CODE BEGIN RTOS_SEMAPHORES */
	/* add semaphores, ... */
	/* USER CODE END RTOS_SEMAPHORES */

	/* USER CODE BEGIN RTOS_TIMERS */
	/* start timers, add new ones, ... */
	/* USER CODE END RTOS_TIMERS */

	/* Create the queue(s) */
	/* creation of btTx */
	btTxHandle = osMessageQueueNew(64, sizeof(uint16_t), &btTx_attributes);

	/* creation of btRx */
	btRxHandle = osMessageQueueNew(64, sizeof(uint16_t), &btRx_attributes);

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	defaultTaskHandle = osThreadNew(startDefaultTask, NULL,
			&defaultTask_attributes);

	/* creation of displayTask */
	displayTaskHandle = osThreadNew(startDisplayTask, NULL,
			&displayTask_attributes);

	/* creation of driveTask */
	driveTaskHandle = osThreadNew(startDriveTask, NULL, &driveTask_attributes);

	/* creation of btTask */
	btTaskHandle = osThreadNew(startBtTask, NULL, &btTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_startDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_startDefaultTask */
void startDefaultTask(void *argument) {
	/* USER CODE BEGIN startDefaultTask */
	//DigitalPin builtInLed(BUILTIN_LED_GPIO_Port, BUILTIN_LED_Pin);
	//builtInLed.writePin(0);
	//bool state = 0;
	//HAL_GPIO_EXTI_Callback(LIM_SW_L_Pin);
	/* Infinite loop */
	for (;;) {
		//state = !state;
		//builtInLed.writePin(state);
		osDelay(10);
	}
	/* USER CODE END startDefaultTask */
}

/* USER CODE BEGIN Header_startDisplayTask */
/**
 * @brief Function implementing the displayTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startDisplayTask */
void startDisplayTask(void *argument) {
	/* USER CODE BEGIN StartDisplayTask */
	// display inits
	uint8_t i = 100;
	uint32_t left = 0, right = 0;
	float batteryVoltage;
	DigitalPin dispA(DISP_A_GPIO_Port, DISP_A_Pin);
	DigitalPin dispB(DISP_B_GPIO_Port, DISP_B_Pin);
	DigitalPin dispC(DISP_C_GPIO_Port, DISP_C_Pin);
	DigitalPin dispD(DISP_D_GPIO_Port, DISP_D_Pin);
	DigitalPin dispE(DISP_E_GPIO_Port, DISP_E_Pin);
	DigitalPin dispF(DISP_F_GPIO_Port, DISP_F_Pin);
	DigitalPin dispG(DISP_G_GPIO_Port, DISP_G_Pin);
	DigitalPin dispDP(DISP_DP_GPIO_Port, DISP_DP_Pin);

	DigitalPin dispLeftGND(DISP_G1_GPIO_Port, DISP_G1_Pin);
	DigitalPin dispRightGND(DISP_G2_GPIO_Port, DISP_G2_Pin);
	dispRightGND.writePin(1);
	dispLeftGND.writePin(1);

	SevenSegmentX2 disp(
			SevenSegment(dispA, dispB, dispC, dispD, dispE, dispF, dispG,
					dispDP), dispRightGND, dispLeftGND);

	// adc init
	VoltageMeter VMeter(&hadc1, 6800.0, 3200.0, 3.30);
	if (!VMeter.init()) {
		osThreadTerminate(NULL);
	}
	disp.clearDisp();
	/* Infinite loop */
	for (;;) {
		disp.writeNumber(left, leftSide);
		osDelay(1);
		disp.writeNumber(right, rightSide);
		osDelay(1);
		if (i == 100) {
			batteryVoltage = VMeter.calculateVoltageVolts();
			disp.parseFloat(batteryVoltage, left, right);
			i = 0;
		}
		i++;
	}
	/* USER CODE END StartDisplayTask */
}

/* USER CODE BEGIN Header_startDriveTask */
/**
 * @brief Function implementing the driveTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startDriveTask */
void startDriveTask(void *argument) {
	DigitalPin DCAIn1(DC_AIN1_GPIO_Port, DC_AIN1_Pin);
	DigitalPin DCAIn2(DC_AIN2_GPIO_Port, DC_AIN2_Pin);

	DigitalPin DCBIn1(DC_BIN1_GPIO_Port, DC_BIN1_Pin);
	DigitalPin DCBIn2(DC_BIN2_GPIO_Port, DC_BIN2_Pin);

	DigitalPin DCStdby(DC_STBY_GPIO_Port, DC_STBY_Pin);
	DCStdby.writePin(1);

	SingleDCMotor MotorA(DCAIn1, DCAIn2, &htim3, *TIM3, TIM_CHANNEL_1,
			&(TIM3->CCR1));
	SingleDCMotor MotorB(DCBIn1, DCBIn2, &htim4, *TIM4, TIM_CHANNEL_2,
			&(TIM4->CCR2));

	MotorA.init();
	MotorA.setDirection(1);
	MotorA.setPWMWidth(100);

	//HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	//TIM3->CCR1 = 65535;
	//HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	//TIM4->CCR2 = 65535;
	for (;;) {

		osDelay(10);
	}
	/* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_startBtTask */
/**
 * @brief Function implementing the btTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_startBtTask */
void startBtTask(void *argument) {
	/* USER CODE BEGIN startBtTask */
	/* Infinite loop */
	for (;;) {
		osDelay(1);
	}
	/* USER CODE END startBtTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
