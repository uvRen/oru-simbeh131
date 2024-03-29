#pragma once
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

public:
	
	#pragma region Iterator
	class iterator {
	public:
		//konstruktor
		iterator(Node<T> *n) {
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

		Node<T>* operator->() {
			return current;
		}

		T& operator*() {
			return current->information;
		}

	private:
		Node<T>* current;
	};
	#pragma endregion Iterator

	#pragma region Konstruktor
	//konstruktor
	forward_list() {
		head = nullptr;
	}
	

	forward_list(const forward_list &obj) {
		Node<T> *old = obj.head;
		Node<T> *ny;
		head = new Node<T>(obj.head->information);
		ny = head;
		old = old->next;

		while (old != nullptr) {
			ny->next = new Node<T>(old->information);
			ny = ny->next;
			old = old->next;
		}
	}

	virtual ~forward_list() {
		clear();
	}
	#pragma endregion Konstruktor


	#pragma region forward_list orginal funktioner
	//funktioner
	void clear() {
		Node<T> *n = head;

		while (n != nullptr) {
			Node<T> *temp = n->next;
			delete n;
			n = temp;
		}
		head = nullptr;
	}

	forward_list& operator=(forward_list &right) {
		clear();

		head = new Node<T>(right.head->information);
		Node<T> *n = head;
		Node<T> *old = right.head->next;

		while (old != nullptr) {
			n->next = new Node<T>(old->information);
			n = n->next;
			old = old->next;
		}

		return *this;
	}

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

	void pop_front() {
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

	iterator insert_after(iterator position, T &value) {
		Node<T> *n = head;
		Node<T> *ny = new Node<T>(value);

		for (forward_list<T>::iterator it = begin(); it != position; ++it) {
			n = n->next;
		}

		ny->next = n->next;
		n->next = ny;
		
		return position + 1;
	}

	iterator erase_after(iterator position) {
		Node<T> *n = head;

		for (forward_list<T>::iterator it = begin(); it != end(); ++it) {
			if (it == position) {
				Node<T> *deleteNode = n->next;
				n->next = n->next->next;
				delete deleteNode;
				//om det sista elementet togs bort returneras end()
				if (n->next == nullptr) {
					return end();
				}
				else {
					return iterator(n->next);
				}
			}
			n = n->next;
		}
		return begin();
	}

	void swap(forward_list<T> &right) {
		Node<T> *n = head;
		head = right.head;
		right.head = n;
	}

	T& front() {
		return head->information;
	}

	

	iterator begin() {
		return iterator(head);
	}

	iterator end() {
		Node<T> *n = head;

		while (n != nullptr) {
			n = n->next;
		}

		return iterator(n);
	}
	#pragma endregion forward_list orginal funktioner

	Node<T>* headNode() {
		return head;
	}
};