#pragma once
#include "CalendarItems.h"
#include <vector>
#include "sqlite3.h"

//Creates a database that can be queried for events and todos
class Database
{
public:
	//Initializes the database
	Database(char* fileName); 
	~Database(){}
	
	//add, delete, or edit events in the events table
	void addEvent(const Event& event)const; 
	void deleteAllEvent(const int& id)const;
	void deleteSingleEvent(Event& event)const;
	void editAllEvent(Event event)const ; 
	void editSingleEvent(Event event)const;

	//add,delete, or edit ToDos in the todos table
	void addTodo(const ToDo& todo)const; 
	void deleteTodo(const int& id)const; 
	void editTodo(const ToDo& todo)const; 

	vector<Event> getAllEvents() const;
	vector <Event> getIntervalEvents(time_t start, time_t end)const;

	vector <ToDo> getAllTodos() const;
	vector <ToDo> getScheduledTodos(time_t start, time_t end)const;
	vector <ToDo> getUnscheduledTodos(time_t start,time_t end)const;

	int getLastRowID()const;
	
	void close();
private:
	//Executes a query in the event and ToDo tables
	vector <Event> queryEvents(const string& query)const; 
	vector <ToDo> queryTodos(const string& query)const;

	//Checks if an event is skipped
	bool isSkipped(const Event& event) const;

	//Converts a row to an Event or ToDo object
	Event rowToEvent(sqlite3_stmt& stmt) const; 
	ToDo rowToTodo(sqlite3_stmt& stmt) const;

	//Create the SQL string for adding an event or todo
	string prepareAddEvent(const Event& event)const ;
	string prepareAddTodo(const ToDo& todo) const;
	
	sqlite3 *db;
	
};

/* Throws an exception when the file cannot be opened */
class DatabaseException {

public:
	DatabaseException(const string& message);
	string& what();

private:
	string message;
};