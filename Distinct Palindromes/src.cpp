#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
const int mod = 1e9 + 7;
int dp[maxn][maxn];
int next[maxn][26];	
int prev[maxn][26];

int dfs(int a, int b){
	if(dp[a][b] == -1){
		dp[a][b] = 1;

		for(int i = 0; i < 26; i++){
			int next_i = next[a][i];
			int prev_i = prev[b][i];

			if(next_i <= b and a <= prev_i and next_i != -1 and prev_i != -1){
				dp[a][b] += dfs(next_i, prev_i);
			}
		}
	}

	return dp[a][b];
}

int main(){
	std::ios::sync_with_stdio(false);

	std::string s;
	std::cin >> s;

	int n = s.size();
	memset(dp, -1, sizeof(dp));

	for(int j = 0; j < 26; j++){
		int last = -1;
		for(int i = 0; i < n; i++){
			prev[i][j] = last;

			if(s[i] == (char) ('a' + j)){
				last = i;
			}
		}

		last = -1;
		for(int i = n - 1; i >= 0; i--){
			next[i][j] = last;

			if(s[i] == (char) ('a' + j)){
				last = i;
			}
		}
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			res += dfs(i, j);
			res %= mod;
		}
	}

	std::cout << res << '\n';
}