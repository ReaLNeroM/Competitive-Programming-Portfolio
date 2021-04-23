// https://codefu.mk/codefu2021-round1.html?subpage=problem&problemid=3216
// PARTIAL

#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <list>
#include <algorithm>
// #include <iostream>

typedef long long ll;
using namespace std;

const ll maxn = 500005;
std::vector<ll> v[maxn];
ll fen[maxn];

class LockedOut {
    void update(ll pos, ll c){
        pos++;
        while(pos < maxn){
            fen[pos] += c;
            pos += pos & -pos;
        }
    }

    ll query(ll pos){
        pos++;
        ll ret = 0;
        while(pos > 0){
            ret += fen[pos];
            pos -= pos & -pos;
        }
        return ret;
    }
public:
    string findCode(int _a, int _b, int _mod, int _x0, int _n){
        ll a = _a;
        ll b = _b;
        ll mod = _mod;
        ll x0 = _x0;
        ll n = _n;

        std::list<std::pair<ll, ll>> l;
        ll x = x0;
        for(ll i = 0; i < n; i++){
            l.push_back({((x < mod / 2) ? 4 : 7), i + 1});
            x = (a * x + b) % mod;
        }

        auto ite = l.begin();
        while(ite != l.end()){
            auto next = ite;
            next++;

            ll curr = ite->first;
            ll nex = next->first;

            if(curr == 4 and nex == 7){
                v[next->second - ite->second].push_back(ite->second);

                if(ite == l.begin()){
                    auto temp = ite;
                    ite = next;
                    ite++;
                    l.erase(temp);
                    l.erase(next);
                } else {
                    auto temp = ite;
                    ite--;
                    l.erase(temp);
                    l.erase(next);
                }
            } else {
                ite++;
            }
        }

        for(ll i = 1; i <= n; i++){
            update(i, 1);
        }

        ll sum = 0;

        for(ll i = 0; i <= n; i++){
            for(ll j : v[i]){
                sum += query(j);
            }
            for(ll j : v[i]){
                update(j, -1);
                update(j + 1, -1);
            }
        }

        return to_string(sum);
    }
};
