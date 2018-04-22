#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 3e5 + 1e2;
const ll INF = 1e15;
std::vector<ll> adj[maxn];
ll res = 0;
ll dp[maxn][2][2];
ll par[maxn];
ll l[maxn];
ll order[maxn];
ll v[maxn];
ll curr = 0;

inline ll calculate(ll a, ll b[][2]){
	if(b[0][1] <= -a and -a <= b[1][1] and b[0][0] == b[1][0]){
		return b[0][0];
	}
	return std::min(std::abs(b[0][1] + a) + b[0][0], std::abs(b[1][1] + a) + b[1][0]);
}

void dfs(ll pos){
	order[curr] = pos;
	curr++;
	for(ll i = 0; i < adj[pos].size(); i++){
		dfs(adj[pos][i]);
	}
}

int main(){
	ll leaves, junctions;
	std::cin >> leaves >> junctions;

	ll n = leaves + junctions;

	for(ll i = 1; i < n; i++){
		std::cin >> par[i] >> l[i];
		par[i]--;
		adj[par[i]].push_back(i);
	}

	std::queue<ll> q;
	q.push(0);

	while(!q.empty()){
		ll fr = q.front();
		q.pop();

		order[curr] = fr;
		curr++;

		for(ll i = 0; i < adj[fr].size(); i++){
			q.push(adj[fr][i]);
		}
	}

	for(ll x = n - 1; x >= 0; x--){
		ll pos = order[x];

		ll size = 0;
		for(ll i = 0; i < adj[pos].size(); i++){
			v[size] = dp[adj[pos][i]][1][1] + l[adj[pos][i]];
			size++;
		}
		
		if(size == 0){
			continue;
		} else if(size == 1){
			dp[pos][0][0] = dp[pos][1][0] = 0;
			dp[pos][0][1] = dp[pos][1][1] = v[0];
			continue;
		}
		

		ll pivot[2];
		std::nth_element(v, v + size / 2 - 1, v + size);
		pivot[0] = v[size / 2 - 1];
		std::nth_element(v, v + size / 2, v + size);
		pivot[1] = v[size / 2];

		for(ll j = 0; j < 2; j++){
			dp[pos][j][0] = 0;
			for(ll i = 0; i < size; i++){
				dp[pos][j][1] = pivot[j];
				dp[pos][j][0] += calculate(l[adj[pos][i]] - dp[pos][j][1], dp[adj[pos][i]]);
			}
		}
	}

	res = std::min(dp[0][0][0], dp[0][1][0]);

	std::cout << res << std::endl;
}
