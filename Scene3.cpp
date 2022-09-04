/***************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene3 class definitions. Scene3
				represents the lake space. This class contains a 
				constructor that creates the space, a nextMove function
				that prompts the user to select neighboring spaces to
				travel next, and a placeUFO function that places the UFO 
				into this specific scene at a random loction, and a
				getType function that returns the type of space this is.

				Used www.asciiart.eu/nature/sunset images for reference
				in creating image file for the lake scene.
***************************************************************************/

#include "Scene3.hpp"


/* Constructor sets the name, dimensions, and creates the space.
 * It opens the image file to initialize the scene*/

Scene3::Scene3()
{
	setName("Lake");
	setRow(18);
	setCol(70);
	createSpace();

	ifstream xFile;
	xFile.open("lake.txt");
	setScene(xFile);
	xFile.close();

}

/* The nextMove function displays a menu to the user to select the
 * next adjacent location to move to. It takes in a pointer to a 
 * Space as a parameter and uses this pointer to set the next
 * location. To pointer accesses the get methods from the parent 
 * class to retrieve the next location, and then returns to the
 * Game class with the new current location.*/

Space* Scene3::nextMove(Space *next)
{
	int choice;

	cout << "\nWhich direction do you want to go next?\n" << endl;
	cout << "1. East (back to campground)" << endl;
	cout << "2. Southeast (shortcut to deep forest)" << endl;
	cout << "3. Northeast (shortcut to waterfall)" << endl;
	
	choice = validate3();

	if (choice == 1)
	{
		next = next->getRight();
		return next;
	}

	if (choice == 2)
	{
		next = next->getBottom();
		return next;
	}

	if (choice == 3)
	{
		next = next->getTop();
		return next;
	}
}


// This function returns the number 3 to represent Scene3
int Scene3::getType()
{
	return 3;
}


/* The placeUFO function randomly generates a random location on the
 * 2D array that holds the scene. The "part1" and "part2" variable 
 * values (which represent the UFO spaceship) are added to the scene.*/

void Scene3::placeUFO()
{

	int r1 = rand() % 3 + 1;
	int c1 = rand() % 65;
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


