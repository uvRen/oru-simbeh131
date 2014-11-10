#include "Movie.h"
#include "MovieRegister.h"
#include "MovieDatabase.h"
#include <iostream>
#include <sstream>

void main3_3_1() {
	Movie m1, m2("Film", "Actor", 123, true, true);

	cout << m2 << endl;
}

void main3_3_2() {
	istringstream iss("(film,actor,120,1,0)");
	Movie m1;

	iss >> m1;
	cout << m1 << endl;
}

void main3_5() {
	Movieregister reg1("MinaFilmer1"), reg2("MinaFilmer2");
	istringstream iss("(film,actor,120,1,0)");
	Movie m1("Film2", "Actor2", 156, false, true), m2("Film", "Actor", 123, true, true), m3("Film3", "Actor3", 145, false, true), m4("Film4", "Actor4", 45, false, true);
	iss >> m1;

	reg1.Add(m1);
	reg1.Add(m2);
	reg2.Add(m3);
	reg2.Add(m4);

	reg1.WriteToFile();
	reg1.ReadFromFile();

	reg2.WriteToFile();
	reg2.ReadFromFile();

	cout << reg1.List() << endl;
	cout << reg2.List() << endl;
}

void main4_1() {
	MovieDatabase db;
	Movieregister reg1("MinaFilmer1"), reg2("MinaFilmer2");

	Movie m1("Film2", "Actor2", 156, false, true), m2("Film", "Actor", 123, true, true), m3("Film3", "Actor3", 145, false, true), m4("Film4", "Actor4", 45, false, true);

	reg1.Add(m1);
	reg1.Add(m2);
	reg2.Add(m3);
	reg2.Add(m4);

	db.AddRegister(reg1);
	db.AddRegister(reg2);

	db.WriteDatabaseToFile();


}

void main4_2() {
	MovieDatabase db;
	Movieregister reg1("MinaFilmer1"), reg2("MinaFilmer2");

	Movie m1("Film2", "Actor2", 156, false, false), m2("Film", "Actor", 123, true, true), m3("Film3", "Actor3", 145, false, true), m4("Film4", "Actor4", 45, false, true);

	reg1.Add(m1);
	reg1.Add(m2);
	reg2.Add(m3);
	reg2.Add(m4);

	db.AddRegister(reg1);
	db.AddRegister(reg2);

	while (true) {
		system("cls");
		if (db.Menu() == -1)
			break;
	}

}

int main() {
	//main3_3_1();
	//main3_3_2();
	//main3_5();
	//main4_1();
	main4_2();
	system("pause");
	return 0;
}