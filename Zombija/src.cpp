#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
ll n;
ll direct, all;
ll val[maxn];
ll cop[maxn];

bool good(ll operations){
	std::copy(val, val + n, cop);

	for(ll i = 0; i < n; i++){
		cop[i] -= operations * all;
	}

	std::sort(cop, cop + n);

	ll needed = 0;

	for(ll i = 0; i < n; i++){
		if(cop[i] > 0){
			needed += (cop[i] + direct - 1) / direct;
		}
	}

	return (needed <= operations);
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> direct >> all;
	direct -= all;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	ll l = 0, r = 1e9;
	ll best = 1e9;
	while(l <= r){
		ll mid = (l + r) / 2;

		if(good(mid)){
			best = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	std::cout << best << '\n';
}
