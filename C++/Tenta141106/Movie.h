#pragma once
#include <string>
#include <iostream>

using namespace std;

class Movie {
private:
	string title, actors;
	int playing_time;
	bool isOwner, hasSeenIt;

public:
	//konstruktor
	Movie() {
		this->title = "";
		this->actors = "";
		this->playing_time = -1;
		this->isOwner = false;
		this->hasSeenIt = false;
	}
	Movie(string title, string actors, int playing_time, bool isOwner, bool hasSeenIt) {
		this->title = title;
		this->actors = actors;
		this->playing_time = playing_time;
		this->isOwner = isOwner;
		this->hasSeenIt = hasSeenIt;
	}

	//medlemsfunktioner
	void setOwner(bool isOwner) { this->isOwner = isOwner; }
	void setHasSeenIt(bool hasSeenIt) { this->hasSeenIt = hasSeenIt; }
	int getPlayingTime() { return playing_time; }
	string getTitle() { return title; }

	void Read() {
		cout << "Filmens titel: ";
		cin >> title;
		cout << "Skådespelare: ";
		cin >> actors;
		cout << "Speltid: ";
		cin >> playing_time;
		cout << "Äger du filmen? ";
		cin >> isOwner;
		cout << "Har du sett filmen? ";
		cin >> hasSeenIt;
	}

	//(title,actors,playing_time,isOwner,hasSeenIt)
	friend ostream& operator<<(ostream &ut, const Movie &m) {
		ut << '(';
		ut << m.title << ',';
		ut << m.actors << ',';
		ut << m.playing_time << ',';
		ut << m.isOwner << ',';
		ut << m.hasSeenIt << ')';

		return ut;
	}

	//(title,actors,playing_time,isOwner,hasSeenIt)
	friend istream& operator>>(istream &in, Movie &m) {
		string s;
		getline(in, s, '(');
		getline(in, m.title, ',');
		getline(in, m.actors, ',');
		in >> skipws >> m.playing_time;
		getline(in, s, ',');
		in >> skipws >> m.isOwner;
		getline(in, s, ',');
		in >> skipws >> m.hasSeenIt;
		getline(in, s, ')');

		return in;
	}
};