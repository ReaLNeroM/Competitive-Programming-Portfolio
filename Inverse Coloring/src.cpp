#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 510;
const ll mod = 998244353;
ll val[maxn];
ll dp[maxn][maxn][2];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, k;
	std::cin >> n >> k;
	k--;

	for(ll larg = 1; larg <= n and larg <= k; larg++){
		dp[larg][n][0] = 1;

		for(ll i = n - 1; i >= 0; i--){
			for(ll j = i + 1; j <= n and j - i <= larg; j++){
				if(j - i == larg){
					dp[larg][i][1] += dp[larg][j][0] + dp[larg][j][1];
					dp[larg][i][1] %= mod;
				} else {
					dp[larg][i][0] += dp[larg][j][0];
					dp[larg][i][0] %= mod;

					dp[larg][i][1] += dp[larg][j][1];
					dp[larg][i][1] %= mod;
				}
			}
		}
	}

	ll res = 0;

	for(ll i = 1; i <= n and i <= k; i++){
		ll v = std::min(n, k / i);
		ll x = 2 * dp[i][0][1];
		x %= mod;
		x *= (dp[v][0][0] + dp[v][0][1]);
		x %= mod;
		res += x;
		res %= mod;
	}

	std::cout << res << '\n';
}
