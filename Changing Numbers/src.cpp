#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll mod = 1e9 + 7;
ll a[maxn], b[maxn];
std::vector<ll> adj[maxn];
bool used[maxn];
ll factorial[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll test_cases;
	std::cin >> test_cases;

	factorial[0] = 1;
	for(ll i = 1; i < maxn; i++){
		factorial[i] = (factorial[i - 1] * i) % mod;
	}

	while(test_cases--){
		ll n, k;
		std::cin >> n >> k;

		std::fill(adj, adj + n + 1, std::vector<ll>{});
		std::fill(used, used + n + 1, false);

		for(ll i = 0; i < n; i++){
			std::cin >> a[i];
		}
		for(ll i = 0; i < n; i++){
			std::cin >> b[i];

			adj[a[i]].push_back(b[i]);
			adj[b[i]].push_back(a[i]);
		}

		ll res = 0;
		ll final_ways = 1;

		std::queue<ll> q;

		for(ll i = 1; i <= n; i++){
			if(!used[i]){
				used[i] = true;
				q.push(i);

				ll found = 0;

				while(!q.empty()){
					ll fr = q.front();
					found++;

					q.pop();

					for(ll next : adj[fr]){
						if(!used[next]){
							used[next] = true;
							q.push(next);
						}
					}
				}

				final_ways *= factorial[found];
				final_ways %= mod;

				res += found - 1;
			}
		}

		final_ways *= factorial[res];
		final_ways %= mod;

		std::cout << res;
		if(k == 2){
			std::cout << ' ' << final_ways;
		}
		std::cout << '\n';
	}
}
