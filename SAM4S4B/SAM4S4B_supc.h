/* SAM4S4B_pmc.h
 *
 * atrikha@hmc.edu
 * 20th November, 2019
 * 
 * Contains base address locations, register structs, definitions, and functions for the SUPC
 * peripheral (Supply Controller) of the SAM4S4B microcontroller. */

#ifndef SAM4S4B_SUPC_H
#define SAM4S4B_SUPC_H

#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// SUPC Base Address Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////

#define SUPC_BASE   (0x400E1410) // SUPC Base Address

////////////////////////////////////////////////////////////////////////////////////////////////////
// SUPC Registers
////////////////////////////////////////////////////////////////////////////////////////////////////

// Bit field struct for the SUPC_CR register
typedef struct {
    volatile uint32_t           : 2;
    volatile uint32_t VR0FF     : 1;
    volatile uint32_t XTALSEL   : 1;
    volatile uint32_t           : 20;
    volatile uint32_t KEY       : 8;
} SUPC_CR_bits;

// Bit field struct for the SUPC_SMMR register
typedef struct {
    volatile uint32_t SMTH     : 4;
    volatile uint32_t          : 4;
    volatile uint32_t SMSMPL   : 3;
    volatile uint32_t          : 1;
    volatile uint32_t SMRSTEN  : 1;
    volatile uint32_t SMIEN    : 1;
    volatile uint32_t          : 18;
} SUPC_SMMR_bits;

// Bit field struct for the SUPC_MR register
typedef struct {
    volatile uint32_t           : 12;
    volatile uint32_t BODRSTEN  : 1;
    volatile uint32_t BODDIS    : 1;
    volatile uint32_t ONREG     : 1;
    volatile uint32_t           : 5;
    volatile uint32_t OSCBYPASS : 1;
    volatile uint32_t           : 3;
    volatile uint32_t KEY       : 8;
} SUPC_MR_bits;

// Bit field struct for the SUPC_WUMR register
typedef struct {
    volatile uint32_t           : 1;
    volatile uint32_t SMEN      : 1;
    volatile uint32_t RTTEN     : 1;
    volatile uint32_t RTCEN     : 1;
    volatile uint32_t           : 1;
    volatile uint32_t LPDBCEN0  : 1;
    volatile uint32_t LPDBCEN1  : 1;
    volatile uint32_t LPDBCCLR  : 1;
    volatile uint32_t           : 4;
    volatile uint32_t WKUPDBC   : 3;
    volatile uint32_t           : 1;
    volatile uint32_t LPDBC     : 3;
    volatile uint32_t           : 13;
} SUPC_WUMR_bits;

// Bit field struct for the SUPC_WUIR register
typedef struct {
    volatile uint32_t WKUPEN0   : 1;
    volatile uint32_t WKUPEN1   : 1;
    volatile uint32_t WKUPEN2   : 1;
    volatile uint32_t WKUPEN3   : 1;
    volatile uint32_t WKUPEN4   : 1;
    volatile uint32_t WKUPEN5   : 1;
    volatile uint32_t WKUPEN6   : 1;
    volatile uint32_t WKUPEN7   : 1;
    volatile uint32_t WKUPEN8   : 1;
    volatile uint32_t WKUPEN9   : 1;
    volatile uint32_t WKUPEN10  : 1;
    volatile uint32_t WKUPEN11  : 1;
    volatile uint32_t WKUPEN12  : 1;
    volatile uint32_t WKUPEN13  : 1;
    volatile uint32_t WKUPEN14  : 1;
    volatile uint32_t WKUPEN15  : 1;
    volatile uint32_t WKUPT0    : 1;
    volatile uint32_t WKUPT1    : 1;
    volatile uint32_t WKUPT2    : 1;
    volatile uint32_t WKUPT3    : 1;
    volatile uint32_t WKUPT4    : 1;
    volatile uint32_t WKUPT5    : 1;
    volatile uint32_t WKUPT6    : 1;
    volatile uint32_t WKUPT7    : 1;
    volatile uint32_t WKUPT8    : 1;
    volatile uint32_t WKUPT9    : 1;
    volatile uint32_t WKUPT10   : 1;
    volatile uint32_t WKUPT11   : 1;
    volatile uint32_t WKUPT12   : 1;
    volatile uint32_t WKUPT13   : 1;
    volatile uint32_t WKUPT14   : 1;
    volatile uint32_t WKUPT15   : 1;
} SUPC_WUIR_bits;

// Bit field struct for the SUPC_SR register
typedef struct {
    volatile uint32_t           : 1;
    volatile uint32_t WKUPS     : 1;
    volatile uint32_t SMWS      : 1;
    volatile uint32_t BODRSTS   : 1;
    volatile uint32_t SMRSTS    : 1;
    volatile uint32_t SMS       : 1;
    volatile uint32_t SMOS      : 1;
    volatile uint32_t OSCSEL    : 1;
    volatile uint32_t           : 5;
    volatile uint32_t LPDBCS0   : 1;
    volatile uint32_t LPDBCS1   : 1;
    volatile uint32_t           : 1;
    volatile uint32_t WKUPIS0   : 1;
    volatile uint32_t WKUPIS1   : 1;
    volatile uint32_t WKUPIS2   : 1;
    volatile uint32_t WKUPIS3   : 1;
    volatile uint32_t WKUPIS4   : 1;
    volatile uint32_t WKUPIS5   : 1;
    volatile uint32_t WKUPIS6   : 1;
    volatile uint32_t WKUPIS7   : 1;
    volatile uint32_t WKUPIS8   : 1;
    volatile uint32_t WKUPIS9   : 1;
    volatile uint32_t WKUPIS10  : 1;
    volatile uint32_t WKUPIS11  : 1;
    volatile uint32_t WKUPIS12  : 1;
    volatile uint32_t WKUPIS13  : 1;
    volatile uint32_t WKUPIS14  : 1;
    volatile uint32_t WKUPIS15  : 1;
} SUPC_SR_bits;

// Bit field struct for the SYSC_WPMR Reserved register
// typedef struct {
//     volatile uint32_t WPEN      : 1;
//     volatile uint32_t           : 7;
//     volatile uint32_t WPKEY     : 24;
// } SYSC_WPMR_bits;

// Peripheral struct for a PMC peripheral
typedef struct {
    volatile SUPC_CR_bits   SUPC_CR;       // (Supc Offset: 0x0000) Supply Controller Control Register
    volatile SUPC_SMMR_bits SUPC_SMMR;     // (Supc Offset: 0x0004) Supply Controller Supply Monitor Mode Register
    volatile SUPC_MR_bits   SUPC_MR;       // (Supc Offset: 0x0008) Supply Controller Mode Register
    volatile SUPC_WUMR_bits SUPC_WUMR;     // (Supc Offset: 0x000C) Supply Controller Wake-up Mode Register
    volatile SUPC_WUIR_bits SUPC_WUIR;     // (Supc Offset: 0x0010) Supply Controller Wake-up Inputs Register
    volatile SUPC_SR_bits   SUPC_SR;       // (Supc Offset: 0x0014) Supply Controller Status Register
} Supc;

// Pointer to a Supc-sized chunk of memory at the SUPC peripheral
#define SUPC ((Supc *) SUPC_BASE)


////////////////////////////////////////////////////////////////////////////////////////////////////
// PMC Definitions
////////////////////////////////////////////////////////////////////////////////////////////////////

// // Values which "periph" can take on in pmcEnablePeriph()
// #define PMC_ID_SUPC   ( 0) // Supply Controller (SUPC)
// #define PMC_ID_RSTC   ( 1) // Reset Controller (RSTC)
// #define PMC_ID_RTC    ( 2) // Real Time Clock (RTC)
// #define PMC_ID_RTT    ( 3) // Real Time Timer (RTT)
// #define PMC_ID_WDT    ( 4) // Watchdog Timer (WDT)
// #define PMC_ID_PMC    ( 5) // Power Management Controller (PMC)
// #define PMC_ID_EFC    ( 6) // Enhanced Embedded Flash Controller (EFC)
// #define PMC_ID_UART0  ( 8) // UART 0 (UART0)
// #define PMC_ID_UART1  ( 9) // UART 1 (UART1)
// #define PMC_ID_PIOA   (11) // Parallel I/O Controller A (PIOA)
// #define PMC_ID_PIOB   (12) // Parallel I/O Controller B (PIOB)
// #define PMC_ID_USART0 (14) // USART 0 (USART0)
// #define PMC_ID_USART1 (15) // USART 1 (USART1)
// #define PMC_ID_HSMCI  (18) // Multimedia Card Interface (HSMCI)
// #define PMC_ID_TWI0   (19) // Two Wire Interface 0 (TWI0)
// #define PMC_ID_TWI1   (20) // Two Wire Interface 1 (TWI1)
// #define PMC_ID_SPI    (21) // Serial Peripheral Interface (SPI)
// #define PMC_ID_SSC    (22) // Synchronous Serial Controler (SSC)
// #define PMC_ID_TC0    (23) // Timer/Counter 0 (TC0)
// #define PMC_ID_TC1    (24) // Timer/Counter 1 (TC1)
// #define PMC_ID_TC2    (25) // Timer/Counter 2 (TC2)
// #define PMC_ID_ADC    (29) // Analog To Digital Converter (ADC)
// #define PMC_ID_DACC   (30) // Digital To Analog Converter (DACC)
// #define PMC_ID_PWM    (31) // Pulse Width Modulation (PWM)
// #define PMC_ID_CRCCU  (32) // CRC Calculation Unit (CRCCU)
// #define PMC_ID_ACC    (33) // Analog Comparator (ACC)
// #define PMC_ID_UDP    (34) // USB Device Port (UDP)

// // Values which the CSS bits in PMC_PCK[k] can take on; clock IDs
// #define PMC_PCK_CSS_SLOW_CLK 0
// #define PMC_PCK_CSS_MAIN_CLK 1
// #define PMC_PCK_CSS_PLLA_CLK 2
// #define PMC_PCK_CSS_PLLB_CLK 3
// #define PMC_PCK_CSS_MCK      4

// // Values which the PRES bits in PMC_PCK[k] can take on; clock division factors
// #define PMC_PCK_PRES_CLK1  0
// #define PMC_PCK_PRES_CLK2  1
// #define PMC_PCK_PRES_CLK4  2
// #define PMC_PCK_PRES_CLK8  3
// #define PMC_PCK_PRES_CLK16 4
// #define PMC_PCK_PRES_CLK32 5
// #define PMC_PCK_PRES_CLK63 6

// // Writing any other value in this field aborts the write operation of the WPEN bit.
// // Always reads as 0.
// #define PMC_WPMR_WPKEY_PASSWD (0x504D43U << 8)

// // Writing any other value in this field aborts the write operation of the CKGR_MOR register.
// #define CKGR_MOR_KEY_PASSWD 0x37


// ////////////////////////////////////////////////////////////////////////////////////////////////////
// // PMC User Functions
// ////////////////////////////////////////////////////////////////////////////////////////////////////

//  Routes Master Clock to the desired peripheral, thereby enabling it.
//  *    -- periphID: a PMC peripheral ID to enable, e.g. PMC_ID_PIOA 
// void pmcEnablePeriph(int periphID) {
//     PMC->PMC_PCER0 = 1 << periphID;
// }

// /* Returns the number of Main Clock cycles within 16 Slow Clock periods.
//  *    -- return: the number of Main Clock cycles in 16 Slow Clock periods.
//  * This is useful for calibrating the Main Clock (which the peripherals indirectly use) if using
//  * a reliable crystal oscillator for the slow clock. Returns 0 if the master clock is disabled or
//  * if the read value is invalid. The RC oscillator which the Slow Clock uses by default runs at
//  * about 32 kHz, but this can vary fairly substantially between boards and over temperatures. */
// int pmcCheckMasterClk() {
//     int valid = PMC->CKGR_MCFR.MAINFRDY; // Check if reported value is valid
//     return valid ? PMC->CKGR_MCFR.MAINF : 0;
// }


// /* Turns off both sources to the main oscillator and bypasses it to allow for an external clock
//  * provided between XIN and XOUT. Note: Because the key must be written simultaneously with other
//  * data, a bitfield cannot be used. However, each register modification is accompanied with a 
//  * comment detailing the equivalent bitfield operation, and a bitfield (CKGR_MOS_bits) is provided
//  * in the register defintions section for reference.
//  * 
//  * Note: This function must be REMOVED from samInit() in SAM4S4B.h if an external oscillator is not
//  * provided or else the microcontroller will not function. */
// void pmcMainClkBypass() {
//     uint32_t CKGR_MOR_reg = PMC->CKGR_MOR; // Capture current state of CKGR_MOR register

//     // "PMC->CKGR_MOR.KEY = CKGR_MOR_KEY_PASSWD;". Enables writes to this register.
//     CKGR_MOR_reg |= (CKGR_MOR_KEY_PASSWD << 16);

//     // "PMC->CKGR_MOR.MOSCXTEN = 0;". Disables the Main Crystal Oscillator.
//     CKGR_MOR_reg &= ~1;

//     // "PMC->CKGR_MOR.MOSCXTBY = 1;". Bypasses the Main Crystal Oscillator.
//     CKGR_MOR_reg |= (1 << 1);

//     PMC->CKGR_MOR = CKGR_MOR_reg; // Writes the modified CKGR_MOR values to the register
//     while(!(PMC->PMC_SR.MOSCXTS)); // Wait for external clock to stabilize
    
//     // "PMC->CKGR_MOR.MOSCSEL = 1;". Selects the Main Crystal Oscillator as the main clock.
//     PMC->CKGR_MOR |= ((CKGR_MOR_KEY_PASSWD << 16) | (1 << 24));

//     // "PMC->CKGR_MOR.MOSCRCEN = 0;". Disables the Main On-Chip RC Oscillator.
//     CKGR_MOR_reg &= ~(1 << 3);

// }

// void pmcEnableWriteProtection() {
// 	PMC->PMC_WPMR= 0x504D4301;                 /* Enable write protect */
// }

// void pmcDisableWriteProtection() {
// 	PMC->PMC_WPMR= 0x504D4300;                 /* Disable write protect */
// }

#endif
