/***************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Node class declaration. This class
				creates a node to hold an object in the player's inventory,
				and is used by the Queue class.
***************************************************************************/

#ifndef	NODE_HPP
#define	NODE_HPP
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Node
{
	private: 
		string photo;
		Node *next;
		Node *prev;

	public:
		Node(string p);		// Constructor
		friend class Queue;
};

#endif
