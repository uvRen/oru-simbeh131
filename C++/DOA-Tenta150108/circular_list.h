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

		Node& operator=(const Node &obj) {
			next = obj.next;
			value = obj.value;
			return *this;
		}
	};

	class circular_list {
	private:
		Node *sentinel;

	public:
		class iterator {
		private:
			Node *current;
		public:
			iterator(Node *n) {
				current = n;
			}

			iterator operator++() {
				current = current->next;
				return *this;
			}

			iterator operator+(int plus) {
				for (int i = 0; i < plus; i++) {
					current = current->next;
				}
				return *this;
			}

			bool operator!=(const iterator &rhs) {
				return (current != rhs.current);
			}

			bool operator==(const iterator &rhs) {
				return (current == rhs.current);
			}

			Node* operator->() {
				return current;
			}

			string& operator*() {
				return current->value;
			}
		};

		//konstruktor
		circular_list() {
			sentinel = new Node();
			sentinel->next = sentinel;
		}

		//kopieringkonstruktor
		circular_list(const circular_list &obj) {
			sentinel = new Node();
			Node *n = obj.sentinel->next;
			Node *ny = sentinel;
			
			while (n != sentinel) {
				Node *add = new Node(n->value);
				ny->next = add;
				ny = ny->next;
				n = n->next;
			}
			ny->next = sentinel;
		}

		//funktioner
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

		string front() {
			return sentinel->next->value;
		}

		void print() {
			for (circular_list::iterator it = begin()+1; it != begin(); ++it) {
				cout << *it << " ";
			}
			/*Node *n = sentinel->next;
			while (n != sentinel) {
				cout << n->value << " ";
				n = n->next;
			}
			cout << endl;*/
		}

		iterator begin() {
			return iterator(sentinel);
		}

		iterator end() {
			Node *n = sentinel;

			while (n->next != sentinel) {
				n = n->next;
			}
			return iterator(n);
		}
	};
}