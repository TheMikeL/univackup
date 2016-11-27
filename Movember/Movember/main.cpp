#include "EventManager.h"
#include <vector>
#include "CalendarItems.h"

using namespace std;
int main(int argc, char* args[]) {
	EventManager em = EventManager(1479727800, 1489845801);
	vector<CalendarItem*> list = em.getView(1479727800, 1489845801);
	for (int i = 0; i < list.size(); i++) {
		cout << list[i]->getName() << ", ";
	}
	cout << endl;
	cout << "HANG" << endl;
	return 0;
}