/* 
 * Database.cpp
 * Author: Matan Feldberg
 * Version 1.0.0
 */
#include "database.h"
#include <vector>
#include <string>
#include <iostream>
#include "CalendarItems.h"
#include <sstream>
#include <algorithm>

Database::Database(char* filename)
{
	//Open the database connection
	int rc = sqlite3_open_v2(filename, &db, SQLITE_OPEN_READWRITE, NULL);
	if (rc) {
		throw DatabaseException("SQL ERROR, CANT OPEN DATABASE");
		sqlite3_close(db);
	}

}
vector <int> stringToIntArr(string str) {
	std::istringstream stream (str);
	vector<int> values = {};
	int n;
	//Return an integer array from a string of integers seperated by spaces
	while (stream >> n) {
			values.push_back(n);
	}
	return values;
}

string intArrToString(vector<int> vec) {
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

bool Database::isSkipped(const Event& event)const{
	vector <int> skips = event.getSkips();
	//If event is skipped
	if (std::find(skips.begin(), skips.end(), event.getNumber() )!= skips.end()) {
		return true;
	}
	
	return false;
}
Event Database::rowToEvent(sqlite3_stmt& ppStmt) const {
	//Performs all variable assignments from a row of results
	int ID = sqlite3_column_int(&ppStmt, 0);
	string name = (char*)sqlite3_column_text(&ppStmt, 1);
	string summary = (char*)sqlite3_column_text(&ppStmt, 2);
	int start = sqlite3_column_int(&ppStmt, 3);
	int end = sqlite3_column_int(&ppStmt, 4);
	int repeatInterval = sqlite3_column_int(&ppStmt, 5);
	int numRepeats = sqlite3_column_int(&ppStmt, 6);
	string type = (char*)sqlite3_column_text(&ppStmt, 7);
	string location = (char*)sqlite3_column_text(&ppStmt, 8);
	string skipString = (char*)sqlite3_column_text(&ppStmt, 9);
	vector<int> skip = stringToIntArr(skipString);
	int number = sqlite3_column_int(&ppStmt, 10);
	//Create the event
	Event event = Event(ID, name, summary, start, end, repeatInterval,
		numRepeats, type, location, number, skip);
	return event;
}
	

vector <Event> Database::queryEvents(const string& query)const {
	//Executes a given query on the events table
	sqlite3_stmt *ppStmt;
	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &ppStmt, 0);

	//If query not executed succesfully
	if (ppStmt == NULL) {
		rc = sqlite3_step(ppStmt);
		throw DatabaseException("SQL ERROR " + rc);
	}
	rc = sqlite3_step(ppStmt);
	vector  <Event> eventList;
	//Add all non-skipped events to the events list
	int i = 0;
	while (rc == SQLITE_ROW) {
		Event event = rowToEvent(*ppStmt);
		if (!isSkipped(event)) {
			eventList.push_back(event);
		}
		rc = sqlite3_step(ppStmt);
		
	}
	sqlite3_finalize(ppStmt);
	return eventList;
}

vector <Event> Database::getIntervalEvents(time_t start, time_t end)const{
	//Return all events in a given interval
	std::ostringstream all;
	all<< "select e.ID, e.Name, e.Summary, (e.Start_Time+e.Repeat_Interval*n.Number) as Start_Time,(e.End_Time+e.Repeat_Interval*n.Number) as End_Time, e.Repeat_Interval, e.Num_Repeats,e.Type,e.Location , e.Skips, n.Number from events e  cross join numbers n where (Start_Time>= " << start <<" OR End_Time> " << start << ") and " << "Start_Time <= " << end << " and " << "(n.Number<=e.Num_Repeats) order by Start_Time asc" << " ;";
	string sql = all.str();
	vector <Event> eventList = queryEvents(sql);
	return eventList;
}


vector <Event> Database::getAllEvents() const{
	string all = "select e.ID, e.Name, e.Summary, (e.Start_Time+e.Repeat_Interval*n.Number) as Start_Time,(e.End_Time+e.Repeat_Interval*n.Number) as End_Time, e.Repeat_Interval, e.Num_Repeats,e.Type,e.Location , e.Skips, n.Number from events e cross join numbers n where (e.Start_Time+n.Number*e.Repeat_Interval) <= (e.Start_Time+e.Repeat_Interval*e.Num_Repeats) order by Start_Time asc;";
	vector <Event> eventList = queryEvents(all);
	return eventList;
}


string Database::prepareAddEvent(const Event& event)const {
	std::ostringstream buffer;
	buffer << "insert into events values (null, " <<
		event.getName() << "," << event.getSummary() << "," << event.getStart()
		<< "," << event.getEnd() << "," << event.getRepeatInterval() << "," <<
		event.getNumRepeats() << "," << event.getType() << "," << event.getLocation() << "," << intArrToString(event.getSkips()) << ");";
	return buffer.str();
}

string Database::prepareAddTodo(const ToDo& todo)const {
	std::ostringstream buffer;
	buffer << "insert into ToDos values (null, " <<
		todo.getName() << "," << todo.getSummary() << "," << todo.getStart()
		<< "," << todo.getEnd() << "," << todo.getType() << "," 
		<< todo.getViableEnd() << "," << todo.getEstimatedTime()
		<< "," <<todo.getWeight() << "," << todo.getScheduled() << "," << todo.getPinned() <<");";

	return buffer.str();
}
void Database::addEvent(const Event& event)const {
	string sql = prepareAddEvent(event);
	int rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT ADD EVENT");
	}
}

void Database::editAllEvent(Event event)const {
std::ostringstream sql;
	sql << "update events set name=" << event.getName() << ", summary=" <<event.getSummary() <<
		", start_time=" << event.getStart() << ", end_time=" << event.getEnd() <<", repeat_Interval=" <<event.getRepeatInterval() <<
		", num_Repeats=" <<event.getNumRepeats() << ", type="<< event.getType() << ", location="<<event.getLocation() <<
		",skips=" << intArrToString(event.getSkips())
		<< "where ID= " << event.getId() << ";";
	
	
	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT EDIT EVENTS");
	}
}

void Database::editSingleEvent(Event event) const{
	event.addSkips(event.getNumber());
	std::ostringstream sql;
	sql << "update events set skips=" << intArrToString(event.getSkips())
		<< "where ID= " << event.getId() << ";";
	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT EDIT EVENT");
	}
	Event event2 = event;
	event2.setID(1);
	event2.setNumRepeats(0);
	event2.setRepeatInterval(0);
	event2.setSkips({});
	addEvent(event2);
	

}

void Database::deleteAllEvent(const int& id)const {
	std::ostringstream sql;
	sql << "delete from events where id=" << id << ";";
	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT DELETE EVENTS");
	}

}

void Database::deleteSingleEvent(Event& event) const{
	event.addSkips(event.getNumber());
	std::ostringstream sql;
	sql << "update events set skips=" << intArrToString(event.getSkips()) <<
		 " where ID= " << event.getId() << ";";
	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT DELETE EVENT");
	}
	
}

ToDo Database::rowToTodo(sqlite3_stmt& ppStmt)const {
	
	int ID = sqlite3_column_int(&ppStmt, 0);
	string name = (char*)sqlite3_column_text(&ppStmt, 1);
	string summary = (char*)sqlite3_column_text(&ppStmt, 2);
	int start = sqlite3_column_int(&ppStmt, 3);
	int end = sqlite3_column_int(&ppStmt, 4);
	string type = (char*)sqlite3_column_text(&ppStmt, 5);
	int viableEnd = sqlite3_column_int(&ppStmt, 6);
	int estimatedTime = sqlite3_column_int(&ppStmt, 7);
	int weight = sqlite3_column_int(&ppStmt, 8);
	bool scheduled = (bool)sqlite3_column_int(&ppStmt, 9);
	bool pinned = sqlite3_column_int(&ppStmt, 10);
	//Create the event
	ToDo todo = ToDo(ID, name, summary, start, end, type,
		viableEnd, estimatedTime, weight, scheduled, pinned);
	return todo;
}

vector <ToDo> Database::queryTodos(const string& query)const {
	//Executes a given query on the todos table
	sqlite3_stmt *ppStmt;
	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &ppStmt, 0);

	//If query not executed succesfully
	if (ppStmt == NULL) {
		rc = sqlite3_step(ppStmt);
		throw DatabaseException("SQL ERROR " + rc);
		
	}
	rc = sqlite3_step(ppStmt);
	vector  <ToDo> todoList;
	int i = 0;
	while (rc == SQLITE_ROW) {
		ToDo todo = rowToTodo(*ppStmt);
		todoList.push_back(todo);
		rc = sqlite3_step(ppStmt);
	}
	sqlite3_finalize(ppStmt);
	return todoList;
}

void Database::addTodo(const ToDo& todo) const{
	string sql = prepareAddTodo(todo);
	int rc = sqlite3_exec(db, sql.c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT ADD TODO");
	}
}

vector <ToDo> Database::getAllTodos() const{
	string all = "select * from todos t order by t.start_time asc;";
	vector <ToDo> todos=queryTodos(all);

	return todos;

}

vector<ToDo> Database::getScheduledTodos(time_t start, time_t end)const {
	std::ostringstream sql;
	sql << "select * from todos t where (t.start_time>=" << start << " and t.start_time< " << end
		<< ") OR (t.end_time> " << start << " and t.end_time< " << end << ") and t.scheduled=1 order by t.start_time asc;";
	
	vector <ToDo> interval = queryTodos(sql.str());
	return interval;
}


vector <ToDo> Database::getUnscheduledTodos(time_t start, time_t end) const{
	std::ostringstream sql;
	sql << "select * from todos t where t.viable_End>=" << start << " and t.viable_end<= " << end << " and t.scheduled=0 order by t.viable_end asc;";
	vector <ToDo> unscheduled = queryTodos(sql.str());
	return unscheduled;
}

void Database::deleteTodo(const int& id) const{
	std::ostringstream sql;
	sql << "delete from todos where id=" << id << ";";
	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT DELETE EVENT");
	}
}

void Database::editTodo(const ToDo& todo)const {
	std::ostringstream sql;
	sql << "update todos set name=" << todo.getName() << ", summary=" << todo.getSummary() <<
		", start_time=" << todo.getStart() << ", end_time=" << todo.getEnd() << 
		", type=" << todo.getType() << ", viable_end=" << todo.getViableEnd() << 
		",estimated_time= " << todo.getEstimatedTime() <<
		", weight=" << todo.getWeight() <<", scheduled=" << todo.getScheduled() << ", pinned= " << 
		todo.getPinned() << " "
		<< "where ID= " << todo.getId() << ";";


	int rc = sqlite3_exec(db, sql.str().c_str(), 0, 0, 0);
	if (rc != SQLITE_OK) {
		throw DatabaseException("SQL ERROR, COULD NOT EDIT EVENTS");
	}

}
void Database::close() {
	sqlite3_close(db);
}

int Database::getLastRowID()const {
	return sqlite3_last_insert_rowid(db);

}
DatabaseException::DatabaseException(const string& message) : message(message) {}
string& DatabaseException::what() { return message; }