#include "player.h"
#include <iostream>
#include <time.h>


player:: player()
{
}

void player::set_id(int id)
{
	player_id = id;
}


int player::remaining_cards() {
	return cards.size();
}

void player::take_card(card card) {
	cards.push_back(card);
}

card player::give_card(int a) {
	int b = cards.size() - 1;
	card l = (cards[a]);
	if (a != b) {
		swap(cards[a], cards[b]);
	}
	cards.pop_back();
	return l;
}

card player::give_card() {
	///prepei na epile3w poia karta mporw na peta3w
	int a = cards.size() - 1;//prosorino,edw tha mpei h karta p dialegei o paikths
	int b = cards.size() - 1;

	card l = (cards[a]);
	if (a != b) {
		swap(cards[a], cards[b]);
	}
	cards.pop_back();
	return l;
}
void player::show_hand() {
	for (int i = 0; i < cards.size(); i++) {
		cout << "Card " << i << ":" << endl;
		cards[i].show_card();
		cout << endl;
		//cout << "Card "<<i<<": " << endl << "shape: " << cards[i].get_shape() << endl << "number: " << cards[i].get_number() << endl;
	}
}

card player::show_card(int a) {
	return cards[a];
}

player::~player()
{

}



