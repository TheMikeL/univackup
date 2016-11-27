#pragma once
#include <string>
#include <ctime>
using namespace std;
class Event {
public:
	Event(time_t start, time_t end, string name, string summary, string location, bool pinned);
	time_t getStartTime();
	friend ostream& operator<<(ostream& os, const Event& e);
	const string& getName();
	void setStart(time_t t);
private:
	string name;
	string summary;
	time_t start;
	time_t end;
	unsigned int x;
	bool pinned;
	string location;
	float weight;
};
