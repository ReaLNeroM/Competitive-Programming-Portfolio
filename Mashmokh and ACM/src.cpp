#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2005;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn];

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n, k;
    std::cin >> n >> k;

    for(ll i = 1; i <= n; i++){
        dp[1][i] = 1;
    }
    
    for(ll i = 2; i <= k; i++){
        for(ll j = 1; j <= n; j++){
            for(ll k = j; k <= n; k += j){
                dp[i][k] += dp[i - 1][j];
                dp[i][k] %= mod;
            }
        }
    }    
    //calc

    ll res = 0;

    for(ll i = 1; i <= n; i++){
        res += dp[k][i];
        res %= mod;
    }

    std::cout << res;

}