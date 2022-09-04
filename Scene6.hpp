/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene6 class declaration.
				This class is derived from the Space class.
********************************************************************/

#ifndef	SCENE6_HPP
#define	SCENE6_HPP
#include "Space.hpp"

class Scene6 : public Space
{
	public:
		Scene6();
		virtual Space *nextMove(Space *next);
		virtual int getType();
		virtual void placeUFO();
};

#endif
