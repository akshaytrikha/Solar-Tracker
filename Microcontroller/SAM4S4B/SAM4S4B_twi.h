/* SAM4S4B_twi.h
 *
 * khoe@g.hmc.edu
 * 11/20/2019
 *
 * Contains base address locations, register structs, definitions, and functions for the TWI (Two-Wire Interface) peripheral of the SAM4S4B microcontroller. */

#ifndef SAM4S4B_TWI_H
#define SAM4S4B_TWI_H

#include <stdint.h>
#include "SAM4S4B_pio.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI Base Address Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////

#define TWI0_BASE   (0x40018000U) // TWI0 Base Address
#define TWI1_BASE   (0x4001C000U) // TWI1 Base Address)

////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI Registers
////////////////////////////////////////////////////////////////////////////////////////////////////

// Bit field struct for the TWI_CR register
typedef struct {
    volatile uint32_t START    : 1;
    volatile uint32_t STOP     : 1;
    volatile uint32_t MSEN     : 1;
    volatile uint32_t MSDIS    : 1;
    volatile uint32_t SVEN     : 1;
    volatile uint32_t SVDIS    : 1;
    volatile uint32_t QUICK    : 1;
    volatile uint32_t SWRST    : 1;
    volatile uint32_t          : 24;
} TWI_CR_bits;

// Bit field struct for the TWI_MMR register
typedef struct {
    volatile uint32_t          : 8;
    volatile uint32_t IADRSZ   : 2;
    volatile uint32_t          : 2;
    volatile uint32_t MREAD    : 1;
    volatile uint32_t          : 3;
    volatile uint32_t DADR     : 7;
    volatile uint32_t          : 9;
} TWI_MMR_bits;

// Bit field struct for the TWI_SMR register
typedef struct {
    volatile uint32_t          : 16;
    volatile uint32_t SADR     : 7;
    volatile uint32_t          : 9;
} TWI_SMR_bits;

// Bit field struct for the TWI_IADR register
typedef struct {
    volatile uint32_t IADR     : 24;
    volatile uint32_t          : 8;
} TWI_IADR_bits;

// Bit field struct for the TWI_CWGR register
typedef struct {
    volatile uint32_t CLDIV    : 8;
    volatile uint32_t CHDIV    : 8;
    volatile uint32_t CKDIV    : 3;
    volatile uint32_t          : 13;
} TWI_CWGR_bits;

// Bit field struct for the TWI_SR register
typedef struct {
    volatile uint32_t TXCOMP   : 1;
    volatile uint32_t RXRDY    : 1;
    volatile uint32_t TXRDY    : 1;
    volatile uint32_t SVREAD   : 1;
    volatile uint32_t SVACC    : 1;
    volatile uint32_t GACC     : 1;
    volatile uint32_t OVRE     : 1;
    volatile uint32_t          : 1;
    volatile uint32_t NACK     : 1;
    volatile uint32_t ARBLST   : 1;
    volatile uint32_t SCLWS    : 1;
    volatile uint32_t EOSACC   : 1;
    volatile uint32_t ENDRX    : 1;
    volatile uint32_t ENDTX    : 1;
    volatile uint32_t RXBUFF   : 1;
    volatile uint32_t TXBUFE   : 1;
    volatile uint32_t          : 16;
} TWI_SR_bits;

// Bit field struct for the TWI_IER register
typedef struct {
    volatile uint32_t TXCOMP   : 1;
    volatile uint32_t RXRDY    : 1;
    volatile uint32_t TXRDY    : 1;
    volatile uint32_t          : 1;
    volatile uint32_t SVACC    : 1;
    volatile uint32_t GACC     : 1;
    volatile uint32_t OVRE     : 1;
    volatile uint32_t          : 1;
    volatile uint32_t NACK     : 1;
    volatile uint32_t ARBLST   : 1;
    volatile uint32_t SCL_WS   : 1;
    volatile uint32_t EOSACC   : 1;
    volatile uint32_t ENDRX    : 1;
    volatile uint32_t ENDTX    : 1;
    volatile uint32_t RXBUFF   : 1;
    volatile uint32_t TXBUFE   : 1;
    volatile uint32_t          : 16;
} TWI_IER_bits;

// Bit field struct for the TWI_IDR register
typedef struct {
    volatile uint32_t TXCOMP   : 1;
    volatile uint32_t RXRDY    : 1;
    volatile uint32_t TXRDY    : 1;
    volatile uint32_t          : 1;
    volatile uint32_t SVACC    : 1;
    volatile uint32_t GACC     : 1;
    volatile uint32_t OVRE     : 1;
    volatile uint32_t          : 1;
    volatile uint32_t NACK     : 1;
    volatile uint32_t ARBLST   : 1;
    volatile uint32_t SCL_WS   : 1;
    volatile uint32_t EOSACC   : 1;
    volatile uint32_t ENDRX    : 1;
    volatile uint32_t ENDTX    : 1;
    volatile uint32_t RXBUFF   : 1;
    volatile uint32_t TXBUFE   : 1;
    volatile uint32_t          : 16;
} TWI_IDR_bits;

// Bit field struct for the TWI_IMR register
typedef struct {
    volatile uint32_t TXCOMP   : 1;
    volatile uint32_t RXRDY    : 1;
    volatile uint32_t TXRDY    : 1;
    volatile uint32_t          : 1;
    volatile uint32_t SVACC    : 1;
    volatile uint32_t GACC     : 1;
    volatile uint32_t OVRE     : 1;
    volatile uint32_t          : 1;
    volatile uint32_t NACK     : 1;
    volatile uint32_t ARBLST   : 1;
    volatile uint32_t SCL_WS   : 1;
    volatile uint32_t EOSACC   : 1;
    volatile uint32_t ENDRX    : 1;
    volatile uint32_t ENDTX    : 1;
    volatile uint32_t RXBUFF   : 1;
    volatile uint32_t TXBUFE   : 1;
    volatile uint32_t          : 16;
} TWI_IMR_bits;

// Bit field struct for the TWI_RHR register
typedef struct {
    volatile uint32_t RXDATA   : 8;
    volatile uint32_t          : 24;
} TWI_RHR_bits;

// Bit field struct for the TWI_THR register
typedef struct {
    volatile uint32_t TXDATA   : 8;
    volatile uint32_t          : 24;
} TWI_THR_bits;

// Peripheral struct for the TWI peripheral
typedef struct {
    volatile TWI_CR_bits    TWI_CR;         // (TWI Offset: 0x00) Control Register
    volatile TWI_MMR_bits   TWI_MMR;        // (TWI Offset: 0x04) Master Mode Register
    volatile TWI_SMR_bits   TWI_SMR;        // (TWI Offset: 0x08) Slave Mode Register
    volatile TWI_IADR_bits  TWI_IADR;       // (TWI Offset: 0x0C) Internal Address Register
    volatile TWI_CWGR_bits  TWI_CWGR;       // (TWI Offset: 0x10) Clock Waveform Generator Register
    volatile uint32_t       Reserved1[2];    // 0x14 - 0x1C
    volatile TWI_SR_bits    TWI_SR;         // (TWI Offset: 0x20) Status Register
    volatile TWI_IER_bits   TWI_IER;        // (TWI Offset: 0x24) Interrupt Enable Register
    volatile TWI_IDR_bits   TWI_IDR;        // (TWI Offset: 0x28) Interrupt Disable Register
    volatile TWI_IMR_bits   TWI_IMR;        // (TWI Offset: 0x2C) Interrupt Mask Register
    volatile TWI_RHR_bits   TWI_RHR;        // (TWI Offset: 0x30) Receive Holding Register
    volatile TWI_THR_bits   TWI_THR;        // (TWI Offset: 0x34) Transmit Holding Register
    volatile uint32_t       Reserved2[4];    // 0xEC - 0xFC
    volatile uint32_t       Reserved3[10];   // 0x100 - 0x128 PDC registers
} TWI;

// Pointer to an TWI-size 0_BASE)
#define TWI0 ((TWI*) TWI0_BASE)
#define TWI1 ((TWI*) TWI1_BASE)

////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI User Functions
////////////////////////////////////////////////////////////////////////////////////////////////////


// initializes TWI to master mode
void twiInit(uint8_t twi_ID) {
	 pioInit(); 
	
	 // enable TWI clock via PMC
   if (twi_ID == 0) {
			 // enable peripheral through PMC
       pmcEnablePeriph(PMC_ID_TWI0);
		 
			 // assigning TWI0 pins to peripheral A
			 pioPinMode(PIO_PA3, PIO_PERIPH_A);
			 pioPinMode(PIO_PA4, PIO_PERIPH_A);
		 
			 // set clock waveform generator
			 TWI0->TWI_CWGR.CLDIV = 0x0D;
			 TWI0->TWI_CWGR.CHDIV = 0x05;
			 TWI0->TWI_CWGR.CKDIV = 0b010;
		 
   } else if (twi_ID == 1) {
       // enable peripheral through PMC
       pmcEnablePeriph(PMC_ID_TWI1);
		 
			 // assigning TWI1 pins to peripheral A
			 pioPinMode(PIO_PB4, PIO_PERIPH_A);
			 pioPinMode(PIO_PB5, PIO_PERIPH_A);
			 
		   // set clock waveform generator
			 TWI1->TWI_CWGR.CLDIV = 0x0D;
			 TWI1->TWI_CWGR.CHDIV = 0x05;
			 TWI1->TWI_CWGR.CKDIV = 0b010;
   }
}

// recieves data from a slave
// slave address size: 1 byte
// slave recieved data size: 2 bytes
char* twiMasterRecieve(char slaveRegisterAddress) {
    // array to store two bytes recieved
    char* dataRecieved[2];
	 
	  // enable master mode
		TWI0->TWI_CR.MSDIS = 0b0;
    TWI0->TWI_CR.MSEN = 0b1;
    

		// disable slave mode
    TWI0->TWI_CR.SVDIS = 0b1;

    // set master to read from slave
    TWI0->TWI_MMR.MREAD = 0b1;
		
	  // set slave address size
	  TWI0->TWI_MMR.IADRSZ = 0b01;

	  // set slave device address
	  TWI0->TWI_MMR.DADR = 0b1000000;
	
		// Set slave internal register address to acccess
    TWI0->TWI_IADR.IADR = slaveRegisterAddress;

    // start the communication
    TWI0->TWI_CR.START = 0b1;

    // wait for byte to be recieved
    while(!(TWI0->TWI_SR.RXRDY));
    // store captured byte
    *dataRecieved[0] = TWI0->TWI_RHR.RXDATA;
		
		// stop the communication
    TWI0->TWI_CR.STOP = 1;

    // wait for byte to be recieved
    while(!(TWI0->TWI_SR.RXRDY));
    // store captured byte
		*dataRecieved[1] = TWI0->TWI_RHR.RXDATA;
		return *dataRecieved;
}

uint8_t readi2c() {
	// set master to read from slave
  TWI0->TWI_MMR.MREAD = 0b1;
		
	// set slave address size
	TWI0->TWI_MMR.IADRSZ = 0b01;

	// set slave device address
	TWI0->TWI_MMR.DADR = 0b1000000;
	
	// Set slave internal register address to acccess
    TWI0->TWI_IADR.IADR = 0x03;
	return (uint8_t)TWI1->TWI_RHR.RXDATA;
}

#endif
