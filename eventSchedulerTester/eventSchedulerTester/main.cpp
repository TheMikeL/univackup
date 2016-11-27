#include "eventScheduler.h"
#include "CalendarItems.h"
#include "timeFunctions.h"
#include <iostream>
using namespace std;

int main() {
	vector<CalendarItem*> calendarEvents;
	vector<CalendarItem> originalEvents;
	for (int i = 0; i < 10; i++) {
		int hour = 3600;
		int minute = 60;
		int start = hour * 10;
		int next = i * hour * 2;
		originalEvents.push_back(Event(0, "event" + to_string(i) + "Name", "event" + to_string(i) + "Summary",
			start + next, start + next + hour, 0, 0, "event" + to_string(i) + "Type",
			"event" + to_string(i) + "Location", 0, vector<int>()));
	}
	for (int i = 0; i < 10; i++) {
		calendarEvents.push_back(&(originalEvents[i]));
	}

	vector<ToDo> originalTodos;
	vector<ToDo*> todos;
	originalTodos.push_back(ToDo(0, "todo1name", "todo1summary", 200000, 201000, "todo1type", 1000000, 1000, 0, true, false));
	originalTodos.push_back(ToDo(0, "todo2name", "todo2summary", 205000, 205500, "todo2type", 1000000, 500, 0, true, true));
	calendarEvents.push_back(&(originalTodos[0]));
	calendarEvents.push_back(&(originalTodos[1]));

	// Testing eventsToTimes
	cout << endl <<  "Testing eventsToTimes" << endl;
	vector<tuple<time_t, time_t>> calendarTimes = eventsToTimes(calendarEvents);
	cout << "Calendar Event times:" << endl;
	for (int i = 0; i < calendarTimes.size(); i++) {
		cout << get<0>(calendarTimes[i]) << " - " << get<1>(calendarTimes[i]) << endl;
	}

	// Testing Constructor
	cout << endl << "Testing Constructor" << endl;
    int snapLevel = 30;
	EventScheduler eventScheduler(make_tuple(0, 300000), calendarEvents, todos, snapLevel);

	// Testing getFreeTime
	cout << endl << "Testing getFreeTime" << endl;
	cout << "Free time from EventScheduler object:" << endl;
	vector<tuple<time_t, time_t>> esFreeTime = eventScheduler.getFreeTime();
	for (int i = 0; i < esFreeTime.size(); i++) {
		cout << get<0>(esFreeTime[i]) << " - " << get<1>(esFreeTime[i]) << endl;
	}

	// Testing stripUnpinnedTodos
	cout << endl <<  "Testing stripUnpinnedTodos" << endl;
	cout << "ToDo list:" << endl;
	for (int i = 0; i < todos.size(); i++) {
		cout << (*todos[i]) << endl;
	}
	//stripUnpinnedToDos(calendarEvents, todos);
	eventScheduler.stripUnpinnedToDos();
	cout << "ToDo list after strip:" << endl;
	for (int i = 0; i < todos.size(); i++) {
		cout << (*todos[i]) << endl;
	}
	cout << "Events after strip:" << endl;
	calendarTimes = eventsToTimes(eventScheduler.getCalendar());
	for (int i = 0; i < calendarTimes.size(); i++) {
		cout << get<0>(calendarTimes[i]) << " - " << get<1>(calendarTimes[i]) << endl;
	}

	// Testing snapForwards
	cout << endl << "Testing snapForwards" << endl;
	time_t time = 1520;
	cout << "snapForwards from time: " << time << " with snapLevel " << snapLevel << ": " << snapForwards(time, snapLevel) << endl;

	// Testing snapBackwards
	cout << endl << "Testing snapBackwards" << endl;
	cout << "snapBackwards from time: " << time << " with snapLevel " << snapLevel << ": " << snapBackwards(time, snapLevel) << endl;

	// Testing combineIntervals
	cout << endl << "Testing combineIntervals" << endl;
	vector<tuple<time_t, time_t>> times;
	times.push_back(make_tuple(0, 1000));
	times.push_back(make_tuple(500, 1100));
	times.push_back(make_tuple(1100, 1500));
	times.push_back(make_tuple(1600, 2000));
	times.push_back(make_tuple(1700, 1900));
	times.push_back(make_tuple(2500, 3000));
	times.push_back(make_tuple(2600, 3000));
	vector<tuple<time_t, time_t>> combinedTimes = combineIntervals(times, 1);
	cout << "Old intervals:" << endl;
	for (int i = 0; i < times.size(); i++) {
		cout << get<0>(times[i]) << " - " << get<1>(times[i]) << endl;
	}
	cout << "New intervals with snap level 1:" << endl;
	for (int i = 0; i < combinedTimes.size(); i++) {
		cout << get<0>(combinedTimes[i]) << " - " << get<1>(combinedTimes[i]) << endl;
	}
	combinedTimes = combineIntervals(times, snapLevel);
	cout << "New intervals with snap level " << snapLevel << ":" << endl;
	for (int i = 0; i < combinedTimes.size(); i++) {
		cout << get<0>(combinedTimes[i]) << " - " << get<1>(combinedTimes[i]) << endl;
	}

	// Testing findFreeTime
	cout << endl << "Testing findFreeTime" << endl;
	vector<tuple<time_t, time_t>> freeTimes = findFreeTime(combinedTimes, 0, 5000);
	cout << "Free time between combined intervals:" << endl;
	for (int i = 0; i < freeTimes.size(); i++) {
		cout << get<0>(freeTimes[i]) << " - " << get<1>(freeTimes[i]) << endl;
	}

	// Testing permutations
	vector<vector<int>> permutationsResult = permutations(3);
	for (int i = 0; i < permutationsResult.size(); i++) {
		for (int j = 0; j < permutationsResult[i].size(); j++) {
			cout << permutationsResult[i][j] << " ";
		}
		cout << endl;
	}

	// Testing scheduleToDos
	vector<ToDo*> newTodos;
	ToDo newTodo1 = ToDo(0, "name1", "summary1", 0, 0, "type1", 72000, 3600, 1, false, false);
	ToDo newTodo2 = ToDo(1, "name2", "summary2", 0, 0, "type2", 72000, 7200, 2, false, false);
	ToDo newTodo3 = ToDo(2, "name3", "summary3", 0, 0, "type3", 72000, 3600, 3, false, false);
	newTodos.push_back(&newTodo1);
	newTodos.push_back(&newTodo2);
	newTodos.push_back(&newTodo3);
	Event newEvent1 = Event(0, "event1", "summary1", 0, 3700, 0, 0, "type1", "location1", 0, vector<int>());
	Event newEvent2 = Event(1, "event2", "summary2", 7200, 10800, 0, 0, "type2", "location2", 0, vector<int>());
	Event newEvent3 = Event(2, "event3", "summary3", 18000, 21600, 0, 0, "type2", "location2", 0, vector<int>());
	vector<CalendarItem*> newCalendar;
	newCalendar.push_back(&newEvent1);
	newCalendar.push_back(&newEvent2);
	newCalendar.push_back(&newEvent3);
	EventScheduler newEventScheduler(make_tuple(0, 33000), newCalendar, newTodos, 30);
	vector<tuple<time_t, time_t>> newFreeTime = vector<tuple<time_t, time_t>>(newEventScheduler.getFreeTime());
	cout << "Free time intervals:" << endl;
	for (int i = 0; i < newFreeTime.size(); i++) {
		cout << get<0>(newFreeTime[i]) << "-" << get<1>(newFreeTime[i]) << endl;
	}
	newEventScheduler.scheduleToDos(0);
	cout << "New schedule after scheduling todos:" << endl;
	vector<CalendarItem*> resultCalendar = newEventScheduler.getCalendar();
	for (int i = 0; i < resultCalendar.size(); i++) {
		cout << (*resultCalendar[i]).getName() << ": " << (*resultCalendar[i]).getStart() << "-" << (*resultCalendar[i]).getEnd() << endl;
	}
	cout << "New todos after scheduling todos:" << endl;
	vector<ToDo*> resultTodos = newEventScheduler.getToDoList();
	for (int i = 0; i < resultTodos.size(); i++) {
		cout << (*resultTodos[i]) << endl;
	}

	cout << "FOR PAUSING" << endl;
	return 0;
}
