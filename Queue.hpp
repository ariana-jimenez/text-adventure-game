/*****************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17/2019
** Description: This file contains the Queue class declarations. This class
				creates a container that holds a circular linked list of
				Nodes. This class is used as the inventory for the player
				and stores photos.
*****************************************************************************/

#ifndef	QUEUE_HPP
#define	QUEUE_HPP
#include "Node.hpp"

class Queue
{
	private:
		Node *head;
		int size;		// counter for tracking number of items in queue

	public:
		Queue();
		bool isEmpty();
		void addItem(string p);
		void removeItem();
		int getSize();
		void printQueue();
		~Queue();
};

#endif
