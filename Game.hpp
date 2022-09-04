/*******************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Game class declarations.
*******************************************************************/

#ifndef	GAME_HPP
#define GAME_HPP
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Space.hpp"
#include "Scene1.hpp"
#include "Scene2.hpp"
#include "Scene3.hpp"
#include "Scene4.hpp"
#include "Scene5.hpp"
#include "Scene6.hpp"
#include "Queue.hpp"
#include "validate1.hpp"
#include "validate2.hpp"
#include "displayImage.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

class Game
{
	private:
		Space *campground;	// Pointers to spaces
		Space *forest;
		Space *trail;
		Space *waterfall;
		Space *summit; 
		Space *lake;
		Space *prev;
		Space *current;
		Queue backpack;		// Queue object
		Queue *inventory;	
		int choice;
		int battery;		// Game counter

	public:
		Game();
		void setup();
		void intro();
		void link();
		void run();
		void clear();
		void getEnter();
		void displayInfo();
		bool checkWin();
		bool checkLose();
		void resetScene();
		bool ufoChance();
		bool takePhoto();
		void hikingEvent();
		void bearAttack();
		void alienAttack();
		~Game();
};

#endif
