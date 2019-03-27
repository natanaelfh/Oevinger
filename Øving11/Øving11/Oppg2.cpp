#include "Oppg2.h"

void insertOrdered(list<Person> &l,Person& p) {
	//if empty


	for (list<Person>::iterator it = l.begin(); it != l.end(); ++it) {
		Person ref = *it;
		string refFirst = ref.getFirstName();
		string refLast = ref.getLastName();
		string pFirst = p.getFirstName();
		string pLast = p.getLastName();

		if (pFirst <= refFirst) {
			if (pLast <= refLast) {
				//plassen før og return
				l.insert(it, p);
				return;
			}
			else {
				// plassen etter og return
				l.insert(it++, p);
				return;
			}
		}

	}

	l.insert(l.end(), p);
}