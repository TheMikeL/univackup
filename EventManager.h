//#include "ICSParser.h"
#include "CalendarItems.h"
//#include "Algorithm/Event Scheduler"
#include "database.h"
#include <vector>
#include <iostream>


#pragma once

class EventManager {
public:
	EventManager(time_t intervalStart, time_t intervalEnd);

	//Adds, Edits, Deletes events from the database and the master list 
	void addEvent(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip = {});
	void addEvent(Event& e);

	void deleteSingleEvent(Event& e);
	void deleteAllEvent(Event& e);

	void editSingleEvent(Event& e);
	void editAllEvent(Event& e);

	void addToDo(ToDo& e);
	void addUnscheduledToDo(ToDo& e);

	void editToDo(ToDo& e);
	void deleteToDo(ToDo& e);

	//Method used to update the events.
	//Sends information to the database and updates the GUI.
	vector<CalendarItem*>  getView(time_t start, time_t end);

	//Method used to use an algorithm to schedule event.
	//Asks the Algorithm/Event Scheulder to do the algorithm
	//to schedule the events accordingly
	vector<Event>   schedule();
	vector<Event>  schedule(time_t start, time_t finish);

	//Method to get all the events and Todos inbetween two times.
	vector<Event> getIntervalEvents(time_t start, time_t finish);
	vector<ToDo> getScheduledTodos(time_t start, time_t finish);
	vector <ToDo> getUnscheduledTodos(time_t start, time_t finish);

	//method to get all events ofa  certain type or todos.
	//returns a vector<calenderItem>
	vector<Event> getTypeInterval(time_t start, time_t finish, const string type);

	vector <CalendarItem*> merge();
	void setIntervalStart(time_t start);
	void setIntervalEnd(time_t end);

	time_t getIntervalStart();
	time_t getIntervalEnd();
	vector<Event> getEventsList();
	vector <ToDo> getTodoList();

	//start up -> auto get current view
	//         -> scheduled Todos
	//         -> events 
	//         in a master list and sends it to the gui.
	//         -> and unscheduled ToDos at the side.  Also send to GUI.

private:
	time_t intervalStart;
	time_t intervalEnd;

	void addEventToList(Event& e);
	void addTodoToList(ToDo& e);

	// The List of events.
	vector<ToDo> toDoList;
	vector<ToDo> unscheduledToDoList;
	vector<Event> eventsList;
	vector<CalendarItem*> masterList;
};
bool isEventWithID(Event e, int id);
bool isEventWithIDandNumber(Event e, int id, int number);