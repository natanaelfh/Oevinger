#include "file.h"

void writeFile() {
	string name;
	cout << "Hva heter filen" << endl;
	getline(cin, name);
	name = name + ".txt";
	ofstream ost{ name };
	if (!ost) error("can't open output file ", name);
	string line;
	while (true)
	{
		getline(cin, line);
		if (line == "quit") {
			break;
		}
		else {
			ost << line << "\n";
		}
	}
	ost.close();

}

void readFile() {
	string name;
	cout << "Hva heter filen" << endl;
	getline(cin, name);
	ifstream ist{ name };
	if (!ist) error("can't open input file ", name);
	string oname;
	cout << "Hva heter filen du skal skrive på " << endl;
	getline(cin, oname);
	ofstream ost{ oname };
	if (!ost) error("can't open output file ", oname);
	string line;
	int linenumber{ 1 };
	while (true) {
		getline(ist, line);
		if (ist.eof() == true) {
			break;
		}
		else {
			ost << linenumber << ": " << line << "\n";
			linenumber += 1;
		}
	}
	ist.close();
	ost.close();
}

void countFile() {
	string name;
	cout << "Hva heter filen: ";
	getline(cin, name);
	ifstream ist{ name };
	if (!ist) error("can't open input file ", name);
	vector<int> charList((static_cast<int>('z'))-(static_cast<int>('a'))+1);
	char c;
	while (true)
	{
		ist.get(c);
		if (ist.eof()) {
			break;
		}
		else {
			if (c < 0 || c>'z') {
				continue;
			}
			if (isalpha(c)) {
				c = tolower(c);
				charList[c - 'a'] += 1;
			}
		}
	}
	ist.close();

	for (int i = 0; i < charList.size();i++) {
		cout << static_cast<char>('a' + i) << ": " << charList[i] << endl;
	}
}

