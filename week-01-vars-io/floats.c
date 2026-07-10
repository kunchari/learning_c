#include <stdio.h>
#include <limits.h>
#include <math.h>

 // Let's go through floor, double
 
#define EPSILON 1e-5
 
int main(int argc, char * argv[]) {

	/*FLOAT*/
	
	float floating;
	/* ^ float is a floating point number of 4 bytes.
	* Allows almost any possible real number representation
	* 32 bits are divided into - Sign(1b), Exponent(8b), Mantissa(23b)
	* Sign - 0 or 1 definies if positive or negative
	* Exponent - power of 2. Uses bias 127. So if 130 is stored, then 130 - 127 = 3 (2^3) 
	* Mantissa - the number (then moved by exponent on N possitions (1st - 1))
	*/
	
	float floating_1 = 42;
	float floating_2 = -3.141592;
	float floating_min = LONG_MIN;
	float floating_max = LONG_MAX;
	float floating_3 = 0.111111111111111111111111111;
	// ^float decimal error (not enough space to save the "tail")
	// Can get values NaN and Inf, though are mostly not allowed (showed as errors)
	
	printf("Uninitialized float: %f\n", floating);
	printf("Normal possible values: \n1. Possitive: %f\n2. Negative: %.10f\n3. Max value: %f\n4. Min value %f\n", 
			floating_1, floating_2, floating_max, floating_min);
	printf("Not enough space: %.15f\n", floating_3);
	
	// Need to mention that %f is used for float and double (shows about 6 numbers after .)
	// To show more - %.Nf where N - needed ammount
	// %e prints the number in scientific way (ex. 1.500000e+08)
	
	
	// IMPORTANT! Due to that possible decimal error, we shouldn't compare them directly.
	
	float a = 0.1;
	float b = 0.2;
	
	printf("\nTrying to compare directly: \n");
	
	if (a + b == 0.3) {
		printf("Good!\n");	
	} else {
		printf("Nope: %.10f\n", a + b);
	}
	
	// How to compare? Using a very small number (epsilon defined globaly)
	
	printf("\nTrying to compare using epsilon: \n");
	
	if (fabs((a + b)) - 0.3 < EPSILON ) {
		printf("Good!\n");
	} else {
		printf("Nope!\n");
	}
	
	return 0;
	}


