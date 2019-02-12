#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"
#include "Player.h"


class BlackJack
{
private:
	void drawFirstTwoCards();
	void drawPlayerCard();
	vector<Player> players;
	vector<Player> getPlayers();
	CardDeck deck;
public:
	BlackJack();
	~BlackJack();
	void startBlackJack();
};

