#include <exception>
#include <iostream>

template<class INFO>
struct Node {
	INFO information;
	Node<INFO> *next;

	Node<INFO>() {
		next = nullptr;
	}

	Node<INFO>(INFO a) {
		information = a;
		next = nullptr;
	}
};

template<class INFO>
class List {
private:
	Node<INFO> *head;
	Node<INFO> *tail;

public:
	//konstruktor
	List() {
		head = tail = nullptr;
	}

	//funktioner
	bool isEmpty() {
		return (head == nullptr);
	}

	//add_at_head
	void push_front(INFO a) {
		//om listan är tom
		if (head == nullptr) {
			head = new Node<INFO>(a);
			tail = head;
		}
		else {
			Node<INFO> *n = new Node<INFO>(a);
			n->next = head;
			head = n;
		}
	}

	INFO pop() {
		Node<INFO> *n = head;
		INFO a = head->information;

		head = head->next;
		delete n;
		return a;
	}

	int count() {
		Node<INFO> *n = head;
		int i = 0;

		while (n != nullptr) {
			i++;
			n = n->next;
		}

		return i;
	}
};