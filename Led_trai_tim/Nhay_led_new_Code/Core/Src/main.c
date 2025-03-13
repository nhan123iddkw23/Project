/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
	uint8_t T_on = 0;
	uint8_t T_off = 0;
	uint64_t time_count = 0;
		uint16_t Phan_tram = 0;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
#define LED1_OFF 		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1) //LED 1
#define LED2_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1) // LED 2
#define LED3_OFF			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1)  // LED 3
#define LED4_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1)  // LED 4
#define LED5_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1)  //LED 31
#define LED6_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1)  // LED 5
#define LED7_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,1)  // LED 6
#define LED8_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1)  // LED 7
#define LED9_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,1) // LED 8
#define LED10_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,1)  // LED 9
#define LED11_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,1)  // LED 10
#define LED12_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,1)  // LED 11
#define LED13_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1)  // LED 12
#define LED14_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1)  // LED 13
#define LED15_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1)  // LED 14
#define LED16_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1) //LED 15
		
#define LED17_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1) //LED 16
#define LED18_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1) //LED 17
#define LED19_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1) //LED 18
#define LED20_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1) //LED 19
#define LED21_OFF 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,1)  // LED 20
#define LED22_OFF 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1)  // LED 21
#define LED23_OFF 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1)  // LED 22
#define LED24_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1)  // LED 23
#define LED25_OFF 		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1) // LED 24
#define LED26_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,1)  // LED 25
#define LED27_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1)  // LED 26
#define LED28_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1)  // LED 32
#define LED29_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1)  // LED 27
#define LED30_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1)  // LED 28
#define LED31_OFF 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1)  // LED 29
#define LED32_OFF 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1)  // LED 30

#define LED1_ON 		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,0) //LED 1
#define LED2_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,0) // LED 2
#define LED3_ON			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,0)  // LED 3
#define LED4_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,0)  // LED 4
#define LED5_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0) //LED 31
#define LED6_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,0)  // LED 5
#define LED7_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,0)  // LED 6
#define LED8_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,0)  // LED 7
#define LED9_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,0) // LED 8
#define LED10_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,0)  // LED 9
#define LED11_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,0)  // LED 10
#define LED12_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,0)  // LED 11
#define LED13_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,0)  // LED 12
#define LED14_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,0)  // LED 13
#define LED15_ON			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,0)  // LED 14
#define LED16_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,0) //LED 15
		
#define LED17_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0) //LED 16
#define LED18_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,0) //LED 17
#define LED19_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,0) //LED 18
#define LED20_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,0) //LED 19
#define LED21_ON 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,0)  // LED 20
#define LED22_ON 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,0)  // LED 21
#define LED23_ON 			HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,0)  // LED 22
#define LED24_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,0)  // LED 23
#define LED25_ON 		  HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,0) // LED 24
#define LED26_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,0)  // LED 25
#define LED27_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,0)  // LED 26
#define LED28_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,0)  // LED 32
#define LED29_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,0)  // LED 27
#define LED30_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,0)  // LED 28
#define LED31_ON 			HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,0)  // LED 29
#define LED32_ON 			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,0)  // LED 30
#define Level1 1
#define Level2 30
#define Level3 70
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define delay 100
#define delay1 50
void delay_us (uint16_t us);
void delay_1us ();
void tat_led();
void bat_led();
void Pwm_Nhap_nhay(uint8_t Phan_tram_sang_led);
void Hat_cat_roi_ben_trai(uint8_t check);
void Hat_cat_roi_ben_phai(uint8_t check);
void bon_canh_hoa();
void Led_lan_ra();
void Led_lan();
void Nhap_nhay_sole();
void Nhay_nguoc();
void Sao_bang_roi_ben_phai(uint8_t check);
void Sao_bang_roi_ben_trai(uint8_t check);
void Nhap_nhay_sole_pwm();
void Mode_1();
void Mode_2();
void Mode_3();
void Mode_4();
void Mode_5();
void Mode_6();
void Mode_7();
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
void tat_led(){
		 HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,1);//LED 1
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,1); // LED 2
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_10,1); // LED 3
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);  // LED 4
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);  //LED 31
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,1);  // LED 5
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,1); // LED 6
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_14,1); // LED 7
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,1); // LED 8
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_12,1); // LED 9
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,1); // LED 10
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,1); // LED 11
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_2,1);  // LED 12
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_1,1);  // LED 13
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,1);  // LED 14
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_7,1);  //LED 15
		
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);  //LED 16
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);  //LED 17
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,1);  //LED 18
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);  //LED 19
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,1); // LED 20
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,1); // LED 21
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_13,1); // LED 22
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_9,1);  // LED 23
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_8,1);  // LED 24
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,1);  // LED 25
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,1);  // LED 26
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,1);  // LED 32
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,1);  // LED 27
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,1);  // LED 28
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_3,1);  // LED 29
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_15,1);  // LED 30
}

void bat_led(){
	LED1_ON;
	LED2_ON;
	LED3_ON;
	LED4_ON;
	LED5_ON;
	LED6_ON;
	LED7_ON;
	LED8_ON;
	LED9_ON;
	LED10_ON;
	LED11_ON;
	LED12_ON;
	LED13_ON;
	LED14_ON;
	LED15_ON;
	LED16_ON;
	LED17_ON;
	LED18_ON;
	LED19_ON;
	LED20_ON;
	LED21_ON;
	LED22_ON;
	LED23_ON;
	LED24_ON;
	LED25_ON;
	LED26_ON;
	LED27_ON;
	LED28_ON;
	LED29_ON;
	LED30_ON;
	LED31_ON;
	LED32_ON;
	 
}
void PWM_Led(uint8_t Phan_tram_sang_led, uint8_t So_led){
	T_on = Phan_tram_sang_led * 100 / 100;
	T_off = 100-T_on;
	if(So_led == 1) {
    LED1_ON;
	  delay_us(T_on);
	  LED1_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 2) {
    LED2_ON;
	  delay_us(T_on);
	  LED2_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 3) {
    LED3_ON;
	  delay_us(T_on);
	  LED3_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 4) {
    LED4_ON;
	  delay_us(T_on);
	  LED4_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 5) {
    LED5_ON;
	  delay_us(T_on);
	  LED5_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 6) {
    LED6_ON;
	  delay_us(T_on);
	  LED6_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 7) {
    LED7_ON;
	  delay_us(T_on);
	  LED7_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 8) {
    LED8_ON;
	  delay_us(T_on);
	  LED8_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 9) {
    LED9_ON;
	  delay_us(T_on);
	  LED9_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 10) {
    LED10_ON;
	  delay_us(T_on);
	  LED10_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 11) {
    LED11_ON;
	  delay_us(T_on);
	  LED11_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 12) {
    LED12_ON;
	  delay_us(T_on);
	  LED12_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 13) {
    LED13_ON;
	  delay_us(T_on);
	  LED13_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 14) {
    LED14_ON;
	  delay_us(T_on);
	  LED14_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 11) {
    LED11_ON;
	  delay_us(T_on);
	  LED11_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 12) {
    LED12_ON;
	  delay_us(T_on);
	  LED12_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 13) {
    LED13_ON;
	  delay_us(T_on);
	  LED13_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 14) {
    LED14_ON;
	  delay_us(T_on);
	  LED14_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 11) {
    LED11_ON;
	  delay_us(T_on);
	  LED11_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 12) {
    LED12_ON;
	  delay_us(T_on);
	  LED12_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 13) {
    LED13_ON;
	  delay_us(T_on);
	  LED13_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 14) {
    LED14_ON;
	  delay_us(T_on);
	  LED14_OFF;
	  delay_us(T_off);
	}
		else	if(So_led == 15) {
    LED15_ON;
	  delay_us(T_on);
	  LED15_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 16) {
    LED16_ON;
	  delay_us(T_on);
	  LED16_OFF;
	  delay_us(T_off);
	}
	else	if(So_led == 17) {
    LED17_ON;
	  delay_us(T_on);
	  LED17_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 18) {
    LED18_ON;
	  delay_us(T_on);
	  LED18_OFF;
	  delay_us(T_off);
	}
		else if(So_led == 19) {
    LED19_ON;
	  delay_us(T_on);
	  LED19_OFF;
	  delay_us(T_off);
	}
  else if(So_led == 20) {
    LED20_ON;
	  delay_us(T_on);
	  LED20_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 21) {
    LED21_ON;
	  delay_us(T_on);
	  LED21_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 22) {
    LED22_ON;
	  delay_us(T_on);
	  LED22_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 23) {
    LED23_ON;
	  delay_us(T_on);
	  LED23_OFF;
	  delay_us(T_off);
	}
	 else if(So_led == 24) {
    LED24_ON;
	  delay_us(T_on);
	  LED24_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 25) {
    LED25_ON;
	  delay_us(T_on);
	  LED25_OFF;
	  delay_us(T_off);
	}
		if(So_led == 26) {
    LED26_ON;
	  delay_us(T_on);
	  LED26_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 27) {
    LED27_ON;
	  delay_us(T_on);
	  LED27_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 28) {
    LED28_ON;
	  delay_us(T_on);
	  LED28_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 29) {
    LED29_ON;
	  delay_us(T_on);
	  LED29_OFF;
	  delay_us(T_off);
	}
	 else if(So_led == 30) {
    LED30_ON;
	  delay_us(T_on);
	  LED30_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 31) {
    LED31_ON;
	  delay_us(T_on);
	  LED31_OFF;
	  delay_us(T_off);
	}
	else if(So_led == 32) {
    LED32_ON;
	  delay_us(T_on);
	  LED32_OFF;
	  delay_us(T_off);
	}	
}
void Sang_nhap_nhay(){
	  HAL_Delay(80);
	  bat_led();
	  HAL_Delay(80);
	  tat_led();  
}


/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

  uint8_t count = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
 HAL_TIM_Base_Start(&htim1);
 	tat_led();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		if(count == 0) {
	    	Mode_1();
		    Mode_2();	
		    Mode_3();
		    Mode_4();
		    Mode_5();
		    Mode_6();
		    Nhap_nhay_sole_pwm();
		    Mode_7();
		}
		if(count == 1) {
		   Mode_1();
	  }
		else if(count == 2) {
       Mode_2();		 
		}
    else if(count == 3) {
		   Mode_3();
	  }
    else if(count == 4) {
	     Mode_4();
	  }
    else if(count == 5) {
       Mode_5();
	  }
		
 
}
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
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 8;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC13 PC14 PC15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA2 PA3 PA4
                           PA5 PA6 PA7 PA8
                           PA9 PA10 PA11 PA12
                           PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4
                          |GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12
                          |GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB10
                           PB11 PB12 PB13 PB14
                           PB15 PB3 PB4 PB5
                           PB6 PB7 PB8 PB9 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_10
                          |GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                          |GPIO_PIN_15|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5
                          |GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 1, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void delay_1us()
{
    __HAL_TIM_SET_COUNTER(&htim1,0);  // set the counter value a 0
    while (__HAL_TIM_GET_COUNTER(&htim1) < 8);  // wait for the counter to reach the us input in the parameter
}

void delay_us (uint16_t us)
{
   while(us>0) {
		 us--;
		 delay_1us();
	 }
}

void Hat_cat_roi_ben_trai(uint8_t check){
	   //32
	 if(check < 16) {
   	 LED32_ON;
	   HAL_Delay(60);
	   }
	  if(check < 15) {
	   //31
	   LED31_ON;	LED32_OFF;
	   HAL_Delay(60);
	 }
	  if(check < 14) {
	   //30
	   LED30_ON;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 13) {
	   //29
	   LED29_ON;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 12) {
	   // 28
	   	LED28_ON;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 11) {
	   //27
	   LED27_ON;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 10) {
		 //26
	    LED26_ON; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 9) {
		 //25
     LED25_ON; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_ON;	LED32_OFF;
	   HAL_Delay(50);
		 //24
	 }
	 if(check < 8) {
	   LED24_ON;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_ON;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 7) {
		 //23
	   LED23_ON; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_ON;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 6) {
		 //22
	   LED22_ON; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_ON;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 5) {
		 //21
	   LED21_ON; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_ON;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 4) {
		 //20
		 LED20_ON; LED21_OFF; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_ON;
	   HAL_Delay(30);
	 }
	 if(check < 3) {
		 //19
	   LED19_ON; LED20_OFF; LED21_OFF; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_ON;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 2) {
		 //18
	   LED18_ON; LED19_OFF; LED20_OFF; LED21_OFF; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_ON;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 1) {
		 //17
	   LED17_ON; LED18_OFF; LED19_OFF; LED20_OFF; LED21_OFF; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_ON;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);	
	 }		 
}


void Hat_cat_roi_ben_phai(uint8_t check){
	   //32
	 if(check < 16) {
   	 LED1_ON;
	   HAL_Delay(60);
	   }
	  if(check < 15) {
	   //31
	   LED2_ON;	LED1_OFF;
	   HAL_Delay(60);
	 }
	  if(check < 14) {
	   //30
	   LED3_ON;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 13) {
	   //29
	   LED4_ON;	LED3_OFF;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 12) {
	   // 28
	   	LED5_ON;	LED4_OFF;	LED3_OFF;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 11) {
	   //27
	   LED6_ON;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 10) {
		 //26
	    LED7_ON; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	  if(check < 9) {
		 //25
     LED8_ON; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(50);
		 //24
	 }
	 if(check < 8) {
	   LED9_ON;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 7) {
		 //23
	   LED9_OFF; LED10_ON;
      LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 6) {
		 //22
	   LED11_ON; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 5) {
		 //21
	   LED12_ON; LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 4) {
		 //20
		 LED13_ON;LED12_OFF; LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	 if(check < 3) {
		 //19
	   LED14_ON;  LED13_OFF;LED12_OFF; LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 2) {
		 //18
	   LED15_ON;LED14_OFF;   LED13_OFF;LED12_OFF; LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 1) {
		 //17
	   LED16_ON;  LED14_OFF;   LED13_OFF;LED12_OFF; LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);	
	 }		 
}


void Sao_bang_roi_ben_trai(uint8_t check){
	   //32
	//      PWM_Led(Level1,6);
	//	    PWM_Led(Level2,7);
	//		  PWM_Led(Level3,8);
	 if(check < 16) {
   	 LED32_ON;
	   HAL_Delay(80);
	   }
	  if(check < 15) {
	   //31
	   LED31_ON;	PWM_Led(Level3,32);;
	   HAL_Delay(80);
	 }
	  if(check < 14) {
	   //30
	   LED30_ON;	PWM_Led(Level3,31);	PWM_Led(Level2,32);
	   HAL_Delay(60);
	 }
	 if(check < 13) {
	   //29
	   LED29_ON;	PWM_Led(Level3,30);	PWM_Led(Level2,31);	PWM_Led(Level1,32);
	   HAL_Delay(80);
	 }
	 if(check < 12) {
	   // 28
	   	LED28_ON;	PWM_Led(Level3,29);	PWM_Led(Level2,30);	PWM_Led(Level1,31);	LED32_OFF;
	   HAL_Delay(80);
	 }
	 if(check < 11) {
	   //27
	   LED27_ON;	PWM_Led(Level3,28);	PWM_Led(Level2,29);	PWM_Led(Level1,30);	LED31_OFF;	LED32_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 10) {
		 //26
	    LED26_ON; PWM_Led(Level3,27);	PWM_Led(Level2,28);	PWM_Led(Level1,29);	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 9) {
		 //25
     LED25_ON; PWM_Led(Level3,26);	PWM_Led(Level2,27);	PWM_Led(Level1,28);	LED29_OFF;	LED30_OFF;	LED31_ON;	LED32_OFF;
	   HAL_Delay(50);
		 //24
	 }
	 if(check < 8) {
	   LED24_ON;
     PWM_Led(Level3,25);	PWM_Led(Level2,26);	PWM_Led(Level1,27);	LED28_OFF;	LED29_OFF;	LED30_ON;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 7) {
		 //23
	   LED23_ON; PWM_Led(Level3,24);	PWM_Led(Level2,25);	PWM_Led(Level1,26);
		 LED27_OFF;	LED28_OFF;	LED29_ON;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 6) {
		 //22
	   LED22_ON; PWM_Led(Level3,23);	PWM_Led(Level2,24);	PWM_Led(Level1,25);
		 LED26_OFF; LED27_OFF;	LED28_ON;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 5) {
		 //21
	   LED21_ON; PWM_Led(Level3,22);	PWM_Led(Level2,23);	PWM_Led(Level1,24);
     LED25_OFF; LED26_OFF; LED27_ON;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 4) {
		 //20
		 LED20_ON; PWM_Led(Level3,21);	PWM_Led(Level2,22);	PWM_Led(Level1,23); LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_OFF;	LED32_ON;
	   HAL_Delay(30);
	 }
	 if(check < 3) {
		 //19
	   LED19_ON;  PWM_Led(Level3,20);	PWM_Led(Level2,21);	PWM_Led(Level1,22); LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_OFF;	LED31_ON;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 2) {
		 //18
	   LED18_ON; PWM_Led(Level3,19);	PWM_Led(Level2,20);	PWM_Led(Level1,21); LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_OFF;	LED30_ON;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 1) {
		 //17
	   LED17_ON;PWM_Led(Level3,18);	PWM_Led(Level2,19);	PWM_Led(Level1,20); LED21_OFF; LED22_OFF; LED23_OFF; LED24_OFF;
     LED25_OFF; LED26_OFF; LED27_OFF;	LED28_OFF;	LED29_ON;	LED30_OFF;	LED31_OFF;	LED32_OFF;
	   HAL_Delay(30);	
	 }		 
}


void Sao_bang_roi_ben_phai(uint8_t check){
	   //32
	 if(check < 16) {
   	 LED1_ON;
	   HAL_Delay(80);
	   }
	  if(check < 15) {
	   //31
	   LED2_ON;	PWM_Led(Level3,1);
	   HAL_Delay(80);
	 }
	  if(check < 14) {
	   //30
	   LED3_ON;		PWM_Led(Level3,2);		PWM_Led(Level2,1);
	   HAL_Delay(80);
	 }
	 if(check < 13) {
	   //29
	   LED4_ON;	PWM_Led(Level3,3);	PWM_Led(Level2,2);  PWM_Led(Level1,1);
	   HAL_Delay(80);
	 }
	 if(check < 12) {
	   // 28
	   LED5_ON;	PWM_Led(Level3,4);	PWM_Led(Level2,3);  PWM_Led(Level1,2);	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 11) {
	   //27
	   LED6_ON;	PWM_Led(Level3,5);	PWM_Led(Level2,4);  PWM_Led(Level1,3);	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	 if(check < 10) {
		 //26
	    LED7_ON;  PWM_Led(Level3,6);	PWM_Led(Level2,5);  PWM_Led(Level1,4);	LED3_OFF;	LED2_OFF;	LED1_OFF;
	   HAL_Delay(60);
	 }
	  if(check < 9) {
		 //25
     LED8_ON; PWM_Led(Level3,7);	PWM_Led(Level2,6);  PWM_Led(Level1,5);	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(50);
		 //24
	 }
	 if(check < 8) {
	   LED9_ON;
     PWM_Led(Level3,8);	PWM_Led(Level2,7);  PWM_Led(Level1,6);	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(50);
	 }
	  if(check < 7) {
		 //23
	   LED10_ON; PWM_Led(Level3,9);	PWM_Led(Level2,8);  PWM_Led(Level1,7);
			LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 6) {
		 //22
	   LED11_ON; PWM_Led(Level3,10);	PWM_Led(Level2,9);  PWM_Led(Level1,8);
		 LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(40);
	 }
	  if(check < 5) {
		 //21
	   LED12_ON; PWM_Led(Level3,11);	PWM_Led(Level2,10);  PWM_Led(Level1,9);
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 4) {
		 //20
		 LED13_ON;PWM_Led(Level3,12);	PWM_Led(Level2,11);  PWM_Led(Level1,10); LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	 if(check < 3) {
		 //19
	   LED14_ON;  PWM_Led(Level3,13);	PWM_Led(Level2,12);  PWM_Led(Level1,11);LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 2) {
		 //18
	   LED15_ON;PWM_Led(Level3,14);	PWM_Led(Level2,13);  PWM_Led(Level1,12); LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);
	 }
	  if(check < 1) {
		 //17
	   LED16_ON;  PWM_Led(Level3,15);	PWM_Led(Level2,14);  PWM_Led(Level1,13); LED11_OFF; LED10_OFF; LED9_OFF;
     LED8_OFF; LED7_OFF; LED6_OFF;	LED5_OFF;	LED4_OFF;	LED3_OFF;	LED2_ON;	LED1_OFF;
	   HAL_Delay(30);	
	 }		 
}

void bon_canh_hoa(){
	//1
	LED1_ON;	LED9_ON;	LED17_ON;	 LED25_ON; HAL_Delay(70);
	//2
	LED2_ON;	LED10_ON;	LED18_ON;	LED26_ON;	HAL_Delay(70);
	//3
	LED3_ON;	LED11_ON;	LED19_ON;	LED27_ON;	HAL_Delay(70);
	//3
	LED4_ON;	LED12_ON;	LED20_ON;	LED28_ON;	HAL_Delay(70);
	//4
	LED5_ON;  LED13_ON;	LED21_ON;	LED29_ON;	HAL_Delay(70);
	//5
	LED6_ON;	LED14_ON;	LED22_ON;	LED30_ON;	HAL_Delay(70);
	//6
	LED7_ON;	LED15_ON;	LED23_ON;	LED31_ON;	HAL_Delay(70);
	//7
	LED8_ON;	LED16_ON;	LED24_ON;	LED32_ON;	HAL_Delay(70);
	

	//7
	LED8_OFF;	LED16_OFF;	LED24_OFF;	LED32_OFF;	HAL_Delay(70);	
		//6
	LED7_OFF;	LED15_OFF;	LED23_OFF;	LED31_OFF;	HAL_Delay(70);	
	//5
	LED6_OFF;	LED14_OFF;	LED22_OFF;	LED30_OFF;	HAL_Delay(70);	
		//4
	LED5_OFF;	LED13_OFF;	LED21_OFF;	LED29_OFF;	HAL_Delay(70);
		//3
	LED4_OFF;	LED12_OFF;	LED20_OFF;	LED28_OFF;	HAL_Delay(70);	
		//3
	LED3_OFF;	LED11_OFF;	LED19_OFF;	LED27_OFF;	HAL_Delay(70);
		//2
	LED2_OFF;	LED10_OFF;	LED18_OFF;	LED26_OFF;	HAL_Delay(70);
	LED1_OFF;	LED9_OFF;	LED17_OFF;	LED25_OFF;	HAL_Delay(70);
	
	
	
		LED8_ON;	LED16_ON;	LED24_ON;	LED32_ON;	HAL_Delay(70);
		LED7_ON;	LED15_ON;	LED23_ON;	LED31_ON;	HAL_Delay(70);
		LED6_ON;	LED14_ON;	LED22_ON;	LED30_ON;	HAL_Delay(70);
		LED5_ON;  LED13_ON;	LED21_ON;	LED29_ON;	HAL_Delay(70);
		LED4_ON;	LED12_ON;	LED20_ON;	LED28_ON;	HAL_Delay(70);
		LED3_ON;	LED11_ON;	LED19_ON;	LED27_ON;	HAL_Delay(70);
		LED2_ON;	LED10_ON;	LED18_ON;	LED26_ON;	HAL_Delay(70);
		LED1_ON;	LED9_ON;	LED17_ON;	 LED25_ON; HAL_Delay(70);
		
		LED1_OFF;	LED9_OFF;	LED17_OFF;	LED25_OFF;	HAL_Delay(70);
		LED2_OFF;	LED10_OFF;	LED18_OFF;	LED26_OFF;	HAL_Delay(70);
		LED3_OFF;	LED11_OFF;	LED19_OFF;	LED27_OFF;	HAL_Delay(70);
		LED4_OFF;	LED12_OFF;	LED20_OFF;	LED28_OFF;	HAL_Delay(70);	
		LED5_OFF;	LED13_OFF;	LED21_OFF;	LED29_OFF;	HAL_Delay(70);
		LED6_OFF;	LED14_OFF;	LED22_OFF;	LED30_OFF;	HAL_Delay(70);	
		LED7_OFF;	LED15_OFF;	LED23_OFF;	LED31_OFF;	HAL_Delay(70);	
		LED8_OFF;	LED16_OFF;	LED24_OFF;	LED32_OFF;	HAL_Delay(70);	
	

}

void Nhap_nhay_sole(){
	    LED1_ON;			LED3_ON;			LED5_ON;			LED7_ON;			LED9_ON;			LED11_ON;			LED13_ON;			LED15_ON;
			LED17_ON;			LED19_ON;			LED21_ON;			LED23_ON;			LED25_ON;			LED27_ON;			LED29_ON;			LED31_ON;
			
			LED2_OFF;			LED4_OFF;			LED6_OFF;			LED8_OFF;			LED10_OFF;			LED12_OFF;			LED14_OFF;			LED16_OFF;
			LED18_OFF;			LED20_OFF;			LED22_OFF;			LED24_OFF;			LED26_OFF;			LED28_OFF;			LED30_OFF;			LED32_OFF;
			HAL_Delay(100);
			LED2_ON;			LED4_ON;			LED6_ON;			LED8_ON;			LED10_ON;			LED12_ON;			LED14_ON;			LED16_ON;			
			LED18_ON;			LED20_ON;			LED22_ON;			LED24_ON;			LED26_ON;			LED28_ON;			LED30_ON;    LED32_ON;
			
			LED1_OFF;			LED3_OFF;			LED5_OFF;			LED7_OFF;		LED9_OFF;			LED11_OFF;			LED13_OFF;			LED15_OFF;
			LED17_OFF;			LED19_OFF;			LED21_OFF;			LED23_OFF;			LED25_OFF;			LED27_OFF;			LED29_OFF;			LED31_OFF;
			HAL_Delay(100);
}

void Nhap_nhay_sole_pwm(){
	 time_count = 0;
	   for(uint8_t i = 0; i < 8; ) {
			   if(count != 0 && count != 7) {
				  break;
				}
			  time_count++;
			  if(time_count == 50){
					i+=1;
					time_count = 0;
				}
			  if(i%2==0) {
	        LED1_ON;			LED3_ON;			LED5_ON;			LED7_ON;			LED9_ON;			LED11_ON;			LED13_ON;			LED15_ON;
		  	  LED17_ON;			LED19_ON;			LED21_ON;			LED23_ON;			LED25_ON;			LED27_ON;			LED29_ON;			LED31_ON;
	        PWM_Led(Level2,2); PWM_Led(Level2,4); PWM_Led(Level2,6); PWM_Led(Level2,8); 
	        PWM_Led(Level2,10); PWM_Led(Level2,12); PWM_Led(Level2,14); PWM_Led(Level2,16); 
	        PWM_Led(Level2,18); PWM_Led(Level2,20); PWM_Led(Level2,22); PWM_Led(Level2,24); 
	        PWM_Led(Level2,26); PWM_Led(Level2,28); PWM_Led(Level2,30); PWM_Led(Level2,32); 
			  }
				else{
					LED2_ON;			LED4_ON;			LED6_ON;			LED8_ON;			LED10_ON;			LED12_ON;			LED14_ON;			LED16_ON;			
			    LED18_ON;			LED20_ON;			LED22_ON;			LED24_ON;			LED26_ON;			LED28_ON;			LED30_ON;    LED32_ON;
					PWM_Led(Level2,1); PWM_Led(Level2,3); PWM_Led(Level2,5); PWM_Led(Level2,7); 
	        PWM_Led(Level2,9); PWM_Led(Level2,11); PWM_Led(Level2,13); PWM_Led(Level2,15); 
	        PWM_Led(Level2,17); PWM_Led(Level2,19); PWM_Led(Level2,21); PWM_Led(Level2,23); 
	        PWM_Led(Level2,25); PWM_Led(Level2,27); PWM_Led(Level2,29); PWM_Led(Level2,31);
				}
		 }   
}
void Led_lan(){
	LED23_ON; LED24_ON; HAL_Delay(delay1);
	LED22_ON; LED25_ON; HAL_Delay(delay1);
	LED21_ON; LED26_ON; HAL_Delay(delay1);
	LED20_ON; LED27_ON; HAL_Delay(delay1);
	LED19_ON; LED28_ON; HAL_Delay(delay1);
	LED18_ON; LED29_ON; HAL_Delay(delay1);
	LED17_ON; LED30_ON; HAL_Delay(delay1);
	LED16_ON; LED31_ON; HAL_Delay(delay1);
	LED15_ON; LED32_ON; HAL_Delay(delay1);
	LED14_ON; LED1_ON; HAL_Delay(delay1);
	LED13_ON; LED2_ON; HAL_Delay(delay1);
	LED12_ON; LED3_ON; HAL_Delay(delay1);
	LED11_ON; LED4_ON; HAL_Delay(delay1);
	LED10_ON; LED5_ON; HAL_Delay(delay1);
	LED9_ON;  LED6_ON; HAL_Delay(delay1);
	LED8_ON;  LED7_ON; HAL_Delay(delay1);
}
void Led_lan_ra(){

	
	LED1_ON; HAL_Delay(delay1);
	LED2_ON; HAL_Delay(delay1);
  LED3_ON; HAL_Delay(delay1);
  LED4_ON; HAL_Delay(delay1);
	LED5_ON; HAL_Delay(delay1);
	LED6_ON; HAL_Delay(delay1);
	LED7_ON; HAL_Delay(delay1);
	LED8_ON; HAL_Delay(delay1);
	LED9_ON; HAL_Delay(delay1);
	LED10_ON; HAL_Delay(delay1);
	LED11_ON; HAL_Delay(delay1);
	LED12_ON; HAL_Delay(delay1);
	LED13_ON; HAL_Delay(delay1);
	
	LED14_ON; HAL_Delay(delay1);
	LED15_ON; HAL_Delay(delay1);
	LED16_ON; HAL_Delay(delay1);
	LED17_ON; HAL_Delay(delay1);
	LED18_ON; HAL_Delay(delay1);
	LED19_ON; HAL_Delay(delay1);
	LED20_ON; HAL_Delay(delay1);
	LED21_ON; HAL_Delay(delay1);
	LED22_ON; HAL_Delay(delay1);
	LED23_ON; HAL_Delay(delay1);
	LED24_ON; HAL_Delay(delay1);
	LED25_ON; HAL_Delay(delay1);
	LED26_ON; HAL_Delay(delay1);
	LED27_ON; HAL_Delay(delay1);
	LED28_ON; HAL_Delay(delay1);
	LED29_ON; HAL_Delay(delay1);
	LED30_ON; HAL_Delay(delay1);
	LED31_ON; HAL_Delay(delay1);
	LED32_ON; HAL_Delay(100);
	 
	LED32_OFF; HAL_Delay(delay1);
	LED31_OFF; HAL_Delay(delay1);
  LED30_OFF; HAL_Delay(delay1);
  LED29_OFF; HAL_Delay(delay1);
	LED28_OFF; HAL_Delay(delay1);
	LED27_OFF; HAL_Delay(delay1);
	LED26_OFF; HAL_Delay(delay1);
	LED25_OFF; HAL_Delay(delay1);
	LED24_OFF; HAL_Delay(delay1);
	LED23_OFF; HAL_Delay(delay1);
	LED22_OFF; HAL_Delay(delay1);
	LED21_OFF; HAL_Delay(delay1);
	LED20_OFF; HAL_Delay(delay1);
	LED19_OFF; HAL_Delay(delay1);
	LED18_OFF; HAL_Delay(delay1);
	LED17_OFF; HAL_Delay(delay1);
	LED16_OFF; HAL_Delay(delay1);
	LED15_OFF; HAL_Delay(delay1);
	LED14_OFF; HAL_Delay(delay1);
	LED13_OFF; HAL_Delay(delay1);
	LED12_OFF; HAL_Delay(delay1);
	LED11_OFF; HAL_Delay(delay1);
	LED10_OFF; HAL_Delay(delay1);
	LED9_OFF; HAL_Delay(delay1);
	LED8_OFF; HAL_Delay(delay1);
	LED7_OFF; HAL_Delay(delay1);
	LED6_OFF; HAL_Delay(delay1);
  LED5_OFF; HAL_Delay(delay1);
	LED4_OFF; HAL_Delay(delay1);
	LED3_OFF; HAL_Delay(delay1);
	LED2_OFF; HAL_Delay(delay1);
	LED1_OFF; HAL_Delay(100);
	
	
	LED32_ON; HAL_Delay(delay1);
	LED31_ON; HAL_Delay(delay1);
  LED30_ON; HAL_Delay(delay1);
  LED29_ON; HAL_Delay(delay1);
	LED28_ON; HAL_Delay(delay1);
	LED27_ON; HAL_Delay(delay1);
	LED26_ON; HAL_Delay(delay1);
	LED25_ON; HAL_Delay(delay1);
	LED24_ON; HAL_Delay(delay1);
	LED23_ON; HAL_Delay(delay1);
	LED22_ON; HAL_Delay(delay1);
	LED21_ON; HAL_Delay(delay1);
	LED20_ON; HAL_Delay(delay1);
	
	LED19_ON; HAL_Delay(delay1);
	LED18_ON; HAL_Delay(delay1);
	LED17_ON; HAL_Delay(delay1);
	LED16_ON; HAL_Delay(delay1);
	LED15_ON; HAL_Delay(delay1);
	LED14_ON; HAL_Delay(delay1);
	LED13_ON; HAL_Delay(delay1);
	LED12_ON; HAL_Delay(delay1);
	LED11_ON; HAL_Delay(delay1);
	LED10_ON; HAL_Delay(delay1);
	LED9_ON; HAL_Delay(delay1);
	LED8_ON; HAL_Delay(delay1);
	LED7_ON; HAL_Delay(delay1);
	LED6_ON; HAL_Delay(delay1);
	LED5_ON; HAL_Delay(delay1);
	LED4_ON; HAL_Delay(delay1);
	LED3_ON; HAL_Delay(delay1);
	LED2_ON; HAL_Delay(delay1);
	LED1_ON; HAL_Delay(100);
	
	LED1_OFF; HAL_Delay(delay1);
	LED2_OFF; HAL_Delay(delay1);
  LED3_OFF; HAL_Delay(delay1);
  LED4_OFF; HAL_Delay(delay1);
	LED5_OFF; HAL_Delay(delay1);
	LED6_OFF; HAL_Delay(delay1);
	LED7_OFF; HAL_Delay(delay1);
	LED8_OFF; HAL_Delay(delay1);
	LED9_OFF; HAL_Delay(delay1);
	LED10_OFF; HAL_Delay(delay1);
	LED11_OFF; HAL_Delay(delay1);
	LED12_OFF; HAL_Delay(delay1);
	LED13_OFF; HAL_Delay(delay1);
	
	LED14_OFF; HAL_Delay(delay1);
	LED15_OFF; HAL_Delay(delay1);
	LED16_OFF; HAL_Delay(delay1);
	LED17_OFF; HAL_Delay(delay1);
	LED18_OFF; HAL_Delay(delay1);
	LED19_OFF; HAL_Delay(delay1);
	LED20_OFF; HAL_Delay(delay1);
	LED21_OFF; HAL_Delay(delay1);
	LED22_OFF; HAL_Delay(delay1);
	LED23_OFF; HAL_Delay(delay1);
	LED24_OFF; HAL_Delay(delay1);
	LED25_OFF; HAL_Delay(delay1);
	LED26_OFF; HAL_Delay(delay1);
	LED27_OFF; HAL_Delay(delay1);
	LED28_OFF; HAL_Delay(delay1);
	LED29_OFF; HAL_Delay(delay1);
	LED30_OFF; HAL_Delay(delay1);
	LED31_OFF; HAL_Delay(delay1);
	LED32_OFF; HAL_Delay(100);
	

}

void Pwm_Nhap_nhay(uint8_t Phan_tram_sang_led){
	T_on = Phan_tram_sang_led * 100 / 100;
	T_off = 100-T_on;
  bat_led();
	delay_us(T_on);
	tat_led();
	delay_us(T_off);
}
void Nhay_nguoc(){
	LED32_ON; LED16_ON; HAL_Delay(70);
	LED31_ON; LED15_ON; HAL_Delay(70);
	LED30_ON; LED14_ON; HAL_Delay(70);
	LED29_ON; LED13_ON; HAL_Delay(70);
	LED28_ON; LED12_ON; HAL_Delay(70);
	LED27_ON; LED11_ON; HAL_Delay(70);
	LED26_ON; LED10_ON; HAL_Delay(70);
	LED25_ON; LED9_ON; HAL_Delay(70);
	LED24_ON; LED8_ON; HAL_Delay(70);
	LED23_ON; LED7_ON; HAL_Delay(70);
	LED22_ON; LED6_ON; HAL_Delay(70);
	LED21_ON; LED5_ON; HAL_Delay(70);
	LED20_ON; LED4_ON; HAL_Delay(70);
	LED19_ON; LED3_ON; HAL_Delay(70);
	LED18_ON; LED2_ON; HAL_Delay(70);
	LED17_ON; LED1_ON; HAL_Delay(100);
	
	LED17_OFF; LED1_OFF; HAL_Delay(70);
	LED18_OFF; LED2_OFF; HAL_Delay(70);
	LED19_OFF; LED3_OFF; HAL_Delay(70);
	LED20_OFF; LED4_OFF; HAL_Delay(70);
	LED21_OFF; LED5_OFF; HAL_Delay(70);
	LED22_OFF; LED6_OFF; HAL_Delay(70);
	LED23_OFF; LED7_OFF; HAL_Delay(70);
	LED24_OFF; LED8_OFF; HAL_Delay(70);
	LED25_OFF; LED9_OFF; HAL_Delay(70);
	LED26_OFF; LED10_OFF; HAL_Delay(70);
	LED27_OFF; LED11_OFF; HAL_Delay(70);
	LED28_OFF; LED12_OFF; HAL_Delay(70);
	LED29_OFF; LED13_OFF; HAL_Delay(70);
	LED30_OFF; LED14_OFF; HAL_Delay(70);
	LED31_OFF; LED15_OFF; HAL_Delay(70);
	LED32_OFF; LED16_OFF; HAL_Delay(70);
	
	LED1_ON; LED17_ON; HAL_Delay(70);
	LED2_ON; LED18_ON; HAL_Delay(70);
	LED3_ON; LED19_ON; HAL_Delay(70);
	LED4_ON; LED20_ON; HAL_Delay(70);
	LED5_ON; LED21_ON; HAL_Delay(70);
	LED6_ON; LED22_ON; HAL_Delay(70);
	LED7_ON; LED23_ON; HAL_Delay(70);
	LED8_ON; LED24_ON; HAL_Delay(70);
	LED9_ON; LED25_ON; HAL_Delay(70);
	LED10_ON; LED26_ON; HAL_Delay(70);
	LED11_ON; LED27_ON; HAL_Delay(70);
	LED12_ON; LED28_ON; HAL_Delay(70);
	LED13_ON; LED28_ON; HAL_Delay(70);
	LED14_ON; LED30_ON; HAL_Delay(70);
	LED15_ON; LED31_ON; HAL_Delay(70);
	LED16_ON; LED32_ON; HAL_Delay(100);
	
	LED32_OFF; LED16_OFF; HAL_Delay(70);
	LED31_OFF; LED15_OFF; HAL_Delay(70);
	LED30_OFF; LED14_OFF; HAL_Delay(70);
	LED29_OFF; LED13_OFF; HAL_Delay(70);
	LED28_OFF; LED12_OFF; HAL_Delay(70);
	LED27_OFF; LED11_OFF; HAL_Delay(70);
	LED26_OFF; LED10_OFF; HAL_Delay(70);
	LED25_OFF; LED9_OFF; HAL_Delay(70);
	LED24_OFF; LED8_OFF; HAL_Delay(70);
	LED23_OFF; LED7_OFF; HAL_Delay(70);
	LED22_OFF; LED6_OFF; HAL_Delay(70);
	LED21_OFF; LED5_OFF; HAL_Delay(70);
	LED20_OFF; LED4_OFF; HAL_Delay(70);
	LED19_OFF; LED3_OFF; HAL_Delay(70);
	LED18_OFF; LED2_OFF; HAL_Delay(70);
	LED17_OFF; LED1_OFF; HAL_Delay(100);
}

void Nhay_1_ben(){
	LED1_ON; LED2_ON; 	LED3_ON; 	LED4_ON; 	LED5_ON; 	LED6_ON; 	LED7_ON; LED8_ON;
	LED9_ON;	LED10_ON;	LED11_ON;	LED12_ON;	LED13_ON;	LED14_ON; 	LED15_ON;	LED16_ON; 
	LED32_OFF;	LED31_OFF; 	LED30_OFF;	LED29_OFF; 	LED28_OFF; 	LED27_OFF; 	LED26_OFF; 	LED25_OFF; 	
	LED24_OFF;	LED23_OFF; 	LED22_OFF; 	LED21_OFF;	LED20_OFF;	LED19_OFF; 	LED18_OFF; 	LED17_OFF; 
	HAL_Delay(70);
	LED1_OFF; LED2_OFF; 	LED3_OFF; 	LED4_OFF; 	LED5_OFF; 	LED6_OFF; 	LED7_OFF; LED8_OFF;
	LED9_OFF;	LED10_OFF;	LED11_OFF;	LED12_OFF;	LED13_OFF;	LED14_OFF; 	LED15_OFF;	LED16_OFF; 
	LED32_ON;	LED31_ON; 	LED30_ON;	LED29_ON; 	LED28_ON; 	LED27_ON; 	LED26_ON; 	LED25_ON; 	
	LED24_ON;	LED23_ON; 	LED22_ON; 	LED21_ON;	LED20_ON;	LED19_ON; 	LED18_ON; 	LED17_ON; 
	HAL_Delay(70);
}


void Mode_1(){
	for(uint8_t n = 0; n < 4; ) {
		  if(count != 0 && count != 1) {
				  break;
				}
	    time_count++;
			if(time_count<10){
				LED32_OFF;
		    PWM_Led(Level1,1);
		    PWM_Led(Level2,2);
		  	PWM_Led(Level3,3);
		    //PWM_Led(99,4);
				LED4_ON;
				
				LED15_OFF;
		    PWM_Led(Level1,16);
		    PWM_Led(Level2,17);
		  	PWM_Led(Level3,18);
		    //PWM_Led(99,19);
				LED19_ON;
			}
			else if(time_count< 20 && time_count>10){
			  LED1_OFF;
			  PWM_Led(Level1,2);
		    PWM_Led(Level2,3);
			  PWM_Led(Level3,4);
		   // PWM_Led(99,5);
				LED5_ON;
				
				LED16_OFF;
			  PWM_Led(Level1,17);
		    PWM_Led(Level2,18);
			  PWM_Led(Level3,19);
		    //PWM_Led(99,20);
				LED20_ON;
			}
			else if(time_count<30 && time_count > 20){
				LED2_OFF;
		    PWM_Led(Level1,3);
		    PWM_Led(Level2,4);
		  	PWM_Led(Level3,5);
		    //PWM_Led(99,6);
				LED6_ON;
				
				LED17_OFF;
		    PWM_Led(Level1,18);
		    PWM_Led(Level2,19);
		  	PWM_Led(Level3,20);
		    //PWM_Led(99,21);
				LED21_ON;
			}
			else if(time_count< 40 && time_count>30){
			  LED3_OFF;
			  PWM_Led(Level1,4);
		    PWM_Led(Level2,5);
			  PWM_Led(Level3,6);
		   // PWM_Led(99,7);
				LED7_ON;
				
				LED18_OFF;
		    PWM_Led(Level1,19);
		    PWM_Led(Level2,20);
		  	PWM_Led(Level3,21);
		    //PWM_Led(99,22);
				LED22_ON;
			}
			else if(time_count< 50 && time_count>40){
				LED4_OFF;
		    PWM_Led(Level1,5);
		    PWM_Led(Level2,6);
		  	PWM_Led(Level3,7);
		    //PWM_Led(99,8);
				LED8_ON;
				
				LED19_OFF;
		    PWM_Led(Level1,20);
		    PWM_Led(Level2,21);
		  	PWM_Led(Level3,22);
		    //PWM_Led(99,23);
				LED23_ON;
			}
			else if(time_count< 60 && time_count>50){
			  LED5_OFF;
			  PWM_Led(Level1,6);
		    PWM_Led(Level2,7);
			  PWM_Led(Level3,8);
		   // PWM_Led(99,9);
				LED9_ON;
				
				LED20_OFF;
		    PWM_Led(Level1,21);
		    PWM_Led(Level2,22);
		  	PWM_Led(Level3,23);
		   // PWM_Led(99,24);
				LED24_ON;
			}
			else if(time_count< 80 && time_count>70){
				LED6_OFF;
		    PWM_Led(Level1,7);
		    PWM_Led(Level2,8);
		  	PWM_Led(Level3,9);
		    //PWM_Led(99,10);
				LED10_ON;
				
				LED21_OFF;
		    PWM_Led(Level1,22);
		    PWM_Led(Level2,23);
		  	PWM_Led(Level3,24);
		    //PWM_Led(99,25);
				LED25_ON;
				
			}
			else if(time_count< 90 && time_count>80){
			  LED7_OFF;
			  PWM_Led(Level1,8);
		    PWM_Led(Level2,9);
			  PWM_Led(Level3,10);
		   // PWM_Led(99,11);
				LED11_ON;
				
				LED22_OFF;
		    PWM_Led(Level1,23);
		    PWM_Led(Level2,24);
		  	PWM_Led(Level3,25);
		   // PWM_Led(99,26);
				LED26_ON;
			}
			else if(time_count< 100 && time_count>90){
				LED8_OFF;
		    PWM_Led(Level1,9);
		    PWM_Led(Level2,10);
		  	PWM_Led(Level3,11);
		    //PWM_Led(99,12);
				LED12_ON;
				
				LED23_OFF;
		    PWM_Led(Level1,24);
		    PWM_Led(Level2,25);
		  	PWM_Led(Level3,26);
		    //PWM_Led(99,27);
				LED27_ON;
			}
			else if(time_count< 110 && time_count>100){
			  LED9_OFF;
			  PWM_Led(Level1,10);
		    PWM_Led(Level2,11);
			  PWM_Led(Level3,12);
		    //PWM_Led(99,13);
				LED13_ON;
				
				LED24_OFF;
		    PWM_Led(Level1,25);
		    PWM_Led(Level2,26);
		  	PWM_Led(Level3,27);
		   // PWM_Led(99,28);
				LED28_ON;
			}
			else if(time_count< 120 && time_count>110){
			  LED10_OFF;
			  PWM_Led(Level1,11);
		    PWM_Led(Level2,12);
			  PWM_Led(Level3,13);
		    //PWM_Led(99,14);
				LED14_ON;
				
				LED25_OFF;
		    PWM_Led(Level1,26);
		    PWM_Led(Level2,27);
		  	PWM_Led(Level3,28);
		   // PWM_Led(99,29);
				LED29_ON;
			}
			else if(time_count< 130 && time_count>120){
				LED11_OFF;
		    PWM_Led(Level1,12);
		    PWM_Led(Level2,13);
		  	PWM_Led(Level3,14);
		  //  PWM_Led(99,15);
				LED15_ON;
				
				LED26_OFF;
		    PWM_Led(Level1,27);
		    PWM_Led(Level2,28);
		  	PWM_Led(Level3,29);
		   // PWM_Led(99,30);
				LED30_ON;
			}
			else if(time_count< 140 && time_count>130){
			  LED12_OFF;
			  PWM_Led(Level1,13);
		    PWM_Led(Level2,14);
			  PWM_Led(Level3,15);
		    //PWM_Led(99,16);
				LED16_ON;
				
				LED27_OFF;
		    PWM_Led(Level1,28);
		    PWM_Led(Level2,29);
		  	PWM_Led(Level3,30);
		    //PWM_Led(99,31);
				LED31_ON;
			}
			else if(time_count< 150 && time_count>140){
				LED13_OFF;
		    PWM_Led(Level1,14);
		    PWM_Led(Level2,15);
		  	PWM_Led(Level3,16);
		    //PWM_Led(99,17);
				LED17_ON;
				
				LED28_OFF;
		    PWM_Led(Level1,29);
		    PWM_Led(Level2,30);
		  	PWM_Led(Level3,31);
		    //PWM_Led(99,32);
				LED32_ON;
			}
			else if(time_count< 160 && time_count>150){
			  LED14_OFF;
			  PWM_Led(Level1,15);
		    PWM_Led(Level2,16);
			  PWM_Led(Level3,17);
		    //PWM_Led(99,18);
				LED18_ON;
				
			  LED29_OFF;
			  PWM_Led(Level1,30);
		    PWM_Led(Level2,31);
			  PWM_Led(Level3,32);
		   // PWM_Led(99,1);
				LED1_ON;
			}
			else if(time_count< 170 && time_count>160){
			  LED15_OFF;
			  PWM_Led(Level1,16);
		    PWM_Led(Level2,17);
			  PWM_Led(Level3,18);
		    //PWM_Led(99,19);
				LED19_ON;
				
				LED30_OFF;
		    PWM_Led(Level1,31);
		    PWM_Led(Level2,32);
		  	PWM_Led(Level3,1);
		    //PWM_Led(99,2);
				LED2_ON;
			}
			else if(time_count< 180 && time_count>170){
				LED16_OFF;
		    PWM_Led(Level1,17);
		    PWM_Led(Level2,18);
		  	PWM_Led(Level3,19);
		    //PWM_Led(99,20);
				LED20_ON;
				
			  LED31_OFF;
			  PWM_Led(Level1,32);
		    PWM_Led(Level2,1);
			  PWM_Led(Level3,2);
		    //PWM_Led(99,3);
				LED3_ON;
			}
			else if(time_count< 190 && time_count>180){
			  LED17_OFF;
			  PWM_Led(Level1,18);
		    PWM_Led(Level2,19);
			  PWM_Led(Level3,20);
		    //PWM_Led(99,21);
				LED21_ON;
				
				LED32_OFF;
		    PWM_Led(Level1,1);
		    PWM_Led(Level2,2);
		  	PWM_Led(Level3,3);
		   // PWM_Led(99,4);
				LED4_ON;
			}
			else if(time_count< 200 && time_count>190){
			  LED18_OFF;
			  PWM_Led(Level1,19);
		    PWM_Led(Level2,20);
			  PWM_Led(Level3,21);
		    //PWM_Led(99,22);
				LED22_ON;
				
				LED1_OFF;
		    PWM_Led(Level1,2);
		    PWM_Led(Level2,3);
		  	PWM_Led(Level3,4);
		    //PWM_Led(99,5);
				LED5_ON;
			}
			else if(time_count< 210 && time_count>200){
				LED19_OFF;
		    PWM_Led(Level1,20);
		    PWM_Led(Level2,21);
		  	PWM_Led(Level3,22);
		    //PWM_Led(99,23);
				LED23_ON;
				
				LED2_OFF;
		    PWM_Led(Level1,3);
		    PWM_Led(Level2,4);
		  	PWM_Led(Level3,5);
		    //PWM_Led(99,6);
				LED6_ON;
			}
			else if(time_count< 220 && time_count>210){
			  LED20_OFF;
			  PWM_Led(Level1,21);
		    PWM_Led(Level2,22);
			  PWM_Led(Level3,23);
		   // PWM_Led(99,24);
				LED24_ON;
				
				LED3_OFF;
		    PWM_Led(Level1,4);
		    PWM_Led(Level2,5);
		  	PWM_Led(Level3,6);
		    //PWM_Led(99,7);
				LED7_ON;
			}
			else if(time_count< 230 && time_count>220){
				LED21_OFF;
		    PWM_Led(Level1,22);
		    PWM_Led(Level2,23);
		  	PWM_Led(Level3,24);
		   // PWM_Led(99,25);
				LED25_ON;
				
				LED4_OFF;
		    PWM_Led(Level1,5);
		    PWM_Led(Level2,6);
		  	PWM_Led(Level3,7);
		   // PWM_Led(99,8);
				LED8_ON;
			}
			else if(time_count< 240 && time_count>230){
			  LED22_OFF;
			  PWM_Led(Level1,23);
		    PWM_Led(Level2,24);
			  PWM_Led(Level3,25);
		   // PWM_Led(99,26);
				LED26_ON;
				
				LED5_OFF;
		    PWM_Led(Level1,6);
		    PWM_Led(Level2,7);
		  	PWM_Led(Level3,8);
		   // PWM_Led(99,9);
				LED9_ON;
			}
			else if(time_count< 250 && time_count>220){
			  LED23_OFF;
			  PWM_Led(Level1,24);
		    PWM_Led(Level2,25);
			  PWM_Led(Level3,26);
		    //PWM_Led(99,27);
				LED27_ON;
				
				LED6_OFF;
		    PWM_Led(Level1,7);
		    PWM_Led(Level2,8);
		  	PWM_Led(Level3,9);
		    //PWM_Led(99,10);
				LED10_ON;
			}
			else if(time_count< 260 && time_count>250){
			  LED24_OFF;
			  PWM_Led(Level1,25);
		    PWM_Led(Level2,26);
			  PWM_Led(Level3,27);
		    //PWM_Led(99,28);
				LED28_ON;
				
				LED7_OFF;
		    PWM_Led(Level1,8);
		    PWM_Led(Level2,9);
		  	PWM_Led(Level3,10);
		    //PWM_Led(99,11);
				LED11_ON;
			}
			else if(time_count< 270 && time_count>260){
				LED25_OFF;
		    PWM_Led(Level1,26);
		    PWM_Led(Level2,27);
		  	PWM_Led(Level3,28);
		    //PWM_Led(99,29);
				LED29_ON;
				
				LED8_OFF;
		    PWM_Led(Level1,9);
		    PWM_Led(Level2,10);
		  	PWM_Led(Level3,11);
		    //PWM_Led(99,12);
				LED12_ON;
			}
			else if(time_count< 280 && time_count>270){
			  LED26_OFF;
			  PWM_Led(Level1,27);
		    PWM_Led(Level2,28);
			  PWM_Led(Level3,29);
		    //PWM_Led(99,30);
				LED30_ON;
				
				LED9_OFF;
		    PWM_Led(Level1,10);
		    PWM_Led(Level2,11);
		  	PWM_Led(Level3,12);
		    //PWM_Led(99,13);
				LED13_ON;
			}
			else if(time_count< 290 && time_count>280){
			  LED27_OFF;
			  PWM_Led(Level1,28);
		    PWM_Led(Level2,29);
			  PWM_Led(Level3,30);
		   // PWM_Led(99,31);
				LED31_ON;
				
				LED10_OFF;
		    PWM_Led(Level1,11);
		    PWM_Led(Level2,12);
		  	PWM_Led(Level3,13);
		    //PWM_Led(99,14);
				LED14_ON;
			}
			else if(time_count< 300 && time_count>290){
				LED28_OFF;
		    PWM_Led(Level1,29);
		    PWM_Led(Level2,30);
		  	PWM_Led(Level3,31);
		    //PWM_Led(99,32);
				LED32_ON;
				
				LED11_OFF;
		    PWM_Led(Level1,12);
		    PWM_Led(Level2,13);
		  	PWM_Led(Level3,14);
		   // PWM_Led(99,15);
				LED15_ON;
			}
			else if(time_count< 310 && time_count>300){
			  LED29_OFF;
			  PWM_Led(Level1,30);
		    PWM_Led(Level2,31);
			  PWM_Led(Level3,32);
		    //PWM_Led(99,1);
				LED1_ON;
				
				LED12_OFF;
		    PWM_Led(Level1,13);
		    PWM_Led(Level2,14);
		  	PWM_Led(Level3,15);
		    //PWM_Led(99,16);
				LED16_ON;
			}
			else if(time_count< 320 && time_count>310){
				LED30_OFF;
		    PWM_Led(Level1,31);
		    PWM_Led(Level2,32);
		  	PWM_Led(Level3,1);
		    //PWM_Led(99,2);
				LED2_ON;
				
				LED13_OFF;
		    PWM_Led(Level1,14);
		    PWM_Led(Level2,15);
		  	PWM_Led(Level3,16);
		   // PWM_Led(99,17);
				LED17_ON;
			}
			else if(time_count< 330 && time_count>320){
			  LED31_OFF;
			  PWM_Led(Level1,32);
		    PWM_Led(Level2,1);
			  PWM_Led(Level3,2);
		    //PWM_Led(99,3);
				LED3_ON;
				
				LED14_OFF;
		    PWM_Led(Level1,15);
		    PWM_Led(Level2,16);
		  	PWM_Led(Level3,17);
		    //PWM_Led(99,18);
				LED18_ON;
			}
			else if(time_count > 330) {
				 time_count = 0;
			   n+=1;
			}
	 }
	for(uint8_t i = 0; i < 5; i++) {
		  Nhap_nhay_sole();
			 if(count == 2) {
					break;
				}
			}
}

void Mode_2(){
	 for(uint8_t n = 0; n < 4; n++){
		   if(count != 0 && count != 2) {
				  break;
				}
		 uint16_t i =0;
		 HAL_Delay(50);
	   while(Phan_tram<99) {
			 i++;
			 if(i == 10 && Phan_tram < 99) {
				 Phan_tram+=1;
				 i = 0;
			 }

			 
			   Pwm_Nhap_nhay(Phan_tram);
			 if(Phan_tram == 99) {
				 bat_led();
			   }
		   } 
		   HAL_Delay(50);
			 Phan_tram = 100;
		 	 while(Phan_tram>0) {
			 i++;
			 if(i == 10 && Phan_tram > 0) {
				 Phan_tram-=1;
				 i = 0;
			 }

			 
			   Pwm_Nhap_nhay(Phan_tram);
			 if(Phan_tram == 0) {
				 tat_led();
			   }
		   }
		 }
}

void Mode_3(){
		for(uint8_t  i = 0; i <= 16; i++) {
			   if(count != 0 && count != 3) {
				  break;
				}
		   Hat_cat_roi_ben_trai(i);
			 Hat_cat_roi_ben_phai(i);
	   }
}

void Mode_4(){
	 	 tat_led();
		 for(uint8_t i = 0; i < 3; i++) {
			  if(count != 0 && count != 4) {
				  break;
				}
		  bon_canh_hoa();
			  if(count == 5) {
					break;
				}
		 }
		 for(uint8_t i = 0; i < 10; i++) {
			   if(count != 0 && count != 4) {
				  break;
				}
		  Nhap_nhay_sole();
			 if(count == 5) {
					break;
				}
		 }
}

void Mode_5(){
	   
		 tat_led();
		 Led_lan();
		  tat_led();
		 for(uint8_t i = 0; i < 2; i++) {
			   if(count != 0 && count != 5) {
				  break;
				}
		  Led_lan_ra();	
		 }
		 	LED32_ON; LED1_ON; HAL_Delay(delay1);
	    LED31_ON; LED2_ON; HAL_Delay(delay1);
    	LED30_ON; LED3_ON; HAL_Delay(delay1);
	    LED29_ON; LED4_ON; HAL_Delay(delay1);
    	LED28_ON; LED5_ON; HAL_Delay(delay1);
	    LED27_ON; LED6_ON; HAL_Delay(delay1);
	    LED26_ON; LED7_ON; HAL_Delay(delay1);
	    LED25_ON; LED8_ON; HAL_Delay(delay1);
	    LED24_ON; LED9_ON; HAL_Delay(delay1);
	    LED23_ON; LED10_ON; HAL_Delay(delay1);
	    LED22_ON; LED11_ON; HAL_Delay(delay1);
	    LED21_ON; LED12_ON; HAL_Delay(delay1);
	    LED20_ON; LED13_ON; HAL_Delay(delay1);
	    LED19_ON; LED14_ON; HAL_Delay(delay1);
	    LED18_ON;  LED15_ON; HAL_Delay(delay1);
	    LED17_ON;  LED16_ON; HAL_Delay(delay1);
		 for(uint8_t i = 0; i < 4; i++) {
			   if(count != 0 && count != 5) {
				  break;
				}
  	  bat_led();
	    HAL_Delay(delay1);
	    tat_led();
	   HAL_Delay(delay1);
	  }
		 count = 0;
}

void Mode_6(){
	for(uint8_t i = 0; i < 4; i++) {
		  if(count != 0 && count != 6) {
				  break;
				}
		Nhay_nguoc();
	}
}

void Mode_7(){
		for(uint8_t  i = 0; i <= 16; i++) {
			  if(count != 0 && count != 8) {
				  break;
				}
		   Sao_bang_roi_ben_trai(i);
			 Sao_bang_roi_ben_phai(i);
	   }
}
void EXTI0_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI0_IRQn 0 */
  count++;
	if(count == 9) {
		count = 0;
	}
  /* USER CODE END EXTI0_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
  /* USER CODE BEGIN EXTI0_IRQn 1 */

  /* USER CODE END EXTI0_IRQn 1 */
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
