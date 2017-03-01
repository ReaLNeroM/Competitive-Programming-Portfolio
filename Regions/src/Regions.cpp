#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2e5;
int n, r, q;
vector<int> adj[maxn];
int col[maxn];
int curr = 0;
vector<pair<int, int>> gr[maxn];
vector<int> sec[maxn];
vector<int> res[maxn];
int curr_region;

void dfs(int pos, int par = -1){
	gr[col[pos]].push_back({curr, 1});
	sec[col[pos]].push_back(curr);
	curr++;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];

		dfs(next, pos);
	}
	gr[col[pos]].push_back({curr, -1});
}

void calc(int pos, int par, int above){
	res[curr_region][col[pos]] += above;

	for(int i = 0; i < adj[pos].size(); i++){
		int next = adj[pos][i];

		calc(next, pos, above + (col[pos] == curr_region));
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> r >> q;

	for(int i = 0; i < n; i++){
		if(i != 0){
			int supervisor;
			cin >> supervisor;

			supervisor--;
			adj[supervisor].push_back(i);
		}

		cin >> col[i];
		col[i]--;
	}

	dfs(0);

	for(int i = 0; i < r; i++){
		if(sec[i].size() > sqrt(n)){
			curr_region = i;
			res[i].resize(r, 0);
			calc(0, -1, 0);
		}
	}

	for(int i = 0; i < q; i++){
		int r1, r2;
		cin >> r1 >> r2;
		r1--, r2--;
		int ans = 0;
		if(!res[r1].empty()){
			ans = res[r1][r2];
		} else {
			int f = 0;
			int s = 0;

			while(f < gr[r1].size()){
				while(s < sec[r2].size() and sec[r2][s] < gr[r1][f].first){
					s++;
				}

				if(gr[r1][f].second == 1){
					ans += sec[r2].size() - s;
				} else {
					ans -= sec[r2].size() - s;
				}

				f++;
			}

		}

		cout << ans << endl;
	}
}
