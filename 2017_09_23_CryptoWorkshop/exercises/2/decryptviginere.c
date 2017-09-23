#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void decrypt_vigenere(char * cipherToPlain, char * key)
{
	int k = 0;
	for (int i = 0; i < strlen(cipherToPlain);i++)
	{
	   k = k % (strlen(key)-1);
	   //printf("\n %c",toupper(cipherToPlain[i]));
	   cipherToPlain[i] = (toupper(cipherToPlain[i]-'A')) - (key[k]-'A') + 26;
	   //printf(" k:%d",key[k]-'A');
           //printf(" A:%d",cipherToPlain[i]);	   
	   cipherToPlain[i] = cipherToPlain[i] % 26;
	   //printf(" B:%d",cipherToPlain[i]);
	   cipherToPlain[i] = cipherToPlain[i] + 'A';
	   //printf(" C:%c",cipherToPlain[i]);
	   k++;
	}
}

int main()
{
	char cipher[65535];
	char key[65535];
	printf("Enter cipher:");
	fgets(cipher,sizeof(cipher),stdin);
	strtok(cipher,"\n");
	printf("Enter key:");
	fgets(key,sizeof(key),stdin);

	char *plaintext;
        plaintext = strdup(cipher);
        decrypt_vigenere(plaintext,key);
	printf("\n%s",plaintext);
	free(plaintext);
	return 0;
}
