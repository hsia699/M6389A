// Source file for Display M6389A
// Author: Jeff Zhong
// Date： 10/15/2024

#include <8052.h>      // Include 8052-specific headers
#include "m6389.h"      // Include display header

// Delay function (in milliseconds)
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 10; j++);
    } 
}

// Start I2C communication.
void i2c_start() {
    SDA = 1;
    SCL = 1;
    delay_ms(1);
	// The SDA line changes from high to low while SCL remains high.
    SDA = 0;
    delay_ms(1);
	// Pull the SCL low to lock the communication.
    SCL = 0;
	delay_ms(1);
}

// Stop I2C communication.
void i2c_stop() {
	// Remain low to make sure the I2C communication is active.
    SDA = 0;
	// Pull SCL high to prepare to stop the communication.
    SCL = 1;
    delay_ms(1);
	// The SDA line change from low to high to end the I2C communication.
    SDA = 1;
	delay_ms(1);
	SCL = 0;
}

// Send Data to the Display
void send_data(unsigned char dat) {
	unsigned char tmp = 0x00;
	unsigned char n = 0x00;
	 for (n = 0; n < 8; n++) {
	     tmp = dat;
		 dat = dat << 1;
		 if ((tmp & 0x80) == 0x80) {
		     SDA = 1;
		 } else {
		     SDA = 0;
		 }
		 SCL = 1;
        delay_ms(1);
		// Reset to low for the time usage.
        SCL = 0;
	 }
    SDA = 1;
	delay_ms(1);
	SCL = 1;
	delay_ms(1);
	SCL = 0;
	delay_ms(1);
}

// Iterate to loop through all segments on the display.
void i2c_display(unsigned char dat) {
	unsigned int i;
	for (i = 0; i < 40; i++) {
		i2c_start();
		// Display I2C address.
		send_data(M6389_ADDR);
		// Device select.
		send_data(0xE0);
	    send_data(i);
		send_data(dat);
		delay_ms(1000);
		i2c_stop();
	}
}

void init_display() {
	unsigned char all_on = 0xFF;
	unsigned char all_off = 0x00;
	
	i2c_start();
	send_data(M6389_ADDR);
	// Device select.
	send_data(0xE0);
	delay_ms(1);
	// Mode set.
	send_data(0xCE);
	delay_ms(1);

	i2c_display(all_on);
    delay_ms(1);

    i2c_display(all_off);
    delay_ms(1);   
	
	i2c_stop();
}

void verify_truth() {
    unsigned int i;
	for (i = 0; i < 40; i++) {
		i2c_start();
		send_data(M6389_ADDR);
		send_data(0xE0);
	    send_data(i);
		send_data(0x80);
		delay_ms(1000);
		i2c_stop();
		delay_ms(3000);
		i2c_start();
		send_data(M6389_ADDR);
		send_data(0xE0);
	    send_data(i);
		send_data(0xC0);
		delay_ms(1000);
		i2c_stop();
		delay_ms(3000);
	}
}

void display_number(unsigned int n, unsigned char value) {
    i2c_start();
	send_data(M6389_ADDR);
	send_data(0xE0);
	send_data(n);
	send_data(value);
	delay_ms(1000);
	i2c_stop();
}
