#include <bits/stdc++.h>

typedef long long ll;

const long double eps = 0.00000000001;

std::map<int, ll> m;

ll dfs(int x){
	if(m[x] != 0){
		return m[x];
	}
	ll res = 0;

	ll highest_call = 1;
	ll last = x;
	for(ll i = 1; i * i <= x; i++){
		ll high = last;

		last = std::floor((long double) x / (i + 1.0) + eps);

		ll low = last;

		// std::cerr << x << ' ' << i << ' ' << ((ll) (high + 0.1)) << ' ' << ((ll) (low + 0.1)) << '\n';

		ll span = high - last;

		ll get = m[i];
		if(get == 0){
			get = dfs(i);
		}

		res += span * get;
		
		highest_call = i;
	}

	for(ll i = 2; i < 2 * highest_call; i++){ //very rough bound, condition happens much earlier
		ll weight = x / i;

		if(weight <= highest_call){
			break;
		}

		ll get = m[weight];
		if(get == 0){
			res += dfs(weight);
		} else {
			res += get;
		}
	}

	m[x] = res;
	return res;
}

ll brute(int n){
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

	int n;
	std::cin >> n;

	m[1] = 1;

	std::cout << dfs(n) << '\n';
	// std::cerr << brute(n) << '\n';
}
