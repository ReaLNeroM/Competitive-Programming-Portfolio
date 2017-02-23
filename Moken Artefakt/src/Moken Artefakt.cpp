#include <iostream>
using namespace std;

int main() {
	int magionicari;
	cin >> magionicari;
	int sila, zbir = 0, potrebni = 0;
	for (int i = 0; i < magionicari; i++) {
		cin >> sila;
		if (zbir < magionicari) {
			zbir += sila + 1;
			potrebni++;
		}
	}

	cout << potrebni;
	return 0;
}
