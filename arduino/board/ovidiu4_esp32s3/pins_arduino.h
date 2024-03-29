#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <stdint.h>

#define USB_VID            0x303a
#define USB_PID            0x1001
#define USB_MANUFACTURER   "Ovidiu4"
#define USB_PRODUCT        "Smart Plant Monitor ESP32-S3"
#define USB_SERIAL         "" // Empty string for MAC adddress

#define EXTERNAL_NUM_INTERRUPTS 46
#define NUM_DIGITAL_PINS        48
#define NUM_ANALOG_INPUTS       20

#define analogInputToDigitalPin(p)  (((p)<20)?(analogChannelToDigitalPin(p)):-1)
#define digitalPinToInterrupt(p)    (((p)<48)?(p):-1)
#define digitalPinHasPWM(p)         (p < 46)

#define LED_BUILTIN         13

#define I2C_POWER           7     // I2C power pin
#define PIN_I2C_POWER       7     // I2C power pin


static const uint8_t TX = 39;
static const uint8_t RX = 38;
#define TX1 TX
#define RX1 RX

static const uint8_t SDA = 42; 
static const uint8_t SCL = 41; 

static const uint8_t SS    = 16; 
static const uint8_t MOSI  = 14; 
static const uint8_t SCK   = 15; 
static const uint8_t MISO  = 37; 

static const uint8_t A0 = 18;
static const uint8_t A1 = 17;
static const uint8_t A2 = 16;
static const uint8_t A3 = 15;
static const uint8_t A4 = 14;
static const uint8_t A5 = 8;
static const uint8_t A6 = 3;
static const uint8_t A7 = 4;
static const uint8_t A8 = 5;
static const uint8_t A9 = 6;
static const uint8_t A10 = 9;
static const uint8_t A11 = 10;
static const uint8_t A12 = 11;
static const uint8_t A13 = 12;
static const uint8_t A14 = 13;

static const uint8_t T3 = 3;
static const uint8_t T4 = 4;
static const uint8_t T5 = 5;
static const uint8_t T6 = 6;
static const uint8_t T8 = 8;
static const uint8_t T9 = 9;
static const uint8_t T10 = 10;
static const uint8_t T11 = 11;
static const uint8_t T12 = 12;
static const uint8_t T13 = 13;
static const uint8_t T14 = 14;

#endif /* Pins_Arduino_h */
