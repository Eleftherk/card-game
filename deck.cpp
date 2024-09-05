#include "deck.h"
#include <vector>
#include <time.h>

deck::deck() {


	for (int i = 0; i < 13; i++) {

		cards.push_back(card(i + 1, "Heart"));
	}
	for (int i = 0; i < 13; i++) {

		cards.push_back(card(i + 1, "Spade"));
	}
	for (int i = 0; i < 13; i++) {

		cards.push_back(card(i + 1, "Diamond"));
	}
	for (int i = 0; i < 13; i++) {

		cards.push_back(card(i + 1, "clube"));
	}
}

void deck::shuffle() {
	int k = cards.size();
	srand(time(NULL));
	for (int i = 0; i < k; i++) {
		int j = rand() % k;
		swap(cards[i], cards[j]);
	}
}

card deck::get_card() {
	card l = (*cards.rbegin());
	cards.pop_back();
	return l;
}

int deck::remaining_cards() {
	return cards.size();
}

void deck::get_card_back(card card) {
	cards.push_back(card);
}

deck::~deck()
{
}

