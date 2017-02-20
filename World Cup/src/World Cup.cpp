#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

struct tv {
	ll p, r, m, d;

	bool operator<(tv x){
		return d < x.d;
	}
};
const int maxn = 30005;
tv t[maxn];

int main() {
    std::ios::sync_with_stdio(false);

    freopen("504ET_1.IN", "r", stdin);
    ll cases;
    std::cin >> cases;

    for(ll test = 0; test < cases; test++){
        ll n, money, days;
        std::cin >> n >> money >> days;

        ll best[n];
        ll update[n];
        multiset<pair<ll, ll>> v[3];

        for(ll i = 0; i < n; i++){
            best[i] = update[i] = -1LL;
            cin >> t[i].p >> t[i].r >> t[i].m >> t[i].d;
        }
        if(test >= 2){
			sort(t, t + n);
			for(ll i = 0; i < n; i++){
				if(money >= t[i].p){
					best[i] = money - t[i].p + t[i].r;
					update[i] = t[i].d;
				}
				for(ll j = 0; j < 3; j++){
					for(auto ite = v[j].begin(); ite != v[j].end(); ite++){
						best[ite->second] += t[ite->second].m * (t[i].d - update[ite->second] - 1);

						update[ite->second] = t[i].d;

						if(best[ite->second] >= t[i].p){
							best[i] = max(best[i], best[ite->second] - t[i].p + t[i].r);
							update[i] = i;
						}
						best[ite->second] += t[ite->second].d;

						if(j == 0){
							pair<ll, ll> nnext = {best[ite->second], ite->second};
							v[0].insert(nnext);
						}
					}
				}

				if(best[i] != -1){
					v[0].insert({best[i], i});
					v[1].insert({t[i].m, i});
					v[2].insert({i, i});
				}

				for(ll j = 0; j < 3; j++){
					while(!v[j].empty() and v[j].size() > 150){
						v[j].erase(v[j].begin());
					}
				}
			}
			ll maxx = 0;
			for(ll i = 0; i < n; i++){
				if(best[i] != -1){
					maxx = std::max(maxx, best[i] + (days - t[n - 1].d) * t[i].m);
				}
			}

			std::cout << maxx << std::endl;
        }
    }
    return 0;
}
