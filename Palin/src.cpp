#include <bits/stdc++.h>

const int maxneed = 15728640;
const int maxn = 5005;
const int INF = 100000000;
int n;
int sum[maxn];
int dp[maxneed];
std::string s;

int dfs(int a, int b){
	int ind = sum[a] + (b - a + 1);

	if(dp[ind] == -1){
		if(a >= b){
			dp[ind] = 0;
		} else {
			dp[ind] = INF;
			dp[ind] = std::min(dp[ind], dfs(a + 1, b) + 1);
			dp[ind] = std::min(dp[ind], dfs(a, b - 1) + 1);

			if(s[a] == s[b]){
				dp[ind] = std::min(dp[ind], dfs(a + 1, b - 1));
			}
		}
	}

	return dp[ind];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::string ss;
	std::cin >> n >> ss;
	s = ss;

	sum[0] = 0;
	for(int i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + (n - (i - 1) + 1);
	}

	for(int i = 0; i < maxneed; i++){
		dp[i] = -1;
	}

	std::cout << dfs(0, n - 1) << std::endl;
}