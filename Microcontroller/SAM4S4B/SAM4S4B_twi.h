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
    volatile uint32_t       Reserved1[3];    // 0x14 - 0x1C
    volatile TWI_SR_bits    TWI_SR;         // (TWI Offset: 0x20) Status Register
    volatile TWI_IER_bits   TWI_IER;        // (TWI Offset: 0x24) Interrupt Enable Register
    volatile TWI_IDR_bits   TWI_IDR;        // (TWI Offset: 0x28) Interrupt Disable Register
    volatile TWI_IMR_bits   TWI_IMR;        // (TWI Offset: 0x2C) Interrupt Mask Register
    volatile TWI_RHR_bits   TWI_RHR;        // (TWI Offset: 0x30) Receive Holding Register
    volatile TWI_THR_bits   TWI_THR;        // (TWI Offset: 0x34) Transmit Holding Register
    volatile uint32_t       Reserved2[5];    // 0xEC - 0xFC
    volatile uint32_t       Reserved3[11];   // 0x100 - 0x128 PDC registers
} TWI;

// Pointer to an TWI-sized chunk of memory at the TWI peripheral
#define TWI0 ((TWI*) TWI0_BASE)
#define TWI1 ((TWI*) TWI1_BASE)

////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////

// Writing any other value in this field aborts the write operation of the WPEN bit.
// Always reads as 0.
#define SPI_WPMR_WPKEY_PASSWD (0x535049u << 8)


////////////////////////////////////////////////////////////////////////////////////////////////////
// TWI User Functions
////////////////////////////////////////////////////////////////////////////////////////////////////


// initializes TWI to master mode
void twiInit(uint8_t pmc_ID) {
    if (pmc_ID == 0) {
        pmcEnablePeriph(PMC_ID_TWI0);
    } else if (pmc_ID == 1) {
        pmcEnablePeriph(PMC_ID_TWI1);
    }

    pioInit();

    // Initially assigning SPI pins (PA11-PA14) to peripheral A (SPI)
   pioPinMode(PIO_PB4, PIO_PERIPH_A);
   pioPinMode(PIO_PB5, PIO_PERIPH_A);
   pioPinMode(PIO_PB13, PIO_PERIPH_A);
   pioPinMode(PIO_PA14, PIO_PERIPH_A);

   // TWI->TWI_CR.SPIEN = 1; // Enable SPI
   // SPI->SPI_MR.MSTR = 1; // Put SPI in master mode
   // SPI->SPI_CSR0.SCBR = clkdivide; // Set the clock divisor
   // SPI->SPI_CSR0.CPOL = cpol; // Set the polarity
   // SPI->SPI_CSR0.NCPHA = ncpha; // Set the phase

}

//void spiInit(uint32_t clkdivide, uint32_t cpol, uint32_t ncpha) {
//    pmcEnablePeriph(PMC_ID_TWI);
//    pioInit();
//
//    // Initially assigning SPI pins (PA11-PA14) to peripheral A (SPI)
//    pioPinMode(PIO_PA11, PIO_PERIPH_A);
//    pioPinMode(PIO_PA12, PIO_PERIPH_A);
//    pioPinMode(PIO_PA13, PIO_PERIPH_A);
//    pioPinMode(PIO_PA14, PIO_PERIPH_A);
//
//    SPI->SPI_CR.SPIEN = 1; // Enable SPI
//    SPI->SPI_MR.MSTR = 1; // Put SPI in master mode
//    SPI->SPI_CSR0.SCBR = clkdivide; // Set the clock divisor
//    SPI->SPI_CSR0.CPOL = cpol; // Set the polarity
//    SPI->SPI_CSR0.NCPHA = ncpha; // Set the phase
//}

// recieves data from a slave
// slave address size: 1 byte
// slave recieved data size: 2 bytes
void twiMasterRecieve(uint8_t pmc_ID, char slaveRegisterAddress) {
    // array to store two bytes recieved
    char* dataRecieved[2];

    // enable master mode
    TWI1->TWI_CR.MSEN = 1;
    TWI1->TWI_CR.MSDIS = 0;

    // disable slave mode
    TWI1->TWI_CR.SVDIS = 1;

    // set master to read from slave
    TWI1->TWI_MMR.MREAD = 1;

    // set slave address size
    TWI1->TWI_MMR.IADRSZ = 0b01;

    // set slave device address
    //
    TWI1->TWI_MMR.DADR = 0b1000000;
    TWI1->TWI_IADR.IADR = slaveRegisterAddress;

    // start the communication
    TWI1->TWI_CR.START = 1;

    // wait for byte to be recieved
    while(!(TWI->TWI_SR.RXRDY));
    // store captured byte
    dataRecieved[0] = TWI1->TWI_RHR.RXDATA;

    // wait for byte to be recieved
    while(!(TWI->TWI_SR.RXRDY));
    // store captured byte
    dataRecieved[1] = TWI1->TWI_RHR.RXDATA;

    // stop the communication
    TWI1->TWI_CR.STOP = 1;
}

//
///* Transmits a character (1 byte) over SPI and returns the received character.
// *    -- send: the character to send over SPI
// *    -- return: the character received over SPI */
// char spiSendReceive(char send) {
//    SPI->SPI_TDR.TD = send; // Transmit the character over SPI
//    while (!(SPI->SPI_SR.RDRF)); // Wait until data has been received
//    return (char) (SPI->SPI_RDR.RD); // Return received character
// }
//
///* Transmits a short (2 bytes) over SPI and returns the received short.
// *    -- send: the short to send over SPI
// *    -- return: the short received over SPI */
// short spiSendReceive16(uint16_t send) {
//    short rec; // Variable for received data, filled one byte at a time
//    rec = spiSendReceive((send & 0xFF00) >> 8); // Send the MSB of the data first
//    rec = (rec << 8) | spiSendReceive(send & 0xFF); // Send the LSB of the data
//    return rec;
//}


#endif
