#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swap(int&a, int&b);

void randomizeVector(vector<int>& vecotr, int n);