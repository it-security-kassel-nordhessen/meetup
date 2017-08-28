// gcc demo.c -o demo -m32 -fno-stack-protector
// ./demo abcdefg
// ./demo abcdefghi
// ./demo abcdefghijklmnopqrs
#include <stdio.h>
#include <string.h>

// printf -> %p print as address
// printf -> %s print as string

int main(int argc, char *argv[]) {
	int value = 5;
	char buffer_a[8];
	char buffer_b[8];

	strcpy(buffer_a, "one"); 
	strcpy(buffer_b, "two"); 
	printf("[BEFORE] buffer_b is at %p and contains \'%s\'\n", buffer_b, buffer_b);
	printf("[BEFORE] buffer_a is at %p and contains \'%s\'\n", buffer_a, buffer_a);
	printf("[BEFORE] value is at %p and is %d (0x%08x)\n", &value, value, value);

	printf("\n[STRCPY] copying argv[1] with %d bytes into buffer_b\n\n", strlen(argv[1]));
	strcpy(buffer_b, argv[1]); /* Copy first argument into buffer_b. */

	printf("[AFTER] buffer_b is at %p and contains \'%s\'\n", buffer_b, buffer_b);
	printf("[AFTER] buffer_a is at %p and contains \'%s\'\n", buffer_a, buffer_a);
	printf("[AFTER] value is at %p and is %d (0x%08x)\n", &value, value, value);
	return 0;
}