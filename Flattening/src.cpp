#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
int val[maxn];
int dp[maxn][maxn];

int main(){
	int test_cases;
	std::cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++){
		std::cout << "Case #" << test_case << ": ";

		int n, k;
		std::cin >> n >> k;

		for(int i = 0; i < n; i++){
			std::cin >> val[i];
		}

		for(int curr_n = n; curr_n >= 0; curr_n--){
			for(int curr_k = k; curr_k >= 0; curr_k--){
				if(curr_n == n){
					dp[curr_n][curr_k] = 0;
					continue;
				} else if(curr_k == k){
					dp[curr_n][curr_k] = n - curr_n;
					continue;
				}

				int& ans = dp[curr_n][curr_k];
				ans = n;

				for(int next_n = curr_n + 1; next_n <= n; next_n++){
					int changes = next_n - curr_n - 1;
					bool isDifferent;

					if(next_n == n){
						isDifferent = false;
					} else {
						isDifferent = (val[next_n] != val[curr_n]);
					}

					if(curr_k == k and isDifferent){
						continue;
					}

					// if(test_case == 2){
					// 	std::cout << curr_n << ' ' << curr_k << ' ' << next_n << ' ' << curr_k + isDifferent << ' ' << changes << ' ' << changes + dp[next_n][curr_k + isDifferent] << '\n';
					// }
					ans = std::min(ans, changes + dp[next_n][curr_k + isDifferent]);
				}
			}
		}

		std::cout << dp[0][0] << '\n';
	}
}
