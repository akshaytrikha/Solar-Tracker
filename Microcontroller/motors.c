#include <stdio.h>
#include <stdint.h>
//#include "SAM4S4B/SAM4S4B.h"

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

// moves theta motor to desiRED_1 angle
void moveTheta(uint8_t stepAngle) {
	// TODO: implement
}

// moves phi motor to desiRED_1 angle
void movePhi(uint8_t stepAngle) {
	// TODO: implement
}

	
	// given freq, duration
	// output freq for duration
//void moveMotor(size_t frequency, size_t duration) {
//	size_t period = 1000000 / frequency; // (period in microseconds)
//	size_t delay = period / 6; // (delay in microseconds)
//	
//	size_t steps = 0;
//		
//	while (steps < (1000 * duration) / period) {
//		// enable motor signals on H-Bridge
//		pioDigitalWrite(RB_EN_1, 1);
//		pioDigitalWrite(BG_EN_1, 1);
//		tcDelayMicroseconds(delay);		
//		
//		// step 1
//		pioDigitalWrite(BLACK_1, 1);
//		pioDigitalWrite(RED_1, 1);
//		pioDigitalWrite(GREEN_1, 0);
//		pioDigitalWrite(BLUE_1, 0);
//		tcDelayMicroseconds(delay);
//		pioDigitalWrite(BLACK_1, 0);
//		pioDigitalWrite(RED_1, 0);
//		
//		// step 2
//		pioDigitalWrite(BLACK_1, 0);
//		pioDigitalWrite(RED_1, 1);
//		pioDigitalWrite(GREEN_1, 1);
//		pioDigitalWrite(BLUE_1, 0);
//		tcDelayMicroseconds(delay);
//		pioDigitalWrite(RED_1, 0);
//		pioDigitalWrite(GREEN_1, 0);
//		
//		// step 3
//		pioDigitalWrite(BLACK_1, 0);
//		pioDigitalWrite(RED_1, 0);
//		pioDigitalWrite(GREEN_1, 1);
//		pioDigitalWrite(BLUE_1, 1);
//		tcDelayMicroseconds(delay);
//		pioDigitalWrite(GREEN_1, 0);
//		pioDigitalWrite(BLUE_1, 0);
//		
//		// step 4
//		pioDigitalWrite(BLACK_1, 1);
//		pioDigitalWrite(RED_1, 0);
//		pioDigitalWrite(GREEN_1, 0);
//		pioDigitalWrite(BLUE_1, 1);
//		tcDelayMicroseconds(delay);
//		pioDigitalWrite(BLACK_1, 0);
//		pioDigitalWrite(BLUE_1, 0);
//		
//		// disable motor signals on H-Bridge
//		pioDigitalWrite(RB_EN_1, 0);
//		pioDigitalWrite(BG_EN_1, 0);
//		
//		tcDelayMicroseconds(delay);
//		++steps;
//	}
//}

void movePositive(size_t frequency) {
	size_t period = 1000000 / frequency; // (period in microseconds)
	size_t delay = period; // (delay in microseconds)
		
	while (1) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 1);
		pioDigitalWrite(BG_EN_1, 1);
		tcDelayMicroseconds(delay);		
		
		// step 1
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		
		// step 2
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		
		// step 3
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 4
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// disable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 0);
		pioDigitalWrite(BG_EN_1, 0);
		
		tcDelayMicroseconds(delay);
	}
}

void moveNegative(size_t frequency) {
	size_t period = 1000000 / frequency; // (period in microseconds)
	size_t delay = period; // (delay in microseconds)
		
	while (1) {
		// enable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 1);
		pioDigitalWrite(BG_EN_1, 1);
		tcDelayMicroseconds(delay);		
		
		// step 1
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		
		// step 2
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 1);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 0);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		
		// step 3
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 1);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// step 4
		pioDigitalWrite(BLACK_1, 1);
		pioDigitalWrite(RED_1, 0);
		pioDigitalWrite(GREEN_1, 0);
		pioDigitalWrite(BLUE_1, 1);
		tcDelayMicroseconds(delay);
		pioDigitalWrite(BLACK_1, 0);
		pioDigitalWrite(BLUE_1, 0);
		
		// disable motor signals on H-Bridge
		pioDigitalWrite(RB_EN_1, 0);
		pioDigitalWrite(BG_EN_1, 0);
		
		tcDelayMicroseconds(delay);
	}
}
