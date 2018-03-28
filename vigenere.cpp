/*******************************************
* Michael Mahan for CSC442-003 spring 2018 *
* Vignère Cypher						   *
*******************************************/
#include <iostream>
#include <math.h>
#include <string.h>
#include <locale>

using namespace std;

void encrypt(string); //message. key
void decrypt(string); //message. key
string sanitize(string);

void encrypt(string key)
{
	int i = 0;
	cout << "key is: " << key <<'\n';
	string cleanKey = sanitize(key);
	cout << "encrypting input\n";
	while(cin.peek() != EOF) //loop until input is finished
	{
		//decryption
		// in = cin.get() //the next char inputted,
		int dIn = int(cin.get()); //in convert to integer for quick comparison
		if(dIn < 65 || (dIn > 90 && dIn < 97) || dIn > 122) //if true, dIn is a nonletter
		{
			if(dIn != 10)
			{
				cout << (char)dIn;
			}
			else //reset key loop if newline
			{
				i = 0;
				cout << "\n";
			}
		}
		else
		{
			if(isupper(dIn))
			{
				cout << (char)((((dIn - 65) + abs((int)cleanKey[i] - 65) + 26)%26) + 65);
			}
			else
			{
				cout << (char)((((dIn - 97) + abs((int)cleanKey[i] - 65) + 26)%26) + 97);
			}

			if(i < cleanKey.length()-1) //go to next key index
			{
				i++;
			}
			else //reset key index after end is reached
			{
				i = 0;
			}
		}
	}
	cout << "\n\n";
}

void decrypt(string key)
{
	int i = 0;
	cout << "key is: " << key <<'\n';
	string cleanKey = sanitize(key);
	cout << "decrypting input\n";
	while(cin.peek() != EOF) //loop until input is finished
	{
		//decryption
		// in = cin.get() //the next char inputted,
		int dIn = int(cin.get()); //in convert to integer for quick comparison
		if(dIn < 65 || (dIn > 90 && dIn < 97) || dIn > 122) //if true, dIn is a nonletter
		{
			if(dIn != 10)
			{
				cout << (char)dIn;
			}
			else //reset key loop if newline
			{
				i = 0;
				cout << '\n';
			}
		}
		else
		{
			if(isupper(dIn))
			{
				cout << (char)((((dIn - 65) - abs(((int)cleanKey[i]) - 65) + 26)%26) + 65);
			}
			else
			{
				cout << (char)((((dIn - 97) - abs(((int)cleanKey[i]) - 65) + 26)%26) + 97);
			}

			if(i < cleanKey.length()-1) //go to next key index
			{
				i++;
			}
			else //reset key index after end is reached
			{
				i = 0;
			}
		}
	}
}

string sanitize(string input)
{
	input.erase(remove(input.begin(), input.end(), ' '), input.end()); //removes whitespace, found at https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
	for(int i = 0; i < input.length(); i++)
	{
		input[i] = toupper(input[i]);
	}
	return input;
}

int main(int argc, char** argv)
{	if(!argv[1])
	{
		return 0;
	}
	else if(!strncmp(argv[1],"-e", 2))	//encryption token
	{
		encrypt(argv[2]);
	}
	else if(!strncmp(argv[1],"-d", 2))	//decryption token
	{
		decrypt(argv[2]);
	}
	else
	{
		cout << "incorrect arguments supplied\n";
	}
	return 0;
}