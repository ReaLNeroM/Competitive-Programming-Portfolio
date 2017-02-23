#include <iostream>
#include <utility>
#include <algorithm>

typedef long long ll;

int main() {
	int lines;
	std::cin >> lines;

	int x1, x2;
	std::cin >> x1 >> x2;

	std::pair <ll, ll> l[lines];
	std::pair <ll, ll> m[lines];

	for (int i = 0; i < lines; i++) {
		std::cin >> l[i].first >> l[i].second;
		m[i].first = x1 * l[i].first + l[i].second;
		m[i].second = x2 * l[i].first + l[i].second;

	}

	std::stable_sort(m, m + lines);

	for (int i = 0; i < lines - 1; i++) {
		if (m[i].second > m[i + 1].second) {
			std::cout << "YES";
			return 0;
		}
	}

	std::cout << "NO";
	return 0;
}
