#include "emne.h"



CourseCatalog::CourseCatalog()
{
}

CourseCatalog::~CourseCatalog()
{
}

void CourseCatalog::addCourse(string code, string name) {
	//this->courses.insert(pair<string, string>(code, name));
	this->courses[code] = name;
}

void CourseCatalog::removeCourse(string code) {
	this->courses.erase(code);
}

string CourseCatalog::getCourse(string code) {
	return this->courses[code];
}

void CourseCatalog::updateCourse(string code, string name) {
	if (this->courses.find(code) != courses.end()) {
		this->addCourse(code, name);
	}
}

ostream& operator<<(ostream& os, const CourseCatalog& catalog) {
	for (const auto& p : catalog.courses) {
		os << p.first << ";" << p.second << endl;
	}

	return os;
}

void writeEmne(CourseCatalog catalog) {
	string name;
	cout << "Hva heter filen" << endl;
	getline(cin, name);

	ofstream ost{ name };
	if (!ost) error("can't open output file ", name);

	ost << catalog;

	ost.close();
}

CourseCatalog readEmne() {
	string name;
	cout << "Hva heter filen" << endl;
	getline(cin, name);

	ifstream ist{ name };
	if (!ist) error("can't open input file ", name);
	CourseCatalog catalog = CourseCatalog::CourseCatalog();
	string code;
	string course;
	while (true) {
		if (ist.eof()) {
			break;
		}
		else {
			getline(ist, code, ';');
			getline(ist, course);
			if (ist.eof()) {
				break;
			}
			catalog.addCourse(code, course);
		}

		
	}
	ist.close();

	return catalog;
}