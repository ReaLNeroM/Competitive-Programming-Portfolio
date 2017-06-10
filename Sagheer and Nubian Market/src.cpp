#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5;
ll base[maxn];
ll cost[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, s;
	std::cin >> n >> s;

	for(ll i = 0; i < n; i++){
		std::cin >> base[i];
	}

	ll l = 0, r = n;
	ll res = 0, best_sum = 0;

	while(l <= r){
		ll mid = (l + r) / 2;

		for(ll i = 0; i < n; i++){
			cost[i] = base[i] + (i + 1) * mid;
		}
		std::sort(cost, cost + n);

		ll sum = 0;
		for(ll i = 0; i < mid; i++){
			sum += cost[i];
		}

		if(sum <= s){
			l = mid + 1;
			res = mid;
			best_sum = sum;
		} else {
			r = mid - 1;
		}
	}

	std::cout << res << ' ' << best_sum;
}