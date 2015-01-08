#pragma once
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
			Node *n = sentinel;
			Node *old = obj.sentinel->next;

			while (old != sentinel) {
				n->next = new Node(old->value);
				n = n->next;
				old = old->next;
			}
			n->next = sentinel;
		}

		//funktioner
		circular_list& operator=(const circular_list &obj) {
			sentinel = new Node();
			Node *n = sentinel;
			Node *old = obj.sentinel->next;

			while (old != sentinel) {
				n->next = new Node(old->value);
				n = n->next;
				old = old->next;
			}
			n->next = sentinel;

			return *this;
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

		string front() {
			return sentinel->next->value;
		}

		void print() {
			for (circular_list::iterator it = begin()+1; it != begin(); ++it) {
				cout << *it << " ";
			}
		}

		//tar bort första noden
		void remove() {
			if (sentinel->next != sentinel) {
				if (sentinel->next->next == sentinel) {
					sentinel->next = sentinel;
				}
				else {
					Node *n = sentinel->next;
					sentinel->next = sentinel->next->next;
					delete n;
				}
			}
		}

		void remove(iterator position) {
			Node *n = sentinel;
			Node *before = new Node();

			circular_list::iterator check = begin();

			for (circular_list::iterator it = begin(); it != end(); ++it) {
				if (count() == 1) {
					sentinel->next = sentinel;
				}
				else {
					check = it;
					check = ++check;
					if (check == position) {
						before = n;
					}
					if (it == position) {
						before->next = n->next;
					}
					n = n->next;
				}
			}
		}

		void remove(string namn) {
			Node *n = sentinel->next;
			Node *before = sentinel;

			for (circular_list::iterator it = begin()+1; it != begin(); ++it) {
				if (count() == 1) {
					sentinel->next = sentinel;
				}
				else if (count() == 2) {
					if (sentinel->next->value.compare(namn) == 0) {
						sentinel->next = sentinel->next->next;
					}
					else {
						sentinel->next->next = sentinel;
					}
				}
				else {
					if (n->value.compare(namn) == 0) {
						before->next = n->next;
					}
					else {
						n = n->next;
						before = before->next;
					}
					

				}
			}
		}

		int count() {
			int antal = 0;
			Node *n = sentinel->next;

			while (n != sentinel) {
				antal++;
				n = n->next;
			}
			return antal;
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