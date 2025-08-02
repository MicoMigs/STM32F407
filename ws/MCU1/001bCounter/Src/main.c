#include <stdint.h>
#include <stdio.h>

// RCC base and AHB1ENR register (for GPIOA clock enable)
#define RCC_BASE        0x40023800UL
#define RCC_AHB1ENR     (*(volatile uint32_t*)(RCC_BASE + 0x30))

// GPIOA base and registers
#define GPIOA_BASE      0x40020000UL
#define GPIOA_MODER     (*(volatile uint32_t*)(GPIOA_BASE + 0x00))
#define GPIOA_PUPDR     (*(volatile uint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR       (*(volatile uint32_t*)(GPIOA_BASE + 0x10))

// Bit mask helpers
#define RCC_AHB1ENR_GPIOAEN     (1 << 0)
#define GPIO_IDR_ID0            (1 << 0)

// Crude delay for debouncing
void delay(volatile uint32_t count) {
    while (count--) {
        __asm__("nop");
    }
}

int main(void)
{
    // Enable GPIOA peripheral clock
    RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Set PA0 as input (MODER = 00)
    GPIOA_MODER &= ~(0x3U << (0 * 2));

    // Optional: Set PA0 as pull-down (PUPDR = 10)
    GPIOA_PUPDR &= ~(0x3U << (0 * 2));
    GPIOA_PUPDR |=  (0x2U << (0 * 2));

    printf("Button Press Counter Initialized\n");

    uint32_t press_count = 0;
    uint8_t last_state = 0;

    while (1)
    {
        uint8_t current_state = (GPIOA_IDR & GPIO_IDR_ID0) ? 1 : 0;

        if (current_state && !last_state) {
            press_count++;
            printf("Button pressed %lu times\n", press_count);
            delay(100000);  // debounce
        }

        last_state = current_state;
    }
}
