// Header file for Display M6389A
// Author: Jeff Zhong
// Date: 10/14/2024

#ifndef M6389_H
#define M6389_H

// I2C Address of the Display
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
//void display_on_digit(unsigned char dat_array[4], unsigned int n);
// Initialization.
void init_display();

#endif
