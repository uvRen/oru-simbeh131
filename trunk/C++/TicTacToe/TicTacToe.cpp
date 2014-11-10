#include "TicTacToe.h"

using namespace std;

//konstruktor
TicTacToe::TicTacToe(void){
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			this->board[r][c] = ' ';
		}
	}
	this->row = 0;
	this->column = 0;
	this->xcursor = 0;
	this->ycursor = 0;
	this->moves = 0;
}

TicTacToe::~TicTacToe(void){
}

//medlemsfunktioner

void TicTacToe::printBoard() {
	cout << " ----------- " << endl << "|   |   |   |" << endl << "|-----------|" << endl << "|   |   |   |" << endl
		<< "|-----------|" << endl << "|   |   |   |" << endl << " ----------- " << endl;
	Course::Console::gotoxy(2, 2);
	setYCursor(2);
	setXCursor(2);
}

void TicTacToe::navigate(int currentX, int currentY, int key) { // returnera 1 om det är en giltig förflyttning
	/*
	W=119
	A=97
	S=115
	D=100
	*/
	if (key == 119) { // flyttar pekaren en ruta upp
		if (currentY != 2) {
			Course::Console::gotoxy(currentX, currentY - 2);
			setYCursor(getYCursor() - 2);
			reduceRow();
		}
	}
	else if (key == 115) { // flyttar pekaren en ruta ner
		if (currentY != 6) {
			Course::Console::gotoxy(currentX, currentY + 2);
			setYCursor(getYCursor() + 2);
			increaseRow();
		}
	}
	else if (key == 97) { // flyttar pekaren en ruta till vänster
		if (currentX != 2) {
			Course::Console::gotoxy(currentX - 4, currentY);
			setXCursor(getXCursor() - 4);
			reduceColumn();
		}
	}
	else if (key == 100) { // flyttar pekaren en ruta till höger
		if (currentX != 10) {
			Course::Console::gotoxy(currentX + 4, currentY);
			setXCursor(getXCursor() + 4);
			increaseColumn();
		}
	}
}

void TicTacToe::writeToArray(int rad, int kolumn, char tecken) {
	board[rad][kolumn] = tecken;
}

char TicTacToe::getValueFromArray(int rad, int kolumn) {
	return board[rad][kolumn];
}

int TicTacToe::checkForWinner() { // 0 -> ingen vinnare, 1 -> x vinner, 2 -> o vinner
	int x = 0, o = 0;
	for (int row = 0; row < 3; row++) { //kontrollerar om det finns en vinnare vågrätt
		for (int col = 0; col < 3; col++) {
			if (board[row][col] == 'x')
				x++;
			else if (board[row][col] == 'o')
				o++;
		}
		if (x == 3)
			return 1;
		else if (o == 3)
			return 2;
		x = 0;
		o = 0;
	}

	for (int col = 0; col < 3; col++) { //kontrollerar om det finns en vinnare vertikalt
		for (int row = 0; row < 3; row++) {
			if (board[row][col] == 'x')
				x++;
			else if (board[row][col] == 'o')
				o++;
		}
		if (x == 3)
			return 1;
		else if (o == 3)
			return 2;
		x = 0;
		o = 0;
	}

	for (int rc = 0; rc < 3; rc++) { // kontrollerar diagonalen top-left till right-bottom
		if (board[rc][rc] == 'x')
			x++;
		else if (board[rc][rc] == 'o')
			o++;
	}
	if (x == 3)
		return 1;
	else if (o == 3)
		return 2;
	x = 0;
	o = 0;

	for (int row = 0; row < 3; row++) { // kontrollerar diagonalen top-right till left-bottom
		if (board[row][2 - row] == 'x')
			x++;
		else if (board[row][2 - row] == 'o')
			o++;
	}
	if (x == 3)
		return 1;
	else if (o == 3)
		return 2;

	return 0;
}