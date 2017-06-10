#include <bits/stdc++.h>

const int maxn = 2005;
int n;
int dp[maxn][maxn];
std::string s;

int main(){
	std::ios::sync_with_stdio(false);

	std::string ss;
	std::cin >> ss;
	n = ss.size();
	s = ss;

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = -1;
		}
	}

	std::string gen = "";

	int open = 0;
	for(int i = 0; i < n; i++){
		if(dfs(i, open + 1))
	}
}