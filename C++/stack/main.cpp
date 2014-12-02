#include "stack.h"

using namespace std;

int main() {
	stack<int> lista;

	lista.push(10);
	lista.push(20);
	lista.push(30);

	cout << lista << endl;
	lista.pop();

	cout << "pop" << endl << endl << lista << endl;

	system("pause");
	return 0;
}