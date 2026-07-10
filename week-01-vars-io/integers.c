#include <stdio.h>
#include <limits.h>
#include <math.h>

 /*
 * Variables may have different names but are supposed to start from either:
 * 1. letter
 * 2. underscore
 * and followed by letters, underscores and digits.
 * Specific names known to the compiler won't go as well (ex.int).
 * Different writing - different name (ex. Sum, sum, SUM)
 */
 
 // Let's go through int, short, long, long long, unsigned and char
 
#define EPSILON 1e-5
 
int main(int argc, char * argv[]) {
	
	/*INT*/
	printf("Integer [int]: \n");
	 
	// declared but not uninitialized int, consists random trash from memory
	
	int number;
	// ^ int is an integer, signed number of 4 bytes in memory. 
	// So 32 bits of 0 or 1 make 2^32 different combinations (from -2^31), 
	// where the first bit defines a sign.
	
	// Now it's initialized!
	number = 37;
		
	int number_1 = 0;
	int number_2 = -1000000000;
	
	// Twice declarized!
	int number_3, number_4;
	// Twice initialized!
	number_3 = number_4 = INT_MAX;
	
	number_4 = number_4 + 1;
	// ^ integer overflow error.
	// Could be written as "number_4 += 1;"

	printf("Number 1: %d\nNumber 2: %d\n", number_1, number_2);
	printf("Number 3: %d <- the biggest possible storred int\n", number_3);
	printf("Integer overflow: %d\n", number_4);
	
	
	/*SHORT*/
	printf("\nShort integer [short]: \n");

	
	short small_num = 42;
	// ^ short also known as short int or signed short int, stores data in 2B
	// Therefore 2^16 different numbers could be stored from -2^15 up to 2^15 (-1)
	// Works the same as int
	
	short small_overflow = SHRT_MAX + 1;
	// ^ the same overflow problem!
	
	short invalid_sum = 32760 + 20;
	// ^ the result of the sum is bigger than possible number
	
	printf("Short int: %hd\n", small_num);
	printf("Short overflow: (expected 32767): %hd\n", small_overflow);
	printf("Big sum of 2 possitive: %hd\n", invalid_sum);
	// ^ while %d or %i is absolutely working, there is a %hd - half decimal (2B)
	
	/*LONG*/
	
	long bigger_num = 100000000000;
	
	return 0;
}

