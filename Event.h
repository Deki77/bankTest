/*
 *Even.h
 *Authors: Dejan Jovasevic, Kyle Griffith
 */

#pragma once
#include <string>
using namespace std;
//Defining variables for arrival = true, departure = false
#define EVENT_ARRIVAL   true
#define EVENT_DEPARTURE !EVENT_ARRIVAL


class Event
{
private:
	int  id;
	bool type;                      // type of event
	int  time;                     // image filename (optional)
	int  length;                    // current status
	
public:

	// Default Constructor
	//Creates even setting everything to zero.
	Event();

	// Constructor
	//Creates event taking in variables for type, time and length
	Event(bool aType, int aTime, int aLength);

	// Getters and setters
	// Description: Returns event type
	bool getType() const;

	// Description: returns event time
	int getTime() const;

	// Description: Returns event list
	int getLength() const;


	// Description: Sets the events type
	void setType(const bool aType);

	// Description: Sets the events arrival time
	void setTime(const int aTime);

	// Description: Sets the events Id
	void setLength(const int aLength);
	//Sets ID for event so that we can keep track of it
	void setId(const int eid);
	//Displays event
	void show();
};
// end of Event.h
