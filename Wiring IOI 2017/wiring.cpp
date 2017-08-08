#include "wiring.h"
#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e5 + 1e2;

ll dp[maxn];
std::set<ll> u[2];
std::vector<std::vector<ll>> v;
ll sum[maxn];

ll cost(ll pos, ll a, ll b){
	ll res = 0;
	res += v[pos + a][0] * a;
	res -= sum[pos + a - 1] - sum[pos - 1];

	res += sum[pos + a + b - 1] - sum[pos + a - 1];
	res -= v[pos + a][0] * b;

	return res;
}

ll min_total_length(std::vector<int> r, std::vector<int> b) {
	for(ll i = 0; i < r.size(); i++){
		v.push_back({r[i], 1});
		u[1].insert(r[i]);
	}
	for(ll i = 0; i < b.size(); i++){
		v.push_back({b[i], 0});
		u[0].insert(b[i]);
	}

	std::sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++){
		if(i == 0){
			sum[i] = v[i][0];
		} else {
			sum[i] = sum[i - 1] + v[i][0];
		}
	}
	for(ll i = v.size() - 1; i >= 0; i--){
		auto ite = u[!v[i][1]].lower_bound(v[i][0]);
		dp[i] = 1e18;

		if(ite != u[!v[i][1]].begin()){
			ite--;
			dp[i] = dp[i + 1] + (v[i][0] - *ite);
		}

		ll block0 = 0, block1 = 0;
		for(ll j = i; j < v.size(); j++){
			if(v[i][1] == v[j][1] and !block1){
				block0++;
			} else if(v[i][1] != v[j][1]){
				block1++;
				dp[i] = std::min(dp[i], dp[i + block0 + block1] + cost(i, block0, block1));
				if(block0 == block1){
					break;
				}
			} else {
				break;
			}
		}
	}

	return dp[0];
}
