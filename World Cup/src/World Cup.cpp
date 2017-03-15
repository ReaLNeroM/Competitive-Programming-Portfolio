#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct tv {
    ll p, r, m, d;

    bool operator<(tv const &x) const {
        return d < x.d;
    }
};

const ll maxn = 30005;
tv t[maxn];
ll n, money, days;
map<ll, pair<ll, pair<ll, ll>>> m;

ll evaluate(pair<ll, ll> a, ll x){
    return a.second + a.first * x;
}

ll query(ll x){
    return evaluate(m.lower_bound(x)->second.second, x);
}

void add(ll x1, ll y1, ll xx){
    ll b = y1 - xx * x1;
    pair<ll, ll> line = {xx, b};

    //find the area where this is best
    ll l = 1, r = days;
    ll biggest = -1;
    ll smallest = days + 1;
    while(l + 100 < r){
        ll mid = (l + r) / 2;
        if(query(mid) - query(mid - 1) < xx){
            if(query(mid) < evaluate(line, mid)){
                biggest = mid;
                l = mid + 1;
            } else {
                l = mid + 1;
            }
        } else if(query(mid) - query(mid - 1) == xx){
            if(query(mid) < evaluate(line, mid)){
                biggest = mid;
                l = mid + 1;
            } else {
            	l = 1, r = 0;
            }
        } else {
            if(query(mid) < evaluate(line, mid)){
                biggest = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    for(ll i = r; i >= l; i--){
        if(query(i) < evaluate(line, i)){
            biggest = i;
            break;
        }
    }

    l = 1, r = days;
    while(l + 100 < r){
        ll mid = (l + r) / 2;
        if(query(mid) - query(mid - 1) < xx){
            if(query(mid) < evaluate(line, mid)){
                smallest = mid;
                r = mid - 1;
            } else {
            	l = mid + 1;
            }
        } else if(query(mid) - query(mid - 1) == xx){
            if(query(mid) < evaluate(line, mid)){
                smallest = mid;
                r = mid - 1;
            } else {
            	l = 1, r = 0;
            }
        } else {
            if(query(mid) < evaluate(line, mid)){
                smallest = mid;
                r = mid - 1;
            } else {
                r = mid - 1;
            }
        }
    }

    for(ll i = l; i <= r; i++){
        if(query(i) < evaluate(line, i)){
            smallest = i;
            break;
        }
    }

    if(biggest == -1){
        return;
    }

    auto ite = m.lower_bound(smallest);
    while(ite != m.end() and ite->first <= biggest){
        int lower = ite->second.first;
        int upper = ite->first;

        if(smallest <= lower and upper <= biggest){
            auto site = ite;
            ite++;
            m.erase(site);
        } else if(smallest <= lower and biggest < upper){
            ite->second.first = biggest + 1;
            ite++;
        } else if(lower < smallest and upper <= biggest){
            auto site = ite;
            ite++;
            m[smallest - 1] = site->second;
            m.erase(site);
        }
    }
    m[biggest] = {smallest, line};
}

int main() {
    std::ios::sync_with_stdio(false);

    ll cases;
    std::cin >> cases;

    for(ll test = 0; test < cases; test++){
        std::cin >> n >> money >> days;

        for(ll i = 0; i < n; i++){
            cin >> t[i].p >> t[i].r >> t[i].m >> t[i].d;
        }

        sort(t, t + n);

        m.clear();
        m[days] = {1, {0, money}};

        ll best = money;
        for(ll i = 0; i < n; i++){
            ll start = query(t[i].d);

            if(start >= t[i].p){
                add(t[i].d + 1, start - t[i].p + t[i].r, t[i].m);
                best = max(best, start - t[i].p + t[i].r + (days - t[i].d) * t[i].m);
            }
        }

        std::cout << best << std::endl;
    }
    return 0;
}
