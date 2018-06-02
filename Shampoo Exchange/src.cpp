#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 100;
ll val[maxn];
ll sec[maxn];
ll used[maxn];
ll n, capacity;
ll finalbottles;
ll res = 0;

bool good(ll seconds){
    std::copy(val, val + n, sec);
    memset(used, 0, sizeof(used));
    
    ll currpos = finalbottles;
    for(int i = 0; i < finalbottles; i++){
        while (used[i] < seconds and sec[i] < capacity and currpos < n){
            ll change = std::min(seconds - used[i], std::min(capacity - sec[i], sec[currpos]));
            sec[i] += change;
            used[i] += change;
            sec[currpos] -= change;
            
            if(sec[currpos] == 0){
                currpos++;
            }
        }
    }
    if(currpos < n){
        return false;
    }
    
    return true;
}

int main(){
    std::cin >> n >> capacity;
    
    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }
    
    ll sum = std::accumulate(val, val + n, 0LL);
    finalbottles = (sum + capacity - 1) / capacity;
    std::sort(val, val + maxn, std::greater<ll>());
    
    for(ll i = finalbottles; i < n; i++){
        res = std::max(res, val[i]);
    }
    
    ll l = res, r = capacity;
    while(l <= r){
        ll mid = (l + r) / 2;
        
        if(good(mid)){
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    std::cout << finalbottles << ' ' << res << '\n';
}
