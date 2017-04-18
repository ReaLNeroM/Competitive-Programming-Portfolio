#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 3e5 + 1e2;
int seg[8 * maxn];
int val[maxn];
std::vector<int> adj[maxn];

void update(int position, int change, int ind = 0, int cl = 0, int cr = maxn - 1){
	if(cl <= position and position <= cr){
	} else {
		return;
	}

	if(cl == cr){
		if(position == cl){
			seg[ind] = change;
		}

		return;
	} else if(cr < cl){
		seg[ind] = 0;
		return;
	}

	int mid = (cl + cr) / 2;

	if(position <= mid){
		update(position, change, 2 * ind + 1, cl     , mid);
	} else {
		update(position, change, 2 * ind + 2, mid + 1, cr );
	}

	seg[ind] = std::max(seg[2 * ind + 1], seg[2 * ind + 2]);
}

int main(){
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;

	std::fill(seg, seg + 8 * maxn, -2e9);

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		update(i, val[i] + 2);
	}

	for(int i = 0; i < n - 1; i++){
		int f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	int res = 2e9;
	for(int i = 0; i < n; i++){
		update(i, val[i]);
		for(int j = 0; j < adj[i].size(); j++){
			update(adj[i][j], val[adj[i][j]] + 1);
		}

		res = std::min(res, seg[0]);

		update(i, val[i] + 2);
		for(int j = 0; j < adj[i].size(); j++){
			update(adj[i][j], val[adj[i][j]] + 2);
		}
	}

	std::cout << res;
}