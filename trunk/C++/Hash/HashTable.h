#include <string>
#include <iostream>
#include <vector>
#include <ostream>
#include <list>

using namespace std;

class Node {
public:
	string key;
	int value;
	Node *next;

	Node() {
		key = "";
		value = 0;
		next = nullptr;
	}

	Node(string key, int value) {
		this->key = key;
		this->value = value;
		next = nullptr;
	}

	void HEJ() {

	}

	friend ostream& operator<<(ostream &ut, const Node &n) {
		ut << '[' << n.key << ',' << n.value << ',' << n.next << ']';
		return ut;
	}
};

class HashTable {
private:
	Node *head;
	//vector<Node> *table;
	list<Node> *table;

public:
	HashTable(int size) {
		for (int i = 0; i < size; i++) {
			table->push_front(Node());
		}
	}

	//void insert(int index, Node n) {
	//	int i=0;
	//	for (list<Node>::iterator it = table->begin(); i <= index; ++it, i++) {
	//		/*if (i == index) {
	//			table->insert(it, n);
	//		}*/
	//	}
	//}









	//HashTable() {
	//	table = new vector<Node>(20);

	//	for (auto &a : *table) {
	//		a = Node();
	//	}
	//}
	//
	//void insert() {
	//	/*for (vector<Node>::iterator it = table->begin(); it != table->end(); ++it) {
	//		if (it == table->begin())
	//			*it = Node("Nyckel", 12);
	//	}*/

	//	table[0] = Node();

	//	for (auto &a : *table)
	//		cout << a << endl;
	//}
};
