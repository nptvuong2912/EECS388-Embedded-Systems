/*
 * speaker.h
 *
 *  Created on: Feb 23, 2016
 *      Author: vnguyen42
 */

#ifndef SRC_SPEAKER_H_
#define SRC_SPEAKER_H_

#include "buttons.h"

//define the pins to desirable variables
#define Up GPIO_PIN_3
#define Down GPIO_PIN_4
#define Left GPIO_PIN_5
#define Right GPIO_PIN_6
#define Select GPIO_PIN_7

//define button variables
#define BUTTONS (Up|Down|Left|Right|Select)

#define Speaker (GPIO_PIN_0|GPIO_PIN_1)

extern unsigned long flag;

extern void speakerTask(void *pvParameters);
extern void speakerTone(unsigned long);

#endif /* SRC_SPEAKER_H_ */
