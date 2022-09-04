/*******************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the displayImage function definition.
				The purpose of this function is to display the title 
				of the game. It takes in a file object as a parameter
				and creates and initializes an array to store the
				contents of the file. Then the array is displayed.

				Image for "aliens.txt", and "end.txt" was used from 
				www.asciiart.eu/space/aliens and the "bear.txt" image
				was used from www.asciiart.eu/animals/bears
*******************************************************************************/

#include "displayImage.hpp"


void displayImage(ifstream& file, int img)
{
	char **title;
	char value;
	int row = 0;
	int col = 0;

	// Set row and column based on image being received
	if (img == 1)	// Title image
	{
		row = 73;
		col = 4;
	}

	else if (img == 2)	// Bear image
	{
		row = 10;
		col = 27;
	}

	else if (img == 3)	// Alien image
	{
		row = 19;
		col = 44;
	}

	else if (img == 4)	// End image
	{
		row = 9;
		col = 23;
	}

	// Dynamically create an array of chars
	title = new char*[row];
	for (int x = 0; x < row; x++)
	{
		title[x] = new char[col];
	}

	// Initialize array to white spaces
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			title[x][y] = ' ';
		}
	}

	// If file opens succesfully, read the characters into the array
	if (file)
	{
		value = file.get();
			
		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				if (file.peek() != EOF)
				{
					title[x][y] = value;
					value = file.get();
				}
			}
		}

		file.close();

		// Display image
		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				cout << title[x][y];
			}
		}

		cout << "\n\n" << endl;

	}

	// Deallocate memory
	for (int x = 0; x < row; x++)
		delete [] title[x];
	delete [] title;
}
