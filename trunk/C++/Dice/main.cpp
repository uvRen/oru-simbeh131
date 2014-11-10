#include "Dice.h"
#include <cstdio>

using namespace std;

int main() {
	Dice d;
	int pressedKey; // 10 = ENTER

	cout << "Kasta en ny t\x84rning med ENTER. F\x94r att avsluta tryck valfri annan tangent." << endl;
	pressedKey = getchar();

	while (pressedKey == 10) {
		d.throw_dice();
		d.printDice(d.read());

		pressedKey = getchar();
	}

	system("pause");
}