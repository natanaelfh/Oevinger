#include "Card.h"
#include "std_lib_facilities.h"


vector<string> rankNames;

string suitToString(Suit suit) {
	map<Suit, string> suits;

	suits.insert({ Suit::clubs, "clubs" });
	suits.insert({ Suit::diamonds, "diamonds" });
	suits.insert({ Suit::spades, "spades" });
	suits.insert({ Suit::hearts, "hearts" });

	return suits.at(suit);
}

string rankToString(Rank rank) {
	map<Rank, string> ranks;

	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::three, "three" });
	ranks.insert({ Rank::four, "four" });
	ranks.insert({ Rank::five, "five" });
	ranks.insert({ Rank::six, "six" });
	ranks.insert({ Rank::seven, "seven" });
	ranks.insert({ Rank::eight, "eight" });
	ranks.insert({ Rank::nine, "nine" });
	ranks.insert({ Rank::ten, "ten" });
	ranks.insert({ Rank::jack, "jack" });
	ranks.insert({ Rank::queen, "queen" });
	ranks.insert({ Rank::king, "king" });
	ranks.insert({ Rank::ace, "ace" });

	return ranks.at(rank);

}

string toString(CardStruct card) {
	ostringstream os;
	os << rankToString(card.r) << " of " << suitToString(card.s) << endl;
	return os.str();
}

string toStringShort(CardStruct card) {
	ostringstream os;

	int value{ static_cast<int>(card.r) };
	int suit{ static_cast<int>(card.s) };

	char firstLetter;
	switch (suit)
	{
	case 0:
		firstLetter = 'C';
		break;

	case 1:
		firstLetter = 'D';
		break;
	case 2:
		firstLetter = 'H';
		break;
	case 3:
		firstLetter = 'S';
		break;


	default:
		break;
	}


	os << firstLetter << to_string(value) << endl;

	return os.str();
}

Card::Card() {
	valid = false;
}

Card::Card(Suit s, Rank r) {
	this->s = s;
	this->r = r;
}

bool Card::isValid() {
	return this->valid;
}

Suit Card::getSuit() {
	return this->s;
}

Rank Card::getRank() {
	return this->r;
}

string Card::toString() {
	ostringstream os;
	os << rankToString(this->r) << " of " << suitToString(this->s);
	return os.str();
}

string Card::toStringShort() {
	ostringstream os;

	int value{ static_cast<int>(this->r) };
	int suit{ static_cast<int>(this->s) };

	char firstLetter;
	switch (suit)
	{
	case 0:
		firstLetter = 'C';
		break;

	case 1:
		firstLetter = 'D';
		break;
	case 2:
		firstLetter = 'H';
		break;
	case 3:
		firstLetter = 'S';
		break;


	default:
		break;
	}


	os << firstLetter << to_string(value);

	return os.str();
	
}

void testEnumCast() {
	int a{ static_cast<int>(Rank::king) };
	cout << "King to int: " << a << endl;

	Rank r { static_cast<Rank>(12) };
	cout << rankToString(r);
}