#ifndef STM
#define STM

#include <stdint.h>

#define RCC_AHB1ENR   (*(volatile uint32_t *)(0x40023830))
#define RCC_APB1ENR   (*(volatile uint32_t *)(0x40023840))
#define RCC_APB2ENR   (*(volatile uint32_t *)(0x40023844))

#define GPIOA_MODER   (*(volatile uint32_t *)(0x40020000))
#define GPIOA_OTYPER  (*(volatile uint32_t *)(0x40020004))
#define GPIOA_OSPEEDR (*(volatile uint32_t *)(0x40020008))
#define GPIOA_PUPDR   (*(volatile uint32_t *)(0x4002000C))
#define GPIOA_AFRL    (*(volatile uint32_t *)(0x40020020))
#define GPIOA_AFRH    (*(volatile uint32_t *)(0x40020024))

#define GPIOB_MODER   (*(volatile uint32_t *)(0x40020400))
#define GPIOB_OTYPER  (*(volatile uint32_t *)(0x40020404))
#define GPIOB_OSPEEDR (*(volatile uint32_t *)(0x40020408))
#define GPIOB_PUPDR   (*(volatile uint32_t *)(0x4002040C))
#define GPIOB_AFRL    (*(volatile uint32_t *)(0x40020420))
#define GPIOB_AFRH    (*(volatile uint32_t *)(0x40020424))

#define USART2_SR     (*(volatile uint32_t *)(0x40004400))
#define USART2_DR     (*(volatile uint32_t *)(0x40004404))
#define USART2_BRR    (*(volatile uint32_t *)(0x40004408))
#define USART2_CR1    (*(volatile uint32_t *)(0x4000440C))
#define USART2_CR2    (*(volatile uint32_t *)(0x40004410))
#define USART2_CR3    (*(volatile uint32_t *)(0x40004414))

#define CAN1_MCR      (*(volatile uint32_t *)(0x40006400))
#define CAN1_MSR      (*(volatile uint32_t *)(0x40006404))
#define CAN1_TSR      (*(volatile uint32_t *)(0x40006408))
#define CAN1_RF0R     (*(volatile uint32_t *)(0x4000640C))
#define CAN1_IER      (*(volatile uint32_t *)(0x40006414))
#define CAN1_BTR      (*(volatile uint32_t *)(0x4000641C))
#define CAN1_TI0R     (*(volatile uint32_t *)(0x40006580))
#define CAN1_TDT0R    (*(volatile uint32_t *)(0x40006584))
#define CAN1_TDL0R    (*(volatile uint32_t *)(0x40006588))
#define CAN1_TDH0R    (*(volatile uint32_t *)(0x4000658C))
#define CAN1_RI0R     (*(volatile uint32_t *)(0x400065A0))
#define CAN1_RDT0R    (*(volatile uint32_t *)(0x400065A4))
#define CAN1_RDL0R    (*(volatile uint32_t *)(0x400065A8))
#define CAN1_RDH0R    (*(volatile uint32_t *)(0x400065AC))
#define CAN1_FMR      (*(volatile uint32_t *)(0x40006600))
#define CAN1_FM1R     (*(volatile uint32_t *)(0x40006604))
#define CAN1_FS1R     (*(volatile uint32_t *)(0x4000660C))
#define CAN1_FFA1R    (*(volatile uint32_t *)(0x40006614))
#define CAN1_FA1R     (*(volatile uint32_t *)(0x4000661C))
#define CAN1_F0R1     (*(volatile uint32_t *)(0x40006640))
#define CAN1_F0R2     (*(volatile uint32_t *)(0x40006644))

#endif
