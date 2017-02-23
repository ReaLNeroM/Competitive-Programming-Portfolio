#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int dokumenti, firmi, cel, poedinecna, polovina, num;
	double num1;
	long long leadingnum = -1, pari;
	string ime, follower;
	cin >> dokumenti >> cel;
	cin >> firmi;

	for (int i = 0; i < firmi; i++) {
		num = dokumenti;
		pari = 0;
		cin >> ime >> poedinecna >> polovina;

		while (num > cel) {
			num1 = num;
			num1 = ceil(num1 / 2);
			if (num - num1 < cel) {
				pari += poedinecna * (num - cel);
			} else {
				if (polovina < poedinecna * num1) {
					pari += polovina;
				} else {
					pari += poedinecna * num1;
				}
			}

			num -= num1;
		}

		if (pari < leadingnum or leadingnum == -1) {
			leadingnum = pari;
			follower = ime;
		}
	}

	cout << follower << " " << leadingnum;
	return 0;
}
