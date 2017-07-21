#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
ll dp[maxn][maxn];
ll pos[maxn][maxn];
ll val[maxn];
ll n, m;

ll score(ll i, ll p, ll j){
	return dp[i][p] + dp[p][j] + (val[j] - val[i]);	
}

int main(){
	std::ios::sync_with_stdio(false);
	
	while(std::cin >> n >> m){
		memset(dp, 0, sizeof(dp));
		memset(pos, 0, sizeof(pos));
		
		val[0] = 0;
		val[m + 1] = n;
		for(ll i = 1; i <= m; i++){
			std::cin >> val[i];
		}
		
		m += 2;
		
		for(ll sz = 2; sz <= m; sz++){
			for(ll i = 0; i + sz <= m; i++){
				dp[i][i + sz - 1] = 1e18;
				if(sz == 2){
					dp[i][i + sz - 1] = 0;
					pos[i][i + sz - 1] = i;
				} else {
					ll l = pos[i][i + sz - 2];
					ll r = pos[i + 1][i + sz - 1];
					
					for(ll j = l; j <= r; j++){
						if(score(i, j, i + sz - 1) < dp[i][i + sz - 1]){
							dp[i][i + sz - 1] = score(i, j, i + sz - 1);
							pos[i][i + sz - 1] = j;
						}
					}
				}
			}
		}
		
		std::cout << dp[0][m - 1] << '\n';
	}
}