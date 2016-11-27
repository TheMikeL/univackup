//#include "ICSParser.h"
//#include "CalendarItem.h"
//#include "SQLite_Database.h"
//#include "Algorithm/Event Scheduler"

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include "CalendarItems.h"
//#include "database.h"
#include "EventManager.h"
#include <algorithm> 

using namespace std;



	EventManager::EventManager(time_t intervalStart, time_t intervalEnd): intervalStart(intervalStart),intervalEnd(intervalEnd) 
	{
		eventsList = getIntervalEvents(intervalStart, intervalEnd);
		toDoList = getScheduledTodos(intervalStart, intervalEnd);
		merge();
	}


	void EventManager::addEvent(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip) {
		Event e = Event(id, name, summary, start, end, repeatInterval, numRepeats, type, location, number, {});
		addEvent(e);
	}

	void EventManager::addEventToList(Event& e) {
		time_t start = e.getStart();
		time_t end = e.getEnd();
		int count = -1;
		vector<Event>::iterator it = eventsList.begin();
		if ((start >= intervalStart || end >= intervalStart) && start < intervalEnd) {
			for (int i = 0; i < eventsList.size(); i++) {
				if (start < eventsList[i].getStart()) {
					count = i;
					break;
				}
				count = i;
			}
		}

		
		eventsList.insert(it + count, e);
	}
	//insert in correct place, by start time, check if in current interval, if yes add to own list + database, if not just database.
	//Note: how do i check what the current interval is? -> currently thinking get state. but i'll see.
	void EventManager::addEvent(Event & e){
		
		int id;
		try {
			Database data("Calendar.db");
			data.addEvent(e);
			id = data.getLastRowID();
			data.close();
		}
		catch (DatabaseException& e) {
			e.what();
		}
		e.setID(id);
		e.setNumber(0);
		addEventToList(e);
	}


	void EventManager::deleteSingleEvent(Event& e) {
		int id = e.getId();
		int num = e.getNumber();
		int i = 0;
		while (i < eventsList.size()) {
			if (isEventWithIDandNumber(eventsList[i], id,num)) {
				eventsList.erase(eventsList.begin() + i);
				break;
			}
			else {
				++i;
			}
		}

		try {
			Database data("calendar.db");
			data.deleteSingleEvent(e);
			data.close();
			//UPDATE GUI 
		}
		catch (DatabaseException& e) {
			e.what();
		}
	}
	
	bool isEventWithIDandNumber(Event e, int id, int number) {
		if (e.getId() == id && e.getNumber()==number)
			return true;
		else
			return false;
	}
	

	bool isEventWithID(Event e, int id) {
		if (e.getId() == id) 
			return true;
		else
			return false;
	}

	void EventManager::deleteAllEvent(Event& e) {
		int id = e.getId();
		int i = 0;
		while (i < eventsList.size()) {
			if (isEventWithID(eventsList[i],id)) {
				eventsList.erase(eventsList.begin() + i);
			}
			else {
				++i;
			}
		}

		try {
			Database data("calendar.db");
			data.deleteAllEvent(id);
			data.close();
			//UPDATE GUI 
		}
		catch (DatabaseException& e) {
			e.what();
		}
	}
	
	void EventManager::editSingleEvent(Event& e) {
		
		int eid = e.getId();
		int num = e.getNumber();
		int i = 0;
		while (i < eventsList.size()) {
			if (isEventWithIDandNumber(eventsList[i], eid, num)) {
				eventsList.erase(eventsList.begin() + i);
				break;
			}
			else {
				++i;
			}
		}
		Database data("calendar.db");
		data.editSingleEvent(e);
		data.close();

		int id = data.getLastRowID();
		Event e2 = e;
		e2.setID(id);
		e2.setRepeatInterval(0);
		e2.setNumRepeats(0);
		e2.setSkips({});

		addEventToList(e2);

	}

	void EventManager::editAllEvent(Event& e) {
		Database data("Calendar.db");
		data.editAllEvent(e);
		data.close();
		int id = e.getId();
		for (int i = 0; i < eventsList.size(); i++) {
			if (eventsList[i].getId() == id) {
				eventsList[i].setName(e.getName());
				eventsList[i].setSummary(e.getSummary());
				eventsList[i].setStart(e.getStart());
				eventsList[i].setEnd(e.getEnd());
				eventsList[i].setType(e.getType());
				eventsList[i].setRepeatInterval(e.getRepeatInterval());
				eventsList[i].setNumRepeats(e.getNumRepeats());
				eventsList[i].setLocation(e.getLocation());
			}
		}
	}

	vector<Event> EventManager::getIntervalEvents(time_t start, time_t finish) {
		Database data("calendar.db");
		vector<Event> events = data.getIntervalEvents(start, finish);
		eventsList = events;
		data.close();
		return eventsList;
	}

	vector<Event> EventManager::getTypeInterval(time_t start, time_t finish, const string type) {
		Database data("Calendar.db");
		vector<Event> Events = data.getIntervalEvents(start, finish);
		vector<Event> temp;
		for (int i = 0; i < Events.size(); i++) {
			if (type.compare(Events[i].getType()) == 0) {
				temp.push_back(Events[i]);
			}
		}
		data.close();
		eventsList = temp;
		return eventsList;
	}

	void EventManager::addTodoToList(ToDo& t) {
		time_t start = t.getStart();
		time_t end = t.getEnd();
		int count = -1;
		vector<ToDo>::iterator it = toDoList.begin();
		if ((start >= intervalStart || end >= intervalStart) && start < intervalEnd) {
			for (int i = 0; i < toDoList.size(); i++) {
				if (start < toDoList[i].getStart()) {
					count = i;
					break;
				}
				count = i;
			}
		}

		if(count>=0)
			toDoList.insert(it + count, t);
	}

	//same as todo, same as unscheduled since can only add unscheduled todos, until scheduled.
	void EventManager::addToDo(ToDo & t) {
		int id;
		try {
			Database data("Calendar.db");
			data.addTodo(t);
			id = data.getLastRowID();
			data.close();
		}
		catch (DatabaseException& e) {
			e.what();
		}
		t.setID(id);

		addTodoToList(t);
	}
	

	void EventManager::addUnscheduledToDo(ToDo & e) {
		unscheduledToDoList.push_back(e);
		Database data("calendar.db");
		data.addTodo(e);
		data.close();
	}


	void EventManager::editToDo(ToDo& t) {
		int id = t.getId();
		for (int i = 0; i < toDoList.size(); i++) {
			if (id == toDoList[i].getId()) {
				toDoList[i].setName(t.getName());
				toDoList[i].setSummary(t.getSummary());
				toDoList[i].setStart(t.getStart());
				toDoList[i].setEnd(t.getEnd());
				toDoList[i].setType(t.getType());
				toDoList[i].setViableEnd(t.getViableEnd());
				toDoList[i].setEstimatedTime(t.getEstimatedTime());
				toDoList[i].setWeight(t.getWeight());
				toDoList[i].setScheduled(t.getScheduled());
				toDoList[i].setPinned(t.getPinned());

			}
		}
		Database data("calendar.db");
		data.editTodo(t);
		data.close();
	}

	bool isTodoWithID(ToDo e, int id) {
		if (e.getId() == id)
			return true;
		else
			return false;
	}
	void EventManager::deleteToDo(ToDo & t)
	{
		int id = t.getId();
		int i = 0;
		while (i < toDoList.size()) {
			if (isTodoWithID(toDoList[i], id)) {
				toDoList.erase(toDoList.begin() + i);
			}
			else {
				++i;
			}
		}

		try {
			Database data("calendar.db");
			data.deleteTodo(id);
			data.close();
			//UPDATE GUI 
		}
		catch (DatabaseException& e) {
			e.what();
		}
	}

	vector<Event> EventManager::schedule(time_t start, time_t end) {
		Database data("Calendar.db");
		vector<Event> Events = data.getIntervalEvents(start, end);
		eventsList = Events;
		data.close();
		return eventsList;
	}

	//send view back to GUI,  have to return a list.
	vector<Event> EventManager::schedule() {
		Database data("Calendar.db");
		vector<Event> Events = data.getIntervalEvents(0, 9999999999);
		eventsList = Events;
		data.close();
	  return eventsList;
	}

	
	vector <ToDo> EventManager::getScheduledTodos(time_t start, time_t finish) {
		Database data("calendar.db");
		vector<ToDo> todos = data.getScheduledTodos(start, finish);
		toDoList = todos;
		data.close();
		return todos;
	}
	vector <ToDo> EventManager::getUnscheduledTodos(time_t start, time_t finish) {
		Database data("calendar.db");
		vector<ToDo> todos = data.getUnscheduledTodos(start, finish);
		unscheduledToDoList = todos;
		data.close();
		return todos;
	}



	vector <CalendarItem*> EventManager::merge() {
		vector <CalendarItem*> MasterList;
		int counter;
		for (int i = 0; i < eventsList.size(); i++) {
			MasterList.push_back(&eventsList[i]);
		}
		for (int i = 0; i < toDoList.size(); i++) {
			for (int j = 0; j < MasterList.size(); j++) {
				if (toDoList[i].getStart() < (MasterList[j]->getStart())) {
					counter = j;
					break;
				}
				counter = j;
			}
			MasterList.insert(MasterList.begin() + counter, &toDoList[i]);
			
		}
		return MasterList;
	}

	vector <CalendarItem*> EventManager::getView(time_t start, time_t end)
	{
		intervalStart = start;
		intervalEnd = end;
		eventsList.clear();
		toDoList.clear();

		eventsList= getIntervalEvents(start, end);
		toDoList=getScheduledTodos(start,end);
		masterList = merge();
		return masterList;

	}

	vector<Event> EventManager::getEventsList() {
		return eventsList;
	}

	vector<ToDo> EventManager::getTodoList()
	{
		return toDoList;
	}

	void EventManager::setIntervalStart(time_t start) {
		intervalStart = start;
	}
	void EventManager::setIntervalEnd(time_t end) {
		intervalEnd = end;
	}

	time_t EventManager::getIntervalStart(){
		return intervalStart;
	}

	time_t EventManager::getIntervalEnd(){
		return intervalEnd;
	}

	//scheduling events, 2 lists, all events in the calender(events and todos that are scheduled, and a list of unscheduled todos.
	//scheulde unscheduled ToDos ^
	//add accessor for the event list for the gui.
	//fix iterators.
	//start up method,get everything for starting up.