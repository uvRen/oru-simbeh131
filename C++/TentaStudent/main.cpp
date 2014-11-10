#include "Studentregister.h"

using namespace std;

int main() {
	locale swedish("swedish");
	locale::global(swedish);

	Studentregister reg;
	reg.setSchool("Örebro Universitet");

	istringstream iss1("(Simon,Berntsson,2013)");
	istringstream iss2("(Bella,Johnsson,2014)");
	Student s1, s2;

	//reg.Add(s1);
	//string s = reg.List();

	//cout << s << endl;

	cout << s1 << endl;
	iss1 >> s1;
	iss2 >> s2;
	s1.write();
	s2.write();

	reg.Add(s1);
	reg.Add(s2);
	string s = reg.List();

	cout << endl << reg.getSchool() << endl;

	cout << reg.List() << endl;

	reg.WriteToFile();
	reg.ReadFromFile("studenter.txt");

	cout << "Efter läsning:" << endl << reg.List() << endl;

	system("pause");
}