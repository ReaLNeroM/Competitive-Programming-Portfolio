#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll mod = 1e9 + 7;
const ll INF = 1e18;
ll n, d[2];
ll dp[maxn][2];
ll sufsum[maxn][2];
ll val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> d[0] >> d[1];

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	dp[n - 2][0] = dp[n - 2][1] = dp[n - 1][0] = dp[n - 1][1] = 1;
	sufsum[n - 1][0] = sufsum[n - 1][1] = 1;
	sufsum[n - 2][0] = sufsum[n - 2][1] = 2;
	
	ll farthest[] = {n, n};

	for(ll i = n - 3; i >= 0; i--){
		for(ll order = 0; order < 2; order++){
			ll& ans = dp[i][order];

			if(val[i + 2] - val[i] >= d[order]){
				ans += dp[i + 1][!order];
				ans %= mod;
			}

			if(val[i + 2] - val[i + 1] < d[0]){
				farthest[0] = i + 2;
			}
			if(val[i + 2] - val[i + 1] < d[1]){
				farthest[1] = i + 2;
			}

			ll smallestInd = std::max(i + 3, (ll) (std::lower_bound(val, val + n, d[order] + val[i]) - &val[0])) - 1;
			if(smallestInd < farthest[!order]){
				ans += sufsum[smallestInd][!order];
				ans -= sufsum[farthest[!order]][!order];
				ans += mod;
				ans %= mod;
			}

			sufsum[i][order] = (sufsum[i + 1][order] + dp[i][order]) % mod;
		}
	}

	ll res = 0;
	ll smallestDiff = INF;

	for(ll i = 0; i < n; i++){
		if(smallestDiff >= d[0]){
			res += dp[i][0];
		}
		if(smallestDiff >= d[1]){
			res += dp[i][1];
		}

		smallestDiff = std::min(smallestDiff, val[i + 1] - val[i]);
		res %= mod;
	}

	std::cout << res << '\n';
}
