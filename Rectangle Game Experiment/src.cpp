#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 100;
static int dp[maxn][maxn];

int main(){
	int n = maxn;
	for(int i = 1; i < n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = false;
			for(int k = 1; k < i; k++){
				if(i - k <= k and !dp[k][j]){
					dp[i][j] = true;
				}
			}
			for(int k = 1; k < j; k++){
				if(j - k <= k and !dp[i][k]){
					dp[i][j] = true;
				}
			}

			std::cout << dp[i][j];
		}
		std::cout << std::endl;
	}
}