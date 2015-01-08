#include <string>
#include <iostream>

using namespace std;
namespace Betyg4 {
	class Node {
	public:
		Node *next;
		string value;

		Node() {
			next = nullptr;
			value = "";
		}

		Node(string value) {
			next = nullptr;
			this->value = value;
		}

	};

	class circular_list {
	private:
		Node *sentinel;

	public:
		circular_list() {
			sentinel = new Node();
			sentinel->next = sentinel;
		}

		void add(string value) {
			Node *n = new Node(value);
			Node *head = sentinel;
			//om listan bara innehåller sentinel noden
			if (sentinel->next == sentinel) {
				sentinel->next = n;
				n->next = sentinel;
			}
			//om listan innehåller flera noder
			else {
				n->next = sentinel->next;
				sentinel->next = n;
			}
		}

		bool empty() {
			if (sentinel->next == sentinel) {
				return true;
			}
			else {
				return false;
			}
		}
	};
}