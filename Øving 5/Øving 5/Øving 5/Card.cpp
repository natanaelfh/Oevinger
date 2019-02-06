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
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });
	ranks.insert({ Rank::two, "two" });

}