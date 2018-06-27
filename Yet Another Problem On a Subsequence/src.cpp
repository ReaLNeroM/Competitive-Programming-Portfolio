#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 998244353LL;
ll val[maxn];
ll dp[maxn];
ll binomial[maxn][maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }

    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= i; j++){
            if(j == 0 or j == i){
                binomial[i][j] = 1;
            } else{
                binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
                binomial[i][j] %= mod;
            }
        }
    }

    dp[n] = 1;
    for(ll i = n - 1; i >= 0; i--){
        ll get = val[i];
        if(val[i] <= 0 or val[i] > n){
            continue;
        }
        for(ll j = i + get + 1; j <= n; j++){
            dp[i] += dp[j] * binomial[j - i - 1][get];
            dp[i] %= mod;
        }
    }

    for(ll i = 0; i < n; i++){
        res += dp[i];
        res %= mod;
    }

    std::cout << res << '\n';
}