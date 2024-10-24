// Header file for Display M6389A
// Author: Jeff Zhong
// Date: 10/14/2024

#ifndef M6389_H
#define M6389_H

// I2C Address of the Display. The actual I2C address is 0x39, this is the 7-bit address used by the I2C protocol.
// When communicating with I2C devices, the 7-bit address is combined with a read/write bit to form the 8-bit address.
// So the original address will be shifted left by one bit, so will use 0x72 in the program.
#define M6389_ADDR 0x72

// Define SDA and SCL Pins
#define SDA P1_5
#define SCL P1_4

// Delay.
void delay_ms(unsigned int ms);
// Start the IC.
void i2c_start(void);
// Stop the I2C.
void i2c_stop(void);
// Send display content data to the display.
void send_data(unsigned char dat);
// Display function.
void i2c_display(unsigned char dat);
// Initialization.
void init_display();
// Verify the truth table of the screen.
void verify_truth();
// Display number 0-9 on the LCD screen.
void display_number(unsigned int n, unsigned char value);
#endif
