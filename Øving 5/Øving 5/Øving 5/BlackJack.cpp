#include "BlackJack.h"



BlackJack::BlackJack()
{
}


BlackJack::~BlackJack()
{
}


vector<Player> BlackJack::getPlayers() {
	vector<Player> players;
	//add dealer
	Player dealer = Player(true, "Dealer");
	players.push_back(dealer);

	//under skal jeg fortsette � legge til players, jeg er usikker p� om dette fungerer
	//mtp at alle starter med samme navn, h�per det er dette objecter er til
	string name;
	Player temp;
	do
	{
		cout << "Add player name(empty for no more players): ";
		cin >> name;
		if (name != "") {
			temp = Player(false, name);
			players.push_back(temp);
		}

	} while (name != "");
	this->players = players;
	return players;
}

void BlackJack::drawFirstTwoCards() {
	//en funksjon som trekker de to f�rste kortene, her er det ingen mulighet for � velge noe
	for (int i = 0; i < 2; i++) {
		for (Player player : this->players) {
			player.drawCard(this->deck.drawCard());
		}
	}


}

void BlackJack::startBlackJack() {
	//hvordan man starter spilet
	//burde kun trenge � skive dette i main for � spille
	vector<Player> players = getPlayers();
	void drawFirstTwoCards();
	this->deck = CardDeck::CardDeck();
	this->deck.shuffle();
}
