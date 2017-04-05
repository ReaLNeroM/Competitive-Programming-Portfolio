#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll maxn = 2e5 + 1e2;
vector<ll> adj[maxn], temp_adj[maxn];
ll val[maxn];
ll loc[maxn];
ll subl[maxn], subr[maxn];
ll sub[maxn];
ll curr_ite = 0;

ll dfs(ll ind, ll par){
	loc[ind] = curr_ite;
	subl[ind] = curr_ite;
	subr[ind] = curr_ite;
	sub[ind] = val[ind];
	curr_ite++;

	for(ll i = 0; i < temp_adj[ind].size(); i++){
		if(temp_adj[ind][i] != par){
			adj[ind].push_back(temp_adj[ind][i]);
			sub[ind] += dfs(temp_adj[ind][i], ind);
		}
	}

	subr[ind] = curr_ite - 1;

	return sub[ind];
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	for(ll i = 0; i < n; i++){
		cin >> val[i];
	}
	for(ll i = 1; i < n; i++){
		ll par;
		cin >> par;
		par--;
		temp_adj[i].push_back(par);
		temp_adj[par].push_back(i);
	}
	
	dfs(0, -1);
	
	ll q;
	cin >> q;

	ll root = 0;
	for(ll i = 0; i < q; i++){
		char t;
		ll ind;
		cin >> t >> ind;
		ind--;

		if(t == 'S'){
			if(loc[root] == loc[ind]){
				cout << sub[0] << '\n';
			} else if(subl[ind] <= loc[root] and loc[root] <= subr[ind]){
				ll l = 0, r = adj[ind].size() - 1;
				ll res = -1;

				while(l <= r){
					ll mid = (l + r) / 2;

					if(subl[adj[ind][mid]] <= loc[root] and loc[root] <= subr[adj[ind][mid]]){
						res = sub[0] - sub[adj[ind][mid]];
						break;
					} else if(loc[root] < subl[adj[ind][mid]]){
						r = mid - 1;
					} else {
						l = mid + 1;
					}
				}

				cout << res << '\n';
			} else {
				cout << sub[ind] << '\n';
			}
		} else {
			root = ind;
		}
	}
}
	