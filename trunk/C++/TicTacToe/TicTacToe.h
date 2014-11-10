#pragma once
#include <iostream>
#include <conio.h>
#include "Console.h"
#include <cstdio>

class TicTacToe
{
private:

	int xcursor, ycursor, moves;
	int row, column; // positionerna i board arrayen

	//private funktioner som ändrar rad och kolumn
	void increaseRow() { this->row++; }
	void reduceRow() { this->row--; }
	void increaseColumn() { this->column++; }
	void reduceColumn() { this->column--; }

public:
	char board[3][3];
	//konstruktor
	TicTacToe(void);
	~TicTacToe(void);

	//medlemsfunktioner
	void printBoard();
	void navigate(int currentX, int currentY, int key);
	void navigateBack(int currentX, int currentY);
	void increaseMoves() { this->moves++; }
	int getMoves() { return this->moves; }
	int checkForWinner(); // 0 -> ingen vinnare, 1 -> x vinner, 2 -> o vinner
	void writeToArray(int row, int column, char tecken);
	char getValueFromArray(int row, int column);

	//get & set för vart muspekaren befinner sig
	void setXCursor(int x) { this->xcursor = x; }
	void setYCursor(int y) { this->ycursor = y; }
	int getXCursor() { return this->xcursor; }
	int getYCursor() { return this->ycursor; }

	//get & set för rad och kolumn i arrayen
	int getRow() { return row; }
	int getColumn() { return column; }
};

