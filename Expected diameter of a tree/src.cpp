#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;

struct dsu {
	dsu* par = this;
	ll size = 1;
	ll ind;
	ll rank = 0;
	ll sum = 0.0;

	dsu* head(){
		if(par != par->par){
			par = par->head();
		}

		return par;
	}

	void merge(dsu* sec){
		dsu* fir = head();
		sec = sec->head();

		ll ss = fir->size + sec->size;

		fir->size = sec->size = ss;

		if(fir->rank > sec->rank){
			sec->par = fir;
		} else if(fir->rank < sec->rank){
			fir->par = sec;
		} else {
			sec->par = fir;
			fir->rank++;
		}
	}
};

ll v, e, q;
dsu components[maxn];
std::vector<ll> adj[maxn];
ll dp[maxn][2];
ll through[maxn][2];
ll seen[maxn];

void dfs(ll pos, ll par){
	dp[pos][0] = dp[pos][1] = 0;

	for(ll i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs(adj[pos][i], pos);

			ll get = dp[adj[pos][i]][0] + 1;

			if(dp[pos][0] < get){
				dp[pos][1] = dp[pos][0];
				through[pos][1] = through[pos][0];
				dp[pos][0] = get;
				through[pos][0] = adj[pos][i];
			} else if(dp[pos][1] < get){
				dp[pos][1] = get;
				through[pos][1] = adj[pos][i];
			}
		}
	}
}

void dfs2(ll pos, ll par){
	if(par != -1){
		if(through[par][0] == pos){
			if(dp[pos][0] < dp[par][1] + 1){
				dp[pos][1] = dp[pos][0];
				through[pos][1] = through[pos][0];
				dp[pos][0] = dp[par][1] + 1;
				through[pos][0] = par;
			} else if(dp[pos][1] < dp[par][1] + 1){
				dp[pos][1] = dp[par][1] + 1;
				through[pos][1] = par;
			}
		} else {
			if(dp[pos][0] < dp[par][0] + 1){
				dp[pos][1] = dp[pos][0];
				through[pos][1] = through[pos][0];
				dp[pos][0] = dp[par][0] + 1;
				through[pos][0] = par;
			} else if(dp[pos][1] < dp[par][0] + 1){
				dp[pos][1] = dp[par][0] + 1;
				through[pos][1] = par;
			}
		}
	}

	for(ll i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			dfs2(adj[pos][i], pos);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e >> q;

	for(ll i = 0; i < v; i++){
		components[i].ind = i;
		through[i][0] = through[i][1] = -1;
	}

	for(ll i = 0; i < e; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);

		components[f].merge(&components[s]);
	}

	for(ll i = 0; i < v; i++){
		if(!seen[components[i].head()->ind]){
			seen[components[i].head()->ind] = true;
			dfs(i, -1);
			dfs2(i, -1);
		}
	}

	for(ll i = 0; i < v; i++){
		components[i].head()->sum += dp[i][0];
		components[i].head()->most = 
	}

	for(ll i = 0; i < q; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		if(components[f].head() == components[s].head()){
			std::cout << -1 << '\n';
		} else {
			std::cout.precision(10);
			double res = (double) components[s].head()->sum;
			res /= (double) components[s].head()->size;
			double sec = (double) components[f].head()->sum;
			sec /= (double) components[f].head()->size;
			res = res + sec + 1.0;
			std::cout << std::fixed << res << '\n';
		}
	}
}