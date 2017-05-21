#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 505;
ll val[maxn];
ll dp[maxn][maxn];
ll n;

ll dfs(ll i, ll j){
	if(dp[i][j] == -1){
		ll &ans = dp[i][j];
		ans = n;
		if(i > j){
			ans = 0;
		} else if(i == j){
			ans = 1;
		} else {
			ans = 1 + dfs(i + 1, j);
			for(int k = i + 2; k <= j; k++){
				if(val[i] == val[k]){
					ans = std::min(ans, dfs(i + 1, k - 1) + dfs(k + 1, j));
				}
			}
			if(val[i] == val[i + 1]){
				ans = std::min(ans, 1 + dfs(i + 2, j));
			}
		}
	}

	return dp[i][j];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}

	std::cout << dfs(0, n - 1);
}