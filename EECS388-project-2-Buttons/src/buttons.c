/*
 * buttons.c
 *
 *  Created on: Feb 12, 2016
 *      Author: vnguyen42
 */

#include "buttons.h"
#include "speaker.h"
#include "system.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "stdio.h"

static unsigned long timeToExec = 0;
static const unsigned long delay = ONE_MS;

static unsigned long BUTIN[2] = {BUTTONS, BUTTONS};

enum state {I,B,V};

enum state curState = I;

void buttonsInit() {

	// Enable GPIO Port G and configure it to drive the buttons
	 SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);

	 GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, BUTTONS);

	 GPIOPadConfigSet(GPIO_PORTG_BASE, BUTTONS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


}

void buttonsExec() {
	if (sysTickCount >= timeToExec) {
		flag = 0;
		BUTIN[0] = GPIOPinRead(GPIO_PORTG_BASE,BUTTONS);

		switch (curState) {

		case I:
			if(BUTIN[0] != BUTTONS) {

				curState = B;

				timeToExec += 9*delay;
			}
			break;

		case B:
			if (BUTIN[0] == BUTIN[1]) {
				curState = V;
				speakerTone(BUTIN[0]);
				flag = 1;

				timeToExec += 199*delay;
			}
			else {
				curState = I;

			}
			break;

		case V:
			if (BUTIN[0] != BUTIN[1]) {

				curState = I;
				speakerTone(BUTIN[1]);
				flag = 1;

				timeToExec += 500*delay;
			}
			break;

		}

		BUTIN[1] = BUTIN[0];
		timeToExec += delay;

	}





}
