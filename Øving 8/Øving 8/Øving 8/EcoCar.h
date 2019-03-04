#pragma once
#include "std_lib_facilities.h"

class Car {
private:
	int freeSeats;

public:
	bool hasFreeSeats() const;
	void reserveFreeSeats();
	Car(int n);
};


class Person {
private:
	string name;
	string email;
	Car *car;
public:
	Person(string name, string email, Car *car = nullptr);

	string getName();
	void setName(string name);

	string getEmail();
	void setEmail(string email);

	Car* getCar();
	void setCar(Car *car);


	const bool hasAvailableSeats();


	friend ostream& operator<<(ostream& os, const Person& p);
};