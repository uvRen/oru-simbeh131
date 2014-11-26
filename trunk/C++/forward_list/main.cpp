//#include "forward_list.h"
#include <iostream>
#include <forward_list>

using namespace std;

int main() {
	/*forward_list<int> lista;

	lista.push_front(10);
	cout << lista.front() << endl;
	lista.push_front(20);
	cout << lista.front() << endl;*/

	forward_list<int> lista;

	lista.push_front(10);
	lista.front() = 20;
	cout << lista.front();


	system("pause");
	return 0;
}