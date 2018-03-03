#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 505;
const ll maxbit = 11;
ll dp[maxn][maxn][maxbit];
ll ways[maxn][maxn];
ll m;

ll dfs(ll size, ll left, ll bit){
	if(dp[size][left][bit] == -1){
		ll &ans = dp[size][left][bit];
		ans = 0;

		if(left == 0){
			ans = 1;
		} else if(bit == 0){
			ans = 0;
		} else {
			ll jmp = (1 << (bit - 1));
			for(ll i = 0; i <= left; i += 2 * jmp){
				ans += (ways[size][i / jmp] * dfs(size, left - i, bit - 1)) % m;
				ans %= m;
			}
		}
	}

	return dp[size][left][bit];
}

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n >> m;

    for(ll i = 0; i < maxn; i++){
    	for(ll j = 0; j < maxn; j++){
    		for(ll k = 0; k < maxbit; k++){
    			dp[i][j][k] = -1;
    		}
    	}
    }

    for(ll i = 0; i < maxn; i++){
        ways[i][0] = 1;
        ways[i][i] = 1;
    }
    
    for(ll i = 1; i < maxn; i++){
        for(ll j = 1; j < maxn; j++){
            ways[i][j] = ways[i - 1][j - 1] + ways[i - 1][j];
            ways[i][j] %= m;
        }
    }
    
    
    for(ll i = 1; i <= n; i++){
        ll res = dfs(i, n, maxbit - 1);
        
        // std::cout << "E" << res << ' ';
        
        for(ll j = 1; j < i; j++){
            res -= (ways[i][j] * dfs(j, n, maxbit - 1)) % m;
            res %= m;
            if(res < 0){
                res = -res;
            }
            // std::cout << ways[i][j] * dfs(j, n, maxbit - 1) << ' ';
        }
        // std::cout << '\n';
        dp[i][n][maxbit - 1] = res;
        
        std::cout << res << '\n';
    }
}