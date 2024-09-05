#pragma once
//#ifndef PLAYER_H
//#define PLAYER_H
#include <vector>
#include "card.h"
#include<iostream>
class player
{
	vector<card>cards;
	int player_id=NULL;
public:
	player();
	void set_id(int id);
	int remaining_cards();
	void take_card(card card);
	card give_card(int a);
	card give_card();
	void show_hand();
	void get_id() {
		std::cout << player_id << endl;
	}
	card show_card(int a);

	~player();
};

//#endif