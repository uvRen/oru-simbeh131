#include "stack.h"

using namespace std;

int main() {
	stack<int> lista;

	int tal = 0;
	while (true) {
		cout << "Ange ett tal att l�gga i stacken: ";
		cin >> tal;
		if (tal == -1) {
			break;
		}
		lista.push(tal);
		cout << endl << "STACKEN:" << endl << lista << endl;
	}

	system("pause");
	return 0;
}