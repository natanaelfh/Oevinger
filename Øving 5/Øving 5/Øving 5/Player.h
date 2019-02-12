#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"
class Player
{
private:
	bool isDealer;
	bool isValid;
	vector<Card> cardsDrawn;
public:
	int getCardValue();
	void drawCard(Card card);
	void choose();

	string name;
	Player();
	Player(bool isDealer, string name);
	~Player();
};

