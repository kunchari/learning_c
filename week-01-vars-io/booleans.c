#include <stdio.h>
#include <stdbool.h>

 // Let's go through _Bool
 
int main(int argc, char * argv[]) {

	bool is_true = true;
	//^ this is bool, bool only indicates as true or false (1/0)
	// It requires 1B of memory but only uses 1b

	bool is_false = false;
	// It has only two options

	if (is_true == 1) {
		printf("True as 1!\n");
	}
	if (is_true == (bool)0.1) {
		printf("True as 0.1!\n");
	}
	if (is_false == (bool)0) {
		printf("False only as 0!\n");
	}

	// ^ (bool)0.1 is a cast, it converts the number to the boolean type.
	// All numbers except 0 are considered true, 0 is always false
	// The process only checks if the number is 0

	_Bool old_bool = 1;
	// ^ this is old bool, native to C. It only stores 0 or 1.

	if ((!is_false == is_true) == old_bool) {
		printf("It's true! Not false equals true\n");
	}


	return 0;
}



