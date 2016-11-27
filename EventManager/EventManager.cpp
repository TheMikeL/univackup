//#include "ICSParser.h"
//#include "CalendarItem.h"
//#include "SQLite_Database.h"
//#include "Algorithm/Event Scheduler"

//definitely needs some improvement. I'm just not sure if some things work or not.
//-Calvin.
//just get things from database.
#include <vector>
#include <iostream>
#include <string>
//#include "database.h"
#include "EventManager.h"

using namespace std;



EventManager::EventManager() {

}


	void EventManager::addEvent(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip) {
		eventsList.push_back(Event(id, name, summary, start, end, repeatInterval, numRepeats, type, location, number, skip));
		Database data("Calendar.db");
		data.addEvent(Event(id, name, summary, start, end, repeatInterval, numRepeats, type, location, number, skip));
		data.close();
	}
	//insert in correct place, by start time, check if in current interval, if yes add to own list + database, if not just database.
	//Note: how do i check what the current interval is? -> currently thinking get state. but i'll see.
	void EventManager::addEvent(Event & e){
		time_t start = e.getStart();
		int count = -1;
		int id;
		for (int i = 0; i < eventsList.size(); i++) {
			if (start < (eventsList[i].getStart())) {
				count = i;
				break;
			}
		}
		/*Database data("Calendar.db");
		data.addEvent(e);
		id = data.getLastRowID();
		data.close();*/
		e.setID(id);
		if (count >= 0) {
			eventsList.insert(eventsList.begin() + count, e);
		}
	}

	void EventManager::addToDo(int id, string name, string summary, time_t start, time_t end, string type, time_t viableStart, time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned) {
		toDoList.push_back(ToDo(id, name, summary, start, end, type, viableStart, viableEnd, estimatedTime, weight, scheduled, pinned));
		Database data("Caldendar.db");
		data.addTodo(ToDo(id, name, summary, start, end, type, viableStart, viableEnd, estimatedTime, weight, scheduled, pinned));
		data.close();
	}
	//same as todo, same as unscheduled since can only add unscheduled todos, until scheduled.
	void EventManager::addToDo(ToDo & e) {
		if (e.getScheduled()) {
			toDoList.push_back(e);
		}
		else {
			addUnscheduledToDo(e);
		}
		Database data("calendar.db");
		data.addTodo(e);
		data.close();
	}
	// redundant
	void EventManager::addUnscheduledToDo(int id, string name, string summary, time_t start, time_t end, string type, time_t viableStart, time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned) {
		unscheduledToDo.push_back(ToDo(id, name, summary, start, end, type, viableStart, viableEnd, estimatedTime, weight, scheduled, pinned));
		Database data("Caldendar.db");
		data.addTodo(ToDo(id, name, summary, start, end, type, viableStart, viableEnd, estimatedTime, weight, scheduled, pinned));
		data.close();
	}
	//redundant
	void EventManager::addUnscheduledToDo(ToDo & e) {
		unscheduledToDo.push_back(e);
		Database data("calendar.db");
		data.addTodo(e);
		data.close();
	}
	//doesn't work. fix cause don't work
	void EventManager::deleteEvent(Event& e) {
		int id = e.getId();
		for (int i = 0; i < eventsList.size(); i++) {
			if (id == eventsList[i].getId()) {
				eventsList.erase(eventsList.begin() + i);
			}
		}
		Database data("calendar.db");
		data.deleteSingleEvent(e);
		data.close();
	}
	//fix iterator.
	void EventManager::deleteEvent(int id) {
		for (int i = 0; i < eventsList.size(); i++) {
			if (id == eventsList[i].getId()) {
				eventsList.erase(eventsList.begin() + i);

				Database data("calendar.db");
				data.deleteSingleEvent(eventsList[i]);
				data.close();
			}
		}
	}
	//fix iterator.
	//update database here.
	//use mutators.
	//edit through database.
	//make 2 one for database ver, one local + database.
	//editAllEvents method -> add that. -> decided not to add -> that's a lot of methods for each specific one.
	void EventManager::editEvent(Event& e) {
		int id = e.getId();
		for (int i = 0; i < eventsList.size(); i++) {
			if (id == eventsList[i].getId()) {
				eventsList[i].setID(e.getId());
				eventsList[i].setNumRepeats(e.getNumRepeats());
				eventsList[i].setStart(e.getStart());
				eventsList[i].setEnd(e.getEnd());
				eventsList[i].setRepeatInterval(e.getRepeatInterval());
				eventsList[i].setSkips(e.getSkips());
			}
		}
		Database data("calendar.db");
		data.editSingleEvent(e);
		data.close();
	}

	void EventManager::editToDo(ToDo& e) {
		int id = e.getId();
		for (int i = 0; i < toDoList.size(); i++) {
			if (id == toDoList[i].getId()) {
				toDoList[i].setID(e.getId());
				toDoList[i].setStart(e.getStart());
				toDoList[i].setEnd(e.getEnd());
			}
		}
		Database data("calendar.db");
		data.editTodo(e);
		data.close();
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

	//void getState() {
	//	//In calender mode
	//}

	vector<Event> EventManager::getInterval(time_t start, time_t finish) {
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
			if(type.compare(Events[i].getType()) == 0) {
				temp.push_back(Events[i]);
	      }
		}		
		data.close();
		eventsList = temp;
		return eventsList;
	}

	vector<Event> EventManager::getEventsList() {
		return eventsList;
	}

	//scheduling events, 2 lists, all events in the calender(events and todos that are scheduled, and a list of unscheduled todos.
	//scheulde unscheduled ToDos ^
	//add accessor for the event list for the gui.
	//fix iterators.
	//start up method,get everything for starting up.