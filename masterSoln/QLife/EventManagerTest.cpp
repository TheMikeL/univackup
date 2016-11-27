#include "stdafx.h"
#include "sqlite3.h"
#include "database.h"
#include <iostream>
#include "CalendarItems.h"
#include <sstream>
#include "EventManager.h"




int main(int argc, char **argv)
{


EventManager em(1479727800, 1489845801);

Event ev1 = Event(5, "'CISC328'", "'ApWJizzard'", 1479929800, 1481727800, 604800, 2, "'Class'", "'Stirling Hall D'", 1, {});
Event ev2 = Event(6, "'CISC327'", "'Bagel'", 1479939800, 1481727800, 604600, 1, "'Class'", "'Stirling Hall E'", 0, {});
Event ev3 = Event(5, "'CISC329'", "'Bagel'", 1479929900, 1481727800, 604800, 3, "'Class'", "'Stirling Hall F'", 1, {});

//em.addEvent(ev1);
//em.editAllEvent(ev3);
//em.editSingleEvent(ev1);
//em.deleteAllEvent(ev1);
//em.deleteSingleEvent(ev2);

ToDo td1 = ToDo(1, "'brush teeth'", "'gotta get my teeth white'", 1479717000, 1479717120, "'personal'", 1479717120, 120, 90, true, false);
ToDo td2 = ToDo(5, "'Be Bold'", "'gotta Jive'", 0, 0, "'persp'", 1479817120, 1000, 30, false, false);
ToDo td3 = ToDo(1, "'do a flip'", "'gymnastics'", 0, 0, "'fun'",  1485817120, 1900, 40, false, false);
ToDo td4 = ToDo(1, "'bingul'", "'bagel'", 0, 0, "'food'", 1495817120, 3900, 50, false, false);

//em.addToDo(td1);
//em.editToDo(td2);
//em.deleteToDo(td1);

vector <Event> events = em.getIntervalEvents(1479727800, 1489845801);
vector <ToDo> todos = em.getScheduledTodos(1479717000, 1480350600);
vector <CalendarItem* > lis = em.getView(1479717000, 1489845801);
int i = 0;
for (i; i < lis.size(); i++) {
	cout << lis[i]->getId() << " " << lis[i]->getName() << " " << lis[i]->getSummary()<< " " <<lis[i] ->getStart() << endl;
}

cout << " -----------------------------" << endl;

/*
for (i=0; i < todos.size(); i++) {
	cout << todos[i];
}*/
return 0;
}