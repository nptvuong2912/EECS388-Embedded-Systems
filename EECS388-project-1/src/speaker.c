/*
 * speaker.c
 *
 *  Created on: Feb 12, 2016
 *      Author: vnguyen42
 */
#include "speaker.h"

#include "system.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

static unsigned long timeToExec = 0;
static const unsigned long delay = SYSTICK_FREQUENCY/880;

/*
 *  The initialization and execution functions for this task
 */
void speakerInit() {

	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);

	//Connected to Pins 0 and 1
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_0);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_1);

    //initial values of the pins must be opposite
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 0x00); //Low
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, GPIO_PIN_1); //High

    // Initialize the first execution time for the task by adding to the current SysTickCount
    timeToExec = sysTickCount + delay;
}

void speakerExec() {
	if(sysTickCount >= timeToExec) {

        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_0) ^ GPIO_PIN_0);
        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1) ^ GPIO_PIN_1);

        //	Advance next execution time for the speaker task
        timeToExec += delay;
	}
}

