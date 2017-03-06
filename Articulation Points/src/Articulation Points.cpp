#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100;
int n, e;
vector<int> adj[maxn];
int dfs_num[maxn];
int dfs_low[maxn];
int state[maxn];
int par[maxn];
int curr = 0;
int start = 0;
int root = 0;
bool art_point[maxn];

void dfs(int pos){
	state[pos] = 1;
	dfs_num[pos] = curr;
	dfs_low[pos] = curr;
	curr++;

	int foundb = 0;
	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(adj[pos][i] != par[pos]){
			if(state[nnext] == 0){
				if(par[pos] == -1){
					root++;
				}
				par[nnext] = pos;
				dfs(nnext);
				if(dfs_low[nnext] >= dfs_num[pos]){
					art_point[pos] = true;
				}
				if(dfs_low[nnext] > dfs_num[pos] and !foundb){
					cout << pos << ' ' << nnext << endl;
					foundb = true;
				}
			}

			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		}
	}

	state[pos] = 2;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	for(int i = 0; i < n; i++){
		if(state[i] == 0){
			start = i;
			root = 0;
			par[i] = -1;
			dfs(i);
			if(root >= 2){
				art_point[i] = true;
			} else {
				art_point[i] = false;
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(art_point[i]){
			cout << i << endl;
		}
	}
}
