#include "temp.h"


Temps operator>>(istream& is, Temps& t) {
	string max;
	string min;
	getline(is, max, '\t');
	getline(is, min, '\n');

	if (is.eof()) {
		t.max = 0;
		t.min = 0;
		return t;
	}
	t.max = stod(max);
	t.min = stod(min);
	return t;
}

vector<Temps> readTemp() {
	string name;
	cout << "Hva heter filen" << endl;
	getline(cin, name);

	ifstream ist{ name };
	if (!ist) error("can't open input file ", name);
	vector<Temps> temps;
	Temps temp;

	while (true) {
		if (ist.eof()) {
			temps.pop_back();
			break;
		}
		else {
			ist >> temp;
			temps.push_back(temp);
		}


	}
	ist.close();

	return temps;
}