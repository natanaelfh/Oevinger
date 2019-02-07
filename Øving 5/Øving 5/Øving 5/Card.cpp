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
	os << rankToString(card.r) << " of " << suitToString(card.s);
	return os.str();
}

string toStringShort(CardStruct card) {
	ostringstream os;

}

void testEnumCast() {
	int a{ static_cast<int>(Rank::king) };
	cout << "King to int: " << a << endl;

	Rank r { static_cast<Rank>(12) };
	cout << rankToString(r);
}