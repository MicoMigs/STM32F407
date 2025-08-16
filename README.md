# STM32F4x Series Driver Development: Modular and Reusable Tools

## Changelog

| Date       | Update Description                                            | Module/Directory           |
|------------|---------------------------------------------------------------|----------------------------|
| 2025-08-15 | Implemented GPIO API driver |  `Drivers\Inc\stm32f07xx_gpio_driver.c & Drivers\Inc\stm32f07xx_gpio_driver.c ` |
| 2025-08-15 | Added GPIO pin Interrupts Config & demo |  `Src\demo_03_button_interrupt.c` |
| 2025-08-08 | Demo for initializing and toggling a GPIO pin |  `Src\01led_toggle.c` |
| 2025-08-07 | GPIO driver clk control, init, de-init, data read and write |  `Drivers\Src\stm32f07xx_gpio_driver.c` |
| 2025-08-05 | GPIO driver API requirements |  `Drivers\Inc\stm32f07xx_gpio_driver.c` |
| 2025-08-05 | GPIO driver API requirements |  `Drivers\Inc\stm32f07xx_gpio_driver.h` |
| 2025-08-05 | Comments added |  `Drivers\Inc\stm32f407xx.h` |
| 2025-08-04 | Clock enable and disable macros added                         | `Drivers\Inc\stm32f407xx.h`            |
| 2025-08-04 | GPIOx, I2Cx, SPIx, USARTx, SYSCFG peripheral support added    | `Drivers\Inc\stm32f407xx.h`            |
| 2025-08-03 | **Drivers:** Framework scaffold for STM32F4x peripherals      | `Drivers\Inc\stm32f4xx_drivers`        |