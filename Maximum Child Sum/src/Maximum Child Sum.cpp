#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 2e5 + 1e2;
ll sq = 320;
vector<ll> adj[maxn];
ll val[maxn];
ll loc[maxn];
ll subl[maxn], subr[maxn];
ll sub[maxn];
ll seg[4 * maxn];
ll res[maxn];
ll constant_update_res[maxn];
ll constant_update[maxn];
ll v = 1;
vector<ll> list_of_constant_update;

vector<pair<pair<ll, ll>, ll>> queries;

void update(ll pos, ll val, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	while(cl < cr){
		seg[ind] += val;

		ll mid = (cl + cr) / 2;

		if(pos <= mid){
			ind = 2 * ind + 1;
			cr = mid;
		} else {
			ind = 2 * ind + 2;
			cl = mid + 1;
		}
	}

	seg[ind] += val;
}

ll query(ll ql, ll qr, ll ind = 0, ll cl = 0, ll cr = maxn - 1){
	if(ql <= cl and cr <= qr){
		return seg[ind];
	} else if(qr < cl or cr < ql){
		return 0;
	}

	ll mid = (cl + cr) / 2;

	return query(ql, qr, 2 * ind + 1, cl     , mid) +
		   query(ql, qr, 2 * ind + 2, mid + 1, cr );
}

ll dfs(ll pos, ll ind){
	loc[ind] = pos;
	subl[ind] = pos;
	subr[ind] = pos;

	ll next_pos = pos + 1;
	for(ll i = 0; i < adj[ind].size(); i++){
		next_pos = dfs(next_pos, adj[ind][i]);
	}
	subr[ind] = next_pos - 1;

	return next_pos;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	for(ll i = 0; i < n; i++){
		ll t;
		cin >> t;

		if(t == 1){
			ll par, value, ind = v;
			cin >> par >> value;
			par--;

			val[ind] = value;
			adj[par].push_back(ind);

			v++;
			queries.push_back({{par, value}, ind});
		} else {
			ll ind;
			cin >> ind;
			ind--;

			queries.push_back({{i, ind}, -1});
		}
	}

	dfs(0, 0);

	for(ll i = 0; i < v; i++){
		if(adj[i].size() >= sq){
			list_of_constant_update.push_back(i);
			constant_update[i] = true;
			constant_update_res[i] = 0;
		}
	}

	for(ll i = 0; i < n; i++){
		if(queries[i].second == -1){
			ll curr_node = queries[i].first.second;

			if(constant_update[curr_node]){
				cout << constant_update_res[curr_node] << '\n';
			} else {
				ll highest = 0;
				for(ll j = 0; j < adj[curr_node].size(); j++){
					ll curr_child = adj[curr_node][j];
					highest = max(highest, query(subl[curr_child], subr[curr_child]));
				}

				cout << highest << '\n';
			}
		} else {
			ll ind = queries[i].second;
			update(loc[ind], queries[i].first.second);
			for(ll j = 0; j < list_of_constant_update.size(); j++){
				ll current_update = list_of_constant_update[j];
				if(subl[current_update] <= loc[ind] and loc[ind] <= subr[current_update]){
					if(loc[current_update] != loc[ind]){
						ll cl = 0, cr = adj[current_update].size() - 1;
						while(cl <= cr){
							ll mid = (cl + cr) / 2;

							ll curr_child_node = adj[current_update][mid];
							if(subl[curr_child_node] <= loc[ind] and loc[ind] <= subr[curr_child_node]){
								sub[curr_child_node] += queries[i].first.second;
								constant_update_res[current_update] = max(constant_update_res[current_update], sub[curr_child_node]);
								break;
							} else if(loc[ind] < subl[curr_child_node]){
								cr = mid - 1;
							} else {
								cl = mid + 1;
							}
						}
					}
				}
			}
		}
	}
}

