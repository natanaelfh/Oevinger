#include "utilities.h"
#include "std_lib_facilities.h"


int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}

	return startValue;
}

void swap(int&a, int&b) {
	int c{ 0 };
	int d{ 0 };
	c = a;
	d = b;
	a = d;
	b = c;
}

void randomizeVector(vector<int>& vecotr, int n) {

}