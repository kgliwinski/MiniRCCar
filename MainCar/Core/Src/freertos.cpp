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
#include "FreeRTOS.h"
#include "task.h"
#include "main.hh"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "SevenSegmentX2.hh"
#include "tim.h"
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

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);
void StartDisplayTask(void *argument);

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

	/* USER CODE BEGIN RTOS_QUEUES */
	/* add queues, ... */
	/* USER CODE END RTOS_QUEUES */

	/* Create the thread(s) */
	/* creation of defaultTask */
	defaultTaskHandle = osThreadNew(StartDefaultTask, NULL,
			&defaultTask_attributes);

	/* creation of displayTask */
	displayTaskHandle = osThreadNew(StartDisplayTask, NULL,
			&displayTask_attributes);

	/* USER CODE BEGIN RTOS_THREADS */
	/* add threads, ... */
	/* USER CODE END RTOS_THREADS */

	/* USER CODE BEGIN RTOS_EVENTS */
	/* add events, ... */
	/* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument) {
	DigitalPin DCAIn1(DC_AIN_1_PORT, DC_AIN_1_PIN);
	DigitalPin DCAIn2(DC_AIN_2_PORT, DC_AIN_2_PIN);

	DigitalPin DCBIn1(DC_BIN_1_PORT, DC_BIN_1_PIN);
	DigitalPin DCBIn2(DC_BIN_2_PORT, DC_BIN_2_PIN);

	DCAIn1.writePin(1);
	DCAIn2.writePin(0);

	DCBIn1.writePin(1);
	DCBIn2.writePin(0);

	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	TIM3->CCR1 = 65535;
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_2);
	TIM4->CCR2 = 65535;
	for (;;) {
		osDelay(1);
	}
	/* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_StartDisplayTask */
/**
 * @brief Function implementing the displayTask thread.
 * @param argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDisplayTask */
void StartDisplayTask(void *argument) {
	/* USER CODE BEGIN StartDisplayTask */
	uint8_t i = 0, left = 0, right = 0;
	DigitalPin dispA(DISP_A_PORT, DISP_A_PIN);
	DigitalPin dispB(DISP_B_PORT, DISP_B_PIN);
	DigitalPin dispC(DISP_C_PORT, DISP_C_PIN);
	DigitalPin dispD(DISP_D_PORT, DISP_D_PIN);
	DigitalPin dispE(DISP_E_PORT, DISP_E_PIN);
	DigitalPin dispF(DISP_F_PORT, DISP_F_PIN);
	DigitalPin dispG(DISP_G_PORT, DISP_G_PIN);

	DigitalPin dispGND1(DISP_GND_LEFT_PORT, DISP_GND_LEFT_PIN);
	DigitalPin dispGND2(DISP_GND_RIGHT_PORT, DISP_GND_RIGHT_PIN);
	dispGND1.writePin(1);
	dispGND2.writePin(1);

	SevenSegment single(dispA, dispB, dispC, dispD, dispE, dispF, dispG);
	//SevenSegmentX2 display(single, dispGND1, dispGND2);
	single.clearDisp();
	/* Infinite loop */
	for (;;) {
		single.clearDisp();
		dispGND2.writePin(1);
		dispGND1.writePin(0);
		single.writeDigit(left);
		osDelay(1);
		single.clearDisp();
		dispGND1.writePin(1);
		dispGND2.writePin(0);
		single.writeDigit(right);
		osDelay(1);

		i++;
		if (i == 50) {
			if (right != 9 && left != 9) {
				right++;
			} else if (left != 9) {
				right = 0;
				left++;
			} else if (right != 9) {
				right++;
			} else if (right == 9 && left == 9) {
				right = 0;
				left = 0;
			}
			i = 0;
		}
	}
	/* USER CODE END StartDisplayTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
