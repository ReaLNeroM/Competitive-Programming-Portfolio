#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 2005;
ll n, a, b;
ll dp[maxn][maxn];
ll dont_care = 0;
ll val[maxn];
ll dp2[maxn];
 
ll dfs(ll pos, ll made){
    if(dp[pos][made] == -1){
        dp[pos][made] = (1LL << 60);
 
        if(pos == n){
            if(a <= made and made <= b){
                dp[pos][made] = 0;
            } else {
                dp[pos][made] = (1LL << 60);
            }
        } else {
            ll sum = 0;
 	
            for(ll i = pos; i < n; i++){
                sum += val[i];
                dp[pos][made] = std::min(dp[pos][made], (sum | dfs(i + 1, made + 1)) & (~dont_care));
            }
        }
    }
 
    return dp[pos][made];
}
 
ll dfs2(ll pos){
    if(dp2[pos] == -1){
        if(pos == n){
            dp2[pos] = 0;
        } else {
            dp2[pos] = 10000000;
            ll sum = 0;

            for(ll i = pos; i < n; i++){
                sum += val[i];
                if((sum | dont_care) == dont_care){
                    dp2[pos] = std::min(dp2[pos], dfs2(i + 1) + 1);
                }
            }
        }
    }

    return dp2[pos];
}

int main(){
    std::ios::sync_with_stdio(false);
 
    std::cin >> n >> a >> b;
 
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }
 
    if(a == 1){
        //N^2
        for(ll bit = (1LL << 50); bit > 0; bit /= 2){
            for(ll i = 0; i < maxn; i++){
                dp2[i] = -1;
            }

            dont_care |= (bit - 1LL);
            if(dfs2(0) > b){
                dont_care |= bit;
            }
            dont_care ^= (bit - 1LL);
        }

    } else {
        //N^3

        for(ll bit = (1LL << 50); bit > 0; bit /= 2){
            for(ll i = 0; i < maxn; i++){
                for(ll j = 0; j < maxn; j++){
                    dp[i][j] = -1;
                }
            }

            if((dfs(0, 0) & (~dont_care)) >= bit){
                dont_care |= bit;
            }
        }
    }
 
    std::cout << dont_care;
}