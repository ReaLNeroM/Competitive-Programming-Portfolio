#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll n, k;
ll val[maxn];

bool good(ll split, ll need){
    ll found = 0;
    for(ll i = 0; i < n; i++){
        found += val[i] / split;
    }

    return (found >= need);    
}

int main(){
    std::ios::sync_with_stdio(false);
    
    std::cin >> n >> k;
    
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }
    std::sort(val, val + n);
    
    ll l = 1, r = val[n - 1];
    ll res = 0;
    
    while(l <= r){
        ll mid = (l + r) / 2;
        
        if(good(mid, k)){
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    std::cout << res << '\n';
}