#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "utilities.h"
#include "test.h"
int main(){
	//testEnumCast();
	
	// Your code here
	suitToString(Suit::diamonds);

	CardStruct card{ Suit::diamonds, Rank::eight };

	cout << toString(card);
	cout << toStringShort(card);
	
	testGetPlayers();
	
	return 0;




}