#pragma once
#include "event.h"
#include <vector>
#include <tuple>
#include <ctime>
using namespace std;

class EventScheduler {
public:
  /* Constructor. Takes in daysToDo and a list of Events from EventManager.
     SnapLevel is either 15, 30, or 60 minute normalized times.
  */
  EventScheduler(const tuple<time_t, time_t>& daysToDo,
    vector<CalendarItem>& calendarItems, vector<Todo>& todos, int snapLevel);
  /* This is the meatiest function. It schedules a vector of todos into the
     calendar at the 'best' times. This vector of todos will usually be all
     unscheduled todos.

     'Best' can be considered, for now, as spreading the work as evenly as
     possible through the free time currently available.

     Any todo that isn't pinned gets rescheduled by algorithm.
  */
  void scheduleToDos();
private:
  /* This is the start and end time to be considered when indicating free time
  */
  const tuple<time_t, time_t> daysToDo;
  vector<CalendarItem> calendarItems;
  // Storing this means it only has to be calculated whenever times are changed
  vector<tuple<time_t, time_t>> freeTime;
  int snapLevel;
  /* Function returns the first start and end datetime of specified size that
     is free earliest after specified time.
  */
  tuple<time_t, time_t> nextFreePeriod(const time_t& start, const int& size) const;
  /* Function returns a start and end datetime of specified time that is free
     latest after specified time.
  */
  tuple<time_t, time_t> lastFreePeriod(const time_t& start, const int& size) const;
  /* Helper function to change times to match snapLevel
  */
  void normalizeTime();
  /* Helper function to clean up overlapping intervals
  */
  void combineIntervals();
  /* Returns all the free time intervals available.
  */
  vector<tuple<time_t, time_t>> getFreeTime() const;
}
