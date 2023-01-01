# Float2String

Very simple and ligthweight function to convert a floating point variable to a char string, in order to replace the traditional "%f" format specifier, avoiding the huge memory consumption when this floating support mode is enabled.

I use this function on a STM32 IoT project (C language), which sends several sensors information to the MQTT broker. Floating values must be converted to a string during the data buffer preparation.

Examples:

Floating point: 12.345678 
 2 decimal points output string: 12.35 --> 5 bytes string + the null character '\0' --> 6 bytes
 1 decimal point output string: 12.3 --> 4 bytes string + the null character '\0' --> 5 bytes

Floating point: -12.345678 
 2 decimal points output string: -12.35 --> 6 bytes string + the null character '\0' --> 7 bytes
 1 decimal point output string: -12.3 --> 5 bytes string + the null character '\0' --> 6 bytes

Floating point: 0.00045 (or -0.00045) 
 2 decimal points output string: 0 --> 1 byte string + the null character '\0' --> 2 bytes
 1 decimal point output string: 0 --> 1 byte string + the null character '\0' --> 2 bytes

Buffer size must be dimensioned according to the expected range of digits. In the code 10 bytes size is reserved, fitting my original needs.
The second parameter of the function snprintf can follow the buffer size.
