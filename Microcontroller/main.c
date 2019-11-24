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

// pin definitions for theta/phi motors
#define RED 				PIO_PA3
#define BLUE 				PIO_PA27
#define BLACK 			PIO_PA26
#define GREEN 			PIO_PA16
#define THETA_EN	 	PIO_PA4
#define PHI_EN			PIO_PA25

#define DELAY 300 // ms

// initialize SAM4S4B
void init() {
	// initialize microcontroller's PIO capabilities
	samInit();
  pioInit();
	tcDelayInit();

	// set motor pins as outputs
	pioPinMode(RED, PIO_OUTPUT);
  pioPinMode(BLUE, PIO_OUTPUT);
	pioPinMode(BLACK, PIO_OUTPUT);
  pioPinMode(GREEN, PIO_OUTPUT);
	pioPinMode(THETA_EN, PIO_OUTPUT);
	pioPinMode(PHI_EN, PIO_OUTPUT);

}

// pulses theta motor for DELAY ms
void testMotor() {
	// constantly perform loop
	while(1) {
		
		// enable motor signals on H-Bridge
		pioDigitalWrite(THETA_EN, 1);
		
		// step 1
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(DELAY);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		
		// step 2
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(DELAY);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		
		// step 3
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(DELAY);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		
		// step 4
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(DELAY);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(BLUE, 0);
		
		// disable motor signals on H-Bridge
		pioDigitalWrite(THETA_EN, 0);
	}
}

// steps motor in positive direction at frequency Hz for duration seconds
void stepPositive(uint32_t frequency, uint32_t duration, int motor_en) {
	uint32_t delay = 1000 / frequency;
	uint32_t steps = 0;
	
	// constantly perform loop
	
	
	while(steps < duration / (delay)) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(motor_en, 1);
		
		// step 1
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		
		// step 2
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		
		// step 3
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		
		// step 4
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(BLUE, 0);
		
		steps += 4;
	}
	// disable motor signals on H-Bridge
	pioDigitalWrite(motor_en, 0);
}

// steps motor in negative direction at frequency Hz for duration seconds
void stepNegative(uint32_t frequency, uint32_t duration, int motor_en) {
	uint32_t delay = 1000 / frequency;
	uint32_t steps = 0;
	
	// constantly perform loop
	while(steps < duration / (delay)) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(motor_en, 1);
		
		// step 4
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(BLUE, 0);
		
		// step 3
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 1);
		tcDelayMillis(delay);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		
		// step 2
		pioDigitalWrite(BLACK, 0); 
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 1);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(RED, 0);
		pioDigitalWrite(GREEN, 0);
		
		// step 1
		pioDigitalWrite(BLACK, 1);
		pioDigitalWrite(RED, 1);
		pioDigitalWrite(GREEN, 0);
		pioDigitalWrite(BLUE, 0);
		tcDelayMillis(delay);
		pioDigitalWrite(BLACK, 0);
		pioDigitalWrite(RED, 0);
		
		steps += 4;
	}
	// disable motor signals on H-Bridge
	pioDigitalWrite(motor_en, 0);
}

int main(void) {
	// initialize SAM4S4B microcontroller
	init();
	
	// step positive at 100Hz for 2000 milliseconds
	stepPositive(75, 2000, PHI_EN);
	stepNegative(40, 4000, THETA_EN);

	return 0;
}
