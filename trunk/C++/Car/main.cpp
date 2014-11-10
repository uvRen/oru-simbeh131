#include "Car.h"

int main() {
	Car bil1, bil2("Audi", 2012, 350000);

	bil1.readFromConsole();
	bil1.writeToConsole();

	bil2.writeToConsole();

	system("pause");
}