#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll max_bit = 1e7 + 100;
std::array<ll, 3> v[max_bit];
std::array<ll, 3> s[max_bit];
ll val[maxn][2];
ll res = 0;

int main(){
    std::ios::sync_with_stdio(false);
    
    ll n;
    std::cin >> n;
    
    for(ll i = 0; i < n; i++){
        std::cin >> val[i][0] >> val[i][1];
        val[i][1] *= -1;
    }
    
    ll n_a = n / 2;
    ll n_b = n - n_a;
    
    for(ll i = 0; i < (1LL << n_a); i++){
        ll sum = 0;
        ll cards = 0;

        for(ll j = 0, bit = 1; j < n_a; j++, bit *= 2){
            if(i & bit){
                sum += val[j][1];
                cards++;
            } else {
                sum += val[j][0];
                cards--;
            }
        }

        v[i] = {sum, cards, i};
    }

    for(ll i = 0; i < (1LL << n_b); i++){
        ll sum = 0;
        ll cards = 0;

        for(ll j = n_a, bit = 1; j < n; j++, bit *= 2){
            if(i & bit){
                sum += val[j][1];
                cards++;
            } else {
                sum += val[j][0];
                cards--;
            }
        }

        s[i] = {sum, cards, i};
    }

    std::sort(v, v + (1LL << n_a));
    std::sort(s, s + (1LL << n_b), std::greater<std::array<ll, 3>>());

    ll bestsize = n + 1, bestind = 0;

    ll pos = 0;
    for(ll i = 0; i < (1LL << n_a); i++){
        while(pos < (1LL << n_b) and v[i][0] + s[pos][0] > 0){
            pos++;
        }

        if(pos != (1LL << n_b) and v[i][0] + s[pos][0] == 0){
            if(std::abs(v[i][1] + s[pos][1]) < std::abs(bestsize)){
                bestsize = v[i][1] + s[pos][1];
                bestind = s[pos][2] * (1LL << n_a) + v[i][2];
            }
        }
    }

    if(bestsize == n + 1){
        std::cout << -1 << '\n';
    } else {
        for(ll i = 0, bit = 1; i < n; i++, bit *= 2){
            if(bestind & bit){
                std::cout << 1;
            } else {
                std::cout << 0;
            }
        }
    }
}