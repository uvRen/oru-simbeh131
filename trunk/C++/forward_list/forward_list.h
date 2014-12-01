#include <sstream>
#include <iostream>
#include <ostream>
#include <xmemory>
#include <stdexcept>

using namespace std;

template<class T>
struct Node {
	T information;
	Node<T> *next;

	Node<T>() {
		this->next = nullptr;
	}

	Node<T>(T information) {
		this->information = information;
		next = nullptr;
	}
};

template<class T>
class forward_list {
private:
	Node<T> *head;
	Node<T> *tail;

public:
	//konstruktor
	forward_list() {
		head = nullptr;
	}

	~forward_list() {

	}

	class Interator {
	public:
		Iterator(Node<T> *n) {
			current = n;
		}

		Iterator operator++() {
			current = current->next;
			return *this;
		}
		
	private:
		Node<T>* current;
	};

	//funktioner
	bool empty() {
		return (head == nullptr);
	}

	void push_front(T info) {
		//om listan �r tom
		if (head == nullptr) {
			head = new Node<T>(info);
		}
		//om listan inte �r tom
		else {
			Node<T> *n = new Node<T>(info);
			n->next = head;
			head = n;
		}
	}

	void pop() {
		Node<T> *n = head;

		//om listan bara har ett objekt
		if (head->next == nullptr) {
			head = nullptr;
		}
		else {
			head = head->next;
		}
		delete n;
	}

	T& front() {
		return head->information;
	}
};