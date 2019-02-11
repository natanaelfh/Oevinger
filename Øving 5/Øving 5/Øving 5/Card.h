#pragma once
#include "std_lib_facilities.h"
#include "utilities.h"

enum class Suit{clubs, diamonds, hearts, spades};

enum class Rank {
	two = 2, three, four, five, six,
	seven, eight, nine, ten, jack, queen, king, ace
};

string suitToString(Suit suit);


struct CardStruct {
	Suit s;
	Rank r;
};

string toString(CardStruct card);

string toStringShort(CardStruct card);

void testEnumCast();

class Card {

private:
	Suit s;
	Rank r;
	bool valid;
public:
	Card();
	Card(Suit s, Rank r);
	Suit getSuit();
	Rank getRank();
	bool isValid();
	string toString();
	string toStringShort();


};