#include <iostream>
#include <algorithm>
#include <vector>

std::string barano;

bool check(std::string check, bool lcheck) {
	if(barano.length() > check.length() and !lcheck){
		return false;
	} else if (barano.length() != check.length() and lcheck) {
		return false;
	}
	for (int i = 0; i < barano.length(); i++) {
		if (barano[i] != check[i]) {
			return false;
		}
	}

	return true;
}
int main() {
	std::cin >> barano;
	int regn = 0, registr, base = barano.length();
	std::cin >> registr;
	std::vector<std::string> reg(registr);

	for (int i = 0; i < reg.size(); i++) {
		std::cin >> reg[i];
		if (!check(reg[i], false)) {
			reg.erase(reg.begin() + i);
			i--;
			registr--;
		} else if (check(reg[i], true)) {
			regn = 1;
		}
	}
	if (regn == 1) {
		barano += 49;
		bool change;
		do {
			change = false;
			int digs;
			for (int i = 0; i < (int) reg.size(); i++) {
				if (check(reg[i], true)) {
					digs = 9;
					regn++;

					while (digs < regn) {
						digs = digs * 10 + 9;
					}
					digs = (digs + 1) / 10;
					barano.erase(barano.begin() + base, barano.end());
					do {
						barano += 48 + (regn / digs) % 10;
						digs /= 10;
					} while (digs >= 1);
					change++;
				}
			}
		} while (change);
	}
	std::cout << barano;
	return 0;
}
