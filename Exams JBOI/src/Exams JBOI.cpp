#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	ll tests, points;
	std::cin >> tests >> points;

	ll exam[tests];
	for (ll i = 0; i < tests; i++) {
		std::cin >> exam[i];
	}

	ll asize = 1LL << (tests / 2);
	static ll a[1 << 20];
	for (ll i = 0; i < asize; i++) {
		a[i] = 0;

		for (ll j = 0, bit = 1; bit <= i; j++, bit *= 2) {
			if (bit & i) {
				a[i] += exam[j];
			}
		}
	}
	std::sort(a, a + asize);

	ll res = 0;

	for (ll i = 0; i < (1LL << (tests + 1) / 2); i++) {
		ll currp = 0;

		for (ll j = 0, bit = 1; bit <= i; j++, bit *= 2) {
			if (bit & i) {
				currp += exam[j + tests / 2];
			}
		}

		ll left = 0, right = asize - 1;

		while (left <= right) {
			ll mid = (left + right) / 2;

			if (a[mid] + currp < points) {
				left = mid + 1;
			} else if (a[mid] + currp >= points) {
				right = mid - 1;
			}
		}

		res += asize - left;
	}

	std::cout << res;
	return 0;
}
