#include "Player.h"
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"


Player::Player()
{
	this->isValid = false;
}

Player::Player(bool isDealer, string name)
{
	this->isValid = true;
	this->isDealer = isDealer;
	this->name = name;
}


Player::~Player()
{
}


int Player::getCardValue() {

	//denne gir hittil max score, dette kan bli et problem for dealer må kanskje lage en ny en som gir min score?
	//trenger man mer enn max og min?
	const vector<Card> cardsDrawn{ this->cardsDrawn };
	int temp{ 0 };
	int newValue{ 0 };
	int numOfAce{ 0 };
	for (Card card : cardsDrawn) {
		newValue = static_cast<int>(card.getRank());
		if (newValue == 14) {
			numOfAce += 1;
		}
		else {
			temp += newValue;
		}
	}
	temp = temp + (numOfAce * 14);
	for (int i = 0; i < numOfAce;i++) {
		if (temp > 21) {
			temp = temp - 13;
		}
	}


	return temp;
}

void Player::drawCard(Card card) {

	//meningen er å si hva man trekker dersom man ikke er på sitt første kort eller om man ikke er dealer
	this->cardsDrawn.push_back(card);

	if ((this->isDealer && this->cardsDrawn.size() != 0) || this->isDealer == false) {
		cout << this->name << " drew a " << card.toString() << endl;
	}
}