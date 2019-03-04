#include "EcoCar.h"

bool Car::hasFreeSeats() const {
	if (this->freeSeats > 0) {
		return true;
	}
	else {
		return false;
	}
}

void Car::reserveFreeSeats() {
	this->freeSeats = this->freeSeats - 1;
}

Car::Car(int n) {
	this->freeSeats = n;
}

Person::Person(string name, string email, Car *car) {
	this->name = name;
	this->email = email;
	this->car = car;
}

string Person::getName() {
	return this->name;
}

void Person::setName(string name) {
	this->name = name;
}

string Person::getEmail() {
	return this->email;
}

void Person::setEmail(string email) {
	this->email = email;
}

Car* Person::getCar() {
	return this->car;
}

void Person::setCar(Car *car) {
	this->car = car;
}


const bool Person::hasAvailableSeats() {
	if (this->car == nullptr) {
		return false;
	}
	else {
		Car car = *this->car;
		return car.hasFreeSeats();
	}

	}



ostream& operator<<(ostream& os, const Person& p) {
	os << "Name: " << p.name << endl;
	os << "Email: " << p.email << endl;
	Person person = p;
	os << "Free seats: " << person.hasAvailableSeats() << endl;

	return os;
}