#include "Person.h"
using namespace std;


Person::Person()
{
}


Person::~Person()
{
}


void Person::setFirstName(string name) {
	firstName = name;
}

void Person::setLastName(string name) {
	lastName = name;
}

string Person::getFirstName() {
	return firstName;
}

string Person::getLastName() {
	return lastName;
}

ostream & operator<<(ostream & os, const Person & p)
{
	os << p.firstName << " " << p.lastName;
	return os;

}
