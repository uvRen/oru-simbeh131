#pragma once
#include "circular_list.h"

using namespace std;

namespace Betyg41 {
	class josephus {
	private:
		Betyg4::circular_list personer;

	public:
		josephus() {

		}

		void addPersons() {
			string input = "";

			while (true) {
				cout << "Namn: ";
				cin >> input;
				if (input.compare("0") == 0) {
					break;
				}
				personer.add(input);
			}
		}

		void printPersons() {
			personer.print();
		}

		string playGame() {
			int antal = 1;
			for (Betyg4::circular_list::iterator it = personer.begin() + 1; personer.count() > 1; ++it) {
				if (it != personer.begin()) {
					if (antal % 3 == 0) {
						personer.remove(*it);
					}
					antal++;
				}
			}
			return personer.front();
		}
	};
}