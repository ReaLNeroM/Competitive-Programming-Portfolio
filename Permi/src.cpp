#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 2500;
ll dp[maxn][maxn];
ll res[maxn];
ll n, order;

ll dfs(ll a, ll b){
	if(dp[a][b] == -1){
		if(a == 0 and b == 0){
			dp[a][b] = 1;
		} else if(a == 0){
			dp[a][b] = dfs(a, b - 1);
		} else if(b == 0){
			dp[a][b] = 0;
		} else {
			dp[a][b] = dfs(a - 1, b);
			if(b > a){
				dp[a][b] += dfs(a, b - 1);
			}
			if(dp[a][b] >= 1e18){
				dp[a][b] = 1e18;
			}
		}
	}

	return dp[a][b];
}

int main(){
	std::ios::sync_with_stdio(false);

	ll type;
	for(ll i = 0; i < maxn; i++){
		for(ll j = 0; j < maxn; j++){
			dp[i][j] = -1;
		}
	}

	while(std::cin >> type){
		if(type == 1){
			std::cin >> n >> order;
			order--;

			ll a = 0, b = 0;

			for(ll i = 0; i < 2 * n; i++){
				if(a == n){
					res[n + b] = a + b;
					b++;
				} else {
					ll get = dfs(n - (a + 1), n - b);

					if(order < get){
						res[a] = a + b;
						a++;
					} else {
						order -= get;
						res[n + b] = a + b;
						b++;
					}
				}
			}

			for(ll i = 0; i < 2 * n; i++){
				std::cout << res[i] + 1 << ' ';
			}
			std::cout << '\n';
		} else {
			std::cin >> n;
			for(int i = 0; i < 2 * n; i++){
				std::cin >> res[i];
				res[i]--;
			}

			ll ans = 0;

			ll a = 0, b = 0;

			for(ll i = 0; i < 2 * n; i++){
				if(a == n){
					b++;
				} else {
					ll get = dfs(n - (a + 1), n - b);

					if(res[a] == a + b){
						a++;
					} else {
						ans += get;
						b++;
					}
				}
			}

			std::cout << ans + 1 << '\n';
		}
	}
}