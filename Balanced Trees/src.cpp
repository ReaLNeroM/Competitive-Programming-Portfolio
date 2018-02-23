#include <bits/stdc++.h>

typedef long long ll;

const double eps = 0.000000001;

std::map<int, ll> m;

ll dfs(ll x){
	if(m[x] != 0){
		return m[x];
	}
	ll res = 0;

	ll highest_call = 1;
	double last = x;
	for(ll i = 1; i * i <= x; i++){
		double high = last;
		high = std::floor(high + eps);

		last = (double) x / (i + 1.0);
		double low = std::ceil(last + eps);

		int span = ((ll) (high + 0.1)) - ((ll) (low + 0.1)) + 1;

		int get = m[i];
		if(get == 0){
			res += span * dfs(i);
		} else {
			res += span * get;
		}
		
		highest_call = i;
	}

	for(ll i = 2; i < 2 * highest_call; i++){ //very rough bound, condition happens much earlier
		ll weight = x / i;

		if(weight <= highest_call){
			break;
		}

		int get = m[weight];
		if(get == 0){
			res += dfs(weight);
		} else {
			res += get;
		}
	}

	m[x] = res;
	return res;
}

ll brute(ll n){
	ll val[n + 1];

	val[1] = 1;

	for(ll i = 2; i <= n; i++){
		for(ll j = 2; j <= i; j++){
			ll weight = i / j;
			val[i] += val[weight];
		}
	}

	return val[n];
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	m[1] = 1;

	std::cout << dfs(n) << '\n';
	// std::cerr << brute(n) << '\n';
}
