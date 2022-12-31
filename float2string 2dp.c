	// Convert a floating point to a string, with 2 decimal digits
	// Receive the floating variable and the string to store result

void Float2String(float f_Variable, char *cResult)
{
                double d_IntDigits;                        // Integer digits
                double d_FraDigits;                        // Fraction digits

                d_FraDigits = modf((double)(fabs((double)f_Variable) + 0.005), &d_IntDigits);                   // Absolute and Round the value
                if((f_Variable < 0.0) && (((uint16_t)d_IntDigits != 0) || ((uint8_t)(d_FraDigits * 100.0) != 0))) {     // test for negative values and not zero                                                                                                                                                                                // test for negative numbers
                               snprintf(cResult, 10,"-%d.%02d", (uint16_t)d_IntDigits, (uint8_t)(d_FraDigits * 100.0));  // Convert float to string with 2 decimal digits, for negative values
                } else {
                    if((((uint16_t)d_IntDigits == 0) && ((uint8_t)(d_FraDigits * 100.0) == 0))) {                   // test for zero values
                        snprintf(cResult, 10,"0");                   // Convert float to string for zero values, 0 instead of 0.00
                    } else {
                        snprintf(cResult, 10,"%d.%02d", (uint16_t)d_IntDigits, (uint8_t)(d_FraDigits * 100.0));                   // Convert float to string with 2 decimal digits, for positive values
                    }
                }
}