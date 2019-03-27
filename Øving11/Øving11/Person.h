#pragma once
#include "std_lib_facilities.h"
class Person
{
public:
	Person();
	~Person();
	string getFirstName();
	string getLastName();
	void setFirstName(string name);
	void setLastName(string name);


	friend ostream& operator<<(ostream& os, const Person& p);

private:
	string firstName;
	string lastName;
};

