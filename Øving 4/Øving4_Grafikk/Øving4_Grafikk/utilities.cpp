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

void randomizeVector(vector<int>& vc, int n) {
	for (int i{ 0 }; i < n; i++) {
		int tilfeldig_tall = rand();
		int tall = (tilfeldig_tall % 101);
		vc.push_back(tall);
	}
}

void sortVector(vector<int>&vr) {
	int i=1;
	while (i < vr.size()) {
		int j{ i };
		while (j > 0 && vr[j - 1] > vr[j]) {
			swap(vr[j], vr[j - 1]);
			j -= 1;
		}
		i += 1;
	}
}

double medianOfVector(const vector<int>& vr) {
	int len = vr.size();
	if (len % 2 == 0) {
		return (((double)vr[len / 2] + (double)vr[len / 2 - 1]) / 2);
	}
	else {
		return (vr[len / 2]);
	}
}

string randomizeString(int lenght, char upper, char lower) {
	string vr;
	for (int i{ 0 }; i < lenght; i++) {
		int tilfeldig_tall = rand();
		int tall = (tilfeldig_tall % ((upper-lower) +1));
		vr.push_back(tall + lower);
	}
	return vr;
}

string readInputToString(int n) {

	bool allAlpha{ 1 };
	string st;
	string final;
	do
	{
		final = "";
		cout << "Input: ";
		cin >> st;
		for (char c : st) {
			if (!isalpha(c)) {
				allAlpha = false;
			}
			final.push_back(toupper(c));
		}

	} while (!allAlpha);

	return final;

}

int countChar(string st, char c) {
	int number{ 0 };
	for (char l : st) {
		if (l == c) {
			number += 1;
		}
	}
	return number;
}

string uniqueChar(string st) {

	string unique{st[0]};
	int lenght{ (int)st.size() };
	int i{ 0 };

	for (char c : st) {
		auto l = unique.find(c);
		if (l == -1) {
			unique.push_back(c);
		}
	}
	return unique;
}

int charsCorrect(string og, string guess) {
	string unique;
	unique = uniqueChar(og);
	int number{ 0 };
	for (char c : unique) {
		int inCode{ 0 };
		int inGuess{ 0 };
		
		inCode = countChar(og, c);
		inGuess = countChar(guess, c);

		int diff = inCode - inGuess;
		if (diff <= 0) {
			number += inCode;
		}
		else {
			number += inGuess;
		}
	}
	return number;
}

int charInRightSpot(string og, string test) {
	int number{ 0 };
	for (int i{ 0 }; i < og.size(); i++) {
		if (og[i] == test[i]) {
			number += 1;
		}
	}
	return number;
}