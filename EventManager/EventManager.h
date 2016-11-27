//
//Cisc 320 Project
//

//#include "ICSParser.h"
#include "calendarItems.h"
//#include "SQLite_Database.h"
//#include "Algorithm/Event Scheduler"
#include "database.h"

#include <vector>
#include <iostream>
using namespace std;

#pragma once

class EventManager {
public:
	EventManager();
	//Method to add events into the calender.
	//It creates an event, inputs the event into the list, and then
	//updates the database
	void addEvent(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip = {});
	void addEvent(Event& e);
	void addToDo(int id, string name, string summary, time_t start, time_t end, string type, time_t viableStart, time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned);
	void addToDo(ToDo& e);
	void addUnscheduledToDo(int id, string name, string summary, time_t start, time_t end, string type, time_t viableStart, time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned);
	void addUnscheduledToDo(ToDo& e);
	//Method to delete an event from the calender.
	//parameter event, an event object.
	//Finds the Event in the vector list then takes it out then
	//deletes it.
	void   deleteEvent(Event& e);
	void   deleteEvent(int id);
	//Method to edit an event in the calender.
	//First finds the event in the vector list
	void   editEvent(Event& e);
	void   editToDo(ToDo& e);
	//Method used to update the events.
	//Sends information to the database and updates the GUI.
	vector<CalendarItem>  updateEvents();
	//Method used to use an algorithm to schedule event.
	//Asks the Algorithm/Event Scheulder to do the algorithm
	//to schedule the events accordingly
	vector<Event>   schedule();
	vector<Event>  schedule(time_t start, time_t finish);
	//Method to get all the events inbetween two times.
	vector<Event> getInterval(time_t start, time_t finish);
	//Method to get the current state of the caleneder
    void getState();
	//method to get all events ofa  certain type or todos.
	//returns a vector<calenderItem>
	vector<Event> getTypeInterval(time_t start, time_t finish, const string type);
	vector<Event> getEventsList();
	//start up -> auto get current view
	//         -> scheduled Todos
	//         -> events 
	//         in a master list and sends it to the gui.
	//         -> and unscheduled ToDos at the side.  Also send to GUI.

private:

	// The List of events.
	vector<ToDo> toDoList;
	vector<ToDo> unscheduledToDo;
	vector<Event> eventsList;

};
