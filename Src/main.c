/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
#include "gpio.h"
#include "dz.h"
#include "dzcode.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
	KEY_Check,			//按键检测
	KEY_Press,			//按键按下
	KEY_Release,		//按键释放
	Key_Over,
}KEY_State;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define B1 HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_9)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t Num=0;
uint8_t KEY_Value=0;
KEY_State KeyState=KEY_Check;
uint8_t KEY_Flag = 0;
uint32_t KEY_Press_TIME=20;	
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	MX_GPIO_Init_A();
	MX_GPIO_Init_B();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
	uint16_t data=0;
  /* USER CODE END 2 */
//R88_row_flush();//刷新行
//R88_col_flush();//刷新列
//R88_off();//关闭所有
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		if(KEY_Flag==1)
		{
			KEY_Flag=0;
			if((KEY_Value==1)&&(KEY_Press_TIME<=700)){data++; HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);}
			else if((KEY_Value==1)&&(KEY_Press_TIME>1200)){data=99;HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);}
			KEY_Press_TIME=20;
		}	
		if(data==0)
		{
			//R88_show_img(Small_Arr2);
				Display(biglove,1);
		}
		if(data==1)
		{
        i3=20;
			//R88_show_img(Small_Arr2);
				Display(biglove,0);
		}
		
		
		//##################小心
		if(data==2)
		{
				Display(smalllove,1);
		}
		if(data==3)
		{
		i3=20;
		Display(smalllove,0);
		}
		
		
		
		//##################12
		if(data==4)
		{
			Display(twelve,1);
		}
		if(data==5)
		{
		i3=20;
		Display(twelve,0);
		}
		
		
		
		//##################12
		if(data==6)
		{
			Display(q_min,1);
		}
		if(data==7)
		{
			Display(q_min,1);
		}
		
		
		
		
		if(data==8)
		{
		i3=20;
		Display(q_max,0);
		}
		if(data==9)
		{
		Display(q_max,1);
		}
		
		
		
		if(data==10)
		{
		//i3=20;
		Display(biglove,1);
		HAL_Delay(100);
		//i3=20;
		Display(smalllove,1);
		HAL_Delay(100);
		//i3=20;
		Display(twelve,1);
		
		}
		if(data==11)
		{
			R88_on();
			HAL_Delay(100);
			R88_off();
			HAL_Delay(100);
		}
		if(data==12)
		{
		data=0;
		}
		if(data==99)
		{
			Display(as,0);
		}
//		else
//		{
//			Display(biglove,1);
//		//HAL_Delay(200);
//		}
    /* USER CODE BEGIN 3 */
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
//  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
//  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
//  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
//  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
//  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
//  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	
	
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void KeyScan(void)
{
	switch(KeyState)
	{
		case KEY_Check:
		{
			
			if(B1==GPIO_PIN_RESET)
			{KeyState=KEY_Press;
				//HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_13);
			};
		}	
		break;
		case KEY_Press:
		{
			if(B1==GPIO_PIN_RESET)KEY_Value=1;
			KeyState=KEY_Release;	
		}	
		break;
		case KEY_Release:
		{
			if(B1==GPIO_PIN_RESET)
			{
				KEY_Press_TIME=KEY_Press_TIME+10;
			}
			else 
			{
				KeyState=KEY_Check;
				KEY_Flag=1;
			}
		}	
		break;
		default:break;		
	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
