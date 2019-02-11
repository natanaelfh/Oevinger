#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"


class CardDeck
{

private:
	vector<Card> cards;
	int currentCardIndex;
	void swap(int pos1, int pos2);
public:
	CardDeck();
	~CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};

