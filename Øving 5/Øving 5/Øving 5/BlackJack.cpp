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

	//under skal jeg fortsette å legge til players, jeg er usikker på om dette fungerer
	//mtp at alle starter med samme navn, håper det er dette objecter er til
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
	//en funksjon som trekker de to første kortene, her er det ingen mulighet for å velge noe
	for (int i = 0; i < 2; i++) {
		for (Player player : this->players) {
			player.drawCard(this->deck.drawCard());
		}
	}


}

void BlackJack::startBlackJack() {
	//hvordan man starter spilet
	//burde kun trenge å skive dette i main for å spille
	vector<Player> players = getPlayers();
	void drawFirstTwoCards();
	this->deck = CardDeck::CardDeck();
	this->deck.shuffle();
}
