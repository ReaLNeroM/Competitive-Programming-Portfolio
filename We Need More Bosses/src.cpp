#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 3e5 + 1e2;
int n, e;
vector<int> adj[maxn];

int par[maxn];
int dfs_num[maxn];
int dfs_low[maxn];
int state[maxn];

int bridge_above[maxn];
int max_bridge_trail[maxn];

int curr = 0;
int res = 0;

void bridge_dfs(int pos){
	state[pos] = 1;

	dfs_num[pos] = curr;
	dfs_low[pos] = curr;
	curr++;
	
	for(int nnext : adj[pos]){
		if(nnext != par[pos]){
			if(state[nnext] == 0){
				par[nnext] = pos;

				bridge_dfs(nnext);

				if(dfs_low[nnext] > dfs_num[pos]){
					bridge_above[nnext]++;
				}
			}

			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		}
	}

	state[pos] = 2;
}

int max_bridge_trail_dfs(int pos){
	state[pos] = 1;

	max_bridge_trail[pos] = bridge_above[pos];

	for(int nnext : adj[pos]){
		if(nnext != par[pos] and state[nnext] == 0){
			max_bridge_trail[pos] = std::max(max_bridge_trail[pos], bridge_above[pos] + max_bridge_trail_dfs(nnext));
		}
	}

	return max_bridge_trail[pos];
}

void res_dfs(int pos){
	state[pos] = 1;

	int best_child = -1;
	int second_best_child = -1;

	for(int nnext : adj[pos]){
		if(nnext != par[pos] and state[nnext] == 0){
			res_dfs(nnext);
			if(best_child < max_bridge_trail[nnext]){
				second_best_child = best_child;
				best_child = max_bridge_trail[nnext];
			} else if(second_best_child < max_bridge_trail[nnext]){
				second_best_child = max_bridge_trail[nnext];
			}
		}
	}

	res = std::max(res, std::max(best_child + second_best_child, std::max(best_child, second_best_child)));
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	par[0] = -1;
	bridge_dfs(0);

	std::fill(state, state + n, 0);
	max_bridge_trail_dfs(0);

	std::fill(state, state + n, 0);
	res_dfs(0);

	std::cout << res << '\n';
}