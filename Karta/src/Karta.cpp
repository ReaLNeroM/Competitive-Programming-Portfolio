#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	int n = 0, e = 0;
	for (int i = 0; i < line.length(); i++) {
		if (isdigit(line[i])) {
			int l = i, transform = 0;
			while (isdigit(line[l])) {
				transform += line[l] - 48;
				transform *= 10;
				l++;
			}
			transform /= 10;
			switch (line[i - 1]) {
			case 'n':
				n += transform;
				break;
			case 'e':
				e += transform;
				break;
			case 'w':
				e -= transform;
				break;
			case 's':
				n -= transform;
				break;
			}
		}

	}
	n = abs(n);
	e = abs(e);
	float zaokruzeno = sqrt(n * n + e * e);
	cout.precision(2);
	cout << fixed << zaokruzeno;
	return 0;
}
