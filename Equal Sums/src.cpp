#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
ll val[maxn][maxn];
ll sumv[maxn];
ll sumh[maxn];
ll sum = 0;
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    
    ll need = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            std::cin >> val[i][j];
            sumv[i] += val[i][j];
            sumh[j] += val[i][j];
            sum += val[i][j];
            need = std::max(need, std::max(sumv[i], sumh[j]));
        }
    }
    
    for(ll i = 0; i < n; i++){
        ll vleft = need - sumv[i];
        for(ll j = 0; j < n; j++){
            ll hleft = need - sumh[j];
            ll min = std::min(hleft, vleft);
            val[i][j] += min;
            sumh[j] += min;
            sumv[i] += min;
            hleft -= min;
            vleft -= min;
        }
    }
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            std::cout << val[i][j] << ' ';
        }
        std::cout << '\n';
    }
}