/*
 * speaker.c
 *
 *  Created on: Feb 23, 2016
 *      Author: vnguyen42
 */

//Header file included
#include "speaker.h"
//Access to global variables and base libraries
#include "system.h"
#include "buttons.h"
// Stellaris driver libraries required by these local function definitions
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"

//5 tones of different frequency
static const unsigned long freqency[5] = {410, 540, 660, 390, 450};
static unsigned long tone; //Assigned to different freqency
//delay time
static unsigned long delay = SYSTICK_FREQUENCY/880;
//check flag
unsigned long flag;

void speakerTask(void *pvParameters) {
		//Enable GPIO Port H and configure it to drive the speaker
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);

		//The speaker is attached to H<1:0>, set as output. Connected to Pins 0 and 1
	    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_1);
	    GPIOPinTypeGPIOOutput(GPIO_PORTH_BASE, GPIO_PIN_0);

	    //initial values of the pins must be opposite to toggle the speaker
	    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, 0); //Low
	    GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, 2); //High

	while (true) {

				if(flag) {

				//toggling to make the noise
		        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_0, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_0) ^ GPIO_PIN_0);
		        GPIOPinWrite(GPIO_PORTH_BASE, GPIO_PIN_1, GPIOPinRead(GPIO_PORTH_BASE, GPIO_PIN_1) ^ GPIO_PIN_1);
				}

		        //	Advance next execution time for the speaker task
		        vTaskDelay(delay);
			}

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

