/**************************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: The main function calls the menu function to prompt the user
				to begin or exit the game. If the menu function returns true,
				create game object and run continuously until user decides
				to exit the game. 
**************************************************************************************/

#include <cstdlib>
#include <ctime>
#include "menu.hpp"
#include "Game.hpp"


int main()
{
	bool play;
	unsigned seed = time(0);
	srand(seed);

	// Call menu
	play = menu();
	
	// If user decides to play, create and start game	
	while (play)
	{
		Game game;
		game.run();
		play = menu();
	}
	
	return 0;
}
