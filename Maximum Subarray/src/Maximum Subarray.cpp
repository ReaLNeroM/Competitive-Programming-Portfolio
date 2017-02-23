#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int val = 0;
	int res = 0;

	for(int i = 1; i <= n; i++){
		int inp;
		cin >> inp;

		val = max(0, val) + inp;
		res = max(res, val);
	}

	cout << res;
	return 0;
}
