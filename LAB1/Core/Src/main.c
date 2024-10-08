/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
int counter  = 0;
int counter1 = 0;
int sec = 60, min =3600, hour =43200;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

//Segment numbers stored in array.
//Each element represents for a displayed number (range from 0 - 9). Decoder for Common Anode.
uint8_t segmentNumber[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
void display7SEG(int num){
    uint8_t number = segmentNumber[num];
	//Check a nth bit by shifting n times to the right, then bitwise AND it:
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, ((number>>0)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, ((number>>1)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, ((number>>2)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, ((number>>3)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, ((number>>4)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, ((number>>5)&0x01));
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, ((number>>6)&0x01));
}

void ex1()
{
	  switch(counter){
	  case 0:
	    HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, SET);
	    HAL_GPIO_WritePin(LED_YEL0_GPIO_Port, LED_YEL0_Pin, RESET);
	    counter ++;
	    break;
	  case 2:
	    HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, RESET);
	    HAL_GPIO_WritePin(LED_YEL0_GPIO_Port, LED_YEL0_Pin, SET);
	    counter++;
	    break;
	  case 3:
	    counter = 0;
	    break;
	  default:
	    counter++;
	    break;
	    }
}

void ex2()
{
	  switch (counter) {
	  case 0:
	    HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, GPIO_PIN_SET);
	    HAL_GPIO_WritePin(LED_YEL0_GPIO_Port, LED_YEL0_Pin, GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(LED_GRE0_GPIO_Port, LED_GRE0_Pin, GPIO_PIN_RESET);
	    counter++;
	    break;
	  case 5:
	    HAL_GPIO_TogglePin(LED_RED0_GPIO_Port, LED_RED0_Pin);
	    HAL_GPIO_TogglePin(LED_GRE0_GPIO_Port, LED_GRE0_Pin);
	    counter++;
	    break;
	  case 8:
	    HAL_GPIO_TogglePin(LED_GRE0_GPIO_Port, LED_GRE0_Pin);
	    HAL_GPIO_TogglePin(LED_YEL0_GPIO_Port, LED_YEL0_Pin);
	    counter++;
	    break;
	  case 9:
	    counter = 0;
	    break;
	  default:
	    counter++;
	    break;
		}
}

void ex4()
{
    if(counter >= 10) counter = 0;
    display7SEG(counter++);
}

void setLedRed(int a)
{
    HAL_GPIO_WritePin(LED_RED0_GPIO_Port, LED_RED0_Pin, a);
    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, a);
//    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, a);
//    HAL_GPIO_WritePin(LED_RED3_GPIO_Port, LED_RED3_Pin, 1 - a);
}

void setLedRed1(int a)
{
    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, a);
    HAL_GPIO_WritePin(LED_RED3_GPIO_Port, LED_RED3_Pin, a);
}

void setLedYellow(int a)
{
    HAL_GPIO_WritePin(LED_YEL0_GPIO_Port, LED_YEL0_Pin, a);
    HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, a);
//    HAL_GPIO_WritePin(LED_YEL2_GPIO_Port, LED_YEL2_Pin, a);
//    HAL_GPIO_WritePin(LED_YEL3_GPIO_Port, LED_YEL3_Pin, a);
}

void setLedYellow1(int a)
{
    HAL_GPIO_WritePin(LED_YEL1_GPIO_Port, LED_YEL1_Pin, a);
    HAL_GPIO_WritePin(LED_YEL3_GPIO_Port, LED_YEL3_Pin, a);
}

void setLedGreen(int a)
{
    HAL_GPIO_WritePin(LED_GRE0_GPIO_Port, LED_GRE0_Pin, a);
    HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, a);
//    HAL_GPIO_WritePin(LED_GRE2_GPIO_Port, LED_GRE2_Pin, a);
//    HAL_GPIO_WritePin(LED_GRE3_GPIO_Port, LED_GRE3_Pin, a);
}

void setLedGreen1(int a)
{
    HAL_GPIO_WritePin(LED_GRE1_GPIO_Port, LED_GRE1_Pin, a);
    HAL_GPIO_WritePin(LED_GRE3_GPIO_Port, LED_GRE3_Pin, a);
}

void ex5()
{
	  switch (counter) {
	  case 9:
		 setLedRed(1);
		 setLedYellow(0);
		 setLedGreen(0);
		 counter--;
		 break;
	  case 4:
		 setLedRed(0);
		 setLedYellow(0);
		 setLedGreen(1);
		 counter--;
		 break;
	  case 1:
		 setLedRed(0);
		 setLedYellow(1);
		 setLedGreen(0);
		 counter--;
		 break;
	  case 0:
	    counter = 9;
	    break;
	  default:
	    counter--;
	    break;
		}
}

void ex5_1()
{
	  switch (counter1) {
	  case 0:
		 setLedRed1(0);
		 setLedYellow1(0);
		 setLedGreen1(1);
		 counter1++;;
		 break;
	  case 3:
		 setLedRed1(0);
		 setLedYellow1(1);
		 setLedGreen1(0);
		 counter1++;
		 break;
	  case 5:
		 setLedRed1(1);
		 setLedYellow1(0);
		 setLedGreen1(0);
		 counter1++;
		 break;
	  case 9:
	    counter1 = 0;
	    break;
	  default:
	    counter1++;
	    break;
		}
}
void ex6()
{
	// ODR: Output Data Register. It means that we operate on registers. The code is : GPIOA->ODR =  0x0008 (0b0000000000001000).
	// We want to set pin A3 and reset the other pins in the 16 pin bus.
	// Aim: Check connection between pins by blinking 12 LEDs in sequence. Then repeat a loop.
	//We configure pins from A4 through A15, so as to see A4 to be displayed we set A3 in default.
	  if(counter >=0 && counter <= 11)
	    GPIOA->ODR = GPIOA->ODR << 1; // Shift the register to the left 1 bit
	  if(counter >= 12){   // After a loop, set up again.
	    GPIOA->ODR = 0x0010;//0b0000000000010000;
	    counter  = 0;
		  }
	  counter++;
}

void clearAllClock(){
    GPIOA -> ODR = 0x0000;
}

void setNumberOnClock(int num){
  if(num >= 0 && num <=11){
    GPIOA->ODR |= 1 << (num + 4); // Because pin A_4 has value 0.
  }
}

void clearNumberOnClock(int num){
	if(num >= 0 && num <=11){
	 // To clear a bit, we must invert the bit string with bitwise NOT operator(~), then AND it.
	  GPIOA->ODR &= ~(1 << (num + 4));
	}
}

void ex10()
{
    sec ++;
    min ++;
    hour ++;
    clearAllClock();

    //display sec, min, hour every 5s,300s, and 3600s respectively.
    setNumberOnClock(sec/5);
    setNumberOnClock(min/300);
    setNumberOnClock(hour/3600);

    //Return after every cycle
    if (sec == 60)
        sec = 0;
    if (min == 3600)
        min = 0;
    if (hour == 43200)
        hour = 0;

}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  //counter = 9;
  //GPIOA->ODR = 0x0008;
  clearAllClock();
  sec = 0, min =0, hour =0;

  while (1)
  {
    /* USER CODE END WHILE */
	//display7SEG(counter);
//	setNumberOnClock(8);
//	HAL_Delay(1000);
//	clearNumberOnClock(8);
//	HAL_Delay(1000);
//	setNumberOnClock(7);
//	HAL_Delay(1000);
//	clearAllClock();
	 ex10();
	// ex5_1();
	 HAL_Delay(100);
  }
    /* USER CODE BEGIN 3 */

  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin|LED_YEL0_Pin|LED_GRE0_Pin|LED_RED1_Pin
                          |LED_YEL1_Pin|LED_GRE1_Pin|LED_RED2_Pin|LED_YEL2_Pin
                          |LED_GRE2_Pin|LED_RED3_Pin|LED_YEL3_Pin|LED_GRE3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED0_Pin LED_YEL0_Pin LED_GRE0_Pin LED_RED1_Pin
                           LED_YEL1_Pin LED_GRE1_Pin LED_RED2_Pin LED_YEL2_Pin
                           LED_GRE2_Pin LED_RED3_Pin LED_YEL3_Pin LED_GRE3_Pin */
  GPIO_InitStruct.Pin = LED_RED0_Pin|LED_YEL0_Pin|LED_GRE0_Pin|LED_RED1_Pin
                          |LED_YEL1_Pin|LED_GRE1_Pin|LED_RED2_Pin|LED_YEL2_Pin
                          |LED_GRE2_Pin|LED_RED3_Pin|LED_YEL3_Pin|LED_GRE3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
