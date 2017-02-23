#include <iostream>
#include <utility>
#include <algorithm>

typedef long long ll;

bool cmp(std::pair<std::pair<int ,int>, int> x, std::pair<std::pair<int, int>, int> y){
	if(x.first.first == y.first.first){
		return x.first.second < y.first.second;
	}

	return x.first.first < y.first.first;
}

int main() {
	int intervals;
	std::cin >> intervals;

	std::pair<std::pair <int, int>, int> inval[intervals];

	for (int i = 0; i < intervals; i++) {
		std::cin >> inval[i].first.first >> inval[i].first.second;
		inval[i].second = i + 1;
	}

	std::sort(inval, inval + intervals, cmp);

	int used = 1, lastpos = 0;
	for (int i = 1; i < intervals; i++) {
		if (inval[lastpos].second > inval[i].second) {
			lastpos = i;

		} else if (inval[lastpos].first.second <= inval[i].first.first) {
			used++;
			std::cout << inval[lastpos].second << ' ';
			lastpos = i;
		}
		if (i == intervals - 1) {
			std::cout << inval[lastpos].second;
		}
	}

	return 0;
}
