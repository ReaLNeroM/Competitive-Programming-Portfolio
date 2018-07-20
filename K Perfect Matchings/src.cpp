#include <bits/stdc++.h>

typedef long long ll;

const ll MAXN = 1e2 + 1e2;
const ll mod = ((ll) 1e15) + 37LL;
ll n, e, k;
std::vector<ll> adj[MAXN];
ll adjmat[MAXN][MAXN];
std::vector<ll> disabled[MAXN];
std::set<ll> found_hashes;
std::set<ll> found_steps;
bool used[MAXN];
ll partner[MAXN];

ll find(ll pos){
	if(used[pos]){
		return false;
	}
	used[pos] = true;

	for(ll next : adj[pos]){
		if(adjmat[pos][next] == 1 and (partner[next] == -1 or find(partner[next]))){
			partner[next] = pos;
			return true;
		}
	}

	return false;
}

std::vector<std::pair<ll, ll>> matching(){
	std::fill(partner, partner + n, -1);

	for(ll i = 0; i < n; i++){
		std::fill(used, used + n, false);
		
		if(!find(i)){
			return {};
		}
	}

	std::vector<std::pair<ll, ll>> v;
	for(ll i = 0; i < n; i++){
		v.push_back({partner[i], i});
	}

	return v;
}

bool seen(std::vector<std::pair<ll, ll>>& x){
	ll hash = 23LL;

	for(ll i = 0; i < x.size(); i++){
		hash *= 107LL;
		hash += x[i].first + 3LL;
		hash %= mod;

		hash *= 107LL;
		hash += x[i].second + 3LL;
		hash %= mod;
	}

	found_hashes.insert(hash);
}

bool seen_step(){
	ll hash = 23LL;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(adjmat[i][j] == -1){
				hash *= 109LL;
				hash += i + 3LL;
				hash %= mod;
				hash *= 109LL;
				hash += i + 3LL;
				hash %= mod;
			}
		}
	}

	if(found_steps.find(hash) != found_steps.end()){
		return true;
	}

	found_steps.insert(hash);
	return false;
}

void dfs(){
	seen_step();

	std::vector<std::pair<ll, ll>> x = matching();
	if(x.empty()){
		return;
	}
	seen(x);

	for(ll i = 0; i < x.size() and k >= found_hashes.size(); i++){
		ll f = x[i].first;
		ll s = x[i].second;

		if(adjmat[f][s]){
			adjmat[f][s] = -1;
			dfs();
			adjmat[f][s] = 1;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> e >> k;

	for(ll i = 0; i < e; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;
		s -= n;

		adjmat[f][s] = true;
		adj[f].push_back(s);
	}

	dfs();

	std::cout << ((k < found_hashes.size()) ? "Yes" : "No") << '\n';
}
