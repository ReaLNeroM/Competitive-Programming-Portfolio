#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e5 + 1e2;
int n;
int ceillog2[maxn];
vector<int> adj[maxn];
int res[maxn];
int heavy[maxn];
int distancee[maxn];
int leaf[maxn];

int dfs(int pos, int par){
	int dist = 0;
	int sec_dist = 0;
	int ind = -1;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i] != par){
			int ans = dfs(adj[pos][i], pos) + 1;
			if(dist <= ans){
				sec_dist = max(sec_dist, dist);
				dist = ans;
				ind = adj[pos][i];
			} else {
				sec_dist = max(sec_dist, ans);
			}
		}
	}

	res[pos] = sec_dist;
	heavy[pos] = false;
	leaf[pos] = res[pos];
	distancee[pos] = 0;

	if(ind != -1){
		if(res[pos] < dist){
			heavy[pos] = true;
			leaf[pos] = leaf[ind];
			distancee[pos] = distancee[ind] + 1;
			if(res[pos] >= leaf[ind] + ceillog2[distancee[pos]] + 1){
				heavy[pos] = false;
				leaf[pos] = res[pos];
				distancee[pos] = 0;
			} else {
				res[pos] = leaf[ind] + ceillog2[distancee[pos]] + 1;
			}
		}
	}

	return res[pos];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fill(ceillog2, ceillog2 + maxn, -1);
	ceillog2[1] = 0;
	for(int i = 1; i < maxn; i *= 2){
		for(int j = i + 1; j <= i * 2 and j < maxn; j++){
			ceillog2[j] = ceillog2[i] + 1;
		}
	}

	int t;
	cin >> t;

	for(int x = 0; x < t; x++){
		cin >> n;

		fill(res, res + maxn, -1);
		fill(heavy, heavy + maxn, false);
		fill(distancee, distancee + maxn, 0);
		fill(leaf, leaf + maxn, 0);
		fill(adj, adj + maxn, vector<int>(0));
		for(int i = 0; i < n - 1; i++){
			int f, s;
			cin >> f >> s;

			f--, s--;
			adj[f].push_back(s);
			adj[s].push_back(f);
		}

		cout << dfs(0, -1) << '\n';
	}
}
