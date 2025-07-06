#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Computer {
	char* name;
	float frequency;
	int ram;
	bool dvd;
	float price;

public:
	Computer();
	Computer(const char* _name, float _freq, int _ram, bool _dvd, float _price);
	Computer(const Computer& obj);
	Computer& operator=(const Computer& obj);
	~Computer();

	const char* getName() const;
	float getFrequency() const;
	int getRAM() const;
	bool hasDVD() const;
	float getPrice() const;

	void setPrice(float _price);
	void show() const;
};