#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2e5 + 1e2;

int v, e, p;
int dfs_num[maxn];
int dfs_low[maxn];
int level[maxn];
int dp[maxn][30];
std::vector<std::vector<int>> adj[maxn];
int color[maxn];
int bridge[maxn];
int in[maxn];
int out[maxn];
int res[maxn];
int order_given[maxn];
int curr = 0;
int path_f[maxn];
int path_s[maxn];

void dfs(int pos, int par, int par_edge){
	color[pos] = 1;
	dfs_num[pos] = curr;
	dfs_low[pos] = curr;
	curr++;
	
	if(par == -1){
		level[pos] = 0;		
	} else {
		level[pos] = level[par] + 1;
	}
	dp[pos][0] = par;

	for(int i = 0; i < adj[pos].size(); i++){
		if(color[adj[pos][i][0]] == 0){
			dfs(adj[pos][i][0], pos, adj[pos][i][1]);

			if(dfs_low[adj[pos][i][0]] > dfs_num[pos]){
				bridge[adj[pos][i][1]] = true;
			}

			dfs_low[pos] = std::min(dfs_low[pos], dfs_low[adj[pos][i][0]]);
		} else if(adj[pos][i][1] != par_edge){
			dfs_low[pos] = std::min(dfs_low[pos], dfs_low[adj[pos][i][0]]);
		}
	}

	color[pos] = 2;
}

std::vector<int> dfs3(int pos, int par, int par_edge){
	color[pos] = 3;

	int here_in = in[pos];
	int here_out = out[pos];

	for(int i = 0; i < adj[pos].size(); i++){
		if(color[adj[pos][i][0]] == 2){
			std::vector<int> get = dfs3(adj[pos][i][0], pos, adj[pos][i][1]);
			here_in += get[0];
			here_out += get[1];
		}
	}
	
	if(par_edge != -1 and bridge[par_edge]){
		if(here_in > 0){
			if((par < pos) == order_given[par_edge]){
				res[par_edge] = 1;
			} else {
				res[par_edge] = 2;
			}
		} else if(here_out > 0){
			if((par < pos) == order_given[par_edge]){
				res[par_edge] = 2;
			} else {
				res[par_edge] = 1;
			}
		}
	}

	color[pos] = 4;

	return {here_in, here_out};
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		if(f != s){
			if(f < s){
				order_given[i] = true;
			} else {
				order_given[i] = false;
			}

			adj[f].push_back({s, i});
			adj[s].push_back({f, i});
		}
	}

	for(int i = 0; i < v; i++){
		if(color[i] == 0){
			dfs(i, -1, -1);
		}
	}

	std::cin >> p;
	
	for(int i = 1; i < 30; i++){
		for(int j = 0; j < v; j++){
			if(dp[j][i - 1] != -1){
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
			}
		}	
	}
	
	for(int i = 0; i < p; i++){
		std::cin >> path_f[i] >> path_s[i];
		path_f[i]--, path_s[i]--;

		int x = path_f[i];
		int y = path_s[i];
		
		int lx = level[x];
		int ly = level[y];
		
		for(int j = 29; j >= 0; j--){
			if(lx - (1 << j) >= ly){
				lx -= (1 << j);
				x = dp[x][j];
			} else if(ly - (1 << j) >= lx){
				ly -= (1 << j);
				y = dp[y][j];
			}
		}
		
		for(int j = 29; j >= 0; j--){
			while(lx - (1 << j) >= 0){
				int nx = dp[x][j];
				int ny = dp[y][j];
				
				if(nx != ny){
					x = nx;
					y = ny;
					lx -= (1 << j);
					ly -= (1 << j);
				} else {
					break;
				}
			}
		}
		
		//lca
		if(x != y){
			x = dp[x][0];
			y = dp[y][0];
		}
		
		if(x == -1 or y == -1){
			continue;
		}
		
		
		in[x]--;
		out[x]--;
		
		in[path_s[i]]++;
		out[path_f[i]]++;
	}
		
	for(int i = 0; i < v; i++){
		if(color[i] == 2){
			dfs3(i, -1, -1);
		}
	}
	
	for(int i = 0; i < e; i++){
		if(res[i] == 0){
			std::cout << 'B';
		} else if(res[i] == 1){
			std::cout << 'R';
		} else {
			std::cout << 'L';
		}
	}

	std::cout << std::endl;
}
