#pragma once
#include "event.h"
#include <vector>
#include <string>

vector<Event> addEvent(vector<Event> events, Event e);

vector<Event> deleteEvent(vector<Event> events, const string& name);

Event* getEvent(vector<Event>* events, const string& name);
