#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll INF = 1e15;
ll n;
ll calc[maxn];
ll w[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(ll test = 1; test <= tests; test++){
		std::fill(calc, calc + maxn, INF);
		calc[0] = 0;

		std::cin >> n;

		ll res = 0;

		for(ll i = 0; i < n; i++){
			std::cin >> w[i];
		}

		for(ll i = 0; i < n; i++){
			ll l = 1, r = res;
			ll best = 0;

			while(l <= r){
				ll mid = (l + r) / 2;

				if(w[i] * 6 >= calc[mid]){
					l = mid + 1;
					best = mid;
				} else {
					r = mid - 1;
				}
			}

			calc[best + 1] = std::min(calc[best + 1], calc[best] + w[i]);
			res = std::max(res, best + 1);
		}

		std::cout << "Case #" << test << ": " << res << '\n';
	}
}