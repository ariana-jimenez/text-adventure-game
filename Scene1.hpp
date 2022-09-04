/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene1 class declaration.
				This class is derived from the Space class.
********************************************************************/

#include "Space.hpp"
#ifndef	SCENE1_HPP
#define	SCENE1_HPP

class Scene1 : public Space
{
	public:
		Scene1();
		virtual Space *nextMove(Space *next);
		virtual int getType();
};

#endif
