#include <vector>
#include <algorithm>
#include <windows.h>
#include "Computer.h"
using namespace std;

int main() {
	SetConsoleOutputCP(1251); 
	SetConsoleCP(1251);

	vector<Computer> comps;
	comps.push_back(Computer("Asus", 3.2f, 16, true, 25000));
	comps.push_back(Computer("HP", 2.4f, 8, false, 18000));
	comps.push_back(Computer("Lenovo", 1.8f, 4, false, 15000));
	comps.push_back(Computer("Dell", 3.6f, 32, true, 32000));
	comps.push_back(Computer("Acer", 2.2f, 16, true, 20000));

	cout << "=== Список комп'ютерів ===\n";
	for (const auto& comp : comps) comp.show();
	char search[100];
	cout << "\nВведіть назву комп'ютера для пошуку: ";
	cin.getline(search, 100);

	auto found = find_if(comps.begin(), comps.end(), [search](const Computer& c) {
		return strcmp(c.getName(), search) == 0;
		});
	if (found != comps.end()) {
		cout << "Знайдено:\n";
		found->show();
	}
	else {
		cout << "Комп'ютер не знайдено.\n";
	}
	auto min_freq_it = min_element(comps.begin(), comps.end(), [](const Computer& a, const Computer& b) {
		return a.getFrequency() < b.getFrequency();
		});
	if (min_freq_it != comps.end()) {
		cout << "\nКомп'ютер з мінімальною частотою:\n";
		min_freq_it->show();
		comps.erase(min_freq_it);
	}
	cout << "\nПісля видалення мін. частоти:\n";
	for (const auto& comp : comps) comp.show();
	int dvd_count = count_if(comps.begin(), comps.end(), [](const Computer& c) {
		return c.hasDVD();
		});
	cout << "\nКількість комп'ютерів з DVD-ROM: " << dvd_count << "\n";
	for_each(comps.begin(), comps.end(), [](Computer& c) {
		if (c.getRAM() > 16) {
			c.setPrice(c.getPrice() + 5000);
		}
		});
	cout << "\nПісля збільшення вартості (RAM > 16):\n";
	for (const auto& comp : comps) comp.show();
	sort(comps.begin(), comps.end(), [](const Computer& a, const Computer& b) {
		return a.getPrice() > b.getPrice();
		});
	cout << "\nСортування за спаданням ціни:\n";
	for (const auto& comp : comps) comp.show();
	sort(comps.begin(), comps.end(), [](const Computer& a, const Computer& b) {
		return a.getPrice() < b.getPrice();
		});
	cout << "\nСортування за зростанням ціни:\n";
	for (const auto& comp : comps) comp.show();
	return 0;
}