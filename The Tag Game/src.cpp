#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2e5 + 100;
std::vector<ll> adj[maxn];
ll root_dist[maxn];
ll root_done[maxn];
ll x_dist[maxn];
ll x_done[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, x;
	std::cin >> n >> x;
	x--;

	for(ll i = 0; i < n - 1; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	std::fill(root_dist, root_dist + maxn, -1);
	std::fill(x_dist, x_dist + maxn, -1);

	std::queue<ll> q;

	root_dist[0] = 0;
	root_done[0] = true;
	q.push(0);

	while(!q.empty()){
		ll fr = q.front();
		ll frdist = root_dist[fr];
		q.pop();

		for(ll i = 0; i < adj[fr].size(); i++){
			ll next = adj[fr][i];
			ll nextdist = frdist + 1;

			if(!root_done[next]){
				root_done[next] = true;
				root_dist[next] = nextdist;
				q.push(next);
			}
		}
	}

	x_dist[x] = 0;
	x_done[x] = true;
	q.push(x);

	while(!q.empty()){
		ll fr = q.front();
		ll frdist = x_dist[fr];
		q.pop();

		for(ll i = 0; i < adj[fr].size(); i++){
			ll next = adj[fr][i];
			ll nextdist = frdist + 1;

			if(!x_done[next]){
				x_done[next] = true;
				x_dist[next] = nextdist;
				q.push(next);
			}
		}
	}

	ll res = 0;
	for(ll i = 0; i < n; i++){
		if(root_dist[i] >= root_dist[x] and root_dist[i] > x_dist[i]){
			res = std::max(res, 2 * root_dist[i]);
		}
	}

	std::cout << res;
}