#include <bits/stdc++.h>

const int maxn = 1e4 + 1e2;
int val[maxn];
int dp[1100];

int main(){
	int spaces, n;
	std::cin >> spaces >> n;

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::sort(val, val + n);

	for(int i = 1; i <= n; i++){
		dp[i] = 1e9;
	}

	for(int i = 1; i <= spaces; i++){
		dp[0] = 0;
		for(int j = n; j >= 1; j--){
			dp[j] = std::min(dp[j], dp[j - 1] + ((i < val[j - 1]) ? (val[j - 1] - i) : (i - val[j - 1])));
		}
	}


	std::cout << dp[n] << std::endl;
}