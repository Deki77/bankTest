/*
 * myADT.cpp - Assignment 1
 * 
 * Class Description: Abstract data type for saving profile objects to array-based structure.
 *
 * In this version, we use our MyADT.
 *
 * Created on: May 24, 2016
 * Author: DJ
 */

#include <iostream>
#include <string>
#include <cctype>
#include <string.h>
#include "PQueue.h"


using namespace std;
//Default constructor
PQueue::PQueue(){
	headptr = NULL;
	backptr = NULL;
	count = 0;
}
//Destructor
PQueue::~PQueue(){
	while(headptr!=NULL){
		Node* temp = headptr->next;
		delete headptr;
		headptr = temp;
 	}
}
//Checks to see if pqueue is empty by checking if headptr points to NULL, returns true if empty false if not
bool PQueue::isEmpty() const {
	return(headptr == NULL);
}
//Adds event into PQueue
bool PQueue::enqueue(const Event& newElement){

   // cout << "enqueue" << endl;
    //Create pointer to new Node which is given the element it is to work with
    Node* newPointer = new Node(newElement);
    //Sets current and previous pointers to node in order to be able to traverse through linked list and find where the new Node should be placed
    Node* current = headptr;
    Node* previous = NULL;
    //cout <<"Hello" <<endl;
    //Run through all elements of the linked list, appropriately changing current and next so they follow the traveresement.
    for(; current != NULL; previous = current, current = current->next){
        //cout << "My" << endl;
        //Check if new Node should be added at the front of the list when list is not empty
        if(newElement.getTime() < current->data.getTime()){
            if (current == headptr) {
              //cout <<"Name" << endl;
            	newPointer->next=headptr;
                headptr=newPointer;
            }
            //Places Node inbetween 2 exisiting nodes
            else{
            	//cout << "Is" << endl;
							previous->next = newPointer;
							newPointer->next = current;
            
        }
        return true;

    }
}
//Checks if list is empty, if so places Node at the front of the list
if(headptr == NULL){
    
    headptr = newPointer;
    backptr = newPointer;
	}
//Places Node at the back of the list again setting appropriate pointers so the list is complete.
else{

		backptr->next = newPointer;
		backptr = newPointer;
	}
	return true;

}
//Checks if headptr is not null, if not it changes headptr to point to the next element, essentailly deleting Node from Pqueue
bool PQueue::dequeue(){
	bool status = (headptr!=NULL);
	if(status){
		headptr = headptr->next;
	}
	return(status);
}
//Peek function returns pointer to event, I know it should be Event but it was more logical for us to do it this way sorry.
Event* PQueue::peek()const throw(EmptyDataCollectionException){
    //If headptr is not null, list not empty, we return the data object (event) from the specified nodde. If list is empty we throw exception
		if(headptr!=NULL)
        return(&headptr->data);
    else
        throw(EmptyDataCollectionException("PQueue Fail"));
}
//Displays current node
void PQueue::show(){
	Node* current = headptr;
	for(; current != NULL; current = current->next)
		current->data.show();
}
