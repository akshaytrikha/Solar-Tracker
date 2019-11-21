/*
	Akshay Trikha & Kahiwa Hoe
	atrikha@hmc.edu & khoe@hmc.edu
	20th November, 2019

	main file for solar tracker SAM4S4B code
*/

// includes
#include <stdio.h>
#include <stdint.h>
#include "SAM4S4B/SAM4S4B.h"

// pin definitions for theta motor
#define RED_1 		3
#define BLUE_1 		27
#define BLACK_1 	26
#define GREEN_1 	28
#define RB_EN_1 	4
#define BG_EN_1		25

// pin definitions for phi motor
#define RED_2 		0
#define BLUE_2 		0
#define BLACK_2 	0
#define GREEN_2 	0
#define RB_EN_2 	0
#define BG_EN_2		0

#define DELAY 300 // ms

// initialize SAM4S4B
void init() {
	// initialize microcontroller's PIO capabilities
	samInit();
  pioInit();
	tcDelayInit();

	// set theta motor pins as outputs
	pioPinMode(RED_1, PIO_OUTPUT);
  pioPinMode(BLUE_1, PIO_OUTPUT);
	pioPinMode(BLACK_1, PIO_OUTPUT);
  pioPinMode(GREEN_1, PIO_OUTPUT);
	pioPinMode(RB_EN_1, PIO_OUTPUT);
  pioPinMode(BG_EN_1, PIO_OUTPUT);

  // set phi motor pins as outputs
//	pioPinMode(RED_2, PIO_OUTPUT);
//  pioPinMode(BLUE_2, PIO_OUTPUT);
//	pioPinMode(BLACK_2, PIO_OUTPUT);
//  pioPinMode(GREEN_2, PIO_OUTPUT);
//	pioPinMode(RB_EN_2, PIO_OUTPUT);
//  pioPinMode(BG_EN_2, PIO_OUTPUT);
}

// pulses theta motor for DELAY ms
void testMotor() {
	// constantly perform loop
	while(1) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 1);
		pioDigitalWrite(BG_EN_1, 1);
		
		// step 1
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(DELAY);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		
		// step 2
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(DELAY);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		
		// step 3
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(DELAY);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 4
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(DELAY);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// disable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 0);
		pioDigitalWrite(BG_EN_1, 0);
	}
}

// steps motor in positive direction at frequency Hz for duration seconds
void stepPositive(uint32_t frequency, uint32_t duration) {
	uint32_t delay = 1000 / frequency;
	uint32_t steps = 0;
	
	// constantly perform loop
	while(steps < duration / (delay)) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 1);
		pioDigitalWrite(BG_EN_1, 1);
		
		// step 1
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		
		// step 2
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		
		// step 3
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 4
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		steps += 4;
	}
	// disable motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 0);
	pioDigitalWrite(BG_EN_1, 0);
}

// steps motor in negative direction at frequency Hz for duration seconds
void stepNegative(uint32_t frequency, uint32_t duration) {
	uint32_t delay = 1000 / frequency;
	uint32_t steps = 0;
	
	// constantly perform loop
	while(steps < duration / (delay)) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 1);
		pioDigitalWrite(BG_EN_1, 1);
		
		// step 4
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 3
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 2
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		
		// step 1
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		
		steps += 4;
	}
	// disable motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 0);
	pioDigitalWrite(BG_EN_1, 0);
}

int main(void) {
	// initialize SAM4S4B microcontroller
	init();
	
	// step positive at 100Hz for 2000 milliseconds
	stepPositive(75, 2000);
	stepNegative(40, 4000);

	return 0;
}
