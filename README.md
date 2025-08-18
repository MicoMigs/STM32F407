## Getting Started

1. **Toolchain**: Any ARM GCC or vendor toolchain (e.g., arm-none-eabi-gcc, STM32CubeIDE, Keil, IAR).  
2. **Target**: STM32F407 (F4x family). Update linker script/startup as needed.  
3. **Clone & Build**:  
   - Add `Drivers/Inc` to your include paths.  
   - Compile sources in `Drivers/Src` and selected demo(s) in `Src`.  
4. **Flash**: Use ST-LINK or your preferred debugger/programmer.  

---

## Demos

- `Src/01led_toggle.c`  
  Initializes a GPIO pin and toggles it to verify clocking and basic I/O.  

- `Src/demo_03_button_interrupt.c`  
  Configures a GPIO pin with EXTI interrupt to demonstrate input handling and ISR flow.  

- `Src/demo_04_spi_tx.c`  
  Initializes **SPI2 in master mode** (8-bit, CPOL=1, CPHA=0, SSM enabled).  
  Sends `"Hello World"` over MOSI at ~8 MHz, with NSS/SSI set to avoid MODF.  

---

## Changelog

| Date       | Description                                                   | Module / Directory Path                                       |
|------------|---------------------------------------------------------------|---------------------------------------------------------------|
| 2025-08-17 | Implemented SPI driver and added TX demo                      | `Drivers/Inc/stm32f407xx_spi_driver.h`, `Drivers/Src/stm32f407xx_spi_driver.c`, `Src/demo_04_spi_tx.c` |
| 2025-08-15 | Implemented GPIO API driver                                   | `Drivers/Inc/stm32f407xx_gpio_driver.h`, `Drivers/Src/stm32f407xx_gpio_driver.c` |
| 2025-08-15 | Added GPIO Pin Interrupt Configuration & Demo                 | `Src/demo_03_button_interrupt.c`                              |
| 2025-08-08 | Demo for GPIO pin initialization and toggling                 | `Src/01led_toggle.c`                                          |
| 2025-08-07 | Added GPIO driver: clock control, init, de-init, data I/O     | `Drivers/Src/stm32f407xx_gpio_driver.c`                       |
| 2025-08-05 | Defined GPIO driver API requirements (source)                 | `Drivers/Src/stm32f407xx_gpio_driver.c`                       |
| 2025-08-05 | Defined GPIO driver API requirements (header)                 | `Drivers/Inc/stm32f407xx_gpio_driver.h`                       |
| 2025-08-05 | Added documentation comments                                  | `Drivers/Inc/stm32f407xx.h`                                   |
| 2025-08-04 | Added clock enable/disable macros                             | `Drivers/Inc/stm32f407xx.h`                                   |
| 2025-08-04 | Added peripheral support for GPIOx, I2Cx, SPIx, USARTx, SYSCFG | `Drivers/Inc/stm32f407xx.h`                                   |
| 2025-08-03 | Initial driver framework scaffold for STM32F4x peripherals    | `Drivers/Inc/stm32f4xx_drivers`                               |

---

## Roadmap

- Extend SPI driver (half-duplex, simplex RX/TX, hardware NSS, interrupts/DMA)  
- USART driver (TX/RX, async, interrupt/DMA)  
- I2C driver (master, interrupts/DMA)  
- Board support abstractions and more demos  
- Unit-style hardware tests where feasible  

---

## Contributing

Issues and PRs are welcome. Please keep code style consistent and document public APIs in headers.

---

## License

Add your preferred license (e.g., MIT) here.
