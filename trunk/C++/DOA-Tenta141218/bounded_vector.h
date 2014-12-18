#include <iostream>

using namespace std;

namespace Betyg4 {

	class Node {
	public:
		char c;
		int antal;
		Node *next;

		Node() {
			c = ' ';
			antal = 0;
		}

		Node(char c) {
			this->c = c;
			antal = 1;
		}
	};

	class bounded_list {
	private:
		Node *head;

	public:

		bounded_list() {
			head = new Node();
			head->next = nullptr;

			Node *n = head;

			for (int i = 122; i >= 97; i--) {
				Node *ny = new Node(i);
				ny->next = head->next;
				head->next = ny;
			}
		}

		void printList() {
			Node *n = head->next;
			while (n != nullptr) {
				cout << n->c << endl;
				n = n->next;
			}
		}

	};
}