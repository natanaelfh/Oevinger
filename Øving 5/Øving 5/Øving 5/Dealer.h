#pragma once
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"
class Dealer
{

private:
	int score;
	int numberOfDrawnCards;
	vector<Card> drawCards;
	void decide();
public:
	Dealer();
	~Dealer();
	int getValue();
	
};