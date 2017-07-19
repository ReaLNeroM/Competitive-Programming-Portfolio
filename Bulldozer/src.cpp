#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2005;
std::vector<ll> v[maxn];
std::set<ll> s;
ll n;
ll res = 0;

void solve(){
	std::sort(v, v + n);

	for(ll i = 0; i < n; i++){
		ll curr = 0;

		ll l = i, r = i - 1;
		while(r != n - 1 and v[r + 1][0] == v[l][0]){
			curr += v[r + 1][2];
			r++;
		}

		for(ll j = r + 1; j < n; j++){
			curr += v[j][2];

			if(j == n - 1 or v[j][0] != v[j + 1][0]){
				res = std::max(res, curr);
			}
		}

		i = r;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(ll i = 0; i < n; i++){
		v[i].resize(3);
		std::cin >> v[i][0] >> v[i][1] >> v[i][2];
	}

	solve();

	for(ll i = 0; i < n; i++){
		std::swap(v[i][0], v[i][1]);
	}

	solve();

	std::cout << res << std::endl;
}