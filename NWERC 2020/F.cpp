// https://codeforces.com/gym/103049/problem/F

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
ll x[maxn];
ll v[maxn];
bool dead[maxn];
map<ll, ll> m;
ll n;

long double get_collision_time(ll i, ll j){
    if(x[i] > x[j]){
        exit(-1);
    }
    if(v[i] - v[j] > 0){
        long double xx = x[j] - x[i];
        xx /= (long double) v[i] - v[j];
        return xx;
    }
    return -1.0;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    std::cin >> n;

    for(ll i = 0; i < n; i++){
        cin >> x[i] >> v[i];
        m[x[i]] = i;
    }

    std::priority_queue<std::pair<long double, std::pair<ll, ll>>> pq;

    for(ll i = 0; i + 1 < n; i++){
        long double collision_time = get_collision_time(i, i + 1);
        if(collision_time > -0.2){
            pq.push({-collision_time, {i, i + 1}});
        }
    }

    while(!pq.empty()){
        auto fr = pq.top();
        pq.pop();

        if(dead[fr.second.first] or dead[fr.second.second]){
            continue;
        }

        // mark them as dead.

        dead[fr.second.first] = true;
        dead[fr.second.second] = true;
        m.erase(m.find(x[fr.second.first]));
        m.erase(m.find(x[fr.second.second]));

        auto ite = m.lower_bound(x[fr.second.first]);
        if(ite == m.end()){
            continue;
        }
        auto sec = ite;
        if(sec == m.begin()){
            continue;
        }
        sec--;

        ll i = sec->second;
        ll j = ite->second;

        long double collision_time = get_collision_time(i, j);

        if(collision_time > -0.2){
            pq.push({-collision_time, {i, j}});
        }
    }

    ll res = 0;

    ll alives = 0;
    for(ll i = 0; i < n; i++){
        if(!dead[i]){
            alives++;
        }
    }
    cout << alives << '\n';
    for(ll i = 0; i < n; i++){
        if(!dead[i]){
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}
