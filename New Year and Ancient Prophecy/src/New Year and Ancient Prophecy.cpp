#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string str;
	cin >> str;

	ll ways[7];
	ways[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		ways[i] = 1;
		if (i != n) {
			bool bigger = false;
			int j;

			for (j = n - 1; j >= i and !bigger; j--) {
				if (j + 1 - i == n - 1 - j) {
					for (int k = i; k <= j; k++) {
						if (str[k] > str[j + 1 + k - i]) {
							break;
						} else if (str[k] < str[j + 1 + k - i]) {
							bigger = true;
						}
					}
				} else if (j + 1 - i < n - 1 - j) {
					bigger = true;
				}
			}
			j += 2;
			while (j > i and bigger) {
				ways[i] += ways[j];
				j--;
			}

			ways[i] %= mod;
		}
	}

	cout << ways[0];

	return 0;
}
