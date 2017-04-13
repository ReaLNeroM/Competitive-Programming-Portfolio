#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 15;
int dp[maxn][maxn];

int main(){
	int n = 10;
	
	for(int i = 0; i < maxn; i++){
		for(int j = 0; j < maxn; j++){
			dp[i][j] = 1e9;
			if(i >= j){
				dp[i][j] = 0;
			}
		}
	}

	for(int size = 2; size <= n; size++){
		for(int i = 0; i + size - 1 < maxn; i++){
			for(int k = i; k <= i + size - 1; k++){
				dp[i][j] = std::min(dp[i][j], std::max(dp[i][k - 1], dp[k + 1][i + size - 1]) + k);
			}
		}
	}
}