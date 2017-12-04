#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];
int dp[maxn][2];
int n, a, b;

int dfs(int pos, int side){
	if(dp[pos][side] == -1){
		if(side == 0){
			dp[pos][side] = 0;
		} else {
			dp[pos][side] = 1000000000;
		}

		for(int i = pos; i < n - 1; i++){
			if(side == 0){
				dp[pos][side] = std::max(dp[pos][side], dfs(i + 1, !side));
			} else {
				dp[pos][side] = std::min(dp[pos][side], dfs(i + 1, !side));
			}
		}

		if(pos == 0){
			if(side == 0){
				dp[pos][side] = std::max(dp[pos][side], std::abs(val[n - 1] - b));
			} else {
				dp[pos][side] = std::min(dp[pos][side], std::abs(val[n - 1] - b));
			}
		} else {
			if(side == 0){
				dp[pos][side] = std::max(dp[pos][side], std::abs(val[n - 1] - val[pos - 1]));
			} else {
				dp[pos][side] = std::min(dp[pos][side], std::abs(val[n - 1] - val[pos - 1]));
			}
		}
	}

	return dp[pos][side];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> a >> b;
	
	memset(dp, -1, sizeof(dp));

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::cout << dfs(0, 0) << '\n';
}