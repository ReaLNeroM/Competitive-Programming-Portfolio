#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll INF = 1e18;
ll val[2][maxn];
ll dp[2][2][maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
        
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j < n; j++){
            std::cin >> val[i][j];
        }
    }
    
    dp[0][0][n - 1] = dp[1][0][n - 1] = val[0][n - 1] + val[1][n - 1];
    dp[0][1][n - 1] = dp[1][1][n - 1] = val[1][n - 1];

	for(ll j = n - 2; j >= 0; j--){
		for(ll i = 1; i >= 0; i--){
			dp[0][i][j] = dp[1][i][j + 1] + val[i][j];
			dp[1][i][j] = dp[0][i][j + 1] + val[i][j];

			dp[0][i][j] = std::max(dp[0][i][j], dp[0][!i][j + 1] + val[i][j] + val[!i][j]);
			dp[1][i][j] = std::min(dp[1][i][j], dp[1][!i][j + 1] + val[i][j] + val[!i][j]);
        }
    }
    
    std::cout << dp[1][0][0] << '\n';
}
