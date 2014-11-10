#include "Car.h"

//kontruktor
Car::Car() {
	this->brand = "";
	this->year = 0;
	this->price = 0;
}

Car::Car(string brand, int year, double price) {
	this->brand = brand;
	this->year = year;
	this->price = price;
}

Car::~Car()
{
}

//medlemsfunktioner

void Car::readFromConsole() {
	cout << "Ange m\x84rke: ";
	cin >> this->brand;
	cout << "Ange tillverknings\x86r: ";
	cin >> this->year;
	cout << "Ange pris: ";
	cin >> this->price;
	cout << endl;
}

void Car::writeToConsole() {
	cout << "M\x84rke: " << this->brand << endl << "Tillverknings\x86r: " << this->year << endl << "Pris: " << this->price << endl << endl;
}