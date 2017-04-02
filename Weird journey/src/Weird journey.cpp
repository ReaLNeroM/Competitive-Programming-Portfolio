#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e6 + 1e2;
vector<ll> adj[maxn];
ll reachable[maxn];
ll needtoreach[maxn];

int main(){
	ios::sync_with_stdio(false);
	ll v, e;
	cin >> v >> e;

	fill(reachable, reachable + maxn, false);
	ll selfs = 0;

	queue<ll> q;

	for(ll i = 0; i < e; i++){
		ll f, s;
		cin >> f >> s;

		f--, s--;

		if(f == s){
			selfs++;
		} else {
			adj[f].push_back(s);
			adj[s].push_back(f);
		}

		needtoreach[f] = true;
		needtoreach[s] = true;

		if(q.empty()){
			q.push(f);
			reachable[f] = true;
		}
	}

	while(!q.empty()){
		ll fr = q.front();
		q.pop();

		for(ll i = 0; i < adj[fr].size(); i++){
			ll nnext = adj[fr][i];

			if(!reachable[nnext]){
				reachable[nnext] = true;
				q.push(nnext);
			}
		}
	}

	for(ll i = 0; i < v; i++){
		if(!reachable[i] and needtoreach[i]){
			cout << 0 << endl;
			return 0;
		}
	}

	ll res = 0;

	for(ll i = 0; i < v; i++){
		for(ll j = 0; j < adj[i].size(); j++){
			res += adj[i].size() - (j + 1);
			res += adj[adj[i][j]].size() - (j + 1);
		}
	}

	res += 2 * (e - selfs) * selfs;
	res += selfs * (selfs - 1);

	res /= 2;
	cout << res << endl;
}