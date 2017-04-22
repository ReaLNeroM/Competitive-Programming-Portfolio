#include <bits/stdc++.h>
  
typedef long long ll;
  
const ll max_board = 10000000 + 10000;
const ll maxn = 100000 + 10000;
  
static ll fen[max_board];
std::vector<ll> insertion[max_board];
std::vector<std::vector<ll>> quer[max_board];
ll x[maxn], y[maxn], v[maxn];
ll res[maxn];
  
void update(ll pos, ll val){
    pos++;
    while(pos < max_board){
        fen[pos] += val;
        pos += pos & -pos;
    }
}
  
ll query(ll pos){
    pos++;
    ll res = 0;
    while(pos > 0){
        res += fen[pos];
        pos -= pos & -pos;
    }
  
    return res;
}
  
int main(){
    std::ios::sync_with_stdio(false);
  
    ll n;
    std::cin >> n;
  
    for(ll i = 0; i < n; i++){
        std::cin >> x[i] >> y[i] >> v[i];
        x[i]++;
        y[i]++;
        insertion[y[i]].push_back({i});
    }
  
    ll q;
    std::cin >> q;
  
    for(ll i = 0; i < q; i++){
        ll x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++;
  
        quer[y2    ].push_back({x2    , i,  1});
        quer[y2    ].push_back({x1 - 1, i, -1});
        quer[y1 - 1].push_back({x2    , i, -1});
        quer[y1 - 1].push_back({x1 - 1, i,  1});
    }
  
    for(ll i = 0; i < max_board; i++){
        for(ll j = 0; j < insertion[i].size(); j++){
            update(x[insertion[i][j]], v[insertion[i][j]]);
        }
  
        for(ll j = 0; j < quer[i].size(); j++){
            ll gotten = query(quer[i][j][0]);
  
            res[quer[i][j][1]] += quer[i][j][2] * gotten;
        }
    }
  
    for(ll i = 0; i < q; i++){
        std::cout << res[i] << '\n';
    }
  
}