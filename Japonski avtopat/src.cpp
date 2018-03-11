#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 1e6 + 1e2;
std::vector<ll> v[maxn];
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    ll n, m;
    std::cin>> n >> m;
 
    for(ll i = 0; i < n; i++){
        v[i].resize(2);
        std::cin >> v[i][0] >> v[i][1];
    }
 
    std::sort(v, v + n);
 
    ll res = 0;
    ll curr = 0;
    for(ll i = 0; i < n; i++){
        if(curr < v[i][1]){
            res += v[i][1] - curr;
        }
        curr = v[i][1];
    }
 
    std::cout << res << '\n';
 
}