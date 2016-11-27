/*
* PieChart.cpp
*
*  Created on: Nov 16, 2016
*      Author: Curtis
*/
#include "stdafx.h"

#include <vector>
#include <time.h>

#include "PieChartAnalysis.h"
#include "CalendarItems.h"


using namespace std;

PieChartAnalysis::PieChartAnalysis(const vector<CalendarItem*>& masterList) {
	double toDoTime = 0;
	double eventTime = 0;
	double sleep = 0;
	double freeTimeTime = 0;


	for (CalendarItem* ci : masterList) {
		if (dynamic_cast<Event*>(ci) == nullptr) {
			ToDo* todo = dynamic_cast<ToDo*>(ci);
			if (todo->getScheduled())
				toDoTime += difftime(ci->getEnd(), ci->getStart());					// it's a to-do
		}
		else {
			if (ci->getType() == "Sleep")
				sleep += difftime(ci->getEnd(), ci->getStart());
			else
				eventTime += difftime(ci->getEnd(), ci->getStart());					// it's an event
		}
	}



	freeTimeTime = TIME_IN_WEEKS - toDoTime - eventTime - sleep;

	sleepSlice = sleep / TIME_IN_WEEKS;
	toDoSlice = toDoTime / TIME_IN_WEEKS;
	eventSlice = eventTime / TIME_IN_WEEKS;
	freeTimeSlice = freeTimeTime / TIME_IN_WEEKS;
}

double PieChartAnalysis::getSleepSlice() const {
	return sleepSlice;
}
double PieChartAnalysis::getToDoSlice() const {
	return toDoSlice;
}
double PieChartAnalysis::getEventSlice() const {
	return eventSlice;
}
double PieChartAnalysis::getFreeTimeSlice() const {
	return freeTimeSlice;
}
