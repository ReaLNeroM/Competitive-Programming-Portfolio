#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e6 + 1e2;

ll n;
static ll val[maxn];
std::vector<ll> adj[maxn];
static ll down[maxn];
static ll anything[maxn];
static ll upanything[maxn];
static ll up[maxn];
static ll sum[maxn];
static ll par[maxn];
ll order[maxn];
ll revorder[maxn];
ll res = 0;

void solve(){
	std::fill(down, down + maxn, 0);
	std::fill(anything, anything + maxn, 0);
	std::fill(upanything, upanything + maxn, 0);
	std::fill(up, up + maxn, 0);
	std::fill(sum, sum + maxn, 0);
	std::fill(par, par + maxn, -2);

	std::queue<ll> q;
	q.push(0);
	par[0] = -1;

	ll curr = 0;

	while(!q.empty()){
		ll fr = q.front();
		q.pop();
		order[curr] = fr;
		revorder[n - 1 - curr] = fr;
		curr++;

		for(ll next : adj[fr]){
			if(par[next] == -2){
				par[next] = fr;
				q.push(next);
			}
		}
	}

	for(ll i = 0; i < n; i++){
		ll pos = revorder[i];
		down[pos] += val[pos];

		for(ll next : adj[pos]){
			if(next != par[pos]){
				down[pos] += std::max(0LL, down[next]);
			}
		}
	}

	for(ll i = 0; i < n; i++){
		ll pos = revorder[i];
		anything[pos] = down[pos];

		for(ll next : adj[pos]){
			if(next != par[pos]){
				anything[pos] = std::max(anything[pos], anything[next]);
			}
		}
	}

	for(ll i = 0; i < n; i++){
		ll pos = order[i];
		ll most = down[pos];

		most += std::max(0LL, up[pos]);

		ll best = upanything[pos], second_best = 0;

		for(ll next : adj[pos]){
			if(next != par[pos]){
				up[next] = most - std::max(0LL, down[next]);
				upanything[next] = std::max(upanything[next], up[next]);

				if(anything[next] > best){
					second_best = best;
					best = anything[next];
				} else if(anything[next] > second_best){
					second_best = anything[next];
				}
			}
		}

		for(ll next : adj[pos]){
			if(next != par[pos]){
				if(best == anything[next]){
					upanything[next] = second_best;
				} else {
					upanything[next] = best;
				}
			}
		}
	}

	for(ll i = 0; i < n; i++){
		std::fill(sum, sum + adj[i].size(), 0);

		for(ll j = 0; j < adj[i].size(); j++){
			if(adj[i][j] == par[i]){
				sum[j] = up[i];
			} else {
				sum[j] = down[adj[i][j]];
			}
		}

		ll others_sum = val[i];
		for(ll j = 0; j < (int) adj[i].size(); j++){
			others_sum += std::max(0LL, sum[j]);
		}

		for(ll j = 0; j < (int) adj[i].size(); j++){
			others_sum -= std::max(0LL, sum[j]);
			if(adj[i][j] != par[i]){
				res = std::max(res, others_sum * anything[adj[i][j]]);
			} else {
				res = std::max(res, others_sum * upanything[i]);
			}
			others_sum += std::max(0LL, sum[j]);
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(ll i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(ll i = 0; i < n - 1; i++){
		ll f, s;
		std::cin >> f >> s;
		f--, s--;

		adj[f].push_back(s);
		adj[s].push_back(f);
	}

	solve();
	for(ll i = 0; i < n; i++){
		val[i] *= -1;
	}
	solve();

	std::cout << res << '\n';
}