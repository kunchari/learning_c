#include <stdio.h>
#include <limits.h>

 /*
 * Variables may have different names but are supposed to start from either:
 * 1. letter
 * 2. underscore
 * and followed by letters, underscores and digits.
 * Specific names known to the compiler won't go as well (ex.int).
 * Different name - different variable (ex. Sum, sum, SUM)
 */
 
 // Let's go through int, short, long, long long, unsigned and char
 
int main(int argc, char * argv[]) {
	
	/*INT*/
	printf("Integer [int]: \n\n");
	 
	 
	// declared but not uninitialized int, consists random trash from memory
	
	int number;
	// ^ int is an integer, signed number of 4 bytes in memory. 
	// So 32 bits of 0 or 1 make 2^32 different combinations (from -2^31), 
	// where the first bit defines a sign.
	
	// Now it's initialized!
	number = 37;
	
	int number_2 = -1000000000;
	
	// Twice declarized!
	int number_3, number_4;
	// Twice initialized!
	number_3 = number_4 = INT_MAX;
	
	number_4 = number_4 + 1;
	// ^ integer overflow error.
	// Could be written as "number_4 += 1;"

	printf("Number 1: %d\nNumber 2: %d\n", number, number_2);
	printf("The biggest possible storred int: %d\n", number_3);
	printf("Integer overflow: %d\n", number_4);
	
	
	/*SHORT*/
	printf("\nShort integer [short]: \n\n");

	
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
	printf("Big sum of 2 possitive: (expected 32780) %hd\n", invalid_sum);
	// ^ while %d or %i is absolutely working, there is a %hd - half decimal (2B)
	
	
	/*LONG*/
	printf("\nLong integer [long]: \n\n");

	
	long bigger_num = 100000000000000;
	// ^ long is a type "in between" int and long long. 
	// Depending on the system, it may store numbers in 4B or 8B.
	// On Linux its size is 8B. That means 2^64 different numbers.
	
	long max_long = LONG_MAX;
	// Overflow also works here the same way.
	
	printf("Long int: %ld\n", bigger_num);
	printf("Biggest long int: %ld (May differ on different systems)\n", max_long);
	// ^ uses %ld as long d
	
	/*LONG LONG*/
	printf("\nLong long integer [long long]: \n\n");
	
	long long even_bigger = 1000000000000000000;
	// ^ this is the biggest possible integer type that can be stored in 8B - 2^64
	
	long long the_biggest_int = LLONG_MAX;
	
	printf("Long long int: %lld\n", even_bigger);
	printf("The biggest possible signed stored integer: %lld\n (On Linux is the same with Long)\n", the_biggest_int);
	// ^ uses %lld as long long d
	
	
	/*UNSIGNED*/
	printf("\nUnsigned integers [unsigned int/short/long/long long]: \n\n");
	
	
	// Basically unsigned number means that the first (leftmost) bit is used to store the number.
	// Signed numbers are cut in 1 bit to know if it's negative or possitive. 
	// That means, that the stored numbers are bigger (ex. int -> 0 - 2^32 -1) but only possitive.
	// The capacity is the same for all integers 
	
	unsigned int un_num = UINT_MAX;
	// ^ can be also declared as "unsigned int"
	
	unsigned short 		un_short 		=	USHRT_MAX;
	unsigned long 		un_long 		=	ULONG_MAX;
	unsigned long long 	un_long_long 	=	ULLONG_MAX;
	
	printf("This is the biggest int: %u\n", un_num);
	printf("This is the biggest short int: %hu\n", un_short);
	printf("This is the biggest long int: %lu\n", un_long);
	printf("This is the biggest long long int: %llu\n", un_long_long);
	
	printf("The smallest number is always 0!\n");

	unsigned over_num = UINT_MAX + 2;
	// ^ this won't overflow to the negative number! 
	// The overflow flag will be set and it will be back counting from 0
	
	printf("This is overflow (max + 2): %u\n", over_num);
	
	
	/*CHAR*/
	printf("\nChar: \n\n");
	
	
	char a = 'a';
	// ^ char is a small integer. Takes only a byte - 8 bits.
	// Usually represents a character but still is a number.
	// By defaults char is neither signed nor unsigned. Different systems interpret it differently.
	// This may lead to an error when checking = -1 as on ARM it never will happen.
	// Linux considers it signed. This means -128 - 127 range.
	// Even this 'a' is a number that is ASCII encoded. ('a' = 61 (hex) or 97 (dec))
	
	printf("Here is a character: %c\n", a);
	printf("Here is a character printed as a number: %d\n", a);
	
	// What's interesting, as a common number, character allows operations.
	// For example, add. Or, a funny thing, I can get a real number by substracting '0'
	
	char char_num = '6';
	char_num -= '0';
	// ^ so it works like '6' = 36 and '0' = 30 -> 36-30 = 6.
	// Or, well, the distance between those characters is the same as the between the numbers
	
	printf("Here is '6' - '0': %d\n", char_num);
	printf("Here is whatever it is in ASCII multipleid by 10: %d\n", char_num * 10);

	// Need to mention, that the character is written inside single '' not "".
	// The second option is considered a string. It automatically adds /0 to the end, making it 1B longer.
	
	return 0;
}
