#pragma once

//!  Calculates average index of coincidence for a given key length  
/*!
 * formula: sum_i=A_to_i=Z(fi*(fi-1)) / N * (N-1),
 * where  
 * fi = count of letters (A,B,C...)
 * N  = total number of letters in the ciphertext.
 *
  \param keysize key size to check.
  \param cipher cipher to analyse.
*/
double calcAvgIdxOfCoInc(int keysize, char * cipher);

