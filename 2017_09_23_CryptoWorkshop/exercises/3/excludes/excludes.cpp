#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

/*! 
 * \brief Calculates exclusions for enigma ciphertext.
 */
// by Matthias Altmann
int main()
{
	string cipher;
	cout << "Enter ciphertext:";
        getline(cin,cipher);
	transform(cipher.begin(), cipher.end(),cipher.begin(), ::toupper);
	
	string assumed_plaintext;
	cout << "Enter assumed plaintext:";
	getline(cin,assumed_plaintext);
	transform(assumed_plaintext.begin(), assumed_plaintext.end(), assumed_plaintext.begin(), ::toupper);
	
	// cipher text must be larger than plain text.
	if (cipher.size() < assumed_plaintext.size())
	{ 
		cout << "Ciphertext must be larger than plaintext. Exiting. " << endl;
		return 1;
	}

        cout << "\t" << cipher;
	string shift = "";
	for (int i=0;i<=(cipher.size()-assumed_plaintext.size());i++){
		string tempstr = assumed_plaintext;
		bool toDiscard = false;
		for (int j=0;j<assumed_plaintext.size();j++)
		{
		 	if (cipher[i+j]==assumed_plaintext[j])
			{
				tempstr[j]=tolower(tempstr[j]);
				toDiscard = true;
			}	
		}
		cout << endl;
		cout << ((toDiscard==true) ? "X\t" : "\t") << shift << tempstr;               shift.append(" ");
	}
	cout << endl;
	return 0;
}

