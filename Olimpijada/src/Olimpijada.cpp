#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e5;

int val[maxn];

ll v, dist;
ll e[maxn][2];
ll d[maxn];
vector<pair<ll, ll> > adj[maxn];
ll swipe = 1;
ll sum[maxn];
ll used[maxn];
ll disabled[maxn];
ll res = 0;
ll mid;
ll r_l, r_r;
ll size;
pair<ll, ll> seg[4 * maxn];
pair<ll, ll> worst = {0, maxn};

pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b){
	if(a.second > b.second){
		swap(a, b);
	}
	if(a.second - a.first == b.second - b.first){
		if(a.second - a.first < 0){
			return a;
		} else {
			return b;
		}
	} else if(a.second - a.first > b.second - b.first){
		return b;
	} else {
		return a;
	}
}

pair<ll, ll> query(ll pos = 0, ll cl = 0, ll cr = size - 1, ll ql = -1, ll qr = -1){
	if(ql <= cl and cr <= qr){
		return seg[pos];
	} else if(cr < ql or qr < cl){
		return worst;
	}

	int mid = (cl + cr) / 2;

	return combine(query(2 * pos    , cl     , mid, ql, qr), 
				   query(2 * pos + 1, mid + 1, cr , ql, qr));
}

void upd(ll pos = 0, ll cl = 0, ll cr = size - 1, pair<ll, ll> q = worst){
	while(cl < cr){
		int mid = (cl + cr) / 2;

		seg[pos] = combine(seg[pos], q);
		if(q.second <= mid){
			pos = 2 * pos;
			cr = mid;
		} else {
			pos = 2 * pos + 1;
			cl = mid + 1;
		}
	}
	seg[pos] = combine(seg[pos], q);
}

ll dfs(ll pos, ll swipe){
	if(used[pos] == swipe){
		return 0;
	}
	used[pos] = swipe;

	sum[pos] = 1;

	for(ll i = 0; i < adj[pos].size(); i++){
		ll nnext = adj[pos][i].first;

		sum[pos] += dfs(nnext, swipe);
	}

	return sum[pos];
}

void dfs2(int pos, int par, bool update, int below_med, int dist_nodes){
	if(update){
		upd(0, 0, size - 1, {below_med, dist_nodes});
	} else {
		pair<ll, ll> q = query(0, 0, size - 1, r_l - dist_nodes, r_r - dist_nodes);
		if((q.first + below_med) * 2 >= dist_nodes + q.second and r_l <= dist_nodes + q.second and dist_nodes + q.second <= r_r){
			res = max(res, mid);
			return;
		} else if(below_med * 2 >= dist_nodes and r_l <= dist_nodes and dist_nodes <= r_r){
			res = max(res, mid);
			return;
		}
	}

	for(int i = 0; i < adj[pos].size() and res < mid; i++){
		int nnext = adj[pos][i].first;

		if(nnext != par){
			dfs2(nnext, pos, update, below_med + (adj[pos][i].second >= mid), dist_nodes + 1);
		}
	}
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> v >> r_l >> r_r;

	for(int i = 0; i < v - 1; i++){
		e[i][0] = i / 2;
		e[i][1] = i + 1;
		d[i] = 1;
	}

	for(int swipe = 1; swipe < 20; swipe++){
		for(ll i = 0; i < v; i++){
			adj[i].clear();
		}

		for(ll i = 0; i < v - 1; i++){
			if(!disabled[e[i][0]] and !disabled[e[i][1]]){
				adj[e[i][0]].push_back({e[i][1], d[i]});
				adj[e[i][1]].push_back({e[i][0], d[i]});
			}
		}

		for(ll i = 0; i < v; i++){
			if(used[i] != swipe and !disabled[i]){
				size = dfs(i, swipe);
				bool good = true;
				ll prev = -1;
				ll centroid = i;
				do {
					good = false;
					for(ll j = 0; j < adj[centroid].size(); j++){
						if(adj[centroid][j].first != prev and sum[adj[centroid][j].first] > size / 2){
							prev = centroid;
							centroid = adj[centroid][j].first;
							good = true;
							break;
						}
					}
				} while(good);

				ll l = res, r = 1e9;

				while(l <= r){
					mid = (l + r) / 2;

					for(int j = 0; j < 4 * size; j++){
						seg[j] = worst;
					}

					for(ll j = 0; j < adj[centroid].size(); j++){
						dfs2(adj[centroid][j].first, centroid, false, (adj[centroid][j].second >= mid), 1);
						dfs2(adj[centroid][j].first, centroid, true, (adj[centroid][j].second >= mid), 1);
					}

					if(res >= mid){
						l = mid + 1;
					} else {
						r = mid - 1;
					}
				}

				disabled[centroid] = true;
			}
		}	 
		cout << swipe << endl;
	}

	cout << res;
}

