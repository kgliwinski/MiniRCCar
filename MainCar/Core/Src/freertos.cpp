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

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

//void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

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
	/* USER CODE BEGIN StartDefaultTask */
	uint8_t i = 0, left = 0, right = 0;
	DigitalPin dispA(GPIOA, GPIO_PIN_7);
	DigitalPin dispB(GPIOA, GPIO_PIN_4);
	DigitalPin dispC(GPIOB, GPIO_PIN_1);
	DigitalPin dispD(GPIOB, GPIO_PIN_0);
	DigitalPin dispE(GPIOB, GPIO_PIN_2);
	DigitalPin dispF(GPIOA, GPIO_PIN_5);
	DigitalPin dispG(GPIOA, GPIO_PIN_6);

	DigitalPin dispGND1(GPIOB, GPIO_PIN_15);
	DigitalPin dispGND2(GPIOB, GPIO_PIN_14);
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
		if(i == 50)
		{
			if(right!=9 && left!=9)
			{
				right++;
			}
			else if(left!=9)
			{
				right = 0;
				left ++;
			}
			else if(right!=9)
			{
				right++;
			}
			else if(right == 9 && left==9)
			{
				right = 0;
				left = 0;
			}
			i = 0;
		}
	}
	/* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
