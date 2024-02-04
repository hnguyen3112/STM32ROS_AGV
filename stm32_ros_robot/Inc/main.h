/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ECD1A_Pin GPIO_PIN_1
#define ECD1A_GPIO_Port GPIOB
#define ECD1A_EXTI_IRQn EXTI1_IRQn
#define ECD2A_Pin GPIO_PIN_2
#define ECD2A_GPIO_Port GPIOB
#define ECD2A_EXTI_IRQn EXTI2_IRQn
#define ECD1B_Pin GPIO_PIN_10
#define ECD1B_GPIO_Port GPIOB
#define ECD1B_EXTI_IRQn EXTI15_10_IRQn
#define ECD2B_Pin GPIO_PIN_11
#define ECD2B_GPIO_Port GPIOB
#define ECD2B_EXTI_IRQn EXTI15_10_IRQn
#define OUT1_Pin GPIO_PIN_3
#define OUT1_GPIO_Port GPIOB
#define OUT2_Pin GPIO_PIN_4
#define OUT2_GPIO_Port GPIOB
#define OUT3_Pin GPIO_PIN_5
#define OUT3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
