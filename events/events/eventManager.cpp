#include "eventManager.h"

/** Adds an event to a list of existing events in the right spot
* Events are organized by time so insertion is O(logn) + O(n) using binary search
* (vectors take O(n) to add anywhere but the end, I think)
*/
vector<Event> addEvent(vector<Event> events, Event e) {
	int low = 0;
	int high = events.size() - 1;
	int guess;
	while (low <= high) {
		guess = (low + high) / 2;
		if (events[guess].getStartTime() >= e.getStartTime())
			high = guess - 1;
		else
			low = guess + 1;
	}
	// At this point we always have high, insert_point, low so insert right before low
	events.insert(events.begin() + low, e);
	return events;
}

vector<Event> deleteEvent(vector<Event> events, const string& name) {
	int index = -1;
	for (int i = 0; i < events.size(); i++) {
		if (events[i].getName() == name) {
			index = i;
			break;
		}
	}
	if (index == -1) // Did not find event to delete
		return events;
	else
	    events.erase(events.begin() + index);
	return events;
}

Event* getEvent(vector<Event>* events, const string& name) {
	int index = -1;
	for (int i = 0; i < (*events).size(); i++) {
		if ((*events)[i].getName() == name) {
			index = i;
			break;
		}
	}
	if (index == -1) // Did not find event
		return &(*events)[0];
	else
		return &(*events)[index];
}
