/********************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Scene5 class declaration.
				This class derives from the Space class.
********************************************************************/

#ifndef	SCENE5_HPP
#define	SCENE5_HPP
#include "Space.hpp"

class Scene5 : public Space
{
	public:
		Scene5();
		virtual Space *nextMove(Space *next);
		virtual int getType();
};

#endif
