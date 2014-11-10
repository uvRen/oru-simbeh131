#pragma once
#include <string>
#include <iostream>

using namespace std;

class Car
{
private:
	string brand;
	int year;
	double price;

public:
	//konstruktor
	Car();
	Car(string brand, int year, double price);
	~Car();

	//medlemsfunktioner
	void readFromConsole();
	void writeToConsole();

	//get/set funktioner
	string getBrand() { return this->brand; }
	void setBrand(string brand) { this->brand = brand; }

	int getYear() { return this->year; }
	void setYear(int year) { this->year = year; }

	double getPrice() { return this->price; }
	void setPrice(double price) { this->price = price; }
};

