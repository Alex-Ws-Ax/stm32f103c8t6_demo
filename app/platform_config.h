/**
  ******************************************************************************
  * @file    platform_config.h
  * @author  MCD Application Team
  * @version V4.1.0
  * @date    26-May-2017
  * @brief   Evaluation board specific configuration file.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2017 STMicroelectronics International N.V.
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __PLATFORM_CONFIG_H
#define __PLATFORM_CONFIG_H
#include "stm32f10x.h"
/* Includes ------------------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Define if Low power mode is enabled; it allows entering the device into
   STOP mode following USB Suspend event, and wakes up after the USB wakeup
   event is received. */
//#define USB_LOW_PWR_MGMT_SUPPORT

/*Unique Devices IDs register set*/
#if defined(STM32L1XX_MD) || defined(STM32L1XX_HD) || defined(STM32L1XX_MD_PLUS)

    #define         ID1          (0x1FF80050)
    #define         ID2          (0x1FF80054)
    #define         ID3          (0x1FF80064)

#elif defined (STM32F37X) || defined(STM32F303xC) || defined(STM32F303xE)

    #define         ID1          (0x1FFFF7AC)
    #define         ID2          (0x1FFFF7B0)
    #define         ID3          (0x1FFFF7B4)

#else /*STM32F1x*/

    #define         ID1          (0x1FFFF7E8)
    #define         ID2          (0x1FFFF7EC)
    #define         ID3          (0x1FFFF7F0)

#endif

/* Define the STM32F10x hardware depending on the used evaluation board */
#define USB_DISCONNECT                      GPIOD
#define USB_DISCONNECT_PIN                  GPIO_Pin_9
#define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOD
#define EVAL_COM1_IRQHandler                USART1_IRQHandler
#define RCC_APB2Periph_ALLGPIO              (RCC_APB2Periph_GPIOA \
                                               | RCC_APB2Periph_GPIOB \
                                               | RCC_APB2Periph_GPIOC \
                                               | RCC_APB2Periph_GPIOD \
                                               | RCC_APB2Periph_GPIOE )

#define USARTx_DR_ADDRESS                0x40013804
#define USARTx_TX_DMA_CHANNEL            DMA1_Channel4
#define USARTx_TX_DMA_FLAG_TC            DMA1_FLAG_TC4
#define USARTx_TX_DMA_FLAG_GL            DMA1_FLAG_GL4
#define USARTx_TX_DMA_IRQ                DMA1_Channel4_IRQn
#define DMAx_CLK                         RCC_AHBPeriph_DMA1

/* UART defines For STM32F10x (can be ported to any other devices) */
#define VCP_USART               USART1
#define VCP_USART_CLK           RCC_APB2Periph_USART1
#define VCP_USART_APB_CLK       RCC_APB2PeriphClockCmd
#define VCP_USART_GPIO_CLK      RCC_APB2Periph_GPIOA
#define VCP_USART_GPIO_APB_CLK  RCC_APB2PeriphClockCmd
#define VCP_USART_TX_PIN        GPIO_Pin_9
#define VCP_USART_RX_PIN        GPIO_Pin_10

/* DMA defines For STM32F10x (can be ported to any other devices) */
#define VCP_RX_DMA_CHANNEL      DMA1_Channel5
#define VCP_RX_DMA_IRQ          DMA1_Channel5_IRQn
#define VCP_RX_DMA_IT_TC        DMA1_IT_TC5
#define VCP_RX_DMA_IRQHandler   DMA1_Channel5_IRQHandler
#define VCP_RX_DMA_FLAG_GL      DMA1_FLAG_GL5
#define VCP_RX_DMA_FLAG_TC      DMA1_FLAG_TC5

#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1
#define EVAL_COM1_TX_PIN                 GPIO_Pin_9
#define EVAL_COM1_TX_GPIO_PORT           GPIOA
#define EVAL_COM1_TX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM1_RX_PIN                 GPIO_Pin_10
#define EVAL_COM1_RX_GPIO_PORT           GPIOA
#define EVAL_COM1_RX_GPIO_CLK            RCC_APB2Periph_GPIOA
#define EVAL_COM1_IRQn                   USART1_IRQn

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __PLATFORM_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
