#include <iostream>
#include <deque>
#include <algorithm>

typedef long long ll;

int main() {
	ll players, check;
	std::cin >> players >> check;

	ll tests[players];
	std::pair<ll, int> sorted[players];
	for(ll i = 0; i < players; i++){
		std::cin >> tests[i];
		sorted[i].first = tests[i];
		sorted[i].second = i;
	}

	std::sort(sorted, sorted + players);

	ll left = 0, right = players - 1;

	ll min = players;
	while(left <= right){
		ll mid = (left + right) / 2;

		ll eliminated = 0, needed = 0;

		for(ll i = 0; i < players; i++){
			if(sorted[mid].first > tests[i]){
				eliminated++;
				needed += tests[i];
			} else if(sorted[mid].first == tests[i] and sorted[mid].second >= i){
				eliminated++;
				needed += sorted[mid].first;
			} else {
				needed += sorted[mid].first;
			}
		}

		if(check >= needed){
			left = mid + 1;
			min = std::min(min, players - eliminated);
		} else {
			right = mid - 1;
		}
	}



	std::cout << min;
	return 0;
}
