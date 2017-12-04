#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 4e3 + 1e2;
static int dp[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	std::string a, b;
	std::cin >> a >> b;
	
	while(a.size() < maxn){
		a += '0';
	}

	std::fill(&dp[0][0], &dp[0][0] + maxn * maxn, 1e9);
	for(int i = 0; i < maxn - 1; i++){
		for(int j = 0; j <= b.size(); j++){
			dp[i][j] = j;
		}
	}

	for(int j = 0; j < b.size(); j++){
		for(int i = 0; i < maxn - 1; i++){
			dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j] + (a[i] != b[j]));	//change
		}
	}

	int res = 1e9;
	for(int i = 0; i < maxn - 1; i++){
		for(int j = 0; j <= b.size(); j++){
			res = std::min(res, dp[i][j] + ((int) b.size() - j));
		}
	}

	std::cout << res << '\n';
}