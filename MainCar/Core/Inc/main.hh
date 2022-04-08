/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
/* USER CODE BEGIN Private defines */

// display ports and pins
#define DISP_A_PORT GPIOA
#define DISP_A_PIN GPIO_PIN_7
#define DISP_B_PORT GPIOA
#define DISP_B_PIN GPIO_PIN_4
#define DISP_C_PORT GPIOB
#define DISP_C_PIN GPIO_PIN_1
#define DISP_D_PORT GPIOB
#define DISP_D_PIN GPIO_PIN_0
#define DISP_E_PORT GPIOB
#define DISP_E_PIN GPIO_PIN_2
#define DISP_F_PORT GPIOA
#define DISP_F_PIN GPIO_PIN_5
#define DISP_G_PORT GPIOA
#define DISP_G_PIN GPIO_PIN_6
#define DISP_GND_LEFT_PORT GPIOB
#define DISP_GND_LEFT_PIN GPIO_PIN_15
#define DISP_GND_RIGHT_PORT GPIOB
#define DISP_GND_RIGHT_PIN GPIO_PIN_14

// DC motors

// DC A
#define DC_AIN_1_PORT GPIOB
#define DC_AIN_1_PIN GPIO_PIN_5
#define DC_AIN_2_PORT GPIOB
#define DC_AIN_2_PIN GPIO_PIN_6
#define DC_A_PWM_Tim htim3

// DC B
#define DC_BIN_1_PORT GPIOB
#define DC_BIN_1_PIN GPIO_PIN_3
#define DC_BIN_2_PORT GPIOA
#define DC_BIN_2_PIN GPIO_PIN_15
#define DC_B_PWM_Tim htim4
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
