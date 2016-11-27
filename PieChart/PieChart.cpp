// PieChart.cpp : Defines the entry point for the console application.
//



/*
* testPie.cpp
*
*  Created on: Nov 21, 2016
*      Author: Curtis
*/

#include "stdafx.h"
#include <vector>
#include <time.h>
#include <tuple>
#include <ctime>
#include <sstream>
#include <iostream>

#include "PieChartAnalysis.h"
#include "CalendarItems.h"

using namespace std;

int main() {

	vector<CalendarItem*> calendarEvents;
	calendarEvents.push_back(new Event(0, "event1", "summary1", 1000, 1500, 0, 0, "Sleep", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event2", "summary2", 2000, 2500, 0, 0, "type2", "location2", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event3", "summary3", 3000, 3500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event4", "summary4", 4000, 4500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event5", "summary5", 5000, 5500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event6", "summary6", 6000, 6500, 0, 0, "Sleep", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event7", "summary7", 7000, 7500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event8", "summary8", 8000, 8500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event9", "summary9", 9000, 9500, 0, 0, "type1", "location1", 0, vector<int>()));
	calendarEvents.push_back(new Event(0, "event10", "summary10", 10000, 10500, 0, 0, "type1", "location1", 0, vector<int>()));
	
	
	calendarEvents.push_back(new ToDo(0, "event1", "summary1", 1000, 1500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event2", "summary2", 2000, 2500, "type2", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event3", "summary3", 3000, 3500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event4", "summary4", 4000, 4500, "type1", 0, 0, 0, 0, false, false));
	calendarEvents.push_back(new ToDo(0, "event5", "summary5", 5000, 5500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event6", "summary6", 6000, 6500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event7", "summary7", 7000, 7500, "type1", 0, 0, 0, 0, false, false));
	calendarEvents.push_back(new ToDo(0, "event8", "summary8", 8000, 8500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event9", "summary9", 9000, 9500, "type1", 0, 0, 0, 0, true, false));
	calendarEvents.push_back(new ToDo(0, "event10", "summary10", 10000, 10500, "type1", 0, 0, 0, 0, true, false));


	PieChartAnalysis pca = PieChartAnalysis(calendarEvents);
	cout << pca.getEventSlice() << endl;
	cout << pca.getToDoSlice() << endl;
	cout << pca.getSleepSlice() << endl;
	cout << pca.getFreeTimeSlice() << endl;

	return 0;
}
