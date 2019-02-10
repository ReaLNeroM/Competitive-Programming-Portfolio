#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int dp[maxn];
const int mod = 10007;

int main(){
	std::ios::sync_with_stdio(false);

	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i < maxn; i++){
		dp[i] = 2;

		for(int j = 0; j + 2 <= i; j++){
			dp[i] += dp[i - (j + 2)];
			dp[i] %= mod;

			if(j != 0 and i <= 2 * j + 1){
				dp[i] += 1;
				dp[i] %= mod;
			}
		}
	}

	int test_cases;
	std::cin >> test_cases;

	while(test_cases--){
		int test_id, n;
		std::cin >> test_id >> n;

		std::cout << test_id << ' ' << dp[n] << '\n';
	}
}