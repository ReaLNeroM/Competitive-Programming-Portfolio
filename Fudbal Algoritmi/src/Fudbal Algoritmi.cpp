#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	double a, b;
	cin >> a >> b;

	a /= 100;
	b /= 100;

	bool prime[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0};
	double full = 0;

	for (int i = 0; i < (1 << 18); i++) {
		int c = 0;
		for(int j = 1; j <= i; j *= 2){
			if(i & j){
				c++;
			}
		}

		if(prime[c]){
			double chance = pow(a, c) * pow(1 - a, 18 - c);

			full += chance;
		}
	}

	double prevchance = full;
	for (int i = 0; i < (1 << 18); i++) {
		int c = 0;
		for(int j = 1; j <= i; j *= 2){
			if(i & j){
				c++;
			}
		}

		if(prime[c]){
			double chance = pow(b, c) * pow(1 - b, 18 - c);
			chance *= (1 - prevchance);

			full += chance;
		}
	}

	if(full > 0.999 or full < 0.00001){
		cout.precision(1);
	} else {
		cout.precision(2);
	}
	cout << fixed << floor(full * 100) / 100;
	return 0;
}
