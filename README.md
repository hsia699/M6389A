# M6389A
Verify the truth table of M6389A
Using the 8051 microtroller, so need to manually write specific functions to directly simulate I2C communication which I controled the SDA and SCL lines by GPIO ports on the 8051 microcontrllers.
Remember always read the data sheet to make sure the microcontroller and the control IC of the display have a common working voltage range.
Verify the truth tablemeans turn on all the segments in a reasonabe order.
The display has two COM ports to multiplexing the display, enabling the control of multiple segments with fewer connections.
There are three files, the header file m6389.h includes all functions declarition, m6389.c is where the actual implementation of the functions declared in the m6389.h. It would include the logic to initialize and control the display using the M6389 controller. The main file apply the functions to verify the truth table.
