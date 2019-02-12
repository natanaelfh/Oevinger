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
	string name;
	vector<Card> cardsDrawn;
public:
	int getCardValue();
	void drawCard(Card card);
	void choose();
	Player();
	Player(bool isDealer, string name);
	~Player();
};

