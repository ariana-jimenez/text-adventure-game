/*****************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Space class definitions. It contains
				a default constructor that sets the member variables to null.
				It contains getter and setter functions, and methods to create,
				initialize, modify, and display the spaces.
******************************************************************************/

#include "Space.hpp"

// Default constructor 
Space::Space()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;
	row = 0;
	col = 0;
	part1 = "___";
	part2 = "<ooo>";	
}


// Sets the name of the space
void Space::setName(string n)
{
	name = n;
}


// Returns name 
string Space::getName()
{
	return name;
}

// Sets the row for the array
void Space::setRow(int r)
{
	row = r;
}


// Sets the column for the array
void Space::setCol(int c)
{
	col = c;
}


// Set space to top pointer
void Space::setTop(Space *t)
{
	top = t;
}


// Set space to bottom pointer
void Space::setBottom(Space *b)
{
	bottom = b;
}


// Set space to left pointer
void Space::setLeft(Space *l)
{
	left = l;
}


// Set space to right pointer
void Space::setRight(Space *r)
{
	right = r;
}

// Getter functions for returning spaces
Space* Space::getTop()
{
	return top;
}


Space* Space::getBottom()
{
	return bottom;
}


Space* Space::getLeft()
{
	return left;
}


Space* Space::getRight()
{
	return right;
}


/* The createSpace function creates a dynamic 2D array
 * to hold the scenes for the spaces*/

void Space::createSpace()
{
	scene = new char*[row];
	for (int x = 0; x < row; x++)
	{
		scene[x] = new char[col];
	}

	// Initialize array to white spaces
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			scene[x][y] = ' ';
		}
	}
}


/*	The setScene function  takes in a file object as a parameter
	stores the contents of the file into the array.*/

void Space::setScene(ifstream& file)
{
	char value;

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
					scene[x][y] = value;
					value = file.get();
				}
			}
		}

		file.close();
	}
}


// The display function displays the array
void Space::display()
{
	for (int i = 0; i < col; i++)
	{
		cout << "_";
	}

	cout << endl;

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < col; y++)
		{
			cout << scene[x][y];
		}
	}

	cout << endl;

	for (int i = 0; i < col; i++)
	{
		cout << "_";
	}
	cout << endl;
}


Space* Space::nextMove(Space *next)
{
}


int Space::getType()
{
}

void Space::placeUFO()
{
}


// Destructor deallocates memory
Space::~Space()
{
	top = nullptr;
	bottom = nullptr;
	left = nullptr;
	right = nullptr;

	// Delete 2D array
	for (int x = 0; x < row; x++)
		delete [] scene[x];
	delete [] scene;

	scene = nullptr;
}
