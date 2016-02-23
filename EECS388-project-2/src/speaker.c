/*
 * speaker.c
 *
 *  Created on: Feb 12, 2016
 *      Author: Vuong Nguyen
 *      EECS 388 - Project 2.
 */
//Header file included
#include "speaker.h"
//Access to global variables and base libraries
#include "system.h"
#include "buttons.h"
// Stellaris driver libraries required by these local function definitions
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


static unsigned long timeToExec = 0;
//5 tones of different frequency
static const unsigned long freqency[5] = {410, 540, 660, 390, 450};
static unsigned long tone; //Assigned to different freqency
//delay time
static unsigned long delay = SYSTICK_FREQUENCY/880;
//check flag
unsigned long flag;
/*
 *  The initialization and execution functions for this task
 */
void speakerInit() {
	//Enable GPIO Port H and configure it to drive the speaker
	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);

	//The speaker is attached to H<1:0>, set as output. Connected to Pins 0 and 1
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_1);
    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_0);

    //initial values of the pins must be opposite
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 0); //Low
    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 2); //High

    // Initialize the first execution time for the task by adding to the current SysTickCount
    timeToExec = sysTickCount + delay;

}

void speakerTone(unsigned long t) {

	if ((t&Up) == 0) {
		tone = freqency[0];
	}
	else if ((t&Left) == 0) {
		tone = freqency[1];
	}
	else if ((t&Right) == 0) {
			tone = freqency[2];
	}
	else if ((t&Down) == 0) {
			tone = freqency[3];
	}
	else if ((t&Select) == 0) {
			tone = freqency[4];
	}

	delay = SYSTICK_FREQUENCY/(2*tone);

}


void speakerExec() {


	if(sysTickCount >= timeToExec) {

		if(flag) {



		//fluctuating to make the noise
        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_0) ^ GPIO_PIN_0);
        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1) ^ GPIO_PIN_1);
		}

        //	Advance next execution time for the speaker task
        timeToExec += delay;
	}


}

