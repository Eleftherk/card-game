#include "card.h"
#include "deck.h"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include "player.h"
// paixnidi san thn agwnia alla xwris toys kanones gia toys assoys

int num_of_players = NULL;
using namespace std;

void test_if_9(int &j, int &num_of_players,int &number_of_card) {
	if (number_of_card == 9) {
		if (j == (num_of_players - 1))j = 0;
		else j++;
	}

}

void test_if_8(int& j, int& num_of_players, int& number_of_card) {
	if (number_of_card == 8) {
		if (j == 0) j = (num_of_players - 1);
		else j--;
	}
}

void test_if_7(bool &is_7, int& j, int& num_of_players, int& number_of_card) {
	is_7 = false;
	if (number_of_card == 7) is_7 = true;
}



int main() {
	int j = 0;
	bool play = true;
	deck deck1;
	deck1.shuffle();
	vector<card>game;

	cout << "Give me the number of players(2-4)..." << endl;
	cin >> num_of_players;
	cout << "The number of players is: "<<num_of_players << endl;
	player *players = new player [num_of_players];
	for (int i = 0; i < num_of_players; i++) {
		players[i].set_id(i);
	}
	for (int i = 0; i < num_of_players; i++) {
		for (int j = 0; j < 7; j++) {
			players[i].take_card(deck1.get_card());
		}
	}
	

	// paixnidi
	game.push_back(deck1.get_card());

	while (play)
	{
		for (j = 1; j < num_of_players; j++)
		{
			//prepei na ta valw allou
			if ((*game.rbegin()).get_number() == 9) {
				if (j == (num_of_players - 1))j = 0;
				else j++;
			}
			if ((*game.rbegin()).get_number() == 8) {
				if (j == 0) j = (num_of_players - 1);
				else j--;
			}
			if ((*game.rbegin()).get_number() == 7) {
				players[j].take_card(deck1.get_card());
				// elegxos an exei kartes h trapoyla
				if (deck1.remaining_cards() == 0) {
					card top_card = *game.rbegin();
					game.pop_back();
					for (int i = 0; i < game.size(); i++) {
						deck1.get_card_back(*game.rbegin());
						game.pop_back();
					}
					game.push_back(top_card);
				}

				players[j].take_card(deck1.get_card());
			}
			// elegxos an exei kartes h trapoyla
			if (deck1.remaining_cards() == 0) {
				card top_card = *game.rbegin();
				game.pop_back();
				for (int i = 0; i < game.size(); i++) {
					deck1.get_card_back(*game.rbegin());
					game.pop_back();
				}
				game.push_back(top_card);
			} 
			//paizei o user
			if (j == 0) {
				cout << endl << "top card:" << endl;
				(*game.rbegin()).show_card();
				cout << endl << endl;
				cout << "this is your hand:" << endl;
				players[j].show_hand();
				bool can_be_played = false;
				int a = NULL;
				a = NULL;
				while (can_be_played == false) {
					cout << "give me your number of card you wanna play(51-> if you wanna take an extra card)..." << endl;

					cin >> a;
					if (a == 51 ||((a >= 0) && (a < players[j].remaining_cards()) &&
						( (*game.rbegin()).get_number() == players[j].show_card(a).get_number() ||
							(*game.rbegin()).get_shape() == players[j].show_card(a).get_shape()))) {
						can_be_played = true;
					}
				}
				switch (a)
				{
				case 51:
					if(deck1.remaining_cards() > 0)
					{
						players[j].take_card(deck1.get_card());
					}
					else {
						cout << "no card remained";
					}
					cout << "this is your hand now:" << endl;
					players[j].show_hand();
					can_be_played = false;
					a = NULL;
					while (can_be_played == false) {
						cout << "give me your number of card you wanna play(50-> if you wanna pass)..." << endl;
						cin >> a;
						if (a == 50 || ((a>= 0) && (a < players[j].remaining_cards()) && 
							((*game.rbegin()).get_number() == players[j].show_card(a).get_number() ||
								(*game.rbegin()).get_shape() == players[j].show_card(a).get_shape()))) {
							can_be_played = true;
						}
					}
					if (a == 50) break;
					game.push_back(players[j].give_card(a));
					break;

				default:
					game.push_back(players[j].give_card(a));
					break;
				}
				if (players[j].remaining_cards() == 0) {
					play = false;
					break;
				}
				cout << "this is your hand:" << endl;
				players[j].show_hand();
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			}
			 //paizei to bot
			else
			{
				
				cout << endl << "top card:" << endl;
				(*game.rbegin()).show_card();
				cout << endl << endl;
				srand(time(NULL));
				bool k = false;
				int a = NULL;
				bool can_be_played = false;
				while (can_be_played == false) {
					k = rand() % 3;
					switch (k)
					{
					case true:
						a = rand() % players[j].remaining_cards();
						break;

					case false:
						a = 51;
						break;
					}
					if ((a == 51) || ((a >= 0) && (a < players[j].remaining_cards()) &&
						((*game.rbegin()).get_number() == players[j].show_card(a).get_number() ||
							(*game.rbegin()).get_shape() == players[j].show_card(a).get_shape())))
						can_be_played = true;
				
				}
				
				switch (a)
				{
				case 51:
					cout << "take card" << endl;
					if(deck1.remaining_cards() > 0)
					{
						players[j].take_card(deck1.get_card());
					}
					can_be_played = false;
					while (can_be_played == false) {
						k = rand() % 10;
						switch (k)
						{
						case true:
							a = rand() % players[j].remaining_cards();
							break;

						case false:
							a = 50;
							break;
						}
						if ((a == 50) || ((a >= 0) && (a < players[j].remaining_cards()) &&
							((*game.rbegin()).get_number() == players[j].show_card(a).get_number() ||
								(*game.rbegin()).get_shape() == players[j].show_card(a).get_shape())))
							can_be_played = true;
					}
					if (a == 50) {
						cout << "player " << j << "passed." << endl;
					}
					else
					{
						game.push_back(players[j].give_card(a));
						cout << "player " << j << "played" << endl;
					}
					break;
				default:
					game.push_back(players[j].give_card(a)); 
					cout << "player " << j << "played"<<endl;

					break;
				}
				
				
				
				if (players[j].remaining_cards() == 0) {
					play = false;
					break;
				}
				cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
			}
			cout << endl << deck1.remaining_cards() << endl << endl;
							
		}
		
		//break;

	}

	cout << "Winer is player " << j << endl;
	cout << deck1.remaining_cards();

	return 0;
}