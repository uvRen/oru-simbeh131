#pragma once
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

class IP
{
private:
	string IPadress, subnetMask, hostIdentity, subnetworkIdentity, internalHostIdentity;
	char klass;

	char calculateClass(IP p);
	string calculateHost(IP p);
	string calculateSubnetwork(IP p);
	string calculateInternalHost(IP p);
	int checkCorrectInput(string ipadress, string mask);
	int checkIP(string ipadress);
	int checkMask(string mask);
	bool followingOnes(string binary);

public:
	//konstruktor
	IP();
	IP(string IPadress, string subnetMask);
	~IP();

	//funktioner
	int binaryToDecimal(string binary);
	string decimalToBinary(int decimaltal);
	string getIP() { return this->IPadress; }
	void calculate(IP p);
	void printAll();
	void getInfo();
	int convertStringToInt(string tal);
};

