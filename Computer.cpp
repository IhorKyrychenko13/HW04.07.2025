#include "Computer.h"
Computer::Computer() {
	name = new char[10] {"undefined"};
	frequency = 0;
	ram = 0;
	dvd = false;
	price = 0;
}
Computer::Computer(const char* _name, float _freq, int _ram, bool _dvd, float _price) {
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy_s(name, len, _name);
	frequency = _freq;
	ram = _ram;
	dvd = _dvd;
	price = _price;
}
Computer::Computer(const Computer& obj) {
	int len = strlen(obj.name) + 1;
	name = new char[len];
	strcpy_s(name, len, obj.name);
	frequency = obj.frequency;
	ram = obj.ram;
	dvd = obj.dvd;
	price = obj.price;
}
Computer& Computer::operator=(const Computer& obj) {
	if (this != &obj) {
		delete[] name;
		int len = strlen(obj.name) + 1;
		name = new char[len];
		strcpy_s(name, len, obj.name);

		frequency = obj.frequency;
		ram = obj.ram;
		dvd = obj.dvd;
		price = obj.price;
	}
	return *this;
}
Computer::~Computer() {
	delete[] name;
}
const char* Computer::getName() const { return name; }
float Computer::getFrequency() const { return frequency; }
int Computer::getRAM() const { return ram; }
bool Computer::hasDVD() const { return dvd; }
float Computer::getPrice() const { return price; }
void Computer::setPrice(float _price) {
	if (_price > 0) price = _price;
}
void Computer::show() const {
	cout << "Назва: " << name << endl;
	cout << "Частота: " << frequency << " GHz\n";
	cout << "ОЗП: " << ram << " GB\n";
	cout << "DVD-ROM: " << (dvd ? "є" : "немає") << endl;
	cout << "Ціна: " << price << " грн\n\n";
}