#pragma once

#include "emne.h"
#include "file.h"
#include "std_lib_facilities.h"

struct Temps {
	double max;
	double min;
};

Temps operator>>(istream& is, Temps& t);

vector<Temps> readTemp();
