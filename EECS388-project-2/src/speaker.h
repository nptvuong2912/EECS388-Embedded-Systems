/*
 * speaker.h
 *
 *  Created on: Feb 12, 2016
 *      Author: vnguyen42
 */

// A simple task that periodically toggles the speaker.
//*****************************************************************************

#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "buttons.h"

#define Up GPIO_PIN_3
#define Down GPIO_PIN_4
#define Left GPIO_PIN_5
#define Right GPIO_PIN_6
#define Select GPIO_PIN_7

#define BUTTONS (Up|Down|Left|Right|Select)

#define Speaker (GPIO_PIN_0|GPIO_PIN_1)

extern unsigned long flag;


/*
 *  The initialization and execution functions for the LED controller
 */
extern void speakerInit();
extern void speakerExec();
extern void speakerTone(unsigned long);


#endif /* speaker_H_ */
