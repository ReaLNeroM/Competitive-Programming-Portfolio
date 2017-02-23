#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	ll p;
	cin >> n >> p;

	ll l[n + 1], r[n + 1];
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
	l[n] = l[0];
	r[n] = r[0];

	double res = 0;
	for(int i = 0; i < n; i++){
		double chance = ((r[i] - l[i] + 1) - (r[i] / p - (l[i] - 1) / p));
		chance *= ((r[i + 1] - l[i + 1] + 1) - (r[i + 1] / p - (l[i + 1] - 1) / p));

		chance = 1 - chance / ((ll) ((r[i] - l[i] + 1) * (r[i + 1] - l[i + 1] + 1)));
		res += chance * 2000;
	}

	cout << fixed << res;
	return 0;
}
