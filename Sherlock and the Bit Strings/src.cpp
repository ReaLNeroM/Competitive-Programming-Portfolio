#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll maxbit = (1 << 17);
const ll INF = 1000000000000000010;

ll a[maxn], b[maxn], c[maxn];
std::vector<std::vector<ll>> check[maxn];
ll dp[maxn][maxbit];
ll mask[maxn];
ll n, k, p;

ll dpfunc(ll pos, ll bitset){
	if(dp[pos][bitset] != -1){
		return dp[pos][bitset];
	}

	for(auto v : check[pos]){
		ll a = v[0];
		ll count = v[1];

		ll finalbitset = (mask[pos - a] & bitset);
		if(__builtin_popcount(finalbitset) != count){
			dp[pos][bitset] = 0;
			return 0;
		}
	}

	if(pos == n){
		dp[pos][bitset] = 1;
		return 1;
	}

	dp[pos][bitset] = dpfunc(pos + 1, (bitset * 2    ) & (maxbit - 1)) +
					  dpfunc(pos + 1, (bitset * 2 + 1) & (maxbit - 1));

	if(dp[pos][bitset] > INF){
		dp[pos][bitset] = INF;
	}
	return dp[pos][bitset];
}

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll i = 0; i < maxn; i++){
		mask[i] = (1LL << i) - 1;
	}

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cin >> n >> k >> p;
		p--;

		memset(dp, -1, sizeof(dp));
		for(int i = 0; i < maxn; i++){
			check[i].clear();
		}

		for(ll i = 0; i < k; i++){
			std::cin >> a[i] >> b[i] >> c[i];
			a[i]--, b[i]--;
			check[b[i] + 1].push_back({a[i], c[i]});
		}

		std::cout << "Case #" << testcase << ": ";

		ll made = 0;
		for(ll i = 0; i < n; i++){
			if(p <   dpfunc(i + 1, (made * 2)      & (maxbit - 1))){
				std::cout << 0;
				made = made * 2;
				made &= (maxbit - 1);
			} else {
				std::cout << 1;
				p -= dpfunc(i + 1, (made * 2)      & (maxbit - 1));
				made = made * 2 + 1;
				made &= (maxbit - 1);
			}
		}

		std::cout << '\n';
	}
}
