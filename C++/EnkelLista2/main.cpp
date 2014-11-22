#include "List.h"
#include <iostream>

int main() {
	List a;

	a.add_at_tail("Simon");
	a.add_at_tail("Isabella");
	a.add_at_tail("Andrea");
	a.add_at_head("Sarah");

	cout << a.printList() << endl;

	system("pause");
	return 0;
}