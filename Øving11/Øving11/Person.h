#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <list>
using namespace std;

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

