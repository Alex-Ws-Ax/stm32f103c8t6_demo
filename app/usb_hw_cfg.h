#ifndef __USB_HW_CFG_H_
#define __USB_HW_CFG_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "platform_config.h"
#include <stdint.h>
#include "usb_type.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported define -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void Set_System(void);
void Set_USBClock(void);
void Enter_LowPowerMode(void);
void Leave_LowPowerMode(void);
void USB_Interrupts_Config(void);
void USB_Cable_Config (FunctionalState NewState);
void USART_Config_Default(void);
bool USART_Config(void);
void USB_To_USART_Send_Data(uint8_t* data_buffer, uint8_t Nb_bytes);
void USART_To_USB_Send_Data(void);
void Handle_USBAsynchXfer (void);
void Get_SerialNum(void);
void VCP_RX_DMA_Channel_ISR(void);
void VCP_SendRxBufPacketToUsb(void);
void VCP_Data_InISR(void);
/* External variables --------------------------------------------------------*/


#endif
