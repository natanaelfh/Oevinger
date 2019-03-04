#include "std_lib_facilities.h"
#include "EcoCar.h"

int main(){

	// Your code here
	Car bil1 = Car(3);
	Car bil2 = Car(0);
	Car bil3 = Car(1);


	Person person1 = Person("Per", "Per@mail.no", &bil1);
	Person person2 = Person("Lisa", "lisa@mail.no", &bil2);
	Person person3 = Person("Jonas", "lisa@mail.no");

	cout << person1;
	cout << person2;
	cout << person3;


	return 0;
}