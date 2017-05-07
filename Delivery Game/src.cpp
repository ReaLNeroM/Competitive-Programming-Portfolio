#include <bits/stdc++.h>
 
typedef long long ll;
 
const ll maxn = 30005;
int n;
int x[maxn];
int prep[maxn];
int speed[maxn];
std::map<ll, std::vector<ll>> m;

int evaluate(std::vector<ll> v, int pos){
    return v[0] + v[2] * pos;
}

int query(int pos){
    return evaluate(m.lower_bound(pos)->second, pos);
}

void add(int pos, int m, int b){
    b -= m * pos;

    auto ite = m.lower_bound()
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n;
 
    for(ll i = 0; i < n; i++){
        std::cin >> dist[i] >> prep[i] >> speed[i];
    }

    int move = dist[0];

    for(ll i = 0; i < n; i++){
        dist[i] = move - dist[i];
    }

    m[move] = {0, {speed[0], prep[0]}};

    for(ll i = 1; i < n; i++){
        ll start = query(dist[i]);

        add(dist[i], speed[i], start + prep[i]);
    }

    std::cout << query(move) << std::endl;
    return 0;
}