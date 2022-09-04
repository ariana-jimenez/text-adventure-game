/**************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene6 class definitions. Scene6
				represents the summit space. This class contains a 
				constructor that creates the space, a nextMove function
				that prompts the user to select neighboring spaces to
				travel next, and a placeUFO function that places the UFO 
				into this specific scene at a random location, and a
				getType function that returns the type of space this is.
				
				Image for the summit used with permission from
				www.asciiart.eu/space/planets.
**************************************************************************/

#include "Scene6.hpp"


/* Constructor sets the name, dimensions, and creates the space.
 * It opens the image file to initialize the scene*/

Scene6::Scene6()
{
	setName("Summit");
	setRow(15);
	setCol(75);
	createSpace();

	ifstream xFile;
	xFile.open("summit.txt");
	setScene(xFile);
	xFile.close();
}

/* The nextMove function displays a menu to the user to select the
 * next adjacent location to move to. It takes in a pointer to a 
 * Space as a parameter and uses this pointer to set the next
 * location. To pointer accesses the get methods from the parent 
 * class to retrieve the next location, and then returns to the
 * Game class with the new current location.*/

Space* Scene6::nextMove(Space *next)
{
	int choice;

	cout << "\nWhich direction do you want to go next?\n" << endl;
	cout << "1. West (back to campground)" << endl;
	cout << "2. Northwest (shortcut to waterfall)" << endl;
	cout << "3. Southwest (shortcut to forest)" << endl;

	choice = validate3();

	if (choice == 1)
	{
		next = next->getLeft();
		return next;
	}

	if (choice == 2)
	{
		next = next->getTop();
		return next;
	}

	if (choice == 3)
	{
		next = next->getBottom();
		return next;
	}
}

// This function returns the number 6 to represent Scene6
int Scene6::getType()
{
	return 6;
}


/* The placeUFO function randomly generates a random location on the
 * 2D array that holds the scene. The "part1" and "part2" variable 
 * values (which represent the UFO spaceship) are added to the scene.*/

void Scene6::placeUFO()
{
	int r1 = rand() % 10;
	int c1 = rand() % 70;
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

