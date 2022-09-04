/*****************************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file is used for validating that the user enters only integers 
				1 or 2. The input is received in a string format, and then each character
				is stored in an array of characters so that each character can be 
				checked for double values, negatives, letters, and out of bound
				values. If any of these are found, the user is prompted to input
				a new value until a valid value is read. The input is then returned
				to the part of the program that called it. 
******************************************************************************************/

#include "validate2.hpp"

int validate2()
{
	int input = 0;
	string str;
	int size;
	char *readChar;		// pointer to create an array of char
	bool check = true;	// flag for loop

	while (check)
	{
		// Set flag to false to exit the while loop 
		check = false;

		// Get user input in string format
		getline(cin, str);
		stringstream ss(str);
		ss >> input;
	
		// If user type nothing and hit "Enter", set flag to true to redo the loop
		if (str.empty())
		{
			check = true;
		}

		// Obtain the number of characters in the input plus one for the newline char
		size = str.length() + 1;
		
		// Create an array of characters to store the string 
		readChar = new char[size];

		for (int x = 0; x < size; x++)
		{
			readChar[x] = str[x];
		}

		/* Read each character in array to check for decimals, letters, and 
		 * out of bounds characters. If any of these is found, set flag to true
		 * so that the while loop repeats for new input. 
		*/
		for (int x = 0; x < (size - 1); x++)
		{	
			if (readChar[x] == '.' || isalpha(readChar[x]) || !isdigit(readChar[x]))
			{
				check = true;
			}
		}

		// If input is out of bounds, set flag to true
		if (input < 1 || input > 2)
		{
			check = true;
		}
		
		// If flag has been set to true, display error message and delete the array
		if (check)
		{
			cout << "Enter either number 1 or 2: " << endl;
			delete [] readChar;
		}
	} 
	
	// If input is within bounds, return choice to main, and delete the array.
	if (input == 1 || input == 2) 
	{
		delete [] readChar;
		return input;
	}
}
