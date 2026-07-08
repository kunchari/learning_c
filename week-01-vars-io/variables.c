#include <stdio.h>
#include <limits.h>

 /*
 * Variables may have different names but are supposed to start from :
 * 1. letter
 * 2. underscore
 * and followed to letters, underscores and digits.
 * Specific names known to the compiler won't go as well (ex.int).
 * Different writing - different name (ex. Sum, sum, SUM)
 * */
 
 // Let's go through int, floor, double, _Bool and char
 
int main(int argc, char * argv[]) {
	 
	 int number;
	// ^ int is an integer, signed number of 4 bytes. 
	// So 32 bits of 2 making 2^32 different combinations (from - 2^31), 
	// where the first bit defines a sign.
		
	int number_1 = 0;
	int number_2 = -1000000000;
	int number_3 = INT_MAX;
	int number_4 = INT_MAX + 1; 
	// ^ integer overflow error.

	
	printf("Here is a declared but undefined variable: %d\n", number);
	printf("Number 1: %d\nNumber 2: %d\n", number_1, number_2);
	printf("Number 3: %d <- the biggest possible storred int\n", number_3);
	printf("Integer overflow [Not enough space :( ] %d\n", number_4);
	
	return 0;
	}

