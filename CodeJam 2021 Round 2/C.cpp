#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 10;
const ll mod = 1000000007;
using namespace std;

ll fact[maxn];
ll invfact[maxn];

ll expp(ll a, ll b, ll m){
    ll c = 1;
    while(b){
        if(b & 1){
            c *= a;
            c %= m;
        }

        a *= a;
        a %= m;
        b /= 2;
    }

    return c;
}

ll binom(ll n, ll k){
    ll ret = fact[n];
    ret *= invfact[k];
    ret %= mod;
    ret *= invfact[n - k];
    ret %= mod;

    return ret;
}

ll rc[maxn];
vector<ll> greater_than[maxn];
std::vector<ll> adj[maxn];

pair<ll, ll> dfs(ll pos){
    if(adj[pos].empty()){
        return {1, 1};
    }

    ll totalsize = 0;
    vector<ll> sizes;
    vector<ll> perms;
    for(ll i : adj[pos]){
        auto j = dfs(i);
        totalsize += j.first;
        sizes.push_back(j.first);
        perms.push_back(j.second);
    }
    ll ret = 1;
    for(ll j : perms){
        ret *= j;
        ret %= mod;
    }
    ll mysize = totalsize;
    for(ll i = 0; i < sizes.size(); i++){
        ret *= binom(mysize, sizes[i]);
        ret %= mod;
        mysize -= sizes[i];
    }
    return {totalsize + 1, ret};
}

int main(){
    std::ios::sync_with_stdio(false);

    ll testCases;
    std::cin >> testCases;

    fact[0] = 1;
    fact[1] = 1;
    for(ll i = 2; i < maxn; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
    }
    invfact[0] = 1;
    invfact[1] = 1;
    for(ll i = 2; i < maxn; i++){
        invfact[i] = expp(fact[i], mod - 2, mod);
    }

    for(ll testcase = 1; testcase <= testCases; testcase++){
        std::cout << "Case #" << testcase << ": ";

        ll n;
        std::cin >> n;

        for(ll i = 0; i < n; i++){
            rc[i] = 0;
            greater_than[i].clear();
            adj[i].clear();
        }

        vector<ll> s;
        bool done = false;
        for(ll i = 0; i < n; i++){
            ll v;
            cin >> v;
            while((ll) v < s.size() + 1){
                greater_than[i].push_back(s.back());
                rc[s.back()]++;
                s.pop_back();
            }
            if((ll) v != s.size() + 1){
                cout << 0 << endl;
                done = true;
                break;
            }
            if(!s.empty()){
                greater_than[s.back()].push_back(i);
                rc[i]++;
            }
            s.push_back(i);
        }
        if(done){
            continue;
        }

        queue<ll> topo;
        for(ll i = 0; i < n; i++){
            if(rc[i] == 0){
                topo.push(i);
            }
        }

        ll head = topo.front();
        while(!topo.empty()){
            ll fr = topo.front();
            topo.pop();

            for(ll i : greater_than[fr]){
                rc[i]--;
                if(rc[i] == 0){
                    adj[fr].push_back(i);
                    topo.push(i);
                }
            }
        }

        ll ret = dfs(head).second;

        std::cout << ret << '\n';
    }
}