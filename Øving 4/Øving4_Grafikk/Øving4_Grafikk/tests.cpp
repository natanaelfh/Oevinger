#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"


void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testCallByValueRef() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimesRef(v0, increment, iterations);
	cout << "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " result: " << result << endl;
}

void testVectorSorting() {
	vector<int> percentages;
	randomizeVector(percentages, 10);
	for (int i : percentages) {
		cout << i << " ";
	}
	cout << endl;
	swap(percentages[0], percentages[1]);
	for (int i : percentages) {
		cout << i << " ";
	}
	cout << endl;
	sortVector(percentages);
	for (int i : percentages) {
		cout << i << " ";
	}
	cout << endl;

	cout << medianOfVector(percentages) << endl;
}

void testString() {
	string grades;
	grades = randomizeString(3, 'F', 'A');
	cout << grades << endl;
	int tot{ 0 };
	vector<int> gradeCount;
	for (int i = 0; i < 6; i++) {
		gradeCount.push_back(countChar(grades, (char)('A' + i)));
		tot = tot + gradeCount[i] * (5 - i);
	}
	double snitt = (double)tot / grades.size();

	cout << "Snitt: " << snitt << endl;

}

