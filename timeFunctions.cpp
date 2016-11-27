#include "timeFunctions.h"
#include <algorithm>
#include <iostream>

time_t snapForwards(const time_t& time, const int& snapLevel) {
	time_t diff = time % snapLevel;
	if (diff == 0)
		return time;
	else
		return time + (snapLevel - diff);
}

time_t snapBackwards(const time_t& time, const int& snapLevel) {
	return time - (time % snapLevel);
}

vector<tuple<time_t, time_t>> combineIntervals(const vector<tuple<time_t, time_t>>& times, const int& snapLevel) {
	vector<tuple<time_t, time_t>> result;
	time_t start = snapBackwards(get<0>(times[0]), snapLevel);
	time_t end = snapForwards(get<1>(times[0]), snapLevel);
	result.push_back(make_tuple(start, end));
	for (int i = 1; i < times.size(); i++) {
		time_t oldEnd = snapForwards(get<1>(times[i - 1]), snapLevel);
		time_t newStart = snapBackwards(get<0>(times[i]), snapLevel);
		time_t newEnd = snapForwards(get<1>(times[i]), snapLevel);
		if (oldEnd >= newStart) {
			// Next time starts before old time ends, so they intersect
			get<1>(result[result.size() - 1]) = max(oldEnd, newEnd);
		}
		else {
			// No intersection, make a new interval
			result.push_back(make_tuple(newStart, newEnd));
		}
	}
	return result;
}

vector<tuple<time_t, time_t>> eventsToTimes(const vector<CalendarItem*>& events) {
	vector<tuple<time_t, time_t>> times;
	for (int i = 0; i < events.size(); i++) {
		time_t start = (*events[i]).getStart();
		time_t end = (*events[i]).getEnd();
		times.push_back(make_tuple(start, end));
	}
	return times;
}

vector<tuple<time_t, time_t>> findFreeTime(const vector<tuple<time_t, time_t>>& times, const time_t& start, const time_t& end) {
	vector<tuple<time_t, time_t>> result;
	time_t currentTime = start;
	int index = 0;
	while (currentTime < end && index < times.size()) {
		if (currentTime < get<0>(times[index])) {
			result.push_back(make_tuple(currentTime, min(end, get<0>(times[index]))));
		}
		currentTime = get<1>(times[index]);
		index += 1;
	}
	if (index == times.size()) {
		result.push_back(make_tuple(currentTime, end));
	}
	return result;
}

void stripUnpinnedToDos(vector<CalendarItem*>& calendarItems, vector<ToDo*>& todos) {
	unsigned int i = 0;
	while (i < calendarItems.size()) {
		ToDo* todo = dynamic_cast<ToDo*>(calendarItems[i]);
		if (todo != nullptr && !(*todo).getPinned()) {
			(*todo).setScheduled(false);
			todos.push_back(todo);
			calendarItems.erase(calendarItems.begin() + i);
		}
		else {
			i++;
		}
	}
}

vector<vector<int>> permutations(const int size) {
	vector<vector<int>> result = vector<vector<int>>();
	if (size == 0) {
	}
	else if (size == 1) {
		result.push_back({ 0 });
	}
	else {
		vector<vector<int>> recursiveResult = permutations(size - 1);
		for (int i = 0; i < recursiveResult.size(); i++) {
			for (int j = recursiveResult[i].size(); j >= 0; j--) {
				vector<int> temp = vector<int>(recursiveResult[i]);
				temp.insert(temp.begin() + j, size - 1);
				result.push_back(temp);
			}
		}
	}
	return result;
	// 012 021 102 120 201 210
}
