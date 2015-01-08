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

			while (input.compare("0") != 0) {
				cout << "Namn: ";
				cin >> input;
				personer.add(input);
			}
		}

		void printPersons() {
			personer.print();
		}
	};
}