/**************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene1 class definitions. Scene1
				represents the campground space. This class contains a 
				constructor that creates the space, a nextMove function
				that prompts the user to select neighboring spaces to
				travel next, and a getType function that returns the 
				type of space this is.

				Used www.asciiart.eu/nature/camping images for reference
				in creating image file for the campground scene.
**************************************************************************/

#include "Scene1.hpp"


/* Constructor sets the name, dimensions, and creates the space.
 * It opens the image file to initialize the scene*/

Scene1::Scene1()
{
	setName("Campground");
	setRow(18);
	setCol(26);
	createSpace();

	ifstream xFile;
	xFile.open("campground.txt");
	setScene(xFile);
	xFile.close();
}


/* The nextMove function displays a menu to the user to select the
 * next adjacent location to move to. It takes in a pointer to a 
 * Space as a parameter and uses this pointer to set the next
 * location. To pointer accesses the get methods from the parent 
 * class to retrieve the next location, and then returns to the
 * Game class with the new current location.*/

Space* Scene1::nextMove(Space *next)
{
	int choice;

	cout << "\nWhich direction do you want to go next?\n" << endl;
	cout << "1. North (Waterfall)" << endl;
	cout << "2. East  (Summit)" << endl;
	cout << "3. West  (Lake)" << endl;
	cout << "4. South (Forest)" << endl;

	choice = validate4();

	if (choice == 1)
	{
		next = next->getTop();
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

	if (choice == 4)
	{
		next = next->getBottom();
		return next;
	}
}


// This function returns the number 1 to represent Scene1
int Scene1::getType()
{
	return 1;
}
