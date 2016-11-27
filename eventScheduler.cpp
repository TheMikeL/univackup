#include "eventScheduler.h"

EventScheduler::EventScheduler(const tuple<time_t, time_t>& daysToDo,
  vector<CalendarItem>& calendarItems, vector<Todo>& todos, int snapLevel) {
    
}

tuple<time_t, time_t> EventScheduler::nextFreePeriod(const time_t& start,
  const int& size) const {

}

tuple<time_t, time_t> EventScheduler::lastFreePeriod(const time_t& start,
  const int& size) const {

}

vector<tuple<time_t, time_t>> EventScheduler::getFreeTime() const {

}

void scheduleTodos(vector<ToDo>& toDoList) {

}
