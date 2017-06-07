#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1005;
ll n, k;


int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	ll sum = 0;
	for(ll i = 0; i < n; i++){
		ll val;
		std::cin >> val;
		sum += val;
	}

	ll llervals;
	std::cin >> llervals;

	ll res = 1e18;
	for(ll i = 0; i < llervals; i++){
		ll l, r;
		std::cin >> l >> r;

		if(sum < l){
			res = std::min(res, l);
		}
		if(l <= sum and sum <= r){
			res = std::min(res, sum);
		}
	}

	if(res == 1e18){
		res = -1;
	}
	std::cout << res;
}