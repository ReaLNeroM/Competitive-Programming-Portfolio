#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const ll mod = 100003;
int main() {
	ios::sync_with_stdio(false);

	int i, j;
	cin >> i >> j;
	ll res = 1;
	for(int k = 0; k < i - j; k++){
		res *= 2;
		res %= mod;
	}

	res *= i - j + 1;
	res %= mod;

	for(int k = 2; k <= j; k++){
		res *= i - j + k;
		res %= mod;
	}

	cout << res << ' ';
	return 0;
}
