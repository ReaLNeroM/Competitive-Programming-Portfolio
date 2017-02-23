#include <iostream>
#include <vector>

typedef long long ll;

ll dishes, buying, bonuses;

std::vector<std::vector<ll> > quality;
std::vector<std::vector<ll> > dp;

ll TSP(ll lastdish, ll usedset){
	if(dp[lastdish][usedset] == -1){
		ll used = 0;
		for(ll i = 1; i <= usedset; i *= 2){
			if((i & usedset)){
				used++;
			}
		}

		dp[lastdish][usedset] = 0;
		if(used < buying){
			for(ll i = 0, bit = 1; i < dishes; i++, bit *= 2){
				if((bit & usedset) == 0){
					dp[lastdish][usedset] = std::max(dp[lastdish][usedset],
														TSP(i, usedset | bit) + quality[lastdish][i]);
				}
			}
		}
	}

	return dp[lastdish][usedset];
}

int main() {
	std::cin >> dishes >> buying >> bonuses;

	quality.resize(dishes);
	dp.resize(dishes);

	for(ll i = 0; i < dishes; i++){
		quality[i].resize(dishes);
	}

	for(ll i = 0, inp; i < dishes; i++){
		std::cin >> inp;
		for(ll j = 0; j < dishes; j++){
			quality[j][i] = inp;
		}
		dp[i].resize(1 << dishes, -1);
	}

	for(ll i = 0, first, second, combo; i < bonuses; i++){
		std::cin >> first >> second >> combo;
		quality[first - 1][second - 1] += combo;
	}

	ll max = 0;
	for(ll i = 0; i < dishes; i++){
		max = std::max(max, quality[i][i] + TSP(i, 1 << i));
	}

	std::cout << max;
	return 0;
}
