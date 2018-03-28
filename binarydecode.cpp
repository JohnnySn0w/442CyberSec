/*
Binary to ASCII
Michael Mahan for CSC442-003 spring quarter 2018
*/
#include <iostream>
#include <math.h>

using namespace std;

#define BUFFER_SIZE	10000

//function declarations
void ascii7(int[], int);
void ascii8(int[], int);
void check(int[], int);
void grabInput(int[]);
void bufferSet(int[]);
	
//7 bit ascii converter
void ascii7(int buffer[], int length)
{
	int index = 0;
	
	cout << "ascii7: ";
	for(int x = 0; x < length - 1; x+=7)	//loops through each set of 7 bits
	{
		int sum = 0;

		for(int i = 6;i >= 0;i--) //loops throught the 7 bits summing them for conversion
		{
			sum += buffer[index] * pow(2, i);
			index++;
		}
		cout << char(sum); //converts the sum to ascii and prints it
	}
	cout << "\n";
}

//8 bit ascii converter
void ascii8(int buffer[], int length)
{
	int index = 0;
	
	cout << "ascii8: ";
	for(int x = 0; x < length - 1; x+=8) 	//loops through each set of 8 bits
	{
		int sum = 0;

		for(int i = 7;i >= 0;i--) //loops throught the 8 bits summing them for conversion
		{
			sum += buffer[index] * pow(2, i);
			index++;
		}
		cout << char(sum);	//converts the sum to ascii and prints it
	}
	cout << "\n";
}
//checks which ascii it is based on sum of bits, outputs both if ambiguous
//g2g
void check(int buffer[], int length)
{
	if(!((length - 1) % 8)) 	//the -1 is for the EOF
	{
		ascii8(buffer, length);
	}
	if(!((length - 1) % 7))
	{
		ascii7(buffer, length);
	}
}
//grabs from stdin
//g2g
void grabInput(int buffer[])
{
	int i;

	for(i = 0; (cin.peek() != -1) || (cin.peek() != EOF) ; i++)
	{
		buffer[i] = int(cin.get()) - 48;
	}
	int length = i;
	check(buffer, length);
}

//sets all values in buffer to -1
//g2g
void bufferSet(int buffer[])
{
	int buffer[BUFFER_SIZE];

	for(int i = 0; i <= BUFFER_SIZE; i++)
	{
		buffer[i] = -1;
	}
	grabInput(buffer);
}
//g2g
int main()
{
	bufferSet();
	return 0;
}