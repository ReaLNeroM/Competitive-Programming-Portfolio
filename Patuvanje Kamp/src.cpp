#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;
const ll INF = 1e16;
const ll INFPATH = 500000001;

ll v, e;
ll val[maxn];
std::vector<std::pair<ll, ll>> adj[maxn];
ll dist[maxn];
ll x_used[maxn];
bool used[maxn];

std::pair<ll, ll> attempt(ll posa, ll posb, ll x){
	std::fill(dist, dist + v, INF);
	std::fill(used, used + v, 0);
	std::fill(x_used, x_used + v, 0);

	std::priority_queue<std::pair<ll, ll>> pq;
	dist[posa] = 0;
	pq.push({-dist[posa], posa});

	while(!pq.empty()){
		ll frcost = -pq.top().first, fr = pq.top().second;
		pq.pop();

		if(used[fr]){
			continue;
		}
		used[fr] = true;

		for(auto next : adj[fr]){
			ll nextind = next.first;
			ll nextcost = frcost;
			ll next_x_used = x_used[fr];

			if(next.second == -1){
				nextcost += x;
				next_x_used++;
			} else {
				nextcost += next.second;
			}

			if(dist[nextind] > nextcost or (dist[nextind] == nextcost and x_used[nextind] > next_x_used)){
				dist[nextind] = nextcost;
				x_used[nextind] = next_x_used;
				pq.push({-nextcost, nextind});
			}
		}
	}

	return {dist[posb], x_used[posb]};
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e;

	for(ll i = 0; i < e; i++){
		ll f, s;
		std::string cost;
		std::cin >> f >> s >> cost;
		f--, s--;

		if(cost == "x"){
			adj[f].push_back({s, -1});
		} else {
			std::stringstream ostr;
			ostr << cost;

			ll dist;
			ostr >> dist;

			adj[f].push_back({s, dist});
		}
	}

	ll q;
	std::cin >> q;

	for(ll i = 0; i < q; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		ll res = 0, ressum = 0;

		auto initial = attempt(f, s, 1);
		ll last = 1;
		ll big_l = 1, big_r = INFPATH;

		if(initial.first == INF){
			std::cout << 0 << ' ' << 0 << '\n';
			continue;
		}

		while(last < INFPATH){
			initial = attempt(f, s, last);
			ll l = big_l, r = big_r;
			ll best = l - 1;

			while(l <= r){
				ll mid = (l + r) / 2;

				if(attempt(f, s, mid).second == initial.second){
					l = mid + 1;
					best = mid;
				} else {
					r = mid - 1;
				}
			}

			if(initial.second != 0 and best == INFPATH){
				res = -1;
				ressum = -1;
				break;
			}

			if(best != INFPATH){
				if(last <= best){
					res += best - last + 1;

					ressum += initial.first * (best - last + 1LL);
					ressum += (best - last) * (best - last + 1) / 2LL * initial.second;
				}
			} else {
				res += 1;
				ressum += attempt(f, s, best).first;
				break;
			}

			big_l = best + 1;
			last = best + 1;
		}

		if(res == -1){
			std::cout << "inf\n";
		} else {
			std::cout << res << ' ' << ressum << '\n';	
		}
	}
}
