/*
 * buttons.c
 *
 *  Created on: Feb 23, 2016
 *      Author: vnguyen42
 */

//Include the related .h files and libraries
#include "buttons.h"
#include "speaker.h"
#include "system.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "stdio.h"

static unsigned long delay;

static unsigned long BUTIN[2] = {BUTTONS, BUTTONS};

enum state {I,B,V}; //Enum different states

enum state curState = I;

void buttonsTask(void *pvParameters) {

	// Enable GPIO Port G and configure already enable in LEDTask


		 GPIOPinTypeGPIOInput(GPIO_PORTG_BASE, BUTTONS);

		 //Pull-up resistors
		 GPIOPadConfigSet(GPIO_PORTG_BASE, BUTTONS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

		while (true) {

			delay = ONE_MS;
					flag = 0;
					BUTIN[0] = GPIOPinRead(GPIO_PORTG_BASE,BUTTONS);

					switch (curState) {

					case I:
						if(BUTIN[0] != BUTTONS) {

							curState = B;

							delay *= 10; //change the delay
						}
						break;

					case B:
						if (BUTIN[0] == BUTIN[1]) {
							curState = V;
							speakerTone(BUTIN[0]);
							flag = 1;

							delay *= 199;
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

							delay *= 500;
						}
						break;

					}

					BUTIN[1] = BUTIN[0];
					vTaskDelay(delay); //adding the delay time

		}
}
