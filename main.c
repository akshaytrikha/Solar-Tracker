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
#include "SAM4S4B/SAM4S4B_supc.h"
#include "SAM4S4B/SAM4S4B_twi.h"

// pin definitions for theta motor
#define RED_1 		15
#define BLUE_1 		16
#define BLACK_1 	25
#define GREEN_1 	26
#define RB_EN_1 	27
#define BG_EN_1		28

// pin definitions for phi motor
#define RED_2 		0
#define BLUE_2 		0
#define BLACK_2 	0
#define GREEN_2 	0
#define RB_EN_2 	0
#define BG_EN_2		0


#define DELAY 500 // ms

// axis angles
uint8_t theta = 30;
uint8_t phi = 0;

// to keep track of best angles
uint8_t theta_Pmax;
uint8_t phi_Pmax;

// to keep track of max observed power values
uint8_t pmax = 0;

// to keep track of current power output
uint8_t currentPower;

// pulses theta motor for DELAY ms
void testMotor() {
	// enable motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 1);
	pioDigitalWrite(BG_EN_1, 1);

	// constantly perform loop
	while(1) {	
		
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
	}

	// disable motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 1);
	pioDigitalWrite(BG_EN_1, 1);
}


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
	pioPinMode(RED_2, PIO_OUTPUT);
  	pioPinMode(BLUE_2, PIO_OUTPUT);
	pioPinMode(BLACK_2, PIO_OUTPUT);
  	pioPinMode(GREEN_2, PIO_OUTPUT);
	pioPinMode(RB_EN_2, PIO_OUTPUT);
  	pioPinMode(BG_EN_2, PIO_OUTPUT);
}

// returns curent power reading from sensor
uint8_t getPower() {
	// TODO: implement
	return 0;
}

// moves theta motor to desiRED_1 angle
void moveTheta(uint8_t stepAngle) {
	// TODO: implement
}

// moves phi motor to desiRED_1 angle
void movePhi(uint8_t stepAngle) {
	// TODO: implement
}

// setup solar panel to optimal initial angle
void setup() {
	// enable theta motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 1);
	pioDigitalWrite(BG_EN_1, 1);

	// initially set best theta as current theta (30 degrees)
	theta_Pmax = theta;
	pmax = getPower();

	// loop through 120 degrees find best theta
	while (theta <= 150) {
		currentPower = getPower();
		if  (currentPower > pmax) {
			pmax = currentPower;
			theta_Pmax = theta;
		}
		theta += 12;
	}

	// move to theta that yields pmax
	moveTheta(theta_Pmax);

	// disable theta motor signals on H-Bridge
	pioDigitalWrite(RB_EN_1, 0);
	pioDigitalWrite(BG_EN_1, 0);

	// reset pmax variable
	pmax = 0;

	// enable phi motor signals on H-Bridge
	pioDigitalWrite(RB_EN_2, 1);
	pioDigitalWrite(BG_EN_2, 1);

	// loop through 360 degrees find best phi
	while (phi <= 360) {
		currentPower = getPower();
		if  (currentPower > pmax) {
			pmax = currentPower;
			phi_Pmax = phi;
		}
		phi += 36;
	}

	// move to theta that yields pmax
	moveTheta(phi_Pmax);

	// disable phi motor signals on H-Bridge
	pioDigitalWrite(RB_EN_2, 0);
	pioDigitalWrite(BG_EN_2, 0);
}

// move to optimal location every 20 mins
void update() {


	// delay for 20 mins
	tcDelayMillis(DELAY);

	// put SAM4S4B in backup mode

}

int main(void) {
	// initialize SAM4S4B microcontroller
	init();

	// move panel to inital optimal angle
	setup();

		
	return 0;
}
