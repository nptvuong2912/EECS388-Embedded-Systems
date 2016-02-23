/*
 * system.c
 *
 *  Created on: Aug 28, 2015
 *      Author: Brad Torrence
 */

// Always include the header file inside the associated source file!
#include "system.h"

// Stellaris driver libraries
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"

//*************************************************************************************************
// Global variables (marked with extern) must be redeclared before they can be used globally
// This is a good place to also initialize the value using some constant or literal.
//*************************************************************************************************
volatile unsigned long sysTickCount = 0;

//*************************************************************************************************
// The SysTick interrupt service routine (ISR).
// This is a callback function that is run when the system encounters a systick interrupt.
// It maintains the systick count for the system by simply incrementing the count.
//*************************************************************************************************
static void sysTickISR() {
	sysTickCount++;
}

/*************************************************************************************************
 *	Initializes the system clock to run from the crystal
 *		and enables the board's systick functionality.
 ************************************************************************************************/
void systemInit() {
    // Set the clocking to run directly from the crystal.
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_8MHZ);

    // Configure and Enable SysTick mechanism
    SysTickPeriodSet(SysCtlClockGet() / SYSTICK_FREQUENCY);
    SysTickIntRegister(sysTickISR);
    SysTickIntEnable();
    SysTickEnable();
}

