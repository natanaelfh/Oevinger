#include "BlackJack.h"



BlackJack::BlackJack()
{
}


BlackJack::~BlackJack()
{
}


vector<Player> BlackJack::getPlayers() {
	vector<Player> players;
	

	//under skal jeg fortsette å legge til players, jeg er usikker på om dette fungerer
	//mtp at alle starter med samme navn, håper det er dette objecter er til
	string name;
	Player temp;
	do
	{
		cout << "Add player name(empty for no more players): ";
		getline(cin, name);
		if (name != "") {
			temp = Player(false, name);
			players.push_back(temp);
		}

	} while (name != "");
	//add dealer
	Player dealer = Player(true, "Dealer");
	players.push_back(dealer);
	this->players = players;
	return players;
}

void BlackJack::drawFirstTwoCards() {
	//en funksjon som trekker de to første kortene, her er det ingen mulighet for å velge noe
	for (int i = 0; i < 2; i++) {
		for (Player & player : this->players) {
			player.drawCard(this->deck.drawCard());
		}
	}


}


void BlackJack::startBlackJack() {
	//hvordan man starter spilet
	//burde kun trenge å skive dette i main for å spille
	vector<Player> players = getPlayers();
	this->deck = CardDeck::CardDeck();
	this->deck.shuffle();
	this->drawFirstTwoCards();
	this->allDone = false;
	int value;
	do
	{
		allDone = true;
			for (Player & player : this->players) {
				if (player.getInGame()) {
					value = player.getCardValue();
					if (player.choose()) {
						allDone = false;
						player.drawCard(this->deck.drawCard());
						value = player.getCardValue();
						if (player.getDealer()) {

							if (value == 21) {
								return;
								cout << "Dealer vant" << endl;
							}
							
						}
						else {
							if (value > 21) {
								cout << player.getName() << " fikk verdien: " << static_cast<int> (player.getCardValue()) << "\nBeklager du tapte." << endl;
								player.removeFromGame();
							}
						}
					}
				}
			}

	} while (this->allDone != true);

	cout << "----------------------------" << endl;
	cout << "--------GAME OVER-----------" << endl;
	cout << "----------------------------" << endl;
	int dealerValue{ this->players.back().getCardValue() };
	cout << "Dealeren hadde verdi: " << dealerValue << endl;
	for (Player player : this->players) {
		if (dealerValue > 21) {
			if ((player.getInGame()) && (player.getDealer() != true)) {
				cout << player.getName() << " vant! Hurra." << endl;
			}
		}
		else {
			if ((player.getInGame()) && (player.getDealer() != true)) {
				if (player.getCardValue() > dealerValue) {
					cout << player.getName() << " vant over dealer" << endl;
				}
				else {
					cout << player.getName() << " tapte over dealer" << endl;
				}
			}
		}
	}
}
