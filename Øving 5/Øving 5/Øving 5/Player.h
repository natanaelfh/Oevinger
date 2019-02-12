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

	string name;
	bool canDraw;
	bool inGame;
public:
	int getCardValue();
	void drawCard(Card card);
	bool choose();
	string getName();
	bool getDealer();
	bool getCanDraw();
	void pushCanDraw(bool canDraw);
	void removeFromGame();
	bool getInGame();

	Player();
	Player(bool isDealer, string name);
	~Player();
	
};

