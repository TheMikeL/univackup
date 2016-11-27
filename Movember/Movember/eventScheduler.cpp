#include "eventScheduler.h"
#include <algorithm>
#include <iostream>

EventScheduler::EventScheduler(const tuple<time_t, time_t>& daysToDo,
	vector<CalendarItem*>& calendarItems, vector<ToDo*>& todos, int snapLevel) : daysToDo(daysToDo), todos(todos), snapLevel(snapLevel), calendarItems(calendarItems) {
	// Calculate free time
	vector<tuple<time_t, time_t>> takenTimes = eventsToTimes(calendarItems);
	takenTimes = combineIntervals(takenTimes, snapLevel);
	freeTime = findFreeTime(takenTimes, get<0>(daysToDo), get<1>(daysToDo));
}

vector<tuple<time_t, time_t>> EventScheduler::getFreeTime() const {
	return freeTime;
}

void EventScheduler::scheduleToDos(int padding) {
	// First get all permutations of the existing todo list
	vector<vector<int>> permutationResult = permutations(todos.size());

	// Then try every permutation to find the one with the best end weight-scheduled score
	int bestIndex = 0;
	int bestScore = 0;
	vector<bool> bestUsed(permutationResult[0].size());
	for (int i = 0; i < permutationResult.size(); i++) {
		int score = 0;
		int freeTimeIndex = 0;
		// Make a copy of free time so we don't change it
		vector<tuple<time_t, time_t>> currentFreeTime = vector<tuple<time_t, time_t>>(freeTime);
		vector<bool> used(permutationResult[0].size());
		for (int j = 0; j < used.size(); j++) {
			used[j] = false;
		}
		for (int j = 0; j < permutationResult[i].size(); j++) {
			time_t freeTimeStart = get<0>(currentFreeTime[freeTimeIndex]);
			time_t freeTimeEnd = get<1>(currentFreeTime[freeTimeIndex]);
			time_t space = freeTimeEnd - freeTimeStart;
			time_t estimatedTime = (*todos[permutationResult[i][j]]).getEstimatedTime();
			time_t endBy = (*todos[permutationResult[i][j]]).getViableEnd();
			if (estimatedTime <= space && endBy >= freeTimeStart + estimatedTime) {
				// There's enough space and it's not too late so add it by...
				// increase score
				score += (*todos[permutationResult[i][j]]).getWeight();
				used[j] = true;
			}
			// Adjust free time
			if (freeTimeStart + estimatedTime >= freeTimeEnd) {
				freeTimeIndex += 1;
			}
			else {
				get<1>(currentFreeTime[freeTimeIndex]) = freeTimeStart + estimatedTime;
			}
		}
		if (score > bestScore) {
			bestScore = score;
			bestIndex = i;
			bestUsed = vector<bool>(used);
		}
	}

	// Schedule all todos from the best permutation that are schedulable and leave the rest in the todo list
	vector<tuple<time_t, time_t>> currentFreeTime = vector<tuple<time_t, time_t>>(freeTime);
	int freeTimeIndex = 0;
	sort(permutationResult[bestIndex].begin(), permutationResult[bestIndex].end());
	for (int i = 0; i < permutationResult[bestIndex].size(); i++) {
		time_t freeTimeStart = get<0>(currentFreeTime[freeTimeIndex]);
		time_t freeTimeEnd = get<1>(currentFreeTime[freeTimeIndex]);
		time_t space = freeTimeEnd - freeTimeStart;
		time_t estimatedTime = (*todos[permutationResult[bestIndex][i]]).getEstimatedTime();
		time_t endBy = (*todos[permutationResult[bestIndex][i]]).getViableEnd();
		if (estimatedTime <= space && endBy >= freeTimeStart + estimatedTime) {
			// There's enough space and it's not too late so add it by...
			// Add to calendar items and schedule
			calendarItems.push_back(todos[permutationResult[bestIndex][i]]);
			(*todos[permutationResult[bestIndex][i]]).setScheduled(true);
			(*todos[permutationResult[bestIndex][i]]).setStart(freeTimeStart);
			(*todos[permutationResult[bestIndex][i]]).setEnd(freeTimeStart + estimatedTime);
		}
		// Adjust free time
		if (freeTimeStart + estimatedTime >= freeTimeEnd) {
			freeTimeIndex += 1;
		}
		else {
			get<1>(currentFreeTime[freeTimeIndex]) = freeTimeStart + estimatedTime;
		}
	}

	// Delete todos
	int offset = 0;
	for (int i = 0; i < permutationResult[bestIndex].size(); i++) {
		if (bestUsed[i]) {
			todos[permutationResult[bestIndex][i] - offset] = todos.back();
			todos.pop_back();
			offset += 1;
		}
	}

	// TODO: Re-sort calendar after inserts or insert properly

	// Recalculate free time
	vector<tuple<time_t, time_t>> takenTimes = eventsToTimes(calendarItems);
	takenTimes = combineIntervals(takenTimes, snapLevel);
	freeTime = findFreeTime(takenTimes, get<0>(daysToDo), get<1>(daysToDo));
}

vector<CalendarItem*> EventScheduler::getCalendar() const {
	return calendarItems;
}

void EventScheduler::stripUnpinnedToDos() {
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

vector<ToDo*> EventScheduler::getToDoList() const {
	return todos;
}
