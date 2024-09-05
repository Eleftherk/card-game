#pragma once
#ifndef CARD_H
#define CARD_H
#include <string>


using namespace std;

class card
{
	int number;
	string shape;
	//++++image 

public:
	card();
	card(int num, string shap);

	void set_number(int num);
	void set_shape(string shap);
	void show_card();
	int get_number();
	string get_shape();
	//++create_image
	//+++ show_image 

	~card();

};
#endif

