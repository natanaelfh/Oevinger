#include "utilities.h"
#include "std_lib_facilities.h"

int getRandomNumber(int max, int min) {

	return ((rand() % (max - min)) + min);

}


void getTwoDifferentRandomNumbers(int& number1, int&number2, int max, int min) {
	int temp1{ getRandomNumber(max,min) };
	int temp2;
	do
	{
		temp2 = getRandomNumber(max, min);

		
	} while (temp1 == temp2);

	number1 = temp1;
	number2 = temp2;
}

