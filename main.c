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

// pin definitions
#define RED 	15
#define BLUE 	16
#define BLACK 	25
#define GREEN 	26
#define RB_EN 	27
#define BG_EN	28

#define DELAY 500 // ms

// axis angles
uint8_t theta = 30;
uint8_t phi = 0;

// to keep track of best angles
uint8_t theta_Pmax;
uint8_t phi_Pmax;

// to keep track of max observed power values
uint8_t pmax_theta = 0;
uint8_t pmax_phi = 0;

// pulses motor for DELAY ms
void testMotor() {
	// enable motor signals on H-Bridge
	pioDigitalWrite(RB_EN, 1);
	pioDigitalWrite(BG_EN, 1);

	// constantly perform loop
	while(1) {	
		
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
	}
}


// initialize SAM4S4B
void init() {
	// initialize microcontroller's PIO capabilities
	samInit();
  	pioInit();
	tcDelayInit();

	// set pins as outputs
	pioPinMode(RED, PIO_OUTPUT);
  	pioPinMode(BLUE, PIO_OUTPUT);
	pioPinMode(BLACK, PIO_OUTPUT);
  	pioPinMode(GREEN, PIO_OUTPUT);
	pioPinMode(RB_EN, PIO_OUTPUT);
  	pioPinMode(BG_EN, PIO_OUTPUT);
}

// setup solar panel to optimal initial angle
void setup() {
	// enable motor signals on H-Bridge
	pioDigitalWrite(RB_EN, 1);
	pioDigitalWrite(BG_EN, 1);

	// disable motor signals on H-Bridge
	pioDigitalWrite(RB_EN, 0);
	pioDigitalWrite(BG_EN, 0);
}

int main(void) {

	init();
	
	testMotor();
	tcDelayMillis(DELAY);
	
	return 0;
}
