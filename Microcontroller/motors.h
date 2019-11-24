



#define DELAY 1000 // ms


	
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

//void movePositive(size_t frequency) {
//	size_t period = 1000000 / frequency; // (period in microseconds)
//	size_t delay = period / 3; // (delay in microseconds)



