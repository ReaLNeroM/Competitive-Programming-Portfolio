#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6;
int v, e;
vector<pair<int, int>> adj[maxn];
bool used[maxn];
int col[maxn];
int colv[maxn][2];

bool verify(){
	for(int i = 0; i < v; i++){
		int seen[] = {false, false};
		for(int j = 0; j < adj[i].size(); j++){
			if(col[adj[i][j].second] != -1){
				seen[col[adj[i][j].second]] = true;
			}
		}
		if(adj[i].size() >= 2 and (!seen[0] or !seen[1])){
			return false;
		}
	}

	return true;
}

bool dfs(int pos, int need){
	for(int j = 0; j < adj[pos].size(); j++){
		int next = adj[pos][j].first;

		if(col[adj[pos][j].second] == -1 and !colv[pos][need]){
			colv[pos][need]++;
			colv[next][need]++;
			col[adj[pos][j].second] = need;

			if(!colv[next][!need]){
				bool result = dfs(next, !need);

				if(!result){
					colv[pos][need]--;
					colv[next][need]--;
					col[adj[pos][j].second] = -1;
				}
			}
		}
	}

	if(adj[pos].size() >= 2 and !colv[pos][need]){
		return false;
	}
	return true;
}

int main(){

	ios::sync_with_stdio(false);

	cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;

		adj[f].push_back({s, i});
		adj[s].push_back({f, i});
		col[i] = -1;
	}

	for(int i = 0; i < v; i++){
		if(!colv[i][0]){
			if(!dfs(i, 0)){
				cout << 0 << endl;
				return 0;
			}
		}
		if(!colv[i][1]){
			if(!dfs(i, 1)){
				cout << 0 << endl;
				return 0;
			}
		}
	}
	
	if(!verify()){
		cout << "0" << endl;
	} else {
		for(int i = 0; i < e; i++){
			cout << (char) ('1' + max(0, col[i]));
		}
	}
}
