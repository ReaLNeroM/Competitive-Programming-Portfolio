#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e5 + 100;
int edges[maxn][2];
std::vector<std::vector<int>> adj[maxn];
int subtree[maxn];
int farthest_dist[maxn];
int farthest_amount[maxn];
int farthest_amountminus1[maxn];
int badcuts[maxn];
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

void dfs2(int pos, int par){
	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i][0] != par){
			dfs2(adj[pos][i][0], pos);
			int get = farthest_dist[adj[pos][i][0]] + 1;

			if(farthest_dist[pos] < get){
				if(get - farthest_dist[pos] == 1){
					farthest_amountminus1[pos] = 1;
				} else {
					farthest_amountminus1[pos] = 0;
				}
				farthest_dist[pos] = get;
				farthest_amount[pos] = 1;
				badcuts[pos] = badcuts[adj[pos][i][0]] + 1;
			} else if(farthest_dist[pos] == get){
				farthest_amount[pos]++;
				badcuts[pos] = 0;
			}
		}
	}
}

void dfs3(int pos, int par){
	if(par != -1){
		if(farthest_dist[par] == farthest_dist[pos] + 1){
			if(farthest_amount[par] >= 2){
				farthest_dist[pos] = farthest_dist[par] + 1;
				farthest_amount[pos] = 1;
				badcuts[pos] = badcuts
			}
		} else if(farthest_dist[par] + 1 > farthest_dist[pos]){
			farthest_dist[pos] = farthest_dist[par] + 1;
			farthest_amount[pos] = 1;
		} else if(farthest_amountminus1[par] and farthest_dist[pos] == farthest_dist[par] - 1){
			farthest_amount[pos]++;
			badcuts[pos] = 0;
		}
	}

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i][0] != par){
			dfs3(adj[pos][i][0], pos);
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
		farthest[i] = 0;
	}

	dfs2(0, -1);
	dfs3(0, -1);

	for(int i = 0; i < n; i++){
		int largestseen = 0;
		int res = n - 1;
		for(int j = 0; j < adj[i].size(); j++){
			if(largestseen < farthest[adj[i][j][0]] + 1){
				largestseen = std::max(largestseen, farthest[adj[i][j][0]] + 1);
				res = n - 1 - (badcuts[adj[i][j][0]] + 1);
			} else if(largestseen == farthest[adj[i][j][0]] + 1){
				res = n - 1;
			}
		}

		std::cout << res << '\n';
	}
}