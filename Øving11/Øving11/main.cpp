
#include "oppg1.h"
#include "Person.h"
#include "Oppg2.h"
#include "LinkedList.h"
#include <iostream>
#include <list>
#include "oppg4.h"
#include <string>
using namespace std;

int main(){

	// Your code here
	std::vector<std::string>strings{"Consectetur", "Amet", "Sit", "Dolor", "Ipsum", "Lorem"};

	for (std::vector<std::string>::reverse_iterator i = strings.rbegin(); i != strings.rend(); i++) {
		std::cout << *i << endl;
	}
	for (vector<string>::iterator i = strings.begin(); i != strings.end(); i++) {
		cout << *i << endl;
	}

	

	replace(strings, "Lorem", "HOO");

	for (vector<string>::iterator i = strings.begin(); i != strings.end(); i++) {
		cout << *i << endl;
	}


	cout << "N� med sets" << endl;


	set<string>setstring{ "Consectetur", "Amet", "Sit", "Dolor", "Ipsum", "Lorem" };

	for (set<string>::reverse_iterator i = setstring.rbegin(); i != setstring.rend(); i++) {
		cout << *i << endl;
	}
	for (set<string>::iterator i = setstring.begin(); i != setstring.end(); i++) {
		cout << *i << endl;
	}

	replaceset(setstring, "Lorem", "HOO");

	for (set<string>::iterator i = setstring.begin(); i != setstring.end(); i++) {
		cout << *i << endl;
	}


	cout << "Oppg2" << endl;

	Person p;
	p.setFirstName("Yo");
	p.setLastName("Mydude");

	cout << p << endl;

	list<Person> listofpersons;

	Person p1;
	Person p2;
	Person p3;
	Person p4;



	p1.setFirstName("Om");
	p1.setLastName("Normann");
	p2.setFirstName("Ola");
	p2.setLastName("Grynt");
	p3.setFirstName("Ob");
	p3.setLastName("Aaland");
	p4.setFirstName("Ola");
	p4.setLastName("Aaland");


	insertOrdered(listofpersons, p1);

	insertOrdered(listofpersons, p2);

	insertOrdered(listofpersons, p3);


	insertOrdered(listofpersons, p4);
	for (auto p : listofpersons) {
		cout << p << endl;
	}


	testLinkedList();

	char a{ 'a' };
	char b{ 'b' };
	char c = GetMax(a, b);

	cout << c;

	vector<string> liste2{ "1.4", "2.2", "3.4", "4.1", "7.5", "6.5", "7.9" };
	vector<string> liste222 {Shuffle(liste2)};

	for (int i = 0; i < liste222.size(); i++) {
		cout << liste222[i] << " ";

	}
	cout << endl;

	return 0;
}