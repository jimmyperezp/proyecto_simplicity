#ifndef COOKIE_HAL_H
#define COOKIE_HAL_H


#include "DW1000CompileOptions.h"
#include "deprecated.h"
#include "require_cpp11.h"

// Standard C libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>
#include <cstring>
#include <math.h>


//Type definitions to use with the gecko SDK

typedef uint8_t byte;
typedef bool boolean;

//Bit operations
#ifndef bitRead
  #define bitRead(value, bit) (((value) >> (bit)) & 0x01)
  #define bitSet(value, bit)  ((value) |= (1UL << (bit)))
  #define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
  #define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))
#endif
//Constants
#define LOW 0
#define HIGH 1


// Cookie's Board pins & ports

// RSTN (Reset) --> D22 Cookie = PI0 EFR32
#define DW_RST_PORT gpioPortI
#define DW_RST_PIN 0

// SPI Chip Select --> D15 Cookie = PB11 EFR32
#define DW_CS_PORT gpioPortB
#define DW_CS_PIN 11

// IRQ --> D20 Cookie --> PI3 EFR32
#define DW_IRQ_PORT gpioPortI
#define DW_IRQ_PIN 3

// Wakeup --> D24 Cookie --> PI1 EFR32
#define DW_WAKE_PORT gpioPortI
#define DW_WAKE_PIN 11

// Function declarations to initialize the chip
void cookie_hal_init(void);

//SPI control
void cookie_hal_spi_select(bool select);
void cookie_hal_spi_transfer(uint8_t *buffer_tx, uint8_t *buffer_rx, uint16_t length);
void cookie_hal_spi_speed(bool fast);

//DW1000 Reset
void cookie_hal_reset(bool active);


//Delay methods (instead of 'Delay' from arduino)
void cookie_hal_delay_ms(uint32_t ms);
void cookie_hal_delay_us(uint32_t us);

uint32_t cookie_hal_get_millis(void);

#endif
