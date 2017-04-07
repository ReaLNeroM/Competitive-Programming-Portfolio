#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll f[maxn], s[maxn], d[maxn];
vector<pair<ll, ll> > adj[maxn];
bool used[maxn];
ll dist[maxn];

int main(){
	ll t;
	cin >> t;

	for(ll x = 0; x < t; x++){
		ll n, clique, old_dist, e, start;
		cin >> n >> clique >> old_dist >> e >> start;
		fill(used, used + maxn, false);
		fill(dist, dist + maxn, 1e18);
		fill(adj, adj + maxn, vector<pair<ll, ll>>(0));

		for(ll i = 0; i < e; i++){
			cin >> f[i] >> s[i] >> d[i];
			f[i]--, s[i]--;
			adj[f[i]].push_back({s[i], d[i]});
			adj[s[i]].push_back({f[i], d[i]});
		}

		priority_queue<pair<ll, ll>> pq;
		start--;
		dist[start] = 0;
		pq.push({-dist[start], start});

		bool used_clique = false;

		while(!pq.empty()){
			ll frdist = -pq.top().first, fr = pq.top().second;
			pq.pop();

			if(used[fr]){
				continue;
			}
			used[fr] = true;

			if(fr < clique and !used_clique){
				for(ll i = 0; i < clique; i++){
					ll nnext = i;
					if(dist[fr] + old_dist < dist[nnext]){
						dist[nnext] = dist[fr] + old_dist;
						pq.push({-dist[nnext], nnext});
					}
				}
				used_clique = true;
			}

			for(ll i = 0; i < adj[fr].size(); i++){
				ll nnext = adj[fr][i].first;
				ll nnextdist = frdist + adj[fr][i].second;

				if(nnextdist < dist[nnext]){
					dist[nnext] = nnextdist;
					pq.push({-dist[nnext], nnext});
				}
			}
		}

		for(ll i = 0; i < n; i++){
			cout << dist[i] << ' ';
		}
		cout << '\n';
	}
}