#pragma once

#include "std_lib_facilities.h"
#include "file.h"

class CourseCatalog
{

public:
	CourseCatalog();
	~CourseCatalog();
	void addCourse(string, string);
	void removeCourse(string);
	string getCourse(string);
	void updateCourse(string, string);

	friend ostream& operator<<(ostream&, const CourseCatalog&);

private:
	map<string, string> courses;


};

void writeEmne(CourseCatalog);

CourseCatalog readEmne();
