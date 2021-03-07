// https://nena20.kattis.com/problems/march6.triangularcollection

#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 55;
ll val[maxn];

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    ll n;
    std::cin >> n;

    for(ll i = 0; i < n; i++){
        std::cin >> val[i];
    }
    std::sort(val, val + n);

    ll res = 0;
    for(ll i = 0; i < n; i++){
        for(ll j = i + 1; j < n; j++){
            ll fills = 0;
            for(ll k = i + 1; k < j; k++){
                if(val[i] + val[k] > val[j]){
                    fills++;
                }
            }
            res += (1LL << fills) - 1LL;
        }
    }

    std::cout << res << '\n';
}
