#include <bits/stdc++.h>

typedef long long ll;

bool good(ll n, ll k){
	ll copy_x = n;
	ll eaten = 0;

	while(n){
		eaten += std::min(n, k);
		n -= std::min(n, k);
		n -= n / 10;
	}

	if(eaten * 2LL >= copy_x){
		return true;
	}
	return false;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll x;
	std::cin >> x;

	ll l = 1, r = x;
	ll best = x;
	while(l <= r){
		ll mid = (l + r) / 2;

		if(good(x, mid)){
			r = mid - 1;
			best = mid;
		} else {
			l = mid + 1;
		}
	}

	std::cout << best << '\n';
}