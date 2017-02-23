#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	static ll da[2001], db[2001];

	int bis;
	cin >> bis;

	for(int i = 0; i < bis; i++){
		ll y, x;
		cin >> y >> x;
		y--, x--;

		da[y + x]++;
		db[1000 - x + y]++;
	}

	ll sum = 0;
	for(int i = 0; i <= 2000; i++){
		sum += da[i] * (da[i] - 1) / 2;
		sum += db[i] * (db[i] - 1) / 2;
	}

	cout << sum;
	return 0;
}
