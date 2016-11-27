#include "event.h"

Event::Event(time_t start, time_t end, string name, string summary, string location, bool pinned) {
	this->start = start;
	this->end = end;
	this->name = name;
	this->summary = summary;
	this->location = location;
	this->pinned = pinned;
}

const string& Event::getName() {
	return name;
}

void Event::setStart(time_t t) {
	start = t;
}

time_t Event::getStartTime() {
	return start;
}

ostream& operator<<(ostream& os, const Event& e) {
	os << e.name << ": " << e.start << " to " << e.end;
	return os;
}
