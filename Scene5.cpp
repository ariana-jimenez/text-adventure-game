/**************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene5 class definitions. Scene5
				represents the hiking trail space. This class contains a 
				constructor that creates the space, and a getType 
				function that returns the type of space this is. 
***************************************************************************/

#include "Scene5.hpp"


/* Constructor sets the name, dimensions, and creates the space.
 * It opens the image file to initialize the scene*/

Scene5::Scene5()
{
	setName("Hiking Trail");
	setRow(18);
	setCol(37);
	createSpace();

	ifstream xFile;
	xFile.open("trail.txt");
	setScene(xFile);
	xFile.close();
}


Space* Scene5::nextMove(Space *next)
{

}

// This function returns the number 5 to represent Scene5
int Scene5::getType()
{
	return 5;
}



