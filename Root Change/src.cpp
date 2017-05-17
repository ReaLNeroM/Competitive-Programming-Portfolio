#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
int farthest[maxn][2];
int badcuts[maxn][2];

int edges[maxn][2];
std::vector<std::vector<int>> adj[maxn];
int subtree[maxn];
ll res = 0;

int dfs(int pos, int par){
	subtree[pos] = 1;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i][0];

		if(next != par){
			subtree[pos] += dfs(next, pos);
		}
	}

	return subtree[pos];
}

//leads to TLE
void calc_dp(int edge, int side){
	if(farthest[edge][side] != -1){
		return;
	}

	int pos = edges[edge][side];
	int par = edges[edge][!side];

	farthest[edge][side] = 0;
	badcuts[edge][side] = 0;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i][0];

		if(next != par){
			calc_dp(adj[pos][i][1], adj[pos][i][2]);

			if(farthest[edge][side] < farthest[adj[pos][i][1]][adj[pos][i][2]] + 1){
				farthest[edge][side] = farthest[adj[pos][i][1]][adj[pos][i][2]] + 1;
				badcuts[edge][side] = badcuts[adj[pos][i][1]][adj[pos][i][2]] + 1;
			} else if(farthest[edge][side] == farthest[adj[pos][i][1]][adj[pos][i][2]] + 1){
				badcuts[edge][side] = 0;
			}
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	int n;
	std::cin >> n;
	
	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back({s, i, 1});
		adj[s].push_back({f, i, 0});
		edges[i][0] = f;
		edges[i][1] = s;
	}

	dfs(0, -1);

	for(int i = 0; i < n; i++){
		farthest[i][0] = farthest[i][1] = -1;
	}

	for(int i = 0; i < n - 1; i++){
		calc_dp(i, 0);
		calc_dp(i, 1);
	}

	for(int i = 0; i < n; i++){
		int largestseen = 0;
		int res = n - 1;
		for(int j = 0; j < adj[i].size(); j++){
			if(largestseen < farthest[adj[i][j][1]][adj[i][j][2]] + 1){
				largestseen = std::max(largestseen, farthest[adj[i][j][1]][adj[i][j][2]] + 1);
				res = n - 1 - (badcuts[adj[i][j][1]][adj[i][j][2]] + 1);
			} else if(largestseen == farthest[adj[i][j][1]][adj[i][j][2]] + 1){
				res = n - 1;
			}
		}

		std::cout << res << '\n';
	}
}