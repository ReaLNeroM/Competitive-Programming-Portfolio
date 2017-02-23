#include <iostream>
#include <queue>
#include <algorithm>

typedef long long ll;

struct friends{
	ll money, quality;

	bool operator<(friends x) const{
		return money < x.money;
	}
	bool operator()(friends x, friends y) {
		return x.money < y.money;
	}
};

int main() {
	std::ios::sync_with_stdio(false);

	ll friendn, difference;
	std::cin >> friendn >> difference;

	friends fr[friendn];
	for(ll i = 0; i < friendn; i++){
		std::cin >> fr[i].money >> fr[i].quality;
	}

	std::sort(fr, fr + friendn);

	std::priority_queue<friends, std::vector<friends>, friends> fq;
	ll max = 0, amount = 0;
	for(ll i = friendn - 1; i >= 0; i--){
		fq.push(fr[i]);
		amount += fr[i].quality;

		while(fq.top().money >= fr[i].money + difference){
			amount -= fq.top().quality;
			fq.pop();
		}

		max = std::max(max, amount);
	}
	max = std::max(max, amount);

	std::cout << max;
	return 0;
}
