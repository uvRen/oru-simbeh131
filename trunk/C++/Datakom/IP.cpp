#include "IP.h"

//konstruktor
IP::IP()
{
	IPadress = "0.0.0.0";
	klass = 'X';
	subnetMask = "0.0.0.0";
	hostIdentity = "0.0.0.0";
	subnetworkIdentity = "0.0.0.0";
	internalHostIdentity = "0.0.0.0";
}

IP::IP(string IPadress, string subnetMask) {
	this->IPadress = IPadress;
	klass = 'X';
	this->subnetMask = subnetMask;
	hostIdentity = "0.0.0.0";
	subnetworkIdentity = "0.0.0.0";
	internalHostIdentity = "0.0.0.0";
}

IP::~IP()
{
}

//funktioner
int IP::binaryToDecimal(string binary) {
	string temp = "";
	int tal = 0, bin = 0, length;

	length = binary.length() - 1;

	for (int i = length; i >= 0; i--) {
		temp = binary[i];
		bin = atoi(temp.c_str());
		tal += bin * (int)pow(2, (length - i));
	}
	return tal;
}

string IP::decimalToBinary(int decimaltal) {
	int temp = 0;
	string tal = "", test = "", nyttTal = "";
	char c = '-';


	while (decimaltal >= 1) {
		ostringstream convert;
		temp = decimaltal % 2;
		convert << temp;
		decimaltal = decimaltal / 2;
		test = convert.str();
		c = test[0];
		tal.push_back(c);
	}

	int length = tal.length() - 1;
	for (int i = length; i < 7; i++) // lägger till inledande 0:or så det blir totalt 8bitar
		nyttTal.push_back('0');

	for (int i = length; i >= 0; i--) { //vänder på talet. 00101 -> 10100
		nyttTal.push_back(tal[i]);
	}

	return nyttTal;
}

void IP::printAll() {
	cout << setw(15) << "IP: " << this->IPadress << endl << setw(15) << "Klass: " << this->klass << endl << setw(15) << "N\x84tmask: " << this->subnetMask << endl << setw(15)
		<< "Undern\x84t: " << this->subnetworkIdentity << endl << setw(15) << "Intern host: " << this->internalHostIdentity << endl
		<< setw(15) << "Host identity: " << this->hostIdentity << endl;
}

int IP::convertStringToInt(string tal) {
	return atoi(tal.c_str());
}

int IP::checkIP(string ipadress) {
	size_t pos = 0, posBefore = 0;
	int tal;

	pos = ipadress.find(".");
	posBefore = pos + 1;
	tal = convertStringToInt(ipadress.substr(0, pos)); //talet i första delen
	if (pos == string::npos || pos > 3 || pos == 0 || tal > 223) // kollar att det finns en punkt och att första delen har en storlek mellan 1-3 (192.168.1.1) OK! (.168.1.1) INTE OK!
		return 0;

	pos = ipadress.find(".", pos + 1);
	tal = convertStringToInt(ipadress.substr(posBefore, pos)); // talet i andra delen
	posBefore = pos + 1;
	if (pos == string::npos || pos > 7 || pos < 3 || tal > 255) // kollar att den finns en andra punkt och att den delen har en storlek mellan 1-3
		return 0;

	tal = convertStringToInt(ipadress.substr(posBefore, pos)); // talet i tredje delen
	pos = ipadress.find(".", pos + 1);
	if (pos == string::npos || pos > 11 || pos < 5 || tal > 255) // kollar att den finns en tredje punkt och att den delen har en storlek mellan 1-3
		return 0;

	tal = convertStringToInt(ipadress.substr(pos + 1)); // talet i fjärde delen
	if (tal > 255)
		return 0;

	pos = ipadress.find(".", pos + 1);
	if (pos != string::npos) // kollar om det finns en fjärde punkt.
		return 0;

	return 1;
}

bool IP::followingOnes(string binary) {
	bool correct = true, moreOnes = true;

	return correct;
}

int IP::checkMask(string mask) {
	size_t pos = 0, posBefore = 0;
	int tal;
	string binary;
	bool correct = true;

	pos = mask.find(".");
	posBefore = pos + 1;
	tal = convertStringToInt(mask.substr(0, pos)); //talet i första delen
	if (pos == string::npos || pos > 3 || pos == 0 || tal > 255) // kollar att det finns en punkt och att första delen har en storlek mellan 1-3 (192.168.1.1) OK! (.168.1.1) INTE OK!
		return 0;
	binary = decimalToBinary(tal);

	pos = mask.find(".", pos + 1);
	tal = convertStringToInt(mask.substr(posBefore, pos)); // talet i andra delen
	posBefore = pos + 1;
	if (pos == string::npos || pos > 7 || pos < 3 || tal > 255) // kollar att den finns en andra punkt och att den delen har en storlek mellan 1-3
		return 0;

	tal = convertStringToInt(mask.substr(posBefore, pos)); // talet i tredje delen
	pos = mask.find(".", pos + 1);
	if (pos == string::npos || pos > 11 || pos < 5 || tal > 255) // kollar att den finns en tredje punkt och att den delen har en storlek mellan 1-3
		return 0;

	tal = convertStringToInt(mask.substr(pos + 1)); // talet i fjärde delen
	if (tal > 255)
		return 0;

	return 1;
}

int IP::checkCorrectInput(string ipadress, string mask) { // returnerar 0 ifall någon input är felaktig
	//kontrollerar IP
	int ipCheck = 0, maskCheck = 0;
	ipCheck = checkIP(ipadress);

	//kontrollerar masken

	string masken = decimalToBinary(255);



	return 1;
}

void IP::getInfo() {
	string ip, mask;
	int correct = -1;

	while (correct != 1) { // loopar sålänge användaren inte ger en korrekt input
		cout << "Ange IP-adress: ";
		cin >> ip;
		cout << "Ange n\x84tmask: ";
		cin >> mask;

		correct = checkCorrectInput(ip, mask);

		if (correct == 1) {
			this->IPadress = ip;
			this->subnetMask = mask;
		}
		else
			cout << "Ange en korrekt IP-adress och n\x84tmask" << endl;
	}
}

char IP::calculateClass(IP p) {
	int tal;
	string adress;

	adress = p.getIP().substr(0, p.getIP().find(".")); //tar ut sträng mellan position 0 och första punkten. 192.168.1.1 -> 192
	tal = atoi(adress.c_str());

	if (tal < 128)
		return 'A';
	else if (tal >= 128 && tal < 192)
		return 'B';
	else if (tal >= 192 && tal < 224)
		return 'C';
	else
		return 'X';
}

string IP::calculateHost(IP p) {
	char c = this->klass;
	size_t pos = -1;

	if (c == 'A') {
		return p.getIP().substr(p.getIP().find(".") + 1);
	}
	else if (c == 'B') {
		pos = p.getIP().find("."); //första punkten
		pos = p.getIP().find(".", pos + 1); //andra punkten

		return p.getIP().substr(pos + 1);
	}
	else if (c == 'C') {
		pos = p.getIP().find_last_of(".");

		return p.getIP().substr(pos + 1);
	}
	else
		return "0.0.0.0";
}

void IP::calculate(IP p){
	this->klass = calculateClass(p);
	this->hostIdentity = calculateHost(p);
}