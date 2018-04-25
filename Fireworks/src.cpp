#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 3e5 + 1e2;
const ll INF = 1e15;
std::vector<ll> adj[maxn];
ll res = 0;
ll dp[maxn][3];
ll par[maxn];
ll l[maxn];
ll order[maxn];
ll v[maxn];
ll curr = 0;

ll calculate(ll a, ll b[]){
	if(b[1] <= a and a <= b[2]){
		return b[0];
	} else if(a < b[1]){
		return std::abs(b[1] - a) + b[0];
	} else if(b[2] < a){
		return std::abs(b[2] - a) + b[0];
	}
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
			v[size] = dp[adj[pos][i]][1] + l[adj[pos][i]];
			size++;
			v[size] = dp[adj[pos][i]][2] + l[adj[pos][i]];
			size++;
		}

		if(adj[pos].size() == 0){
			continue;
		}
		
		dp[pos][0] = INF;

		for(ll i = 0; i < size; i++){
			ll attempt = 0;
			for(ll k = 0; k < adj[pos].size(); k++){
				attempt += calculate(v[i] - l[adj[pos][k]], dp[adj[pos][k]]);
			}
			
			if(dp[pos][0] > attempt){
				dp[pos][0] = attempt;
				dp[pos][1] = dp[pos][2] = v[i];
			} else if(dp[pos][0] == attempt){
				dp[pos][0] = attempt;
				dp[pos][1] = std::min(dp[pos][1], v[i]);
				dp[pos][2] = std::max(dp[pos][2], v[i]);
			}
		}

		ll vy[3];
		vy[0] = INF;

		for(ll y = 0; y <= 10000; y++){
			ll attempt = 0;
			for(ll k = 0; k < adj[pos].size(); k++){
				attempt += calculate(y - l[adj[pos][k]], dp[adj[pos][k]]);
			}

			if(vy[0] > attempt){
				vy[0] = attempt;
				vy[1] = vy[2] = y;
			} else if(vy[0] == attempt){
				vy[0] = attempt;
				vy[1] = std::min(vy[1], y);
				vy[2] = std::max(vy[2], y);
			}
		}

		ll awteawte = 2;
	}

	std::cout << dp[0][0] << std::endl;
}
