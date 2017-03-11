#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e6;
vector<int> adj[maxn];
int used[maxn];
int dfs_num[maxn];
int dfs_low[maxn];
int curr_ite = 0;
int par[maxn];
vector<pair<int, int>> res;

void dfs(int pos){
	used[pos] = 1;
	dfs_num[pos] = curr_ite;
	dfs_low[pos] = curr_ite;
	curr_ite++;

	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i];

		if(nnext != par[pos]){
			if(used[nnext] == 0){
				par[nnext] = pos;
				dfs(nnext);
				if(dfs_low[nnext] > dfs_num[pos]){
					res.push_back({min(pos, nnext), max(pos, nnext)});
				}
			}
			dfs_low[pos] = min(dfs_low[pos], dfs_low[nnext]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int curr_test = 0;
	int n;
	while(cin >> n){
		curr_test++;
		fill(used, used + n, false);
		fill(adj, adj + n, vector<int>(0));
		res.clear();
		curr_ite = 0;

		for(int i = 0; i < n; i++){
			int ind;
			string s;
			cin >> ind >> s;

			s.erase(s.begin());
			s.erase(--s.end());
			stringstream str;
			str << s;
			int edges;
			str >> edges; 
			for(int i = 0; i < edges; i++){
				int link;
				cin >> link;
				adj[ind].push_back(link);
			}
		}

		for(int i = 0; i < n; i++){
			if(used[i] == 0){
				par[i] = -1;
				dfs(i);
			}
		}

		cout << res.size() << " critical links\n";
		sort(res.begin(), res.end());
		for(int i = 0; i < res.size(); i++){
			cout << res[i].first << " - " << res[i].second << endl;
		}
		cout << endl;
	}
}

