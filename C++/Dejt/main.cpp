#include "../forward_list/forward_list.h"
#include <string>
#include "Interest.h"

int main() {
	Interest intresse;

	intresse.Add("training");
	intresse.Add("movies");
	intresse.Add("swimming");

	intresse.WriteToFile();

	system("pause");
	return 0;
}