/*
 * system.h
 *
 *  Created on: Aug 28, 2015
 *      Author: Brad Torrence
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

// These are required TI hardware libraries
// Included here to avoid repeating the includes for every task.
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"

//*************************************************************************************************
//  The system tick interrupt (systick) is used to divide the system clock to a slower rate,
//  and use it as the main timing mechanism in our program.
//  The SYSTICK_FREQUENCY is used to divide the system clock.
//  All events in the application occur at some fraction of this clock rate.
//  The BASE_FREQUENCY (1000 Hz) is used to create a multiplier
//		MS_TO_TICK that will convert milliseconds to system ticks (systicks)
//  By using MS_TO_TICK instead of SYSTICK_FREQUENCY we can freely change
//		the system tick frequency without re-adjusting the timings of existing definitions.
//  MS_TO_TICK is multiplied by the number of milliseconds between executions
// 		to attain a stable execution frequency,
// 		example: 10 * MS_TO_TICK = 10 ms period between executions
//*************************************************************************************************
#define SYSTICK_FREQUENCY 100000.0
#define BASE_FREQUENCY 1000.0
#define ONE_MS (SYSTICK_FREQUENCY / BASE_FREQUENCY)

//*************************************************************************************************
// This variable will keep track of the number of systicks that have occurred.
// The systick count is recorded to maintain task execution frequencies.
//*************************************************************************************************
extern volatile unsigned long sysTickCount;



/*************************************************************************************************
 *	Initializes the system clock to run from the crystal
 *		and enables the board's systick functionality.
 ************************************************************************************************/
extern void systemInit();

#endif /* SYSTEM_H_ */
