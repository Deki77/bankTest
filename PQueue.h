/*
 * MyADT.h
 * 
 * Class Description: A data collection ADT class to satsfy Assn 1's requirements
 * Class Invariant: Data collection with the following characteristics:
 *			-Each element is unique 
 *Authors: Dejan jovasevic Kyle Griffith
 */
#pragma once
#include <string>
#include "Event.h"
#include "Node.h"
#include "EmptyDataCollectionException.h"
using namespace std;


class PQueue
{
private:
	int count;
	Node* headptr;
	Node* backptr;

	
public:

	PQueue();
	
	~PQueue();
	
  // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
  // Time Efficiency: O(1)
  bool isEmpty() const;

  // Description: Inserts newElement in sort order.
  //              It returns "true" if successful, otherwise "false".
  // Precondition: This Priority Queue is sorted.
  // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
  bool enqueue(const Event& newElement);

  // Description: Removes the element with the "highest" priority.
  //              It returns "true" if successful, otherwise "false".
  // Precondition: This Priority Queue is not empty.
  bool dequeue();

  // Description: Retrieves (but does not remove) the element with the "highest" priority.
  // Precondition: This Priority Queue is not empty.
  // Postcondition: This Priority Queue is unchanged.
  // Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
  Event* peek() const throw(EmptyDataCollectionException);
  void show();
};
