#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
const ll max_time = 1e18;

ll capacity[maxn];
ll per_item[maxn];
ll cashout[maxn];
ll buyers, items, sellers;
ll seller_speed[maxn];

bool possible(ll time){
	std::fill(seller_speed, seller_speed + sellers, 0);
	for(ll i = 0; i < sellers; i++){
		seller_speed[i] = (time - cashout[i]) / per_item[i];
		seller_speed[i] = std::min(seller_speed[i], capacity[i]);
		seller_speed[i] = std::max(seller_speed[i], 0LL);
	}
	std::sort(seller_speed, seller_speed + sellers, std::greater<ll>());

	ll maximum_items_in_time = 0;
	for(ll i = 0; i < buyers; i++){
		maximum_items_in_time += seller_speed[i];
	}

	return (maximum_items_in_time >= items);
}

int main(){
	std::ios::sync_with_stdio(false);

	ll test_cases;
	std::cin >> test_cases;

	for(ll test_case = 1; test_case <= test_cases; test_case++){
		std::cin >> buyers >> items >> sellers;

		for(ll i = 0; i < sellers; i++){
			std::cin >> capacity[i] >> per_item[i] >> cashout[i];
		}

		ll l = 1;
		ll r = max_time;
		ll res = max_time;

		while(l <= r){
			ll mid = (l + r) / 2;

			if(possible(mid)){
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		std::cout << "Case #" << test_case << ": ";
		std::cout << res;
		std::cout << '\n';
	}
}
