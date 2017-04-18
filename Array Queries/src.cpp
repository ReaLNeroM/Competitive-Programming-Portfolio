#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll pref[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	for(ll i = 1; i <= n; i++){
		std::cin >> pref[i];
		pref[i] += pref[i - 1];
	}

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll p, k;
		std::cin >> p >> k;

		ll l = 1, r = n;
		ll earliest = n;
		while(l <= r){
			ll mid = (l + r) / 2;

			if(p + pref[mid] + mid * k <= n){
				l = mid + 1;
			} else {
				earliest = mid;
				r = mid - 1;
			}
		}
		std::cout << earliest << '\n';
	}
}