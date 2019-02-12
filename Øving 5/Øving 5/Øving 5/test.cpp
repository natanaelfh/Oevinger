#include "test.h"

void testGetPlayers() {

	BlackJack game = BlackJack::BlackJack();
	vector<Player> player = game.players;
	Player first = player[0];
	string name = first.name;

	cout << name << endl;
}