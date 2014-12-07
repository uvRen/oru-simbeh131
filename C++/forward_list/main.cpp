#include "forward_list.h"
#include <iostream>
//#include <forward_list>

using namespace std;

int main() {
	/*forward_list<int> lista;

	lista.push_front(10);
	cout << lista.front() << endl;
	lista.push_front(20);
	cout << lista.front() << endl;*/

	forward_list<int> lista;

	lista.push_front(10);
	lista.push_front(20);
	lista.push_front(30);
	lista.push_front(40);
	lista.push_front(50);
	lista.push_front(60);

	//lista.push_front(lista.begin().operator*());  lägger till första elementet en gång till
	forward_list<int> lista2(lista);

	

	for (forward_list<int>::iterator i = lista.begin(); i != lista.end(); ++i) {
		cout << *i << ' ';
	}

	
	
	cout << endl;
	/*
	for (forward_list<int>::iterator i = lista2.begin(); i != lista2.end(); ++i) {
		cout << *i << ' ';
	}

	cout << endl;

	lista = lista2;

	for (forward_list<int>::iterator i = lista.begin(); i != lista.end(); ++i) {
		cout << *i << ' ';
	}

	cout << endl;
*/
	int tal = 45;
	lista.insert_after(lista.begin()+1, tal);
	lista.erase_after(lista.begin() + 1);

	for (forward_list<int>::iterator i = lista.begin(); i != lista.end(); ++i) {
		cout << *i << ' ';
	}

	
	cout << endl;

	system("pause");
	return 0;
}