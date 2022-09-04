/*************************************************************************************
** Final Project
** Name: Ariana Jimenez
** Date: 3/17//2019
** Description: This file contains the Queue class definitions. The purpose of this
				class is to create a container to hold photo items that the player
				creates during gameplay. It has 5 member functions that serve the 
				prupose of testing if the queue is empty, adding to the queue,
			    printing the contents of the queue, and checking size of the queue.
*************************************************************************************/

#include "Queue.hpp"

// Constructor sets head to null and initializes size to 0
Queue::Queue()
{
	head = nullptr;
	size = 0;
}

// The isEmpty method checks if the queue is empty. If it is empty, it returns
// true. Otherwise it returns false.
bool Queue::isEmpty()
{
	if (head == nullptr)
	{
		return true;
	}

	else
	{
		return false;
	}
}


/* The addItem method takes in a string as a parameter. It then creates a
 * new Node and stores that string in the Node (to hold the photo name),
 * and then links the node to other existing nodes in the list, if any.*/

void Queue::addItem(string p)
{
	size++;

	// if list is empty, add the first node. Link the head to point back to itself.
	if (isEmpty())
	{
		head = new Node(p);
		head->prev = head;
		head->next = head;
	}

	else
	{
		// Create a rear pointer to point to the last node in list
		Node *rear = head->prev;

		// Create new node
		Node *ptr = new Node(p);

		// Link new node pointers to point back to head and previous node
		ptr->next = head;
		ptr->prev = rear;

		// Set new node as the rear, point back to head
		head->prev = ptr;
		rear->next = ptr;
	}
}


// The removeItem function removes the first node in the Queue
void Queue::removeItem()
{
	if (!isEmpty())
	{
		// If there is only one node in the queue, set head pointer to null
		if (head->next == head)
		{
			delete head;
			head = nullptr;
		}

		else
		{
			Node *ptr = head;
			Node *rear = head->prev;

			head = ptr->next;
			head->prev = ptr->prev;
			rear->next = ptr->next;
			delete ptr;
		}
	}
}

// Returns the size of the queue
int Queue::getSize()
{
	return size;
}

// Prints all items in the queue from first to last
void Queue::printQueue()
{
	if (isEmpty())
	{
		cout << "Empty (no photos saved)" << endl;
	}

	else
	{
		Node *ptr = head;

		do
		{
			cout << "[" <<  ptr->photo << " Photo] ";
			ptr = ptr->next;

		} while (ptr != head);

		cout << endl;
	}
}

// Destructor deletes all the nodes by calling the removeItem method.
Queue::~Queue()
{
	while (!isEmpty())
	{
		removeItem();
	}
}
