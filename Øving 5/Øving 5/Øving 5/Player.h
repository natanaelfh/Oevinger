#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"
class Player
{
private:
	bool isDealer;
	vector<Card> cardsDrawn;
public:
	int getCardValue();
	void drawCard();
	void choose();
	Player();
	~Player();
};

