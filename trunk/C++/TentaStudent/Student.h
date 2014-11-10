#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Student
{
private:
	string firstName, lastName;
	int enrollmentYear;

public:
	//konstruktor
	Student(void);
	Student(string firstName, string lastName, int enrollmentYear);
	~Student(void);

	//medlemsfunktioner
	//get/set funktioner
	string getFirstName() { return this->firstName; }
	string getLastName() { return this->lastName; }
	int getenrollmentYear() { return this->enrollmentYear; }

	void setFirstName(string firstName) { this->firstName = firstName; }
	void setLastName(string lastName) { this->lastName = lastName; }
	void setenrollmentYear(int enrollmentYear) { this->enrollmentYear = enrollmentYear; }

	//read and write
	void read();
	void write();

	friend ostream &operator<<(ostream &stream, Student &a);
	friend istream &operator>>(istream &stream, Student &a);
};

