// https://codeforces.com/problemset/problem/1399/E2

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll n, S;
ll par[maxn];
ll weight[maxn];
ll cost[maxn];
ll leaves[maxn];
vector<vector<ll>> adj[maxn];

void dfs(ll pos){
	ll parent = par[pos];

	bool nonparentfound = false;
	for(auto edge_info : adj[pos]){
		if(edge_info[0] == parent){
			continue;
		}

		nonparentfound = true;

		par[edge_info[0]] = pos;
		weight[edge_info[0]] = edge_info[1];
		cost[edge_info[0]] = edge_info[2];
		dfs(edge_info[0]);
		leaves[pos] += leaves[edge_info[0]];
	}

	if(!nonparentfound){
		leaves[pos] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll testcases;
	cin >> testcases;

	while(testcases--){
		cin >> n >> S;

		for(ll i = 0; i < n; i++){
			adj[i].clear();
			leaves[i] = 0;
			par[i] = -1;
			weight[i] = 0;
		}

		for(ll i = 0; i < n - 1; i++){
			ll f, s, w, c;
			cin >> f >> s >> w >> c;
			f--, s--;

			adj[f].push_back({s, w, c});
			adj[s].push_back({f, w, c});
		}

		par[0] = -1;
		dfs(0);

		ll currsum = 0;
		for(ll i = 1; i < n; i++){
			currsum += weight[i] * leaves[i];
		}

		vector<ll> pq[3];
		for(ll i = 1; i < n; i++){
			ll currweight = weight[i];
			while(currweight > 0){
				pq[cost[i]].push_back({(currweight - currweight / 2) * leaves[i]});
				currweight /= 2;
			}
		}

		std::sort(pq[1].rbegin(), pq[1].rend());
		std::sort(pq[2].rbegin(), pq[2].rend());

		for(ll i = 1; i < (ll) pq[1].size(); i++){
			pq[1][i] += pq[1][i - 1];
		}
		for(ll i = 1; i < (ll) pq[2].size(); i++){
			pq[2][i] += pq[2][i - 1];
		}

		ll best = pq[1].size() + 2 * pq[2].size();
		for(ll i = -1; i < (ll) pq[1].size(); i++){
			ll asum = (i != -1) ? pq[1][i] : 0;
			ll l = -1, r = (ll) pq[2].size() - 1;

			while(l <= r){
				ll mid = (l + r) / 2;

				ll bsum = (mid != -1) ? pq[2][mid] : 0;

				if(currsum - asum - bsum <= S){
					best = std::min(best, (i + 1) + 2 * (mid + 1));
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
		}

		cout << best << '\n';
	}
}