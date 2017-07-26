#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 16;
ll mat[maxn][maxn];
ll use[maxn][maxn];
ll backup[maxn][maxn];
ll cost[maxn][maxn];
ll par[maxn];
ll v, e;
ll res = 1e18;

void solve(){
	for(ll i = 0; i < v; i++){
		for(ll j = 0; j < v; j++){
			cost[i][j] = backup[i][j];
			if(use[i][j]){
				cost[i][j] = 1e15;
			}
		}
	}
	
	ll curr = 0;
	
	while(true){
		std::fill(par, par + v, -1);
		
		std::queue<ll> q;
		q.push(0);
		par[0] = -2;
		
		while(!q.empty()){
			ll fr = q.front();
			q.pop();
			
			for(ll i = 0; i < v; i++){
				ll next = mat[fr][i];
				
				if(par[next] == -1 and cost[fr][next] > 0){
					par[next] = fr;
					q.push(next);
				}
			}
		}
		
		if(par[v - 1] != -1){
			ll pos = v - 1;
			ll bottleneck = 1e18;
			
			while(pos != 0){
				bottleneck = std::min(bottleneck, cost[par[pos]][pos]);
				pos = par[pos];
			}
			
			pos = v - 1;
			
			while(pos != 0){
				cost[par[pos]][pos] -= bottleneck;
				pos = par[pos];
			}
			
			curr += bottleneck;
		} else {
			break;
		}
	}
	
	res = std::min(res, curr);
}

void dfs(ll pos, ll bit){
	if(pos == v - 1){
		solve();
		return;
	}
	
	for(ll i = 0; i < v; i++){
		if(!((1 << i) & bit) and mat[pos][i]){
			use[i][pos] = true;
			use[pos][i] = true;
			
			dfs(i, (1 << i) | bit);
			
			use[i][pos] = false;
			use[pos][i] = false;
		}	
	}	
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> v >> e;
	
	for(ll i = 0; i < e; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;
		
		std::cin >> cost[f][s];
		cost[s][f] = cost[f][s];
		
		mat[f][s] = mat[s][f] = true;
	}
	
	for(ll i = 0; i < v; i++){
		for(ll j = 0; j < v; j++){
			backup[i][j] = cost[i][j];
		}
	}
	
	dfs(0, 1);
	
	std::cout << res << '\n';
}