#include "stdafx.h"
#include <string>
#include "CalendarItems.h"
#include <vector>
#include <iostream>
using namespace std;

// CalendarItem constructor and accessors

CalendarItem::CalendarItem(int id, string name, string summary, time_t start, time_t end, string type) : id(id), name(name), summary(summary),
		start(start), end(end), type(type) { }

CalendarItem::~CalendarItem(){
}

string CalendarItem::getName() const {
	return name;
}
string CalendarItem::getSummary() const {
	return summary;
}
time_t CalendarItem::getStart() const {
	return start;
}
time_t CalendarItem::getEnd() const {
	return end;
}

string CalendarItem::getType() const {
	return type;
}
int CalendarItem::getId() const {
	return id;
}

void CalendarItem::setID(int newId)
{
	id = newId;
}
void CalendarItem::setName(string newName) {
	name = newName;
}
void CalendarItem::setSummary(string newSummary) {
	summary = newSummary;
}


void CalendarItem::setStart(time_t newStart) {
	start = newStart;
}
void CalendarItem::setEnd(time_t newEnd) {
	end = newEnd;
}

void CalendarItem::setType(string newType) {
	type = newType;
}


// -----------------------------------------------------------------------------------------------------------------------
// Event constructor and accessors

Event::Event(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip = {}) :
		CalendarItem (id, name, summary, start, end, type), repeatInterval(repeatInterval), numRepeats(numRepeats), location(location), number(number),skip(skip) { }

string Event::getLocation() const {
	return location;
}

int Event::getRepeatInterval() const {
	return repeatInterval;
}
int Event::getNumRepeats() const {
	return numRepeats;
}
int Event::getNumber() const {
	return number;
}
vector <int> Event::getSkips() const {
	return skip;
}
void Event::addSkips(int skips) {
	
	skip.push_back(skips);
}

void Event::setLocation(string newLocation) {
	location = newLocation;
}

void Event::setSkips(vector <int> newSkip) {
	skip = newSkip;
}

void Event::setNumRepeats(int newNumRepeat) {
	numRepeats = newNumRepeat;
}
void Event::setRepeatInterval(int newRepeatInterval) {
	repeatInterval = newRepeatInterval;
}
//------------------------------------------------------------------------------------------------------------------------
// ToDo constructor and accessors

ToDo::ToDo(int id, string name, string summary, time_t start, time_t end,
	string type, time_t viableStart, time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned) :
		CalendarItem(id, name, summary, start, end, type), estimatedTime(estimatedTime), viableStart(viableStart),
		viableEnd(viableEnd), weight(weight), scheduled(scheduled), pinned(pinned) { }




int ToDo::getEstimatedTime() const {
	return estimatedTime;
}
time_t ToDo::getViableStart() const {
	return viableStart;
}
time_t ToDo::getViableEnd() const {
	return viableEnd;
}
int ToDo::getWeight() const {
	return weight;
}
bool ToDo::getScheduled() const {
	return scheduled;
}
bool ToDo::getPinned() const {
	return pinned;
}

void ToDo::setEstimatedTime(int newEstimate) {
	estimatedTime = newEstimate;
}
void ToDo::setViableStart(time_t newViableStart) {
	viableStart = newViableStart;
}
void ToDo::setViableEnd(time_t newViableEnd) {
	viableEnd = newViableEnd;
}
void ToDo::setWeight(int newWeight) {
	weight = newWeight;
}
void ToDo::setScheduled(bool newSchedule) {
	scheduled = newSchedule;
}
void ToDo::setPinned(bool newPinned) {
	pinned = newPinned;
}

ostream & operator<<(ostream & out, const Event & event)
{
	out << "ID= " << event.getId() << endl
		<< "Name= " << event.getName() << endl <<
		"Start= " << event.getStart() << endl <<
		"End= " << event.getEnd() << endl <<
		"RepeatInterval= " << event.getRepeatInterval() << endl <<
		"NumRepeats= " << event.getNumRepeats() << endl <<
		"Type=" << event.getType() << endl <<
		"Location= " << event.getLocation() <<endl <<
		"Number= " << event.getNumber()<< endl;
	return out;
}
ostream & operator<<(ostream & out, const ToDo & todo)
{
	out << "ID= " << todo.getId() << endl
		<< "Name= " << todo.getName() << endl <<
		"Start= " << todo.getStart() << endl <<
		"End= " << todo.getEnd() << endl <<
		"EstimatedTime= " << todo.getEstimatedTime() << endl <<
		"ViableStart= " << todo.getViableStart() << endl <<
		"ViableEnd= " << todo.getViableEnd() << endl <<
		"Weight= " << todo.getWeight() << endl <<
		"Scheduled= " << todo.getScheduled() << endl <<
		"Pinned= " << todo.getPinned() << endl;
	
	return out;
}