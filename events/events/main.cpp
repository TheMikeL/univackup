#include "event.h"
#include "eventManager.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<Event> events;
	time_t start;
	time_t end;
	string name;
	string summary;
	string location;
	bool pinned;

	start = 10000;
	end = 12700;
	name = "event";
	summary = "summary";
	location = "location";
	pinned = true;
	for (int i = 0; i < 10; i++) {
		events.push_back(Event(start + i * 100, end + i * 100, name + to_string(i), summary + to_string(i), location + to_string(i), pinned));
	}
	cout << "Initial event list" << endl;
	for (unsigned int i = 0; i < events.size(); i++) {
		cout << events[i] << endl;
	}
	cout << "Inserting an event" << endl;
	// demonstrate adding a few events in the right spot
	events = addEvent(events, Event(10350, 15000, "insertedName", "insertedSummary", "insertedLocation", false));
	for (unsigned int i = 0; i < events.size(); i++) {
		cout << events[i] << endl;
	}
	cout << "Deleting an event" << endl;
	// demonstrate deleting an event by name (could replace with by unique ID later)
	events = deleteEvent(events, "event6");
	for (unsigned int i = 0; i < events.size(); i++) {
		cout << events[i] << endl;
	}
	cout << "Getting an event" << endl;
	cout << *getEvent(&events, "event5") << endl;
	cout << "Editing an event" << endl;
	Event* e = getEvent(&events, "event5");
	(*e).setStart(777);
	cout << (*e) << endl;
	cout << "New events list" << endl;
	for (unsigned int i = 0; i < events.size(); i++) {
		cout << events[i] << endl;
	}
	return 0;
}
