#include "queue.h"
#include <iomanip>

using namespace std;

int main() {
	queue<int> lista;

	int tal = 0;
	while (true) {
		cout << "Ange ett tal att lägga i kön: ";
		cin >> tal;
		if (tal == -1) {
			break;
		}
		lista.push(tal);
		cout << endl << "QUEUE:" << endl << lista << endl;
	}

	system("pause");
	return 0;
}