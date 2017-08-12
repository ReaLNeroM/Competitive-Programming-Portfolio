#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 100;
ll n;
ll h[maxn];
ll candles[maxn];

ll res = 0;

bool good(ll pos){
    if(pos == 0){
        return true;
    }
    std::map<ll, ll> m;
    for(ll i = 0; i < pos; i++){
        m[candles[i]]++;
    }

    std::vector<ll> v;
    v.resize(m.rbegin()->first, 0);
    ll sum = 0;
    ll prev = m.rbegin()->first - 1;
    ll ind;
    for(auto i = m.rbegin(); true; i++){
        if(i == m.rend()){
            ind = 0;
            for(ll j = ind; j <= prev; j++){
            	v[j] = sum;
            }
            prev = ind;
            break;
        } else {
            ind = i->first - 1;
            for(ll j = ind; j <= prev; j++){
                v[j] = sum;
            }
            prev = ind;
        }
        sum += i->second;
    }

    std::sort(v.begin(), v.end());

    ll curr = 0;
    ll left = 0;
    for(ll i = 0; i < v.size(); i++){
        do {
            if(curr == n){
                return false;
            }
            left += h[curr];
            curr++;
        } while(left < v[i]);

        left -= v[i];
    }

    return true;
}

int main(){
    std::ios::sync_with_stdio(false);

    ll evenings;
    std::cin >> n >> evenings;

    for(ll i = 0; i < n; i++){
        std::cin >> h[i];
//    	h[i] = 99998;
    }
    std::sort(h, h + n);

    for(ll i = 0; i < evenings; i++){
        std::cin >> candles[i];
//    	candles[i] = 99998;
    }

    ll l = 0, r = evenings;

    while(l <= r){
        ll mid = (l + r) / 2;

        if(good(mid)){
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    std::cout << res;
}
