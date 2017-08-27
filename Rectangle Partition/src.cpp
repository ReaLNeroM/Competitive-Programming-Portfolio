#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll a[maxn];
ll b[maxn];
ll ac[maxn];
ll bc[maxn];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll y, x, yl, xl;
    std::cin >> y >> x >> yl >> xl;
        
    for(ll i = 0; i < yl; i++){
        std::cin >> ac[i];
    }
    for(ll i = 0; i < xl; i++){
        std::cin >> bc[i];
    }
    
    std::sort(ac, ac + yl);
    std::sort(bc, bc + xl);
    
    ll last = 0;
    for(ll i = 0; i <= yl; i++){
        ll curr;
        
        if(i == yl){
            curr = y;
        } else {
            curr = ac[i];
        }
        
        a[curr - last]++;
        
        last = curr;
    }
    
    last = 0;
    for(ll i = 0; i <= xl; i++){
        ll curr;
        
        if(i == xl){
            curr = x;
        } else {
            curr = bc[i];
        }
        
        b[curr - last]++;
        
        last = curr;
    }
    
    for(ll i = 1; i < maxn; i++){
        res += a[i] * b[i];
    }
    
    std::cout << res << '\n';
}