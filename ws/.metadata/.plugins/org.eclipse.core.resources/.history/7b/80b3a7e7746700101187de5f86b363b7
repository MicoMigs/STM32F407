/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mico Santiago
 * @brief          : Debugging using ARM Cortex M3/M4/M7 based MCUs
 ******************************************************************************
 * The printf works over SWO pin(Serial Wire Output) of SWD interface
 * 	> This is done by SWD accessing the ITM unit inside the M4 processor
 * 		> Contains two lines
 * 			> SWDIO: a bidirectional data line
 * 			> SWCLK: a clock driven by the host
 * 	> Alternative to JTAG
 * 	> Used to access MCU internal flash, memory regions, add breakpoints,
 * 		stop/run CPU
 * 	> Can use serial wire viewer for your printf statements for debugging
 *
 * 	GUIDE
 * 	1. go to Window > Show View > SWV > STM ITM Data Console
 * 	2. Configure (wrench x scredriver bottom right) > select ITM
 * 		Stimulus Port 0
 * 	3. Start Trace (red button bottom right)
 * 	Note: Debug Config is under the green bug
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include<stdio.h>

int main(void)
{
    printf("Hello World\n");
	for(;;);
}

