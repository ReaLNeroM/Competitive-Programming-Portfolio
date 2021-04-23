// https://nadc21.kattis.com/problems/nadc21.circleoffriends
// PARTIAL SOLUTION

#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn = 2e5 + 1e2;
ll val[maxn];
int dp[maxn][60];
int simple[maxn];
set<int> missing[60];
int lef[maxn];
int rig[maxn];
const ll mod = 998244353LL;

int fenwick[maxn + 100];
void update_fenwick(int pos, int val){
    pos += 2;

    while(pos < maxn){
        fenwick[pos] += val;
        fenwick[pos] %= mod;
        pos += pos & -pos;
    }
}

int query_fenwick(int pos){
    pos += 2;
    int res = 0;

    while(pos > 0){
        res += fenwick[pos];
        res %= mod;
        pos -= pos & -pos;
    }

    return res;
}


int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;

    for(int i = 0; i < n; i++){
        std::cin >> val[i];
        for(ll j = 1, bit = 0; j < (1LL << 60); j *= 2, bit++){
            if((j & val[i]) == 0){
                missing[bit].insert(i);
            }
        }
    }

    for(int i = 0; i < n; i++){
        int best = i + 1;
        for(ll j = 1, bit = 0; j < (1LL << 60); j *= 2, bit++){
            auto ite = missing[bit].upper_bound(i);
            if(ite == missing[bit].end()){
                best = max(best, n);
            } else {
                best = max(best, *ite);
            }
        }
        lef[i] = best;
    }

    for(int i = 0; i < n; i++){
        int best = i - 1;
        for(ll bit = 0; bit < 60; bit++){
            auto ite = missing[bit].lower_bound(i);
            if(ite == missing[bit].begin()){
                best = min(best, -1);
            } else {
                ite--;
                best = min(best, *ite);
            }
        }
        rig[i] = best;
    }

    simple[n] = 1;
    update_fenwick(n, 1);

    for(int i = n - 1; i >= 0; i--){
        ll myr = query_fenwick(lef[i]);
        ll myl = query_fenwick(i);
        simple[i] = (mod + myr - myl) % mod;
        update_fenwick(i, simple[i]);
    }

    if(lef[0] == n){
        int res = simple[0];
        for(int i = n - 2; i >= 0; i--){
            ll r = ((n - 1) - i) * simple[n - i];
            r %= mod;
            res = (res + r) % mod;
        }
        cout << res << endl;
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        int k = n;
        if(rig[i] != -1){
            break;
        }

        for(int j = 0; j < 60; j++){
            auto ite = missing[j].lower_bound(0);
            if(*ite > i){
                auto sec = missing[j].end();
                sec--;

            }
        }
    }

    int res = 0;

    //

    std::cout << res << '\n';
}
