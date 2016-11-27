#pragma once
#include <vector>
#include <tuple>
#include <ctime>
#include "CalendarItems.h"
#include "timeFunctions.h"

using namespace std;

class EventScheduler {
public:
	/* Constructor. Takes in daysToDo and a list of Events from EventManager.
	SnapLevel is either 15, 30, or 60 minute normalized times.
	*/
	EventScheduler(const tuple<time_t, time_t>& daysToDo,
		vector<CalendarItem*>& calendarItems, vector<ToDo*>& todos, int snapLevel);

	/* This is the meatiest function. It schedules a vector of todos into the
	calendar at the 'best' times. This vector of todos will usually be all
	unscheduled todos.

	'Best' can be considered, for now, as spreading the work as evenly as
	possible through the free time currently available.

	Any todo that isn't pinned gets rescheduled by algorithm.
	*/
	void scheduleToDos(int padding);
	
	/* Returns all the free time intervals available.
	*/
	vector<tuple<time_t, time_t>> getFreeTime() const;
	
	/* Returns the calendar with all scheduled events and todos.
	*/
	vector<CalendarItem*> getCalendar() const;

	/* Remove unpinned todos from the calendar and add them to the todo list.
	*/
	void stripUnpinnedToDos();

	/* Returns the todo list with all unscheduled todos.
	*/
	vector<ToDo*> getToDoList() const;
private:
	/* This is the start and end time to be considered when indicating free time
	*/
	const tuple<time_t, time_t> daysToDo;
	vector<CalendarItem*> calendarItems;
	// Storing this means it only has to be calculated whenever times are changed
	vector<tuple<time_t, time_t>> freeTime;
	// Store the list of unscheduled ToDos
	vector<ToDo*>& todos;
	// Store the snapLevel
	int snapLevel;
	/* Returns a vector of every possible ordering of todos
	*/
};
