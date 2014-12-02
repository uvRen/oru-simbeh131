#include <iostream>
#include <ostream>

using namespace std;

template<class T>
struct Node {
	T info;
	Node<T> *next;
	Node<T> *before;

	Node<T>() {
		next = nullptr;
		before = nullptr;
	}

	Node<T>(T info) {
		this->info = info;
		next = nullptr;
		before = nullptr;
	}
};

template<class T>
class queue {
//private:
	

public:
	Node<T> *head;
	Node<T> *tail;
	//konstruktor
	queue() {
		head = new Node<T>();
		tail = new Node<T>();
		head->next = tail;
	}

	//funktioner
	void push(T info) {
		//om listan är tom
		if (head->next == tail) {
			Node<T> *n = new Node<T>(info);
			head->next = n;
			tail->before = n;
			n->next = tail;
		}
		else {
			Node<T> *n = new Node<T>(info);
			tail->before->next = n;
			tail->before = n;
			n->next = tail;
		}
	}

	T pop() {
		T info = head->next->info;
		Node<T> *n = head->next;

		head->next = head->next->next;
		delete n;

		return info;
	}

	friend ostream& operator<<(ostream &ut, const queue<T> &a) {
		if (a.head->next != nullptr) {
			Node<T> *n = a.head->next;
			while (n != nullptr) {
				ut << '[' << n->info << ']' << endl;
				if (n->next == a.tail)
					break;
				n = n->next;
			}
		}
		return ut;
	}
};