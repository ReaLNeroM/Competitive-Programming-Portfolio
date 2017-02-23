#include <iostream>
using namespace std;

int main() {
	int a, b, count = 0;
	cin >> a >> b;

	for (int prenes = 0; a >= 1 or b >= 1; a /= 10, b /= 10) {
		if (a % 10 + b % 10 + prenes >= 10) {
			prenes = 1;
			count++;
		} else {
			prenes = 0;
		}
	}

	cout << count;
	return 0;
}
