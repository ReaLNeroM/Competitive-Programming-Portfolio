#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5 + 1e2;
int sq = 320;
vector<int> adj[maxn];
int val[maxn];
int loc[maxn];
int subl[maxn], subr[maxn];
int need[maxn];
vector<int> care;
vector<pair<int, int> > que;

int dfs(int pos, int ind){
	loc[ind] = pos;
	subl[ind] = pos;
	subr[ind] = pos;

	int next_pos = pos + 1;
	for(int i = 0; i < adj[ind].size(); i++){
		next_pos = dfs(next_pos, adj[ind][i]);
	}
	subr[ind] = next_pos - 1;

	return next_pos;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int next_node = 1;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;

		if(t == 1){
			int par, value, ind = next_node;
			cin >> par >> value;
			par--;

			val[ind] = value;
			adj[par].push_back(ind);

			next_node++;
		} else {
			int ind;
			cin >> ind;
			ind--;

			que.push_back({i, ind});
			need[ind]++;
		}
	}

	dfs(0, 0);

	for(int i = 0; i < n; i++){

	}
}

