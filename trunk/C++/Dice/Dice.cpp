#include "Dice.h"

using namespace std;

//konstruktor
Dice::Dice() {
	srand(unsigned(time(NULL)));
}

Dice::~Dice()
{
}

//medlemsfunktioner
void Dice::throw_dice() {
	this->value = rand() % 6 + 1;
}

void Dice::printDice(int value) {
	string tal[6] = { "-----\n!   !\n! x !\n!   !\n-----", "-----\n!  X!\n!   !\n!X  !\n-----",
		"-----\n!  X!\n! X !\n!X  !\n-----", "-----\n!X X!\n!   !\n!X X!\n-----",
		"-----\n!X X!\n! X !\n!X X!\n-----", "-----\n!X X!\n!X X!\n!X X!\n-----" }; //tärningarnas utseende

	cout << tal[value - 1] << endl;
}
