#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1005;
const long double PI = acos(-1);
ll r[maxn];
ll h[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll t;
	std::cin >> t;

	for(ll x = 0; x < t; x++){
		ll n, k;
		std::cin >> n >> k;
		ll res = 0.0;

		for(ll i = 0; i < n; i++){
			std::cin >> r[i] >> h[i];
		}

		for(ll i = 0; i < n; i++){
			ll full = r[i] * r[i] + 2 * r[i] * h[i];

			std::vector<ll> v;
			for(ll j = 0; j < n; j++){
				if(r[j] <= r[i] and j != i){
					v.push_back(r[j] * h[j]);
				}
			}

			std::sort(v.rbegin(), v.rend());
			for(ll j = 0; j < k - 1 and j < v.size(); j++){
				full += 2 * v[j];
			}

			if(v.size() < k - 1){
				continue;
			}

			res = std::max(res, full);
		}

		std::cout.precision(15);
		std::cout << std::fixed << "Case #" << x + 1 << ": " << (long double) res * PI << '\n';
	}
}