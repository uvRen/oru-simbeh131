#pragma once
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <string>

class Dice
{
private:
	int value;

public:
	//konstruktor
	Dice();
	~Dice();

	//medlemsfunktioner
	int read() { return this->value; }
	void throw_dice();
	void printDice(int value);
};

