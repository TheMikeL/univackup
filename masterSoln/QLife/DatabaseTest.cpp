// QLife.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sqlite3.h"
#include "database.h"
#include <iostream>
#include "CalendarItems.h"
#include <sstream>
#include "EventManager.h"

/*vector <int> stringToIntArrs(string str) {
	std::istringstream stream(str);
	vector<int> values = {};
	int n;
	//Return an integer array from a string of integers seperated by spaces
	while (stream >> n) {
		values.push_back(n);
	}
	return values;
}

string intArrToStrings(vector<int> vec) {
	std::ostringstream str;
	unsigned int i = 0;
	if (vec.size() == 0) {
		str << "''";
		return str.str();
	}
	str << "'";
	for (i; i < vec.size(); i++) {

		str << vec[i] << " ";
	}
	str << "'";
	return str.str();
}

////select e.ID, e.Name, e.Summary, (e.Start_Time+e.Repeat_Interval*n.Number) as Start_Time,(e.End_Time+e.Repeat_Interval*n.Number) as End_Time, e.Repeat_Interval, e.Num_Repeats,e.Type,e.Location , n.Number from events e cross join numbers n where (e.Start_Time+n.Number*e.Repeat_Interval) <= (e.Start_Time+e.Repeat_Interval*e.Num_Repeats);
int main(int argc, char **argv)
{
	

	Database data("Calendar.db");

	/*Test Interval/all events*/
	//vector <Event> allEvents = data.getIntervalEvents(1479729800,1482766200 );
	//vector <Event> allEvents = data.getAllEvents();
	//int i = 0;
	/*for (i = 0; i < allEvents.size(); i++) {
		cout << allEvents[i];
		cout << intArrToStrings(allEvents[i].getSkips())<<endl;
	}*/
		
	/*Add event, edit event, delete #2 or delete all*/
	//Event ev1 = Event(NULL, "'CISC320'", "'Mcleod'", 1479745800, 1480350600, 604800, 3, "'Class'", "'Stirling Hall C'", 2, {});
	
	//cout << intArrToStrings({ 1,2,3})<<endl;
	/*vector <int> numSkips =stringToIntArrs("1 2 4");
	for (i = 0; i < numSkips.size(); i++) {
		cout << numSkips[i];
	}
	cout << endl; */


	//data.addEvent(ev1);
	//cout << data.getLastRowID();
	//ev1 = Event(3, "'CISC321'", "'Mcleody'", 1479845800, 1480350600, 604800, 2, "'Class'", "'Stirling Hall E'", 1, {2});
	//data.editAllEvent(ev1);
	//data.editSingleEvent(ev1);
	//data.deleteSingleEvent(ev1);
	//data.deleteAllEvent(ev1.getId());	
	
	//cout << "----------------TODOS----------------" <<endl;
	/* Add todos*/
	/*ToDo td1 = ToDo(1, "'brush teeth'", "'gotta get my teeth white'", 1479717000, 1479717120, "'personal'", 1479717120, 120, 90, true, false);
	ToDo td2 = ToDo(1, "'do something crazy'", "'gotta live'", 0, 0, "'personal'", 1479817120, 1000, 30, false, false);
	ToDo td3 = ToDo(1, "'do a flip'", "'gymnastics'", 0, 0, "'fun'",  1485817120, 1900, 40, false, false);
	ToDo td4 = ToDo(1, "'bingul'", "'bagel'", 0, 0, "'food'", 1495817120, 3900, 50, false, false);
	
	data.addTodo(td1);
	data.addTodo(td2);
	data.addTodo(td3);
	data.addTodo(td4); */

	/*Edit a todo*/
	//td2 = ToDo(2, "'do something less crazy'", "'gotta be livin'", 0, 0, "'personalz'", 1479727000, 1479817120, 1000, 30, false, false);
	//data.editTodo(td2);
	//data.deleteTodo(1);
	//int i;
	//vector <ToDo> allTodos = data.getScheduledTodos (147917000, 1495817120);
	/*for (i = 0; i < allTodos.size(); i++) {
		cout << allTodos[i] << endl;
	}
	
	data.close(); 
	return 0;
}*/