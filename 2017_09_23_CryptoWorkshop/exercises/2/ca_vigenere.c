#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "idxOfCoIncidence.h"
#include "chi-squared.h"
#include "letter-frequency.h"

// gcc ca_vigenere.c chi-squared.c idxOfCoIncidence.c -o ca_vigenere
// Try to crack vigenere cipher
// by Matthias Altmann
int main()
{
	char cipher [65535];
	printf("Enter cipher text:");
	fgets(cipher,sizeof(cipher),stdin);
	// cut line feed
	strtok(cipher,"\n");
	
	// Calculate index of coincidence.
	double avgIdxOfCoInc;
        for (int i = 1;i<strlen(cipher);i++)
	{
                avgIdxOfCoInc = calcAvgIdxOfCoInc(i,cipher);
		if (avgIdxOfCoInc > 0.0000000001)
			printf("\nKey length:%d %2.16f",i,avgIdxOfCoInc);
	}
	printf("\n\n");

	// Calculat Chi Square for specific key length.
	char keysizeToScanStr [20];
	int keysizeToScan = 0;
	printf("Choose key length to calculate chi-square test:");
	fgets(keysizeToScanStr,sizeof(keysizeToScanStr),stdin);
	strtok(keysizeToScanStr,"\n");
        for (int l=0;l<strlen(keysizeToScanStr);l++)
	{
		if (!isdigit(keysizeToScanStr[l]))
		{
		return 0;
		}
	}
 	// convert string key size to int
	keysizeToScan = atoi(keysizeToScanStr);
	// iterate through cipher string with entered key length.
	for (int keyoffset=0;keyoffset < keysizeToScan;keyoffset++)
	{
		int stroffset=keyoffset;
		char strToCheck [65535];
		int p = 0; 
		while (stroffset < strlen(cipher))
		{
			strToCheck[p]=cipher[stroffset];
			stroffset = stroffset + keysizeToScan;
			p++;
		}
		strToCheck[p]='\0';
		printf("\n\n%s ", strToCheck);
		for (int letter=0;letter<=25;letter++)
		{
			printf("\n %d %c %s %f",letter,65+letter,strToCheck,calcChiSquare(strToCheck,letter_freq_english));
			// printf("\n %d %f",letter,strToCheck,calcChiSquare(strToCheck,letter_freq_english));
			for (int i=0;i<strlen(strToCheck);i++)
			{
				strToCheck[i]=(toupper(strToCheck[i])=='A')?'Z':(strToCheck[i]-1);
			}
		}
	}
	return 0;
}
