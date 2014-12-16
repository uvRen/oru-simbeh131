#pragma once
#include <string>
#include <algorithm>
#include <fstream>
#include "words.h"

namespace Betyg4 {
	using namespace std;

	class Node {
	public:
		string INFO;
		int antal;
		Node *next;

		Node() {
			INFO = "";
			antal = 0;
			next = nullptr;
		}

		Node(string INFO) {
			this->INFO = INFO;
			antal = 1;
			next = nullptr;
		}
	};

	class unordered_list {
	private:
		Node *head;
		Node *tail;
		Node *freelist;

	public:
#pragma region Kontruktor
		unordered_list() {
			head = new Node();
			freelist = new Node();
		}

		unordered_list(int size_freelist) {
			head = new Node();
			freelist = new Node();

			for (int i = 0; i < size_freelist; i++) {
				Node *n = new Node();
				n->next = freelist->next;
				freelist->next = n;
			}
		}

		~unordered_list() {
			Node *n = head->next;
			Node *temp = head;

			while (n != nullptr) {
				temp = n->next;
				delete n;
				n = temp;
			}

			n = freelist->next;
			while (n != nullptr) {
				temp = n->next;
				delete n;
				n = temp;
			}

			head->next = nullptr;
			freelist->next = nullptr;
		}

#pragma endregion Konstruktor

#pragma region Iterator
		class iterator {
		public:
			//konstruktor
			iterator(Node *n) {
				current = n;
			}

			//funktioner
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
				return current->INFO;
			}

		private:
			Node* current;
		};

#pragma endregion Iterator

#pragma region Medlemsfunktioner

		Node* lastNode() {
			Node *n = head;

			while (n->next != nullptr) {
				n = n->next;
			}
			return n;
		}

		void add(string INFO) {
			//om ordet redan finns i listan
			Node *n = nullptr;
			n = findWord(INFO);
			if (n != nullptr) {
				n->antal = n->antal + 1;
			}
			else{
				//om det finns noder lediga i freelist
				if (freelist->next != nullptr) {
					Node *n = freelist->next;
					if (freelist->next->next != nullptr) {
						freelist->next = freelist->next->next;
					}
					else {
						freelist->next = nullptr;
					}
					n->INFO = INFO;
					n->antal = 1;
					n->next = nullptr;
					Node *last = lastNode();
					last->next = n;
				}
				//annars allokera minne för en ny nod
				else {
					Node *n = new Node(INFO);
					Node *last = lastNode();
					last->next = n;
				}
			}
		}

		void delete_head_node() {
			Node *n = head->next;
			head->next = n->next;

			n->INFO = "";
			n->antal = 0;
			n->next = freelist->next;
			freelist->next = n;
		}

		void clear() {
			Node *n = head->next;
			Node *temp = head;

			while (head->next != nullptr) {
				temp = head->next;
				head->next = head->next->next;
				temp->INFO = "";
				temp->antal = 0;
				temp->next = freelist->next;
				freelist->next = temp;
			}
		}

		iterator begin() {
			return iterator(head->next);
		}

		iterator end() {
			Node *n = head;

			while (n != nullptr) {
				n = n->next;
			}
			return iterator(n);
		}
		
		int countWords() {
			int antal = 0;
			unordered_list::iterator it = begin();
			for (it = begin(); it != end(); ++it) {
				antal++;
			}
			return antal;
		}

		Node* findWord(string word) {
			Node *n = head->next;

			while (n != nullptr) {
				if (n->INFO.compare(word) == 0) {
					return n;
				}
				n = n->next;
			}
			return nullptr;
		}

		pair<string, int> findMostFrekventWord() {
			pair<string, int> a;
			string word = "";
			int antal = 0;

			unordered_list::iterator it = begin();
			for (it = begin(); it != end(); ++it) {
				if (it->antal > antal) {
					a.first = it->INFO;
					a.second = it->antal;
					antal = it->antal;
				}
			}
			return a;
		}

		void ReadFromFile() {
			ifstream in;
			string row, word;
			int antal = 0;

			try {
				in.open("nils_holgersson.txt");
				if (!in.good()) {
					cout << "Gick ej att öppna filen!" << endl;
				}

				else {
					clear();

					while (getline(in, row)) {
						istringstream iss(row);
						while (getline(iss, word, ' ')) {
							word = words::stringManipulation(word);
							add(word);
						}
					}
				}
				in.close();
			}

			catch (exception e) {

			}

		}

		
#pragma endregion Medlemsfunktioner

		string showValue(Node *n) {
			return n->INFO;
		}

		void printList() {
			Node *n = head->next;

			while (n != nullptr) {
				cout << n->INFO << endl;
				n = n->next;
			}
			cout << endl;
		}

		void count() {
			int list, free;
			list = free = 0;

			Node *n = head->next;
			while (n != nullptr) {
				list++;
				n = n->next;
			}

			n = freelist->next;
			while (n != nullptr) {
				free++;
				n = n->next;
			}

			cout << "Lista: " << list << endl << "Freelist: " << free << endl;
		}
	};
}