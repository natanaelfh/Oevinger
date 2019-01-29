#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swap(int&a, int&b);

void randomizeVector(vector<int>& vecotr, int n);

void sortVector(vector<int>&vr);

double medianOfVector(const vector<int>& vr);

string randomizeString(int lenght, char upper, char lower);

string readInputToString(int n);

int countChar(string st, char c);

int charInRightSpot(string og, string test);

int charsCorrect(string og, string guess);