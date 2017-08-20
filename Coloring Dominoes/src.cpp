#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
char val[2][maxn];
ll dp[maxn][8][8];
ll n;

ll dfs(ll pos, ll a, ll b){
	if(dp[pos][a][b] == -1){
		ll &res = dp[pos][a][b];

		if(pos == n){
			res = 1;
		} else {
			res = 0;

			if(val[0][pos] == val[1][pos]){
				for(ll j = 1; j <= 4; j *= 2){
					if((a & j) and (b & j)){
						res += dfs(pos + 1, 7 ^ j, 7 ^ j);
					}
					res %= mod;
				}
			} else {
				for(ll j = 1; j <= 4; j *= 2){
					for(ll k = 1; k <= 4; k *= 2){
						if((a & j) and (b & k) and j != k){
							if(val[0][pos + 1] == val[0][pos] and val[1][pos + 1] == val[1][pos]){
								res += dfs(pos + 1, j, k);
							} else if(val[0][pos + 1] == val[0][pos]){
								res += dfs(pos + 1, j, 7 ^ k);
							} else if(val[1][pos + 1] == val[1][pos]){
								res += dfs(pos + 1, 7 ^ j, k);
							} else {
								res += dfs(pos + 1, 7 ^ j, 7 ^ k);
							}
						}
						res %= mod;
					}
				}
			}
		}
	}

	return dp[pos][a][b];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(ll i = 0; i < 2; i++){
		for(ll j = 0; j < n; j++){
			std::cin >> val[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));

	std::cout << dfs(0, 7, 7) << '\n';
}
