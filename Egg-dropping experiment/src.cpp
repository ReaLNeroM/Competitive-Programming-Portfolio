#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 205;
int dp[maxn][maxn];

int main(){
	int n = 20;

	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = 1e9;
			if(i > j){
				dp[i][j] = 0;
			}
		}
	}

	for(int size = 1; size <= n; size++){
		for(int i = 0; i + size - 1 < n; i++){
			for(int k = i; k <= i + size - 1; k++){
				dp[i][i + size - 1] = std::min(dp[i][i + size - 1], std::max(dp[i][k - 1], dp[k + 1][i + size - 1]) + k + 1);
				if(i == 0 and i + size - 1 == 4){
					std::cout << dp[i][i + size - 1] << ' ' << dp[i][k - 1] << ' ' << dp[k + 1][i + size - 1] << std::endl;
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = i; j <= n; j++){
			std::cout << dp[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}