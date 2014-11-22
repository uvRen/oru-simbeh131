#include <string>
#include <sstream>

using namespace std;

struct Node {
	string name;
	Node *next;

	Node() {
		name = "";
		next = nullptr;
	}

	Node(string name) {
		this->name = name;
		next = nullptr;
	}
};

class List {
private:
	Node *head;
	Node *tail;

	Node* nodeBefore(Node *find) {
		Node *n = head;

		while (n != nullptr) {
			if (n->next = find)
				return n;

			n = n->next;
		}

		return nullptr;
	}

public:
	//konstruktor
	List() {
		head = tail = nullptr;
	}

	//funktioner

	//l�gger till ett objekt l�ngst fram i listan
	void add_at_head(string name) {
		//lista �r tom
		if (head == nullptr) {
			head = new Node(name);
			tail = head;
		}
		//listan �r INTE tom
		else {
			Node *n = new Node(name);
			n->next = head;
			head = n;
		}
	}

	//l�gger till ett objekt sist i listan
	void add_at_tail(string name) {
		//listan �r tom
		if (head == nullptr) {
			Node *n = new Node(name);
			head = n;
			tail = head;
		}
		//listan �r INTE tom
		else {
			Node *n = new Node(name);
			//om det finns ETT objekt i listan
			if (head == tail) {
				head->next = n;
				tail = n;
			}
			//om det finns FLERA objekt i listan
			else {
				Node *n = new Node(name);
				tail->next = n;
				tail = n;
			}
		}
	}

	//returnerar listans inneh�ll
	string printList() {
		ostringstream oss;
		Node *n = head;

		oss << '[';
		while (n != nullptr) {
			oss << n->name;
			if (n->next != nullptr)
				oss << ',';
			n = n->next;
		}
		oss << ']';

		return oss.str();
	}
};