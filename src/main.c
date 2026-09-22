#include "stm.h"

static void delay(volatile uint32_t n)
{
    while (n--)
    {
        __asm volatile ("nop");
    }
}

static void uart_init(void)
{
    RCC_AHB1ENR |= (1U << 0);
    RCC_APB1ENR |= (1U << 17);

    GPIOA_MODER &= ~((3U << 4) | (3U << 6));
    GPIOA_MODER |=  ((2U << 4) | (2U << 6));

    GPIOA_OTYPER &= ~((1U << 2) | (1U << 3));
    GPIOA_OSPEEDR |= ((3U << 4) | (3U << 6));
    GPIOA_PUPDR &= ~((3U << 4) | (3U << 6));

    GPIOA_AFRL &= ~((0xFU << 8) | (0xFU << 12));
    GPIOA_AFRL |=  ((7U << 8) | (7U << 12));

    USART2_BRR = 0x0683;
    USART2_CR1 = (1U << 13) | (1U << 3) | (1U << 2);
}

static void uart_write(char c)
{
    while (!(USART2_SR & (1U << 7)))
    {
    }
    USART2_DR = c;
}

static void uart_print(const char *s)
{
    while (*s)
    {
        uart_write(*s++);
    }
}

static void can_init(void)
{
    RCC_AHB1ENR |= (1U << 0);
    RCC_APB1ENR |= (1U << 25);

    GPIOA_MODER &= ~((3U << 22) | (3U << 24));
    GPIOA_MODER |=  ((2U << 22) | (2U << 24));

    GPIOA_OTYPER &= ~((1U << 11) | (1U << 12));
    GPIOA_OSPEEDR |= ((3U << 22) | (3U << 24));
    GPIOA_PUPDR &= ~((3U << 22) | (3U << 24));

    GPIOA_AFRH &= ~((0xFU << 12) | (0xFU << 16));
    GPIOA_AFRH |=  ((9U << 12) | (9U << 16));

    CAN1_MCR |= (1U << 0);
    while (!(CAN1_MSR & (1U << 0)))
    {
    }

    CAN1_MCR |= (1U << 15);
    CAN1_BTR = (1U << 30) | (3U << 20) | (2U << 16) | (11U << 0);

    CAN1_FMR |= (1U << 0);
    CAN1_FA1R &= ~(1U << 0);
    CAN1_FM1R &= ~(1U << 0);
    CAN1_FS1R |= (1U << 0);
    CAN1_FFA1R &= ~(1U << 0);
    CAN1_F0R1 = 0;
    CAN1_F0R2 = 0;
    CAN1_FA1R |= (1U << 0);
    CAN1_FMR &= ~(1U << 0);

    CAN1_MCR &= ~((1U << 0) | (1U << 1));
    while (CAN1_MSR & (1U << 0))
    {
    }
}

static void can_send(uint32_t id, uint8_t *data, uint8_t len)
{
    while (!(CAN1_TSR & (1U << 26)))
    {
    }

    CAN1_TI0R = (id << 21);
    CAN1_TDT0R = len & 0xF;

    CAN1_TDL0R = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    CAN1_TDH0R = data[4] | (data[5] << 8) | (data[6] << 16) | (data[7] << 24);

    CAN1_TI0R |= (1U << 0);
}

int main(void)
{
    uart_init();
    can_init();

    uart_print("uart and can ready\r\n");

    uint8_t msg[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};

    while (1)
    {
        can_send(0x123, msg, 8);
        uart_print("can tx\r\n");
        delay(5000000);

        if (CAN1_RF0R & (3U << 0))
        {
            uart_print("can rx\r\n");
            CAN1_RF0R |= (1U << 5);
        }
    }
}
