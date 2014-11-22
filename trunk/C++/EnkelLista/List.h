#include <sstream>

using namespace std;

template<class INFO>
struct Node {
	INFO info;
	Node<INFO> *next;

	Node<INFO>() {
		this->next = nullptr;
	}

	Node<INFO>(INFO info) {
		this->info = info;
		this->next = nullptr;
	}
};

template<class INFO>
class List {
private:
	Node<INFO> *head;
	Node<INFO> *tail;

	Node<INFO> * nodeBefore(Node<INFO> *current) {
		Node<INFO> *n = head;

		while (n != nullptr) {
			if (n->next == current) {
				return n;
			}
			n = n->next;
		}

		return nullptr;
	}

public:
	List() {
		head = tail = nullptr;
	}

	//l�gger till nytt objekt l�ngst fram i listan
	void add_at_head(INFO info) {
		//om listan �r tom
		if (head == nullptr) {
			head = new Node<INFO>(info);
			tail = head;
		}
		//om listan inte �r tom
		else {
			Node<INFO> *n = new Node<INFO>(info);
			n->next = head;
			head = n;
		}
	}

	//l�gger till nytt objekt l�ngst bak i listan
	void add_at_tail(INFO info) {
		//om listan �r tom
		if (head == nullptr) {
			head = new Node<INFO>(info);
			tail = head;
		}
		//om listan inte �r tom
		else {
			Node<INFO> *n = new Node<INFO>(info);
			tail->next = n;
			tail = tail->next;
		}
	}

	//returnerar listans inneh�ll
	string str() {
		ostringstream oss;
		Node<INFO> *n = head;

		if (n == nullptr) {
			return "";
		}

		oss << '[';
		while (n != nullptr) {
			oss << n->info << ',';
			n = n->next;
		}
		string text = oss.str();
		text[text.size() - 1] = ']';
		return text;
	}
};