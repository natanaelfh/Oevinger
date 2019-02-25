#include "std_lib_facilities.h"
#include "file.h"
#include "emne.h"
#include "temp.h"

int main(){

	 //Your code here

	CourseCatalog catalog{ CourseCatalog() };
	catalog.addCourse("TEP4100", "Fluidme kanikk");
	catalog.addCourse("TMA4125", "Satistikk");
	catalog.addCourse("TEP4130", "Fluidme kanikk");
	catalog.addCourse("TMA4155", "Sati stikk");
	catalog.addCourse("TEP4110", "F luidmekanikk");
	catalog.addCourse("TMA4165", "Satistikk");
	catalog.updateCourse("TMA41005", "SS");
	catalog.removeCourse("TEP4110");
	cout << catalog;

	writeEmne(catalog);

	CourseCatalog newCatalog = readEmne();

	cout << newCatalog;

	ifstream temp_file{ "temperatures.txt" };
	Temps t;
	temp_file >> t;
	cout << t.max << " " << t.min << endl;

	vector<Temps> newTemp{ readTemp() };

	return 0;
}