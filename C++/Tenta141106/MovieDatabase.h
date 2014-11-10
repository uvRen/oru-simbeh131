#include "Movie.h"
#include "MovieRegister.h"

class MovieDatabase {
private:
	string activeRegister;
	vector<Movieregister> v;

public:
	MovieDatabase() {
		activeRegister = "";
	}

	void AddRegister(Movieregister r) {
		v.push_back(r);
	}

	void selectActiveRegister() {
		string s;
		system("cls");
		cout << "Ange vilket register du vill anv\x84nda: ";
		cin >> activeRegister;
		getline(cin, s);
	}

	void WriteDatabaseToFile() {
		ofstream ut;
		ut.open("db.txt");

		for (int i = 0; i < v.size(); i++) {
			ut << '(' << v[i].getName() << ')' << endl;
		}

		ut.close();
	}

	vector<string> Search() {
		vector<string> a;
		string result = "", keyword;

		system("cls");
		cout << "Ange namnet p\x86 filmen: ";
		cin >> keyword;

		a.push_back("Filmen finns i f\x94ljnde register:");

		for (int i = 0; i < v.size(); i++) {
			result = v[i].Search(keyword);
			if (result != "")
				a.push_back(result);
		}
		for (int i = 0; i < a.size(); i++) {
			cout << a[i] << endl;
		}
		cout << endl;
		system("pause");
		return a;
	}

	void AddMovie() {
		if (activeRegister.compare("") == 0) {
			selectActiveRegister();
		}
		else {
			for (int i = 0; i < v.size(); i++) {
				if (v[i].getName().compare(activeRegister) == 0) {
					Movie m;
					m.Read();
					v[i].Add(m);
				}
			}
		}
	}

	void seenMovie() {
		string movie;
		if (activeRegister.compare("") == 0) {
			selectActiveRegister();
		}
		else {
			cout << "Vilken film har du sett? ";
			cin >> movie;

			for (int i = 0; i < v.size(); i++) {
				if (v[i].getName().compare(activeRegister) == 0) {
					v[i].seenMovie(v[i].searchMovie(movie));
				}
			}
		}
	}

	void deleteMovie() {
		if (activeRegister.compare("") == 0) {
			selectActiveRegister();
		}
		string movie;
		cout << "Vilken film vill du ta bort? ";
		cin >> movie;

		for (int i = 0; i < v.size(); i++) {
			if (v[i].getName().compare(activeRegister) == 0) {
				v[i].deleteMovieFromRegsiter(v[i].searchMovie(movie));
			}
		}
	}

	int Menu() {
		int val = -1;
		string s;
		cout << "1. V\x84lj aktivt register" << endl;
		cout << "2. S\x94k efter en film i alla register" << endl;
		cout << "3. Mata in en ny film" << endl;
		cout << "4. Ta bort en film" << endl;
		cout << "5. Ange att du har sett en film" << endl;
		cout << "Val: ";

		cin >> val;
		getline(cin, s);

		switch (val) {
		case -1:
			return -1;
		case 1:
			selectActiveRegister();
			break;
		case 2:
			Search();
			break;
		case 3:
			AddMovie();
			break;
		case 4:
			deleteMovie();
			break;
		case 5:
			seenMovie();
			break;
		default:
			break;
		}
		return 1;
	}
};