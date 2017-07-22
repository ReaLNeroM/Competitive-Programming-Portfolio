#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e5 + 1e2;
const ll maxk = 15;
ll weight[maxn];
ll simplesum[maxn];
ll weightsum[maxn];
ll dp[maxn][maxk];

int main(){
	std::ios::sync_with_stdio(false);

	ll n, k;
	std::cin >> n >> k;

	for(ll i = 0; i < n; i++){
		std::cin >> weight[i];
	}

	for(ll i = 1; i < n; i++){
		weightsum[i] = weightsum[i - 1] + i * weight[i];
	}

	for(ll i = 0; i < n; i++){
		if(i == 0){
			simplesum[i] = weight[i];
		} else {
			simplesum[i] = simplesum[i - 1] + weight[i];
		}
	}

	for(ll i = 0; i < maxn; i++){
		dp[i][0] = 1e18;
	}

	for(ll j = 1; j <= k; j++){
		std::vector<std::vector<ll>> v;
		v.push_back({0, 0});

		ll curr_pos = 0;
		for(ll i = 0; i < n; i++){
			curr_pos = std::min(curr_pos, (ll) v.size() - 1);
			while(curr_pos + 1 < v.size() and v[curr_pos][0] + v[curr_pos][1] * simplesum[i] >= v[curr_pos + 1][0] + v[curr_pos + 1][1] * simplesum[i]){
				curr_pos++;
			}

			dp[i][j] = v[curr_pos][0] + v[curr_pos][1] * simplesum[i] + weightsum[i];
			v.push_back({dp[i][j - 1] - weightsum[i + 1] + (i + 1) * simplesum[i + 1], -(i + 1)});

			ll t = v.size() - 3;
			while(v.size() >= 3 and (v[t + 1][0] - v[t][0]) * (v[t][1] - v[t + 2][1]) >= (v[t + 2][0] - v[t][0]) * (v[t][1] - v[t + 1][1])){
				v[v.size() - 2] = v[v.size() - 1];
				v.pop_back();
				t = v.size() - 3;
			}
			// for(ll k = 1; k <= i; k++){
			// 	dp[i][j] = std::min(dp[i][j], dp[k - 1][j - 1] - weightsum[k] + k * simplesum[k] - k * simplesum[i] + weightsum[i]);
			// }
		}
	}

	// for(ll i = 0; i < n; i++){
	// 	for(ll j = 1; j <= k; j++){
	// 		std::cerr << dp[i][j] << ' ';
	// 	}
	// 	std::cerr << '\n';
	// }

	std::cout << dp[n - 1][k] << '\n';
}
