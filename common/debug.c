#include <string.h>
#include "debug.h"
#include "stm32f10x_usart.h"

#define     DEBUG_CMD_PARSE_EN  0
#define     DEBUG_UART      (DEBUG_UART2)
#define     MAX_RX_LEN      64

unsigned char  rx_buf[MAX_RX_LEN] = {0};
unsigned char  rx_index = 0;
unsigned short debug_level = DEBUG_ALL;

#if (DEBUG_UART == DEBUG_UART1)
#define DEBUG_HW_UART   USART1
#elif (DEBUG_UART == DEBUG_UART2)
#define DEBUG_HW_UART   USART2
#endif

#if (DEBUG_UART == DEBUG_UART1)
#define    debug_handler    USART1_IRQHandler
#elif (DEBUG_UART == DEBUG_UART2)
#define    debug_handler    USART2_IRQHandler
#endif

void UART_GPIO_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

#if (DEBUG_UART == DEBUG_UART1)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_10;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
#elif (DEBUG_UART == DEBUG_UART2)
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_3;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
#endif
}


void DebugInit(void)
{
    USART_InitTypeDef uart_init_t = {0};
    NVIC_InitTypeDef nvic_init_t = {0};


#if (DEBUG_UART == DEBUG_UART1)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
#elif (DEBUG_UART == DEBUG_UART2)
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
#endif
    
    
    UART_GPIO_Config();
    USART_StructInit(&uart_init_t);
    USART_Init(DEBUG_HW_UART, &uart_init_t);
#if DEBUG_CMD_PARSE_EN
    USART_ITConfig(DEBUG_UART, USART_IT_RXNE, ENABLE);

    nvic_init_t.NVIC_IRQChannel = USART1_IRQn;
    nvic_init_t.NVIC_IRQChannelPreemptionPriority  = 0;
    nvic_init_t.NVIC_IRQChannelSubPriority         = 0;
    nvic_init_t.NVIC_IRQChannelCmd                 = ENABLE;

    NVIC_Init(&nvic_init_t);
#endif
    USART_Cmd(DEBUG_HW_UART, ENABLE);
}
#if DEBUG_CMD_PARSE_EN
void debug_handler(void)
{
    if (USART_GetITStatus(DEBUG_HW_UART, USART_IT_RXNE) == SET)
    {
        unsigned char data = USART_ReceiveData(DEBUG_HW_UART);
        if (rx_index < MAX_RX_LEN)
        {
            if ((data == 0x0A) || (data == 0x0D))
            {

                cmd_parsing((char *)rx_buf);

                rx_index = 0;
                memset(rx_buf, 0, MAX_RX_LEN);
            }
            else
            {
                rx_buf[rx_index++] = data;
            }
        }
        else
        {
            rx_index = 0;
            memset(rx_buf, 0, MAX_RX_LEN);
        }
        USART_ClearITPendingBit(DEBUG_HW_UART, USART_IT_RXNE);
    }

}
#endif
int fputc(int ch, FILE *p)
{
    USART_SendData(DEBUG_HW_UART, (u8)ch);

    while (USART_GetFlagStatus(DEBUG_HW_UART, USART_FLAG_TXE) == RESET);

    return ch;
}

