#include "Player.h"
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"


Player::Player()
{
}


Player::~Player()
{
}


int Player::getCardValue() {
	const vector<Card> cardsDrawn{ this->cardsDrawn };
	int temp{ 0 };
	int newValue{ 0 };
	int numOfAce{ 0 };
	for (Card card : cardsDrawn) {
		newValue = static_cast<int>(card.getRank());
		if (newValue == 14) {
			numOfAce += 1;
		}
		else
	}


	return temp;
}