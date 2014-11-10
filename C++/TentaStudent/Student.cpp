#include "Student.h"

using namespace std;

//konstruktor
Student::Student(void)
{
	this->firstName = "";
	this->lastName = "";
	this->enrollmentYear = -1;
}

Student::Student(string firstName, string lastName, int enrollmentYear) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->enrollmentYear = enrollmentYear;
}

Student::~Student(void)
{
}

//medlemsfunktioner
void Student::write() {
	cout << setw(16) << "Firstname: " << firstName << endl << setw(16) << "Lastname: " << lastName << endl << "Enrollmentyear: " << enrollmentYear << endl;
}
void Student::read() {
	cout << "Firstname: ";
	cin >> firstName;
	cout << "Lastname: ";
	cin >> lastName;
	cout << "Enrollmentyear: ";
	cin >> enrollmentYear;
}

ostream &operator<<(ostream &stream, Student &a) {
	stream << "(" << a.firstName << "," << a.lastName << "," << a.enrollmentYear << ")";
	return stream;
}

istream &operator>>(istream &stream, Student &a) {
	string s;
	getline(stream, s, '(');
	getline(stream, a.firstName, ',');
	getline(stream, a.lastName, ',');
	stream >> skipws >> a.enrollmentYear;
	getline(stream, s, ')');

	return stream;
}