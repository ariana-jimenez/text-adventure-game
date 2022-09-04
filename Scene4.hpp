/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene4 class declaration.
				This class is derived from the Space class.
********************************************************************/

#ifndef	SCENE4_HPP
#define	SCENE4_HPP
#include "Space.hpp"

class Scene4 : public Space
{
	public:
		Scene4();
		virtual Space *nextMove(Space *next);
		virtual int getType();
		virtual void placeUFO();
};

#endif
