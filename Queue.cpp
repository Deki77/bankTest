/*
 *Queue.cpp
 *
 * 
 *
 *
 * Author: DJ KG
 */

#include <iostream>
#include <string>
#include <cctype>
#include <string.h>
#include "Event.h"
#include "Queue.h"

using namespace std;

#define arrElements(p) (sizeof(p)/sizeof(p[0]))
//Default constructor for Queue, sets add count and remove count to zero, fills all elements to null
Queue::Queue(){
	add_count = 0;
	remove_count = 0;

	int i = 0;
	for (; i<arrElements(lineup); i++) {
		lineup[i] = NULL;

	}
}
//Deconstructor removes all elements from array and deletes objects.
Queue::~Queue(){
	int i = 0;
	for (; i<arrElements(lineup); i++) {
		if(lineup[i]){
			delete lineup[i];
			lineup[i] = NULL;
		}
	}
}
//Checks to see if queue is empty
bool Queue::isEmpty() const {
	return(add_count == remove_count);
}
//Adds new element into the queue, after it is done it increases add count so we know where to add next element
bool Queue::enqueue(const Event& newElement){
	bool status = (add_count < (arrElements(lineup)-1));
	if (status) {
		lineup[add_count] = &newElement;
		add_count++;
	}
	else
		cout <<  "array full" << endl;
	return(status);
}
//Dequeue removes element from queue, it increases remove count so we know where the next element lies. This allows us to have O(1) when deququeing.
bool Queue::dequeue(){
	if(!isEmpty()){
		lineup[remove_count] = NULL;
		remove_count++;
	}
	return false;
}
//Event *Queue::peek() {
//Peek again returns a pointer to an event, again sorry for doing it this way but it just made more sense to us to return the pointer to the object and then work with that
Event* Queue::peek()const throw(EmptyDataCollectionException) {
    if(!isEmpty())
        return((Event* )lineup[remove_count]);
    else
        throw EmptyDataCollectionException("QueueFail");
}

