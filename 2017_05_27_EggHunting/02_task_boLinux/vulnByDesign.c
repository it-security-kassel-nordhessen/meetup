#include <stdio.h>
#include <string.h>

int countInputLength(char *input){	
	char buffer[50];
	strcpy(buffer, input);
	int len = strlen(buffer);
	return len;
}

int main(int argCount, char *args[]){
	if(argCount < 2){
		return 0;
	}

	char input[200];
	strncpy(input, args[1], 200);

	int len = countInputLength(input);
	printf("Your input is %d characters long!\n", len);
	return 0;
}