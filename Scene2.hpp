/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene2 class declaration.
				This class is derived from the Space class.
********************************************************************/

#include "Space.hpp"
#ifndef	SCENE2_HPP
#define	SCENE2_HPP

class Scene2 : public Space
{
	public:
		Scene2();
		virtual Space *nextMove(Space *next);
		virtual int getType();
		virtual void placeUFO();
};

#endif
