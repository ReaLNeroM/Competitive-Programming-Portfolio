#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 210;
ll n, k;
ll dp[maxn][maxn];

ll dfs(ll pos, ll open){
	if(dp[pos][open] == -1){
		if(pos == 2 * n){
			if(open == 0){
				dp[pos][open] = 1;
			} else {
				dp[pos][open] = 0;
			}
		} else {
			dp[pos][open] = dfs(pos + 1, open + 1);

			if(open > 0){
				dp[pos][open] += dfs(pos + 1, open - 1);
			}

			if(open > 0 and dfs(pos + 1, open - 1) == 2e18){
				dp[pos][open] = 2e18;
			}
			if(dfs(pos + 1, open + 1) == 2e18){
				dp[pos][open] = 2e18;
			}

			if(dp[pos][open] > 1e18){
				dp[pos][open] = 2e18;
			}
		}
	}

	return dp[pos][open];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> k;
	k--;

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = -1;
		}
	}

	for(int i = 0; i < 2 * n; i++){
		for(int j = 0; j <= i; j++){
			std::cout << dfs(i, j) << ' ';
		}
		std::cout << std::endl;
	}

	std::string s = "";

	if(k >= dfs(1, 1)){
		std::cout << -1 << std::endl;
		return 0;
	}

	int sum = 0;
	for(int i = 0; i < 2 * n; i++){
		if(k < dfs(i + 1, sum + 1)){

			sum++;
			s += '(';
		} else {
			k -= dfs(i + 1, sum + 1);
			sum--;
			s += ')';
		}
	} 

	std::cout << s << std::endl;
}