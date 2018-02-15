#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 1e2;
ll dp[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	for(ll j = 0; j < maxn; j++){
		dp[0][j] = 1;
	}

	for(ll i = 1; i < maxn; i++){
		for(ll j = 1; j <= i; j++){
			dp[i][j] = dp[i][j - 1] + dp[i - j][j];
		}
		for(ll j = i + 1; j < maxn; j++){
			dp[i][j] = dp[i][j - 1];
		}
		std::cout << i << ' ' << dp[i][i] << '\n';
	}

}