// https://codeforces.com/problemset/problem/1399/E1

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll maxn = 1e5 + 1e2;
ll n, S;
ll par[maxn];
ll weight[maxn];
ll leaves[maxn];
vector<pair<ll, ll>> adj[maxn];

void dfs(ll pos){
	ll parent = par[pos];

	bool nonparentfound = false;
	for(pair<ll, ll> pii : adj[pos]){
		if(pii.first == parent){
			continue;
		}

		nonparentfound = true;

		par[pii.first] = pos;
		weight[pii.first] = pii.second;
		dfs(pii.first);
		leaves[pos] += leaves[pii.first];
	}

	if(!nonparentfound){
		leaves[pos] = 1;
	}
}

int main(){
	ios::sync_with_stdio(false);

	ll testcases;
	cin >> testcases;

	while(testcases--){
		cin >> n >> S;

		for(ll i = 0; i < n; i++){
			adj[i].clear();
			leaves[i] = 0;
			par[i] = -1;
			weight[i] = 0;
		}

		for(ll i = 0; i < n - 1; i++){
			ll f, s, w;
			cin >> f >> s >> w;
			f--, s--;

			adj[f].push_back({s, w});
			adj[s].push_back({f, w});
		}

		par[0] = -1;
		dfs(0);

		ll currsum = 0;
		for(ll i = 1; i < n; i++){
			currsum += weight[i] * leaves[i];
		}

		priority_queue<pair<ll, ll>> pq;
		for(ll i = 1; i < n; i++){
			pq.push({(weight[i] - weight[i] / 2) * leaves[i], i});
		}

		ll operations = 0;
		while(currsum > S){
			pair<ll, ll> top = pq.top();
			pq.pop();

			ll index = top.second;
			currsum -= top.first;
			weight[index] /= 2;

			pq.push({(weight[index] - weight[index] / 2) * leaves[index], index});
			operations++;
		}

		cout << operations << '\n';
	}
}