#include "Player.h"
#include "Card.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "CardDeck.h"


Player::Player()
{
	this->isValid = false;
}

Player::Player(bool isDealer, string name)
{
	this->isValid = true;
	this->isDealer = isDealer;
	this->name = name;
	this->canDraw = true;
	this->inGame = true;
}


Player::~Player()
{
}


int Player::getCardValue() {

	//denne gir hittil max score, dette kan bli et problem for dealer må kanskje lage en ny en som gir min score?
	//trenger man mer enn max og min?
	//viser seg at man kun trenger å finne max under 21
	const vector<Card> cardsDrawn{ this->cardsDrawn };
	int temp{ 0 };
	int newValue{ 0 };
	int numOfAce{ 0 };
	for (Card card : cardsDrawn) {
		newValue = static_cast<int>(card.getRank());
		if (newValue == 14) {
			numOfAce += 1;
		}
		else if (newValue > 10) {
			temp += 10;
		}
		else {
			temp += newValue;
		}
	}
	temp = temp + (numOfAce * 11);
	for (int i = 0; i < numOfAce;i++) {
		if (temp > 21) {
			temp = temp - 10;
		}
	}


	return temp;
}

void Player::drawCard(Card card) {

	//meningen er å si hva man trekker dersom man ikke er på sitt første kort eller om man ikke er dealer
	this->cardsDrawn.push_back(card);

	if ((this->getDealer() && this->cardsDrawn.size() != 0) || (this->getDealer() == false)) {
		cout << this->name << " trakk " << card.toString() << endl;
	}
}

string Player::getName() {
	return this->name;
}

bool Player::getCanDraw() {
	return this->canDraw;
}

void Player::pushCanDraw(bool canDraw) {
	this->canDraw = canDraw;
	return;
}

bool Player::choose() {
	string input;
	if (this->isDealer) {
		if (this->getCardValue() > 16) {
			return false;
		}
		else {
			return true;
		}
	}
	else if (this->getCanDraw() == false){
		cout << this->getName() << ", du har allerede gitt deg" << endl;
		return false;
	}
	else {
		cout << "Du har kortene: " << endl;
		for (Card card : this->cardsDrawn) {
			cout << static_cast<string> (card.toStringShort()) << endl;
		}
		cout << "Maks verdi: " << static_cast<int>( this->getCardValue()) << endl;
		cout << "Vil du trekke? (1 for ja, 0 for nei): ";
		bool isValid{ false };
		do
		{
			getline(cin, input);
			if (input == "1") {
				isValid = true;
				return true;
			}
			else if (input == "0") {
				isValid = true;
				this->pushCanDraw(false);
				return false;
			}
		} while (isValid == false);
	}
}
bool Player::getDealer() {
	return this->isDealer;
}

void Player::removeFromGame() {
	this->inGame = false;
}

bool Player::getInGame() {
	return this->inGame;
}

