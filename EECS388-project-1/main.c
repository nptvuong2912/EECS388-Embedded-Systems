/********************************************************************************************
 *
 * 		Author: 		Vuong Nguyen
 *		Project #1: Lights and sounds - SpeakerBuzz
 *
 *
 ********************************************************************************************/

// Project libraries
#include "src/system.h"
#include "src/oled.h"
#include "src/led.h"
#include "src/speaker.h"

//*************************************************************************************************
//	Main program to initialize hardware and execute Tasks.
//*************************************************************************************************
void main()  {
	//  Initialize system counters
	systemInit();

	// Initialize tasks
	OLEDInit();
	LEDInit();
	speakerInit();

	// Execute tasks repeatedly
    while(true){
    	OLEDExec();
    	LEDExec();
    	speakerExec();
    }
}

