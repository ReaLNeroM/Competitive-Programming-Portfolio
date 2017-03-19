#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2e5;
const int max_l = 1e9;

int big[maxn];
vector<int> adj[maxn];
vector<int> cost[maxn];
vector<int> seg[maxn];

int main() {
	int v, e, q;
	cin >> v >> e >> q;

	for(int i = 0; i < e; i++){
		int f, s, d;
		cin >> f >> s >> d;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
		cost[f].push_back(d);
		cost[s].push_back(f);
	}

	for(int i = 0; i < v; i++){
		cin >> type[i];
	}

	for(int i = 0; i < v; i++){
		seg[i].resize(4 * adj[i].size(), max_l);
	}

	for(int i = 0; i < v; i++){
		for(int j = 0; j < adj[i].size(); j++){
			upd(i, )
		}
	}

	build_big(v, 0, 0, v - 1);

	for(int i = 0; i < q; i++){
		int ind, change;
		cin >> ind >> change;
		ind--;

		type[ind] = change;
	}

	cout << res;
}

