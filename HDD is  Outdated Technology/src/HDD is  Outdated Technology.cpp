#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int val[n];
	for(int i = 0; i < n; i++){
		int inp;
		cin >> inp;
		val[inp - 1] = i;
	}

	ll res = 0;
	for(int i = 1; i < n; i++){
		res += abs(val[i] - val[i - 1]);
	}

	cout << res;
	return 0;
}
