#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int dp[maxn][4];
std::string s[2];
int n;

int dfs(int pos, int bitset){
	if(dp[pos][bitset] == -1){
		int& ans = dp[pos][bitset];
		ans = 0;

		if(pos != n){
			ans = dfs(pos + 1, 3);

			if(pos + 1 < n and bitset == 3 and s[0][pos] == '0' and s[1][pos] == '0'){
				if(s[0][pos + 1] == '0'){
					ans = std::max(ans, dfs(pos + 1, 2) + 1);
				} else if(s[1][pos + 1] == '0'){
					ans = std::max(ans, dfs(pos + 1, 1) + 1);
				}
			} 
			if(pos + 2 <= n and (((bitset & 1) and s[0][pos] == '0') or ((bitset & 2) and s[1][pos] == '0')) and s[0][pos + 1] == '0' and s[1][pos + 1] == '0'){
				ans = std::max(ans, dfs(pos + 2, 3) + 1);
			}
		}
	}

	return dp[pos][bitset];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> s[0] >> s[1];
	n = s[0].size();
	memset(dp, -1, sizeof(dp));

	std::cout << dfs(0, 3);
}
