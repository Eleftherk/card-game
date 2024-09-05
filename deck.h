#pragma once
#include "card.h"
#include <vector>
class deck
{
	vector<card>cards;
public:
	deck();

	void shuffle();
	card get_card();
	int remaining_cards();
	void get_card_back(card card);

	~deck();
};
