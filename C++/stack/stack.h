#include <iostream>
#include <ostream>

using namespace std;

template<class T>
struct Node {
	T info;
	Node *next;

	Node<T>() {
		next = nullptr;
	}

	Node<T>(T info) {
		this->info = info;
		next = nullptr;
	}
};

template<class T>
class stack {
private:
	Node<T> *head;
public:
	//konstruktor
	stack() {
		head = new Node<T>;
	}

	//funktioner
	void push(T info) {
		//listan är tom
		if (head == nullptr) {
			head->next = new Node<T>(info);
		}
		else {
			Node<T> *n = new Node<T>(info);
			n->next = head->next;
			head->next = n;
		}
	}

	T pop() {
		T info = head->next->info;
		Node<T> *n = head->next;
		if (head->next->next != nullptr) {
			head->next = head->next->next;
		}
		else {
			head->next = nullptr;
		}
		delete n;
		return info;
	}

	friend ostream& operator<<(ostream &ut, const stack<T> &a) {
		if (a.head->next != nullptr) {
			Node<T> *n = a.head->next;
			while (n != nullptr) {
				ut << '[' << n->info << ']' << endl;
				n = n->next;
			}
		}
		return ut;
	}

	T top() {
		return head->next->info;
	}
};