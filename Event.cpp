/*
 * Event.cpp
 * Authors: Dejan Jovasevic Kyle Griffith
 */

#include <iostream>
#include <string>
#include <locale>         // std::locale, std::isalpha
#include "Event.h"

using namespace std;

// Default Constructor
//Sets type to true and time and length to zero
Event::Event() {
	type = true;
	time = 0;
	length = 0;
}

// Constructor
// Description: creates an even setting time, type and length to the variables it is called with
Event::Event(bool aType, int aTime, int aLength) {
  setType(aType);
	setTime(aTime);
	setLength(aLength);
}

// Getters and setters
// Description: Returns type
bool Event::getType() const {
	return type;
}

// Description: Returns time
int Event::getTime() const {
	return time;
}

// Description: Returns length
int Event::getLength() const {
	return length;
}

// Description: Sets type
void Event::setType(const bool aType) {
    type = aType;
}

// Description: Sets time
void Event::setTime(const int aTime) {
	time = aTime;
}

// Description: Sets length
void Event::setLength(const int aLength) {
	length = aLength;
}
//Sets ID
void Event::setId(const int eid) {
	id = eid;
}
//writes out all elements of event.
void Event::show() {
	cout << "id=" << id << " Type: " << type  << " time: " << time << " length: " << length << endl;
}
// end of Event.cpp
