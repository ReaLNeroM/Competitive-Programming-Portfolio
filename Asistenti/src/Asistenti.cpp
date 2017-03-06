#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 50005;
int n;
vector<pair<int, int>> adj[maxn];
bool par_arrow[maxn];
vector<int> arrow[maxn];
int dist[maxn];
int filled[maxn];
int res_for[maxn];
int sub[maxn];
int zavisen[maxn];
int res = -1;
int res_amount = 0;

void dfs1(int pos, int par){
	dist[pos] = -1e9;
	if(filled[pos]){
		dist[pos] = 0;
	}
	sub[pos] = filled[pos];

	for(int i = 0; i < adj[pos].size(); i++){
		int nnext = adj[pos][i].first;

		if(nnext != par){
			dfs1(nnext, pos);
			dist[pos] = max(dist[pos], dist[nnext] + adj[pos][i].second);
			sub[pos] += sub[nnext];
		}
	}
}

void dfs2(int pos, int par, int best_above){
	int best = best_above;
	int bestind = -1;
	int best2 = -1e9;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i].first != par){
			if(best < adj[pos][i].second + dist[adj[pos][i].first]){
				best2 = best;
				bestind = i;
				best = adj[pos][i].second + dist[adj[pos][i].first];
			} else if(best2 < adj[pos][i].second + dist[adj[pos][i].first]){
				best2 = adj[pos][i].second + dist[adj[pos][i].first];
			}
		}
	}

	if(best_above == best){
		par_arrow[pos] = true;
	}

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i].first != par){
			if(dist[adj[pos][i].first] + adj[pos][i].second == best){
				arrow[pos].push_back(i);
			}
			if(bestind != i){
				int best_next_above = max(best, best_above + adj[pos][i].second);
				if(filled[pos]){
					best_next_above = max(best_next_above, adj[pos][i].second);
				}
				dfs2(adj[pos][i].first, pos, best_next_above);
			} else {
				int best_next_above = max(best2 + adj[pos][i].second, best_above + adj[pos][i].second);
				if(filled[pos]){
					best_next_above = max(best_next_above, adj[pos][i].second);
				}
				dfs2(adj[pos][i].first, pos, best_next_above);
			}
		}
	}
}

int dfs3_sub(int pos, int par){
	if(arrow[pos].empty()){
		int found = sub[pos];
		return found;
	} else if(arrow[pos].size() == 1){
		return dfs3_sub(adj[pos][arrow[pos][0]].first, pos);
	} else {
		return 0;
	}
}

void dfs3(int pos, int par){
	int found = 0;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i].first != par){
			found += dfs3_sub(adj[pos][i].first, pos);
		}
	}

	res_for[pos] = found;

	for(int i = 0; i < adj[pos].size(); i++){
		if(adj[pos][i].first != par){
			dfs3(adj[pos][i].first, pos);
		}
	}
}

int dfs4(int pos, int par, int in){
	if(pos == 21){
		int xxxx = 5;
	}
	res_for[pos] += in;
	int other = 0;

	if(arrow[pos].empty()){
		other += sub[pos];
		for(int i = 0; i < adj[pos].size(); i++){
			if(adj[pos][i].first != par){
				dfs4(adj[pos][i].first, pos, 0);
			}
		}
	} else if(arrow[pos].size() == 1){
		for(int i = 0; i < adj[pos].size(); i++){
			if(adj[pos][i].first != par){
				if(arrow[pos][0] != i){
					other += dfs4(adj[pos][i].first, pos, 0);
				}
			}
		}
		if(par_arrow[pos]){
			other = dfs4(adj[pos][arrow[pos][0]].first, pos, 0);
		} else {
			other = dfs4(adj[pos][arrow[pos][0]].first, pos, in + other + filled[pos]);
		}
	} else {
		for(int i = 0; i < adj[pos].size(); i++){
			if(adj[pos][i].first != par){
				dfs4(adj[pos][i].first, pos, 0);
			}
		}
	}

	return other;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n - 1; i++){
		int f, s, d;
		cin >> f >> s >> d;

		adj[f].push_back({s, d});
		adj[s].push_back({f, d});
	}
	int fill;
	cin >> fill;
	for(int i = 0; i < fill; i++){
		int ind;
		cin >> ind;
		filled[ind] = true;
	}

	dfs1(0, -1);
	dfs2(0, -1, -1e9);
	dfs3(0, -1);
	dfs4(0, -1, 0);

	for(int i = 0; i < n; i++){
		if(!filled[i]){
			if(res < res_for[i]){
				res = res_for[i];
				res_amount = 1;
				if(res == 3){
					cout << i << endl;
				}
			} else if(res == res_for[i]){
				res_amount++;
				if(res == 3){
					cout << i << endl;
				}
			}
		}
	}
	cout << res << ' ' << res_amount << endl;
}
