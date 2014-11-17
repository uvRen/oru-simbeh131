#include "List.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	List<string> lista;

	lista.add_at_head("Simon");
	lista.add_at_head("Isabella");
	lista.add_at_head("Thomas");
	lista.add_at_tail("Andrea");

	cout << lista.str() << endl;

	system("pause");
	return 0;
}