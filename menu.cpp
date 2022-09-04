/***********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the menu function definition. This
				function introduces the game to the user. It then
				prompts the user to select either (1) Play or (2) Exit.
				The function returns true if user selects (1) and false
				if the user selects (2).
**************************************************************************/

#include "menu.hpp"

bool menu()
{
	// Clear the screen
	for (int x = 0; x < 100; x++)
	{
		cout << "\n";
	}

	// Open file that contains game title & call function to display
	ifstream file;
	file.open("Title.txt");
	displayImage(file, 1);	
	file.close();

	// Game introduction
	cout << "UFO sightings have been reported at ";
	cout << "Skyland Mountain tonight. Your goal " << endl;
	cout << "is to travel through different areas ";
	cout << "of the mountain and obtain proof of " << endl;
	cout << "extraterrestrial life, by taking 5 ";
	cout << "very good photos of the UFO. If your " << endl;
	cout << "camera battery runs out, the game is ";
	cout << "over.\n" << endl;
	cout << "Your starting point is at the campground. ";
	cout << "Important tips to remember:\n" << endl;
	cout << "  - Battery life decreases by (1%) every time " << endl;
	cout << "    you take a picture or move from the " << endl;
	cout << "    campground to another location.\n" << endl;
	cout << "  - Every time you return to the campground, " << endl;
	cout << "    battery decreases by (5%)\n" << endl;
	cout << "  - Battery does not decrease when using shortcuts " << endl;
	cout << "    (hiking trails) to travel between locations.\n" << endl;
	cout << "  - Shortcuts may help save battery, but they are " << endl;
	cout << "    very dangerous. Use at your own risk...\n" << endl;
	
	cout << "\nChoose an option from below: " << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	cout << endl;

	int choice;
	choice = validate2();

	if (choice == 1)
	{
		return true;
	}

	else if (choice == 2)
	{
		return false;
	}
}
