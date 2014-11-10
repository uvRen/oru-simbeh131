#include "TicTacToe.h"

using namespace std;

int main() {
	TicTacToe a;
	int pressedKey = 0;
	cout << "Du navigerar i spelet med W,A,S och D. Avsluta med ESC" << endl;
	a.printBoard();

	while (pressedKey != 27) { // avsluta om ESC
		pressedKey = _getch();
		if (pressedKey == 13) { // placering av x eller o vid ENTER
			if (a.getMoves() % 2 == 0 && a.getValueFromArray(a.getRow(), a.getColumn()) == ' ') { //jämnt delbart = x-tur och kollar ifall det redan finns ett teckan i rutan
				cout << "x";
				a.writeToArray(a.getRow(), a.getColumn(), 'x'); //skriver 'x' till arrayen till angiven position
			}
			else if (a.getValueFromArray(a.getRow(), a.getColumn()) == ' ') { // kollar om rutan är tom
				cout << "o";
				a.writeToArray(a.getRow(), a.getColumn(), 'o'); //skriver 'o' till arrayen till angiven position
			}
			a.increaseMoves();
		}
		else { // navigering i spelplanen
			a.navigate(a.getXCursor(), a.getYCursor(), pressedKey);
		}

		if (a.getMoves() > 4) { //kontrollering om det finns en vinnare
			if (a.getMoves() >= 9) {
				Course::Console::gotoxy(0, 9);
				cout << "OAVGJORT";
				break;
			}
			int winner = a.checkForWinner();
			if (winner == 1) {
				Course::Console::gotoxy(0, 9);
				cout << "X VINNER";
				break;
			}
			else if (winner == 2) {
				Course::Console::gotoxy(0, 9);
				cout << "O VINNER";
				break;
			}
		}
	}
	Course::Console::gotoxy(0, 10); // avslutningstexten skrivs under spelplanen
	system("pause");

	return 0;
}