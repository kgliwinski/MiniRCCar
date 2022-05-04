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
#define BUILTIN_LED_Pin GPIO_PIN_13
#define BUILTIN_LED_GPIO_Port GPIOC
#define USER_BUTTON_Pin GPIO_PIN_0
#define USER_BUTTON_GPIO_Port GPIOA
#define BATT_CHECK_Pin GPIO_PIN_1
#define BATT_CHECK_GPIO_Port GPIOA
#define BT_TX_Pin GPIO_PIN_2
#define BT_TX_GPIO_Port GPIOA
#define BT_RX_Pin GPIO_PIN_3
#define BT_RX_GPIO_Port GPIOA
#define DISP_G_Pin GPIO_PIN_4
#define DISP_G_GPIO_Port GPIOA
#define DISP_F_Pin GPIO_PIN_5
#define DISP_F_GPIO_Port GPIOA
#define DISP_E_Pin GPIO_PIN_6
#define DISP_E_GPIO_Port GPIOA
#define DISP_D_Pin GPIO_PIN_7
#define DISP_D_GPIO_Port GPIOA
#define DISP_C_Pin GPIO_PIN_0
#define DISP_C_GPIO_Port GPIOB
#define DISP_B_Pin GPIO_PIN_1
#define DISP_B_GPIO_Port GPIOB
#define DISP_A_Pin GPIO_PIN_2
#define DISP_A_GPIO_Port GPIOB
#define DC_STBY_Pin GPIO_PIN_10
#define DC_STBY_GPIO_Port GPIOB
#define LIM_SW_L_Pin GPIO_PIN_12	//EXTI12
#define LIM_SW_L_GPIO_Port GPIOB
#define LIM_SW_R_Pin GPIO_PIN_13	//EXTI13
#define LIM_SW_R_GPIO_Port GPIOB
#define DISP_G1_Pin GPIO_PIN_14
#define DISP_G1_GPIO_Port GPIOB
#define DISP_G2_Pin GPIO_PIN_15
#define DISP_G2_GPIO_Port GPIOB
#define DISP_DP_Pin GPIO_PIN_8
#define DISP_DP_GPIO_Port GPIOA
#define DC_AIN2_Pin GPIO_PIN_15
#define DC_AIN2_GPIO_Port GPIOA
#define DC_AIN1_Pin GPIO_PIN_3
#define DC_AIN1_GPIO_Port GPIOB
#define DC_PWMA_Pin GPIO_PIN_4
#define DC_PWMA_GPIO_Port GPIOB
#define DC_BIN1_Pin GPIO_PIN_5
#define DC_BIN1_GPIO_Port GPIOB
#define DC_BIN2_Pin GPIO_PIN_6
#define DC_BIN2_GPIO_Port GPIOB
#define DC_PWMB_Pin GPIO_PIN_7
#define DC_PWMB_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
// DC A
#define DC_A_PWM_Tim htim3

// DC B
#define DC_B_PWM_Tim htim4


/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
