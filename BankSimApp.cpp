/*
 * BankSimApp.cpp
 * Author: DJ KG
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <iomanip>
#include "Event.h"
#include "Queue.h"
#include "PQueue.h"

using namespace std;
//Setting global variables
bool tellerAvailable = true;
int currentTime = 0;
double waitTime = 0;
//declaraing functuons tobe used
void arrive(Event &newEvent, PQueue& eventListPQueue, Queue& bankQueue);
void leave(Event &newEvent, PQueue& eventListPQueue, Queue& bankQueue);
void setDeparture(Event &customer, PQueue& eventListPQueue, int currentTime);
void processEvents(PQueue& eventListPQueue, Queue& bankQueue);

int main(){
	//Create bankQueue and eventListPQueue
	Queue bankQueue;
	PQueue eventListPQueue;
	
	
  string aLine;
  int arrival = 0;
  int duration = 0;
  int totalCustomers = 0;

  // Enter 2 numbers then press "Enter"
  // Repeat the above until you had enough,
  // then type CTRL+D
  //creates new event, by creating pointer to it using default constructor
	Event* newEvent = new Event();
    cout<<"Arrival Duration"<<endl;
  while(getline(cin, aLine)) {
    stringstream ss(aLine);
    ss >> arrival >> duration;

    if(arrival > 0){

			//do stuff with numbers
			cout << "Read: " << arrival << " " << duration << endl;
			//Set attributes for new event
			newEvent->setType(EVENT_ARRIVAL);
			newEvent->setTime(arrival);
			newEvent->setLength(duration);
			newEvent->setId(totalCustomers);
			//checks to see if event was properly added to the PQueue
			if(eventListPQueue.enqueue(*newEvent)){
				cout << "Successfully added to pqueue" << endl;
				totalCustomers++;
			}
			else{
				delete newEvent;
				cout << "Add failed" << endl;
			}
    }
  }
  delete newEvent;

  //eventListPQueue.show();
	
//Now all the events should be within the Pqueue, we run while loop while there is still events to be processed.
	processEvents(eventListPQueue, bankQueue);

cout << "Simulation ends" << endl << endl;
cout << "Final Statistics" << endl << endl;
cout << "\tTotalnumber of people processed: " << totalCustomers << endl;
cout << "\tTotal wait time: " << waitTime << endl;
cout << "\tAverage amount of time spent waiting: " << waitTime/totalCustomers << endl;

  return 0;
}

void processEvents(PQueue& eventListPQueue, Queue& bankQueue){

	while(!eventListPQueue.isEmpty()){
	try{
			//The try and catch checks to see if evenListPqueue.peek returned a prper value
			Event *newEvent = eventListPQueue.peek();

			eventListPQueue.dequeue();
			//If so we find the currentTime, time of event being processed
			currentTime = newEvent->getTime();
			cout << "currentTime " << currentTime << endl;
			//newEvent->show();
			//check whether event is arrival or departure and then call the respective funtions
			if(newEvent->getType() == EVENT_ARRIVAL)
						arrive(*newEvent, eventListPQueue, bankQueue);
					else
						leave(*newEvent, eventListPQueue, bankQueue);
				}
	//catch error if Pqueue is empty, this means we are out of events.
	catch (EmptyDataCollectionException(PQueueFail)) {
	       // cerr << "PQueue Fail" << endl;
	    }
		}

}

//Arrive basically takes in event, Pqueue and Queue, it checks if the bankqueue is empty and if teller is available. If so it sets new departure event and the person
//who arrived goes to the teller. If not then the person is added to the bankqueue in the line
void arrive(Event &newEvent, PQueue& eventListPQueue, Queue& bankQueue){
	cout << "Processing an arrival event at time: " <<setw(7) << currentTime << endl;

	if(bankQueue.isEmpty() && tellerAvailable){
		setDeparture(newEvent, eventListPQueue, currentTime);
		tellerAvailable = false;
	}
	else
		bankQueue.enqueue(newEvent);

}
//Leave deletes the element that just departed first, so we dont have outstanding objects. It checks to see if bankQueue is empty with peek, if proper value
//is returned everything is good to go so we calculate wait time, create a new departure event for the person at the front of the line and pop them off the queue.
void leave(Event &newEvent, PQueue& eventListPQueue, Queue& bankQueue){
	cout << "Processing a departure event at time: " <<setw(7) << currentTime << endl;

	delete &newEvent;
    try{
	Event* customer = bankQueue.peek();
	
		//catch exception
        bankQueue.dequeue();
        
        waitTime += (currentTime - customer->getTime());
        //cout << "Current Time " << currentTime << " Wait Time " << waitTime << " CustomerTime " << customer->getTime() << endl;
        setDeparture(*customer, eventListPQueue, currentTime);
        tellerAvailable = false;
        //if bankqueue is empty there is no new person to set departue time for so we just let the teller become available
    }catch (EmptyDataCollectionException(QueueFail)) {
        //cerr << "QueueFail" << endl;
        tellerAvailable = true;
    }
}
//this function sets all the values for the new departure event and adds it to the Pqueue.
void setDeparture(Event &customer, PQueue& eventListPQueue, int currentTime) {
	customer.setType(EVENT_DEPARTURE);
	customer.setTime(currentTime + customer.getLength());
	customer.setLength(0);

	eventListPQueue.enqueue(customer);
}
