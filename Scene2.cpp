/**************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene2 class definitions. Scene2
				represents the waterfall  space. This class contains a 
				constructor that creates the space, a nextMove function
				that prompts the user to select neighboring spaces to
				travel next, and a placeUFO function that places the UFO 
				into this specific scene at a random location, and a 
				getType function that returns the type of space this is.

				Image for the waterfall used with permission from
				www.asciiart.eu/nature/waterfall.
***************************************************************************/

#include "Scene2.hpp"

/* Constructor sets the name, dimensions, and creates the space.
 * It opens the image file to initialize the scene*/

Scene2::Scene2()
{
	setName("Waterfall");
	setRow(20);
	setCol(67);
	createSpace();

	ifstream xFile;
	xFile.open("waterfall.txt");
	setScene(xFile);
	xFile.close();
}


/* The nextMove function displays a menu to the user to select the
 * next adjacent location to move to. It takes in a pointer to a 
 * Space as a parameter and uses this pointer to set the next
 * location. To pointer accesses the get methods from the parent 
 * class to retrieve the next location, and then returns to the
 * Game class with the new current location.*/

Space* Scene2::nextMove(Space *next)
{
	int choice;

	cout << "\nWhich direction do you want to go next?\n" << endl;
	cout << "1. South (back to campground)" << endl;
	cout << "2. Southeast (shortcut to summit)" << endl;
	cout << "3. Southwest (shortcut to lake)" << endl;

	choice = validate3();

	if (choice == 1)
	{
		next = next->getBottom();
		return next;
	}

	if (choice == 2)
	{
		next = next->getRight();
		return next;
	}

	if (choice == 3)
	{
		next = next->getLeft();
		return next;
	}
}


// This function returns the number 2 to represent Scene2
int Scene2::getType()
{
	return 2;
}


/* The placeUFO function randomly generates a random location on the
 * 2D array that holds the scene. The "part1" and "part2" variable 
 * values (which represent the UFO spaceship) are added to the scene.*/

void Scene2::placeUFO()
{
	int r1 = rand() % 4;
	int c1 = rand() % 62;
	int r2 = r1;
	int c2 = c1;

	for (int x = 0; x < 4; x++)
	{
		scene[r1][c1 - 1] = part1[x];
		c1++;
	}

	++r2;
		
	for (int x = 0; x < 5; x++)
	{
		scene[r2][c2++] = part2[x];
	}
}

