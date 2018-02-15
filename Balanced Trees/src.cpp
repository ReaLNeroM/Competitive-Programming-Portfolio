#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
std::map<ll, ll> m;
ll val[maxn];

ll dfs(ll x){
	ll res = 0;

	ll sqrx = sqrt(x);

	for(ll i = 2; i <= sqrx; i++){
		ll weight = x / i;

		if(m.find(weight) == m.end()){
			res += dfs(weight);
		} else {
			res += m[weight];
		}
	}

	m[x] = res;
	return res;
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n;
	std::cin >> n;

	if(n > 1000){
		m[1] = 1;

		std::cout << dfs(n) << '\n';
	} else {
		val[1] = 1;

		for(ll i = 2; i <= n; i++){
			for(ll j = 2; j <= i; j++){
				ll weight = i / j;
				val[i] += val[weight];
			}
		}

		std::cout << val[n] << '\n';
	}

}