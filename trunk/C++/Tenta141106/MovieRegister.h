#pragma once
#include "Movie.h"
#include <vector>
#include <fstream>
#include <sstream>

class Movieregister {
private:
	string name;
	vector<Movie> v;

public:
	Movieregister() {
		name = "";
	}

	Movieregister(string name) {
		this->name = name;
	}

	string getName() { return this->name; }

	void Add(Movie m) {
		v.push_back(m);
	}

	string List() {
		ostringstream oss;
		for (auto &r : v) {
			oss << r << endl;
		}
		return oss.str();
	}

	string Search(string keyword) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].getTitle().compare(keyword) == 0)
				return this->name;
		}
		return "";
	}

	int searchMovie(string keyword) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i].getTitle().compare(keyword) == 0)
				return i;
		}
		return -1;
	}

	void seenMovie(int pos) {
		v[pos].setHasSeenIt(true);
	}

	void deleteMovieFromRegsiter(int pos) {
		v.erase(v.begin() + pos);
	}

	void WriteToFile() {
		ofstream ut;
		string filnamn;

		filnamn = this->name + ".txt";
		ut.open(filnamn);

		ut << "Register=" << name << endl;
		for (auto &b : v)
			ut << "Movie=" << b << endl;

		ut.close();
	}

	void ReadFromFile() {
		ifstream in;
		string str, row, filnamn;
		v.clear();

		filnamn = this->name + ".txt";

		try {
			in.open(filnamn);

			while (getline(in, row)) {
				istringstream iss(row);
				getline(iss, str, '=');
				if (str.compare("Register") == 0) {
					getline(iss, this->name);
				}
				else if (str.compare("Movie") == 0){
					Movie m;
					iss >> m;
					if (m.getPlayingTime() != -1)
						v.push_back(m);
				}

			}
		}
		catch (exception e) {
			cout << "Exception thrown for file: " << filnamn << endl;
			cout << e.what();
		}
		in.close();
	}
};