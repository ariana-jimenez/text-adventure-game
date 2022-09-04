/*****************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Game class definitions. This class
				is responsible for implementing the entire game. It 
				creates, initializes, and links Space objecs. The run 
				function calls upon various Game, Space, and Queue class
				methods to run the game.
*****************************************************************************/

#include "Game.hpp"

/* Default constructor assigns the address of the Queue object to
 * the inventory pointer, initializes the battery (game time limit),
 * and calls the setup function to create the locations.*/

Game::Game()
{
	inventory = &backpack;
	battery = 100;
	setup();
}

// The setup function creates the locations of the game 
void Game::setup()
{
	campground = new Scene1();
	waterfall = new Scene2();
	lake = new Scene3();
	forest = new Scene4();
	trail = new Scene5();
	summit = new Scene6();
	current = nullptr;
	prev = nullptr;
}


// The intro function displays the starting location of the game
void Game::intro()
{
	clear();

	current = campground;
	link();
	displayInfo();
	current->display();
	
	current = current->nextMove(current);
	link();
	battery--;
}


// The link function links the spaces together
void Game::link()
{
	int type = 0;
	type = current->getType();

	if (type == 1)
	{
		current->setTop(waterfall);
		current->setBottom(forest);
		current->setLeft(lake);
		current->setRight(summit);
	}

	if (type == 2)
	{
		current->setTop(NULL);
		current->setBottom(campground);
		current->setLeft(lake);
		current->setRight(summit);
	}

	if (type == 3)
	{
		current->setTop(waterfall);
		current->setBottom(forest);
		current->setLeft(NULL);
		current->setRight(campground);
	}

	if (type == 4)
	{
		current->setTop(campground);
		current->setBottom(NULL);
		current->setLeft(lake);
		current->setRight(summit);
	}

	if (type == 6)
	{
		current->setTop(waterfall);
		current->setBottom(forest);
		current->setLeft(campground);
		current->setRight(NULL);
	}
}


// The run function runs various prompts for user to select
// which locations to go to and interaction for each location
void Game::run()
{	
	intro();

	while (battery > 0)
	{
		int chance;

		if (checkLose())
		{
			return;
		}

		// If current location is not at campground
		if (current->getType() != 1)
		{
			// If UFO is in scene
			if (ufoChance())
			{
				current->placeUFO();
				clear();
				displayInfo();
				current->display();
				cout << "\nThere it is! Up above! " << endl;
				
				do
				{
					chance = rand() % 2 + 1;

					// If bad photo is taken, try again
					if (!takePhoto())
					{
						// If UFO remains in the area, take picture
						if (chance == 1)
						{	
							resetScene();
							current->placeUFO();
							displayInfo();
							current->display();
							cout << "\nPicture is too blurry... Try again." << endl;
						}

						else
						{
							if (checkLose())
							{
								return;
							}
							resetScene();
							displayInfo();
							current->display();
							cout << "\nThe UFO has left the area..." << endl;
							prev = current;
							current = current->nextMove(current);
							link();
							hikingEvent();
						}
					}
					
					// If good photo was taken, move to another location
					else 
					{
						if (checkLose())
						{
							return;
						}

						chance = 0;	
						resetScene();
						cout << "\nPicture successfully taken!\n" << endl;
						displayInfo();
						

						// If goal has been achieved, return to main
						if (checkWin())
						{
							return;
						}

						prev = current;
						current = current->nextMove(current);
						link();
						hikingEvent();
					}
					
				} while (chance == 1);
			}

			// Prompt user to chose another location if there's no UFO activity
			else
			{
				if (checkLose())
				{
					return;
				}

				clear();
				displayInfo();
				current->display();
				cout << "\nIt appears there's no activity here...";
				cout << "Try another location. " << endl;
				prev = current;
				current = current->nextMove(current);
				link();
				hikingEvent();
			}
		}

		// If at campground, choose next location
		else
		{
			battery -= 5;;
			
			if (checkLose())
			{
				return;
			}
			
			clear();
			displayInfo();
			current->display();
			current = current->nextMove(current);
			link();
			battery--;

			if (checkLose())
			{
				return;
			}
		}
	}
}


// The clear function sets a blank screen for the next display
void Game::clear()
{
	for (int x = 0; x < 100; x++)
	{
		cout << "\n";
	}
}


//The getEnter function prompts the user to hit enter before moving on
void Game::getEnter()
{
	cout << "\nPress enter to continue: " << endl;
	cin.clear();
	cin.get();
	cin.clear();
}

// This function displays the player's battery level,
// inventory contents, and current location.
void Game::displayInfo()
{
	cout << "Battery: " << battery << "%" << endl;
	cout << "Inventory: ";
	inventory->printQueue();
	cout << "Current Location: " << current->getName() << endl;	
}


/* The checkWin function checks the inventory for the 5 photos.
 * If there are 5 photos, it returns true. Otherwise it returns false */
bool Game::checkWin()
{
	if (inventory->getSize() == 5)
	{
		getEnter();
		clear();

		// Display alien image
		ifstream file;
		file.open("end.txt");
		displayImage(file, 4);
		file.close();

		cout << "Congratulations! You have obtained proof of " << endl;
		cout << "the existence of extraterrestrials. Like agent " << endl;
		cout << "Fox Mulder once said: The truth is out there...\n" << endl;
		getEnter();
		
		return true;
	}

	else
	{
		return false;
	}
}


/* The checkLose function checks if the battery level has reached 0.
 * If it has, the function returns true. Otherwise it returns false. */
bool Game::checkLose()
{
	if (battery <= 0)
	{
		clear();
		cout << "Battery: " << battery << "%" << endl;
		cout << "\nYour battery has run out! Game over." << endl;
		getEnter();

		return true;
	}

	else
	{
		return false;
	}
}


/* The resetScene function deletes and dynamically creates the current
 * location for purposes of showing the UFO movement.*/

void Game::resetScene()
{
	int type = current->getType();

	if (type == 2)
	{
		delete waterfall;
		waterfall = new Scene2();
		current = waterfall;
	}

	else if (type == 3)
	{
		delete lake;
		lake = new Scene3();
		current = lake;
	}

	else if (type == 4)
	{
		delete forest;
		forest = new Scene4();
		current = forest;
	}

	else if (type == 5)
	{
		delete trail;
		trail = new Scene5();
		current = trail;
	}

	else if (type == 6)
	{
		delete summit;
		summit = new Scene6();
		current = summit;
	}

	// Relink the spaces & clear the screen
	link();
	clear();
}


// Generate random chance of UFO appearing in location
bool Game::ufoChance()
{
	int num = rand() % 2 + 1;

	if (num == 1)
		return true;

	else
		return false;
}


/* The takePhoto function simulates taking a photo of the UFO. It
 * randomly generates a chance of taking a good or bad photo. If
 * a good photo is taken, the photo gets added to the inventory.*/

bool Game::takePhoto()
{
	char input;
	int num;
	int type = current->getType();

	cout << "Enter 'C' to take a picture. ";
	input = validate1();
	battery--;

	num = rand() % 100 + 1;

	// If num is greater than 50, bad photo was taken
	if (num > 50)
	{
		return false;
	}

	// Otherwise, good photo was taken. Add photo to inventory.
	else
	{
		if (type == 2)
		{	
			inventory->addItem("Waterfall");
		}
		
		if (type == 3)
		{	
			inventory->addItem("Lake");
		}

		if (type == 4)
		{	
			inventory->addItem("Forest");
		}

		if (type == 6)
		{	
			inventory->addItem("Summit");
		}
		
		return true;
	}
}


/* The hikingEvent function occurs when the player has 
 * selected to travel to a new location via shortcut. It
 * displays the hiking trail space and calls the bearAttack
 * function to simulate a bear attack event.*/

void Game::hikingEvent()
{
	// If current or previous location was not the campground
	if (prev->getType() != 1 && current->getType() != 1) 
	{
		// Get current type
		int type = current->getType();

		// If new location is one of below that can only
		// be reached by shortcut. 
		if (type == 2 || type == 3 || type == 4 || type == 6)
		{
			clear();
			cout << "Battery: " << battery << "%" << endl;
			cout << "Inventory: ";
			inventory->printQueue();
			cout << "Current Location: " << trail->getName() << " to the ";
			cout << current->getName() << endl;
			trail->display();
		}

		// Generate chance of bear attack or alien abduction
		int random = rand() % 2 + 1;
		
		if (random == 1)
		{
			bearAttack();
		}

		else
		{
			alienAttack();
		}
	}
}	


/* The bearAttack function randomly generates a chance of a 
 * bear attack. If chance occurs for a bear attack, prompt
 * user to either fight or run away. If fight is chosen,
 * two random rolls occur to simulate the fight. If the 
 * player rolls higher than the bear, the player lives and
 * continues to next location. If player loses roll, the 
 * game is over.*/

void Game::bearAttack()
{		
	int random = rand() % 2 + 1;

	// If random is 1, prompt user to fight or run
	if (random == 1)
	{
		cout << "\nOh no a bear attack! What do you want to do?" << endl;
		cout << "1. Fight" << endl;
		cout << "2. Run back to camp" << endl;
		choice = validate2();
		
		// If fight is chosen, fight the bear
		if (choice == 1)
		{
			int playerRoll = rand() % 100 + 1;
			int bearRoll = rand() % 100 + 1;

			// If player's roll is greater than bear's roll, continue
			if (playerRoll >= bearRoll)
			{
				cout << "You survived and the bear backed away.." << endl;
				getEnter();
			}

			// Lose
			else
			{
				battery = 0;
				clear();

				ifstream file;
				file.open("bear.txt");
				displayImage(file, 2);	
				file.close();

				cout << "You were mauled to death by the bear. Game over." << endl;
				getEnter();
			}
		}

		// If run away is chosen, return to campground
		else
		{
			// Set current location back to camp
			current = campground;
			link();
		}
	}

	// If random is not 1, nothing happens, continue to new location
	else
	{
		cout << "\nYou encounter a bear, but he ignores you.." << endl;
		getEnter();
	}
}


/* The alienAttack function randomly generates a chance of an 
 * alien abduction. User is prompted to either approach the 
 * light or run away. If user selects to approach the light,
 * two random rolls occur to simulate a fight. If the 
 * player rolls higher than the alien, the player lives and
 * continues to next location. If player loses roll, the player
 * gets abducted and game is over.*/

void Game::alienAttack()
{		
	cout << "\nThere's a strange light up ahead... What do you want to do?" << endl;
	cout << "1. Approach the light" << endl;
	cout << "2. Run back to camp" << endl;
	choice = validate2();
		
	// If approach is chosen, generate chance of alien abduction
	if (choice == 1)
	{
		int playerRoll = rand() % 100 + 1;
		int alienRoll = rand() % 100 + 1;

		// If player's roll is greater than alien's roll, continue
		if (playerRoll >= alienRoll)
		{
			cout << "\nThe light mysteriously vanished..." << endl;
			getEnter();
		}
		
		// Else, lose to abduction
		else
		{
			battery = 0;
			clear();

			ifstream file;
			file.open("aliens.txt");
			displayImage(file, 3);	
			file.close();

			cout << "You were abducted by aliens. Game over." << endl;
			getEnter();
		}
	}

	// If run away is chosen, return to campground
	else
	{
		// Set current location back to camp
		current = campground;
		link();
	}
}


// Destructor deallocates memory
Game::~Game()
{
	delete waterfall;
	delete campground;
	delete lake;
	delete forest;
	delete trail;
	delete summit;

	waterfall = nullptr;
	campground = nullptr;
	lake = nullptr;
	forest = nullptr;
	trail = nullptr;
	summit = nullptr;
	inventory = nullptr;
	prev = nullptr;
	current = nullptr;
}
