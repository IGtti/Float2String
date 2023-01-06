# Float2String

Simple and ligthweight function to convert a floating point variable to a char array, in order to replace the traditional "%f" format specifier, avoiding the huge memory consumption when this floating support mode is enabled.

I use this function on a STM32 IoT project (C language), which sends several sensors information to the MQTT broker. Floating values must be converted to a string during the data buffer preparation.

Two files available, select according to your need:<br/>
float2string 1dp.c --> 1 decimal point<br/>
float2string 2dp.c --> 2 decimal points

In the Main function:

char c_Temperature[FLOATSTRINGSIZE];    // defining the buffer to receive the converted data<br/>
float f_Temp;                           // defining the float variable

f_Temp = 12.345678;

Float2String(f_Temp, c_Temperature);    // Convert float to string

Examples:

Floating point: 12.345678<br/>
 2 decimal points output string: 12.35 --> 5 bytes string + the null character '\0' --> 6 bytes<br/>
 1 decimal point output string: 12.3 --> 4 bytes string + the null character '\0' --> 5 bytes

Floating point: -12.345678<br/>
 2 decimal points output string: -12.35 --> 6 bytes string + the null character '\0' --> 7 bytes<br/>
 1 decimal point output string: -12.3 --> 5 bytes string + the null character '\0' --> 6 bytes

Floating point: 0.00045 (or -0.00045)<br/>
 2 decimal points output string: 0 --> 1 byte string + the null character '\0' --> 2 bytes<br/>
 1 decimal point output string: 0 --> 1 byte string + the null character '\0' --> 2 bytes

Buffer size (FLOATSTRINGSIZE) must be dimensioned according to the expected range of digits. In my application 10 bytes size is reserved, fitting my original needs.<br/>
The second parameter (size) of the function "snprintf" can follow the buffer size.
