#include <bits/stdc++.h>
 
typedef long long ll;
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    ll n;
    std::cin>>n;
 
    ll res = 0;
 
    for(ll i = 0; i <= n; i++){
        for(ll j = 0; j <= i; j++){
            res += i + j;
        }
    }
 
    std::cout << res << '\n';
}