/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene3 class declaration.
				This class is derived from the Space class.
********************************************************************/

#ifndef	SCENE3_HPP
#define	SCENE3_HPP
#include "Space.hpp"

class Scene3 : public Space
{
	public:
		Scene3();
		virtual Space *nextMove(Space *next);
		virtual int getType();
		virtual void placeUFO();
};

#endif
