#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
const int maxid = 1e6 + 1e2;
const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};

int val[maxn][maxn];
int id[maxn][maxn];
int par[maxid];
int dfs_num[maxid];
int dfs_low[maxid];
int size[maxid];
std::vector<int> adj[maxid];

int edges;
int curr_edges = 1;
int y, x;
int curr = 1;
int res = 0;

void dfs(int pos){
	if(pos >= edges){
		dfs_num[pos] = curr;
		dfs_low[pos] = curr;
		curr++;
	} else {
		dfs_num[pos] = curr_edges;
		dfs_low[pos] = curr_edges;
		curr_edges++;
	}
	size[pos] = 1;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];
		if(next != par[pos]){
			if(dfs_num[next] == 0){
				par[next] = pos;
				dfs(next);
			}

			dfs_low[pos] = std::min(dfs_low[pos], dfs_low[next]);
			if(dfs_low[next] >= edges){
				size[pos] += size[next];
			}
		}
	}

	if(pos != 1){
		res = std::max(res, size[pos]);
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	
	std::cin >> y >> x;
	
	int black = 0;
	
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> val[i][j];
			black += val[i][j] == 1;
		} 
	}
	
	edges = 2;
	for(int i = 0; i < y; i++){
		if(val[i][0] == 0){
			id[i][0] = edges;
			edges++;
		}
		if(val[i][x - 1] == 0){
			id[i][x - 1] = edges;
			edges++;
		}
	}
	for(int j = 1; j < x - 1; j++){
		if(val[0][j] == 0){
			id[0][j] = edges;
			edges++;
		}
		if(val[y - 1][j] == 0){
			id[y - 1][j] = edges;
			edges++;
		}
	}

	for(int i = 2; i < edges; i++){
		adj[1].push_back(i);
	}

	int curr_id = edges;
	for(int i = 1; i < y - 1; i++){
		for(int j = 1; j < x - 1; j++){
			if(val[i][j] == 0){
				id[i][j] = curr_id;
				curr_id++;
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(val[i][j] == 0){
				for(int k = 0; k < 4; k++){
					int ni = i + ay[k];
					int nj = j + ax[k];

					if(0 <= ni and ni < y and 0 <= nj and nj < x and val[ni][nj] == 0 and (id[i][j] >= edges or id[ni][nj] >= edges)){
						adj[id[i][j]].push_back(id[ni][nj]);
					}
				}
			}
		}
	}

	curr = edges;
	
	dfs(1);

	std::cout << res + black;
}