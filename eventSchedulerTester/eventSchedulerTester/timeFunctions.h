#pragma once
#include "CalendarItems.h"
#include <ctime>
#include <vector>
#include <tuple>
using namespace std;

/* Function returns the time that corresponds to the next snapLevel.
Eg. 7:43:32 -> 8:00:00
*/
time_t snapForwards(const time_t& time, const int& snapLevel);

/* Function returns the time that corresponds to the previous snapLevel.
Eg. 7:43:32 -> 7:30:00
*/
time_t snapBackwards(const time_t& time, const int& snapLevel);

/* Helper function to clean up overlapping intervals.
Takes in a vector of time tuples and returns a new vector of combined intervals.
*/
vector<tuple<time_t, time_t>> combineIntervals(const vector<tuple<time_t, time_t>>& times, const int& snapLevel);

/* Helper function to turn a vector of calendarEvents into a vector of time_t tuples
*/
vector<tuple<time_t, time_t>> eventsToTimes(const vector<CalendarItem*>& events);

/* Helper function to return the non-taken time between two times using a vector of taken intervals.
Expects the intervals to be sorted by the first index of each pair in ascending order and that there are no
overlaps (use combineIntervals prior)
*/
vector<tuple<time_t, time_t>> findFreeTime(const vector<tuple<time_t, time_t>>& times, const time_t& start, const time_t& end);

/* Move any unpinned todos off of the calendar and onto the ToDo list
Currently doesn't maintain any level of sorting on the list of todos.
*/
void stripUnpinnedToDos(vector<CalendarItem*>& calendarItems, vector<ToDo*>& todos);

/* Helper function to make a list of lists of indices.
*/
vector<vector<int>> permutations(const int size);
