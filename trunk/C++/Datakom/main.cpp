/*
Detta programmet baseras p� kursen "Datakommunikaiton och n�t". Programmet kommer genom en inmatad IP-adress av av�ndaren att
ber�kna fram vissa egenskaper hos en IPv4 IP-adress. Till ex: Klass, Host identity, Internal host identity och Subnetwork identity.
*/

#include <iostream>
#include "IP.h"
using namespace std;

int main()
{
	int a = 193;
	string adress = "", klipp = "";
	IP p;
	//p.getInfo();
	//p.calculate(p);
	//p.printAll();

	cout << endl << endl << p.decimalToBinary(98) << endl;
	system("pause");

	return 0;
}
