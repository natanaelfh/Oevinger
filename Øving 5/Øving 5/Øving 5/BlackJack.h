#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"
#include "Player.h"


class BlackJack
{
private:
	bool allDone;
	void drawFirstTwoCards();
	vector<Player> getPlayers();
	CardDeck deck;
	vector<Player> players;
public:
	BlackJack();
	~BlackJack();
	void startBlackJack();

};

