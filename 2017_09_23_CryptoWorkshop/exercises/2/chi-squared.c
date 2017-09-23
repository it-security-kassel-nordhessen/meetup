#include <stdio.h>
#include <ctype.h>
#include <string.h>

// by Matthias Altmann
// Calculate Chi Square
double calcChiSquare(char * strToCheck, const double * referenceLang)
{
	int j = 0;
	while (strToCheck[j] != '\0')
	{
		if (!isalpha(strToCheck[j]))
		{
			// cut the character if non-alpha
			memmove(&strToCheck[j], &strToCheck[j + 1], strlen(strToCheck) - j);
		}
		else
		{
			j++;
		}
	}
	int letter_count;
	double sum = 0;
	for (char letter='A'; letter <= 'Z'; letter++)
	{
		letter_count = 0;
		for (int i=0;i<=strlen(strToCheck);i++)
		{
			letter_count = letter_count + (toupper(strToCheck[i]) == letter);
		}			
		double expected_letter_count = referenceLang[letter-65]*strlen(strToCheck)/100;
                // printf("%c %d %f\n",letter, letter_count, expected_letter_count);
		double toSquare = letter_count - expected_letter_count;
		sum = sum + ((toSquare*toSquare)/expected_letter_count);
	}
	return sum;
}

/*! Test for chi square test.
 *
 * Has to be 18.528310082299488 against english distribution.
 *
 */
/*
int test()
{
	// char strToCheck[] = "aBbbbc";
	char strToCheck[] = "Defend the east wall of the castle";
	// char strToCheck[] = "aoljhlzhyjpwolypzvulvmaollhysplzaruvduhukzptwslzajpwolyzpapzhafwlvmzbizapabapvujpwolypudopjolhjoslaalypuaolwshpualeapzzopmalkhjlyahpuubtilyvmwshjlzkvduaolhswohila";
	printf("%s\n%f\n",strToCheck,calcChiSquare(strToCheck,letter_freq_english));
	return 0;
}*/
