#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
const ll mod = 1e9 + 7;
ll n;
ll a, b, c, d;
ll dp[maxn][maxn];
ll dpb[maxn][maxn];

ll binom(ll a, ll b){
	if(dpb[a][b] == -1){
		if(a == 0 or a <= b or b == 0){
			dpb[a][b] = 1;
		} else {
			dpb[a][b] = binom(a - 1, b) + binom(a - 1, b - 1);
			dpb[a][b] %= mod;
		}
	}

	return dpb[a][b];
}

ll calc(ll a, ll b, ll c){
	if(b == 0){
		return 1;
	} else {
		return calc(a - c, b - 1, c) * binom(a - 1, c - 1) % mod;
	}
}

ll dfs(ll people_left, ll curr_group){
	if(dp[people_left][curr_group] == -1){
		ll& v = dp[people_left][curr_group];

		if(people_left == 0 and curr_group == b + 1){
			v = 1;
		} else if(people_left != 0 and curr_group == b + 1){
			v = 0;
		} else {
			v = 0;

			v += dfs(people_left, curr_group + 1);
			for(ll i = c; i <= d and people_left - i * curr_group >= 0; i++){
				ll x = binom(people_left, i * curr_group) * calc(i * curr_group, i, curr_group);
				x %= mod;
				v += x * dfs(people_left - i * curr_group, curr_group + 1);
				v %= mod;
			}
		}
	}

	return dp[people_left][curr_group];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	std::cin >> a >> b >> c >> d;

	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			dp[i][j] = -1;
			dpb[i][j] = -1;
		}
	}

	std::cout << dfs(n, a) << '\n';
}