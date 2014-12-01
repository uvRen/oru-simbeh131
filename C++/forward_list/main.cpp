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

	for (forward_list<int>::iterator i = lista.begin(); i != lista.end(); ++i) {
		cout << *i << endl;
	}


	system("pause");
	return 0;
}