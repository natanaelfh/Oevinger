#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

int main(){
	int k = 8;
	int t = 5;
	int c{ 1 };
	while (c != 0) {
		cout << "Valg: ";
		cin >> c;
		switch (c)
		{
		case(1): {
			testCallByValue();
			break;
		}

		case(2): {
			testCallByValueRef();
			break;
		}

		case(3): {
			swap(t, k);
			cout << "t: " << t << ", k: " << k << endl;
			break;
		}

		case(4): {
			testVectorSorting();
			break;
		}
		default:
			break;
		}
	}


}



/*
1a)	5
1e) burde bruke referanser pga. kan ikke returnere 2 verdier


*/