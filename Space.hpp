/***********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Space class declaration. This 
				is a pure abstract class and is the parent class
				to Scene1, Scene2, Scene3, Scene4, Scene5, & Scene6
				classes.
***********************************************************************/

#ifndef	SPACE_HPP
#define	SPACE_HPP
#include "validate3.hpp"
#include "validate4.hpp"
#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

class Space
{
	private:
		Space *top;
		Space *bottom;
		Space *left;
		Space *right;
		string name;	// Space name

	protected:
		string part1;	// holds ufo image
		string part2;	// holds ufo image
		char **scene;	// pointer for dynamic 2D array
		int row;
		int col;

	public:
		Space();
		
		// Set methods
		void setName(string);
		void setRow(int);
		void setCol(int);
		void setTop(Space *t);
		void setBottom(Space *b);
		void setLeft(Space *l);
		void setRight(Space *r);

		// Get methods for retrieving spaces
		Space *getTop();
		Space *getBottom();
		Space *getLeft();
		Space *getRight();
		string getName();

		void createSpace();
		void setScene(ifstream&);
		virtual void display();
		virtual Space *nextMove(Space *next) = 0;
		virtual int getType() = 0;
      	virtual void placeUFO();
		~Space();
};

#endif
