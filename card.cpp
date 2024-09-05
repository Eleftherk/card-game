
#include "card.h"
#include<string>
#include <iostream>

using namespace std;
card::card() {
	number = NULL;
	shape = "";

}
card::card(int num, string shap) {
	number = num;
	shape = shap;
}
void card::set_number(int num) {
	number = num;
}
void card::set_shape(string shap) {
	shape = shap;
}
void card::show_card() {
	if (number == 1) {
		cout << "Number: " << "A" << "\n" << "Shape: " << shape << endl;
	}
	else if (number == 11) {
		cout << "Number: " << "J" << "\n" << "Shape: " << shape << endl;
	}
	else if (number == 12) {
		cout << "Number: " << "Q" << "\n" << "Shape: " << shape << endl;
	}
	else if (number == 13) {
		cout << "Number: " << "K" << "\n" << "Shape: " << shape << endl;
	}
	else {
		cout << "Number: " << number << "\n" << "Shape: " << shape << endl;
	}

}
int card::get_number() {
	return number;
}
string card::get_shape() {
	return shape;
}




card::~card()
{
}
