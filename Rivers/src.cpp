#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 105;
ll parent[maxn];
ll cut[maxn];
ll dist[maxn];
std::vector<std::pair<ll, ll>> adj[maxn];
int dp2[maxn][maxn][maxn];
int dp[maxn][maxn][maxn];

ll dfs(ll curr, ll left, ll last);

ll dfs2(ll curr, ll curr_adj, ll left, ll last){
	if(curr_adj >= adj[curr].size()){
		return 0;
	}
	ll ind = adj[curr][curr_adj].first;

	if(dp2[ind][left][last] == -1){
		ll ans = 2e9;

		for(ll i = 0; i <= left; i++){
			ans = std::min(ans, dfs(ind, i, last) + dfs2(curr, curr_adj + 1, left - i, last));
		}

		dp2[ind][left][last] = ans;
	}

	return dp2[ind][left][last];
}

ll dfs(ll curr, ll left, ll last){
	if(dp[curr][left][last] == -1){
		ll ans = 0;
		
		ans += (dist[curr] - dist[last]) * cut[curr];
		for(ll i = 0; i < adj[curr].size(); i++){
			ans += dfs(adj[curr][i].first, 0, last);
		}

		if(left > 0){
			ll other = 0;
			other += dfs2(curr, 0, left - 1, curr);

			ans = std::min(ans, other);
			
			other = (dist[curr] - dist[last]) * cut[curr];
			other += dfs2(curr, 0, left, last);

			ans = std::min(ans, other);			
		}
		dp[curr][left][last] = ans;
	}

	return dp[curr][left][last];
}

void initial_dfs(ll pos, ll par){
	parent[pos] = par;

	for(ll i = 0; i < adj[pos].size(); i++){
		ll next = adj[pos][i].first;

		dist[next] = dist[pos] + adj[pos][i].second;
		initial_dfs(next, pos);
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll n, k;
	std::cin >> n >> k;

	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			for(ll k = 0; k < maxn; k++){
				dp[i][j][k] = dp2[i][j][k] = -1;
			}
		}
	}

	n++;
	for(ll i = 0; i < n - 1; i++){
		ll trees, par, edge_length;
		std::cin >> trees >> par >> edge_length;

		cut[i + 1] = trees;
		adj[par].push_back({i + 1, edge_length});
	}

	dist[0] = 0;
	initial_dfs(0, -1);

	std::cout << dfs(0, k, 0);
}
