#pragma once

/*
* The best way to use pie chart would be to have it update whenever a user adds an event to the calendar, changing one of the
* four categories which are shown on the pie chart breakdown:
* - free time
* - sleep time
* - event time
* - to-do time
* so upon updating the calendar, the pie chart analysis would be called, updating the information
*
* The event manager will handle the request by sending the PieChart the required information,
*/
#include <vector>
#include <time.h>

#include "CalendarItems.h"



using namespace std;

class PieChartAnalysis {
public:
	PieChartAnalysis(const vector<CalendarItem*>&);		// Passed the masterList of calendar items and  sleep time
	double getSleepSlice() const;
	double getToDoSlice() const;
	double getEventSlice() const;
	double getFreeTimeSlice() const;

private:
	const double TIME_IN_WEEKS = 1209600;						// seconds in a week
	double sleepSlice;
	double toDoSlice;
	double eventSlice;
	double freeTimeSlice;

};
