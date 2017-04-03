#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 1e5 + 1e2;
const ll maxb = 1e3 + 1e2;
vector<pair<ll, ll>> adj[maxn];
ll dist[maxn];
bool used[maxn];
ll b_start[maxn];
ll b_step[maxn];
vector<ll> b_place[maxb];

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	ll v, e, b, t;
	cin >> v >> e >> b >> t;

	for(ll i = 0; i < e; i++){
		ll f, s, d;
		cin >> f >> s >> d;
		f--, s--;

		adj[f].push_back({s, d});
		adj[s].push_back({f, d});
	}

	for(ll i = 0; i < b; i++){
		cin >> b_start[i];
		cin >> b_step[i];
		ll size;
		cin >> size;

		b_place[i].resize(size);

		for(ll j = 0; j < size; j++){
			ll ind;
			cin >> ind;
			ind--;

			b_place[i][j] = ind;
		}
	}

	ll l = 0, r = t;
	ll best = -1;
	while(l <= r){
		ll mid = (l + r) / 2;

		fill(dist, dist + maxn, t + 1);
		fill(used, used + maxn, false);

		priority_queue<pair<ll, ll>> pq;
		dist[0] = mid;
		pq.push({-dist[0], 0});

		while(!pq.empty()){
			ll frdist = -pq.top().first, fr = pq.top().second;
			pq.pop();

			if(used[fr]){
				continue;
			}
			used[fr] = true;

			for(ll i = 0; i < adj[fr].size(); i++){
				ll nnext = adj[fr][i].first;
				ll nnextdist = frdist + adj[fr][i].second;

				if(dist[nnext] > nnextdist){
					dist[nnext] = nnextdist;
					pq.push({-dist[nnext], nnext});
				}
			}

			for(ll i = 0; i < b; i++){
				for(ll j = 0; j < b_place[i].size(); j++){
					if(b_place[i][j] == fr){
						ll start = b_start[i] + j;
						while(frdist > start){
							start += b_step[i];
						}

						for(ll k = j + 1; k < b_place[i].size(); k++){
							if(dist[b_place[i][k]] > start + (k - j)){
								dist[b_place[i][k]] = start + (k - j);
								pq.push({-dist[b_place[i][k]], b_place[i][k]});
							}
						}
					}
				}
			}
		}

		if(dist[v - 1] <= t){
			best = max(best, mid);
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	if(best == -1){
		cout << "sleep at the UCf" << endl;
	} else {
		cout << best << endl;
	}
}
