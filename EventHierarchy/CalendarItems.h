/*
 * Events.h
 *
 *  Created on: Nov 3, 2016
 *      
 */

#include <string>
#include <vector>
#pragma once

using namespace std;

/* Implements a Calendar Item Object
*/
class CalendarItem {
public:

	CalendarItem(int id, string name, string summary, time_t start, time_t end, string type);
	virtual ~CalendarItem();
	
	string getName() const;
	string getSummary() const;
	time_t getStart() const;
	time_t getEnd() const;
	string getType() const;
	int getId() const;
	void setName(string name);
	void setSummary(string summary);
	void setStart(time_t start);
	void setType(string type);
	void setEnd(time_t end);
	void setID(int id);



private:
	string name;
	string summary;
	time_t start;
	time_t end;
	string type;
	int id;
};

class Event : public CalendarItem{ 
public:
	Event(int id, string name, string summary, time_t start, time_t end, int repeatInterval, int numRepeats, string type, string location, int number, vector <int> skip);
	string getLocation() const;
	int getRepeatInterval() const;
	int getNumRepeats() const;
	int getNumber() const;
	vector <int> getSkips() const;
	void addSkips(int skips);

	void setNumber(int num);
	void setLocation(string location);
	void setSkips(vector <int> skip);
	void setNumRepeats(int numRepeat); 
	void setRepeatInterval(int repeatInterval);

private:
	int repeatInterval;
	int numRepeats;
	string location;
	int number;
	vector <int> skip;
	
};

class ToDo : public CalendarItem {
public:
	ToDo(int id, string name, string summary, time_t start, time_t end, string type, 
		time_t viableEnd, int estimatedTime, int weight, bool scheduled, bool pinned);
	int getEstimatedTime() const;
	time_t getViableEnd() const;
	int getWeight() const;
	bool getScheduled() const;
	bool getPinned() const;
	void setEstimatedTime(int estimatedTime);
	void setViableEnd(time_t viableEnd);
	void setWeight(int weight);
	void setScheduled(bool scheduled);
	void setPinned(bool pinned);

	int getNumber() const;

private:
	int estimatedTime;
	time_t viableEnd;
	int weight;
	bool scheduled;
	bool pinned;

};
ostream& operator<<(ostream& out, const Event& event);
ostream& operator<<(ostream& out, const ToDo& event);