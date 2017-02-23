#include <iostream>
#include <deque>
#include <algorithm>

typedef long long ll;

bool cmp(std::pair<int, int> x, int val){
	return (val > x.second);
}

int main() {
	std::ios::sync_with_stdio(false);

	int types, curr, goal;
	std::cin >> types >> curr >> goal;

	int bought[curr];

	for (int i = 0; i < curr; i++) {
		std::cin >> bought[i];
	}

	int price[types], value[types];

	for (int i = 0; i < types; i++) {
		std::cin >> price[i];
	}

	for (int i = 0; i < types; i++) {
		std::cin >> value[i];
	}

	int start = 0;
	for (int i = 0; i < curr; i++) {
		start += price[bought[i] - 1];
	}

	std::deque <std::pair <int, int> > a(1 << (types / 2));
	for (int i = 0; i < a.size(); i++) {
		a[i].first = 0;
		a[i].second = 0;
		for (int j = 0, bit = 1; bit <= i; j++, bit *= 2) {
			if (bit & i) {
				a[i].first += price[j];
				a[i].second += value[j];
			}
		}
	}

	std::sort(a.begin(), a.end());

	for (int i = 1; i < a.size(); i++) {
		if (a[i].second <= a[i - 1].second) {
			a.erase(a.begin() + i);
			i--;
		}
	}

	int min = 1000000000;

	for (int i = 0; i < (1 << ((types + 1) / 2)); i++) {
		int currp = 0;
		int currv = 0;

		for (int j = 0, bit = 1; bit <= i; j++, bit *= 2) {
			if (bit & i) {
				currp += price[types / 2 + j];
				currv += value[types / 2 + j];
			}
		}

		std::deque<std::pair<int, int> >::iterator ite;
		ite = std::lower_bound(a.begin(), a.end(), goal - currv, cmp);

		if (ite != a.end()) {
			min = std::min(min, currp + ite->first - start);
		}
	}

	if (min == 1000000000) {
		std::cout << -1;
	} else {
		std::cout << std::max(min, 0) << std::endl;
	}

	return 0;

}
