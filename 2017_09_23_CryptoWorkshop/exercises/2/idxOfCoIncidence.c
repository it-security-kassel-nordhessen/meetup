#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//! Calculate index of coincidence.
/*!
 Calculate index of coincidence for a specific char array 
*/
// by Matthias Altmann
double calcIdxOfCoInc(char * str)
{
        int i,count;
        int sum=0;
        for (int letter='A';letter<='Z';letter++)
        {
                for (i=0, count=0; str[i];i++)
                {
                        count = count + (toupper(str[i]) == letter);
                }
                // calculate upper index of coincidence
                sum = sum + count * (count - 1);
        }
        int sizeofStr = strlen(str);
        return (sizeofStr<=1) ? 0.0 : sum/(double)((sizeofStr)*(sizeofStr-1));
}

double calcAvgIdxOfCoInc(int keysize, char * cipher)
{
        double sum = 0.0;
        // generate textes jumping keysize, offset 1..keysize
        char * tempcipher = (char*) malloc(strlen(cipher) * sizeof(char));
        for (int i = 1; i <= keysize; i++)
        {
                int k = 0; // counter for array to create new text jumping keysize
                for (int j=i-1;j<strlen(cipher);j=j+keysize)
                {
                        tempcipher[k]=cipher[j];
                        k++;
                }
                tempcipher[k]='\0'; // terminating character
                /* printf("\n%s",tempcipher);
                float d = calcIdxOfCoInc(tempcipher);
                printf("\n%2.13f", d);*/
                sum = sum + calcIdxOfCoInc(tempcipher);
        }
        free(tempcipher);
        return (sum / keysize);
}
