// Main file for Display M6389A which will include the display logic designed by the author.
// Author: Jeff Zhong
// Date： 10/15/2024

#include <8052.h>
#include "m6389.h"

//  Declared a two-dimensional array.
unsigned char array[10][4];
	
void main() {
    unsigned int i;
    int j;
    // Initialize the display
    init_display();
    array[0][0] = 0xC0; array[0][1] = 0x80; array[0][2] = 0xC0; array[0][3] = 0x80;  // Number 0.
    array[1][0] = 0x40; array[1][1] = 0x00; array[1][2] = 0x40; array[1][3] = 0x00;  // Number 1.
    array[2][0] = 0xC0; array[2][1] = 0x40; array[2][2] = 0x80; array[2][3] = 0x80;  // Number 2.
    array[3][0] = 0xC0; array[3][1] = 0x40; array[3][2] = 0x40; array[3][3] = 0x80;  // Number 3.
    array[4][0] = 0x40; array[4][1] = 0xC0; array[4][2] = 0x40; array[4][3] = 0x00;  // Number 4.
    array[5][0] = 0x80; array[5][1] = 0xC0; array[5][2] = 0x40; array[5][3] = 0x80;  // Number 5.
    array[6][0] = 0x80; array[6][1] = 0xC0; array[6][2] = 0xC0; array[6][3] = 0x80;  // Number 6.
    array[7][0] = 0xC0; array[7][1] = 0x00; array[7][2] = 0x40; array[7][3] = 0x00;  // Number 7.
    array[8][0] = 0xC0; array[8][1] = 0xC0; array[8][2] = 0xC0; array[8][3] = 0x80;  // Number 8.
    array[9][0] = 0xC0; array[9][1] = 0xC0; array[9][2] = 0x40; array[9][3] = 0xC0;  // Number 9.

    // Iterate to go through each command to turn on the desired segment.
    // Since the first five digits are labeled by a reverse order, so the whole loop will be divided in two sub-loop.
    for (i = 0; i < 10; i++) {
        if (i < 5) {
	    for (j = 3; j >= 0; j--) {
		display_number((i*4)+(3-j), array[i][j]);
		}
	} else {
	    for (j = 0; j < 4; j++) {
		display_number(i*4+j, array[i][j]);
	    }
	}
    }
    while (1);
    delay_ms(1000);
}
