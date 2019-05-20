#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 10;
std::pair<ll, ll> v[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		ll n;
		std::cin >> n;

		for(ll i = 0; i < n; i++){
			ll a, b;
			std::cin >> a >> b;
			v[i] = {a, b};
		}

		std::sort(v, v + n);
		
		ll res = 0;
		do {
			long double l = 0.0; // s / f min
			long double r = 1e9; // s / f  max

			for(ll i = 0; i < n - 1; i++){
				std::pair<ll, ll> a = v[i];
				std::pair<ll, ll> b = v[i + 1];

				b.first -= a.first;
				b.second -= a.second;

				if(b.first <= 0 and b.second <= 0){
					l = 1.0, r = 0.0;
					break;
				}
				if(b.first >= 0 and b.second >= 0){
					continue;
				} else if (b.first > 0 and b.second < 0){
//					l = std::max(l, (long double) b.first / (long double) (-b.second));
					 r = std::min(r, (long double) b.first / (long double) (-b.second));
				} else if(b.first < 0 and b.second > 0){
					 l = std::max(l, (long double) b.first / (long double) (-b.second));
//					r = std::min(r, (long double) b.first / (long double) (-b.second));
				}
			}

			bool good = true;
			long double w = (l + r) / 2;

			if(l - 0.0000000000001L > r){
				good = false;
			}

			for(ll i = 0; i < n - 1; i++){
				std::pair<ll, ll> a = v[i];
				std::pair<ll, ll> b = v[i + 1];

				b.first -= a.first;
				b.second -= a.second;

				if(b.first + w * b.second <= 0.0000000000001L){
					good = false;
				}
			}
			
			if(!good){
				continue;
			}

			res++;
		} while(std::next_permutation(v, v + n));

		std::cout << "Case #" << testcase << ": " << res;

		std::cout << '\n';
	}
}
