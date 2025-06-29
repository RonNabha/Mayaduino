/*
 *******************************************************************************
 * Copyright (c) 2017-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause 
 *
 *******************************************************************************
 */
#if defined(ARDUINO_BLACK_F407VE) || defined(ARDUINO_BLACK_F407VG) || defined(ARDUINO_MAYA_1)

#include "pins_arduino.h"

// Digital PinName array
// This array allows to wrap Arduino pin number(Dx or x)
// to STM32 PinName (PX_n)
const PinName digitalPin[] = {
  // Right Side
  //Int   //Ext
  //3V3   //3V3
  //3V3   //3V3
  //BOOT0 //BOOT1
  //GND   //GND
  //GND   //GND
  PE_1,   PE_0,   // D0, D1
  PB_9,   PB_8,
  PB_7,   PB_6,
  PB_5,   PB_3,
  PD_7,   PD_6,
  PD_5,   PD_4,   // D10, D11
  PD_3,   PD_2,
  PD_1,   PD_0,
  PC_12,  PC_11,
  PC_10,  PA_15,
  PA_12,  PA_11,  // D20, D21 PA_11: USB_DM, PA_12: USB_DP
  PA_10,  PA_9,
  PA_8,   PC_9,
  PC_8,   PC_7,
  PC_6,   PD_15,
  PD_14,  PD_13,  // D30, D31
  PD_12,  PD_11,
  PD_10,  PD_9,
  PD_8,   PB_15,
  // Left Side
  //Ext   //Int
  //5V    //5V
  //5V    //5V
  //3V3   //3V3
  //3V3   //3V3
  //GND   //GND
  PE_2,   PE_3,
  PE_4,   PE_5,   // D40, D41 PE_4: BUT K0, PE_5: BUT K1
  PE_6,   PC_13,
  PC_0,   PC_1,
  PC_2,   PC_3,
  //VREF- //VREF+
  PA_0,   PA_1,   // PA_0(WK_UP): BUT K_UP)
  PA_2,   PA_3,   // D50, D51
  PA_4,   PA_5,
  /*PA_6,   PA_7,*/ // PA_6, PA_7: Moved to allow contiguous analog pins
  PC_4,   PC_5,
  PB_0,   PB_1,
  PA_6,   PA_7,   // PA_6: LED D2, PA_7: LED D3 (active LOW)
  PE_7,   PE_8,   // D60, D61
  PE_9,   PE_10,
  PE_11,  PE_12,
  PE_13,  PE_14,
  PE_15,  PB_10,
  PB_11,  PB_12,  // D70, D71
  PB_13,  PB_14,
  PB_4,
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  44, // A0
  45, // A1
  46, // A2
  47, // A3
  48, // A4
  49, // A5
  50, // A6
  51, // A7
  52, // A8
  53, // A9
  54, // A10
  55, // A11
  56, // A12
  57, // A13
  58, // A14
  59  // A16

};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /**Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    Error_Handler();
  }

  /* Ensure CCM RAM clock is enabled */
  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE();

}

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_BLACK_F407VE || ARDUINO_BLACK_F407VG */
