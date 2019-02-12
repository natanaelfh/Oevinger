#include "CardDeck.h"
#include "Card.h"
#include "std_lib_facilities.h"


CardDeck::CardDeck()
{
	for (int r = 2; r < 15; r++) {
		for (int s = 0; s < 4; s++) {
			Rank rank{ static_cast<Rank>(r) };
			Suit suit{ static_cast<Suit>(s) };
			this->cards.push_back(Card::Card(suit,rank));
		}
	}
	this->currentCardIndex = 0;
}


CardDeck::~CardDeck()
{
}

void CardDeck::swap(int pos1, int pos2) {
	Card temp = this->cards[pos2];
	this->cards[pos2] = this->cards[pos1];
	this->cards[pos1] = temp;
}

void CardDeck::print() {
	for (Card card : this->cards) {
		cout << card.toString();
	}
}

void CardDeck::printShort() {
	for (Card card : this->cards) {
		cout << card.toStringShort();
	}
}

void CardDeck::shuffle() {
	int size = static_cast<int>( this->cards.size());
	for (int i = 0; i < (size / 2); i++) {
		int pos1;
		int pos2;
		getTwoDifferentRandomNumbers(pos1, pos2, size - 1, 0);
		this->swap(pos1, pos2);
	}
}

Card CardDeck::drawCard() {
	Card temp = this->cards[0];
	cards = this->cards;
	cards.erase(cards.begin());
	this->cards = cards;
	this->currentCardIndex++;
	return temp;
}