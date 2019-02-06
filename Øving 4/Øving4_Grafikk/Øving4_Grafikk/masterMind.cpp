#include "masterMind.h"
#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"
#include "masterVisual.h"
#include "Simple_window.h"


void playMasterMind() {


	MastermindWindow mwin{ Point{900, 20}, 400, 600, "Mastermind" };

	constexpr int size{ 4 };
	constexpr int letters{ 6 };
	constexpr int numberOfTries{ 10 };

	string code;
	string guess;

	char upper{ 'A' + (letters - 1) };

	code = randomizeString(letters, upper, 'A');


	cout << "Gjett " << letters << " antall bokstaver" << endl << "Du har "
		<< numberOfTries << " antall forsøk" << endl;

	for (int i=0; i < numberOfTries; i++) {

		cout << "Du er på forsøk nr. " << (i + 1) << endl;

		guess = readInputToString(letters);

		addGuess(mwin, guess, 6, 'A', i);

		if (charInRightSpot(code, guess) == letters) {
			cout << "Alt riktig!\nDu vant!" << endl;
			return;
		}
		else {
			cout << "Du hadde " << charsCorrect(code, guess) << " riktige bokstaver." << endl;
			cout << "Du hadde " << charInRightSpot(code, guess) << " bokstaver på rikitg plass." << endl;
		}
	}
	cout << "Du tapte, bedre lykke neste gang." << endl;
}
