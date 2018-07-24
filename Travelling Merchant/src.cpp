#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e3 + 1e2;
ll buy[maxn][maxn];
ll sell[maxn][maxn];
ll dist[maxn][maxn];
ll arbitrage[maxn][maxn];
ll dp[maxn][maxn];
ll n, m, k;

bool good(ll goal){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = arbitrage[i][j] - goal * dist[i][j];
			if(i == j){
				dp[i][j] = -1e18;
			}
		}
	}

	for(ll middle = 0; middle < n; middle++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				dp[i][j] = std::max(dp[i][j], dp[i][middle] + dp[middle][j]);
			}
			if(dp[i][i] >= 0){
				return true;
			}
		}
	}

	return false;
}

int main(){
	std::cin >> n >> m >> k;

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < k; j++){
			std::cin >> buy[i][j] >> sell[i][j];
		}
	}

	std::fill(&dist[0][0], &dist[0][0] + maxn * maxn, 1e9);

	for(ll i = 0; i < n; i++){
		dist[i][i] = 0;
	}

	for(ll i = 0; i < m; i++){
		ll f, s, c;
		std::cin >> f >> s >> c;
		f--, s--;
		dist[f][s] = c;
	}

	for(ll middle = 0; middle < n; middle++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				dist[i][j] = std::min(dist[i][j], dist[i][middle] + dist[middle][j]);
			}
		}
	}

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			arbitrage[i][j] = 0;

			for(ll curr_item = 0; curr_item < k; curr_item++){
				if(buy[i][curr_item] != -1 and sell[j][curr_item] != -1){
					arbitrage[i][j] = std::max(arbitrage[i][j], -buy[i][curr_item] + sell[j][curr_item]);
				}
			}
		}
	}

	ll l = 1, r = 1e9;
	ll best = 0;

	while(l <= r){
		ll mid = (l + r) / 2;

		if(good(mid)){
			l = mid + 1;
			best = mid;
		} else {
			r = mid - 1;
		}
	}

	std::cout << best << '\n';
}
