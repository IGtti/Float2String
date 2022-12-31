# Float2String
Function to convert a float variable to a char string, in order to replace the traditional "%f" format specifier, avoiding the huge memory consumption when this floating support mode is enabled.

I use this function on a STM32 IoT project (C language), which sends several sensors information to the MQTT broker. Floating values must be converted to a string during the data buffer preparation.
