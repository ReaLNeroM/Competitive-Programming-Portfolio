#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 500;
const double eps = 0.000000001;
int dp[maxn][maxn];
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test = 1; test <= t; test++){
		int n, l;
		std::cin >> n >> l;

		memset(dp, 0, sizeof(dp));
		std::fill(val, val + maxn, 0);

		double piece = 100.0 / n;
		int left = n;

		for(int i = 0; i < l; i++){
			std::cin >> val[i];

			left -= val[i];
		}

		for(int i = n; i >= 0; i--){
			for(int j = 0; j <= left; j++){
				dp[i][j] = std::round((double) val[i] * piece + eps) + dp[i + 1][j];
//				std::cout << i << ' ' << j << ' ' << dp[i][j] << ' ' << dp[i + 1][j] << '\n';

				if(j != 0){
					for(int k = 0; k <= j; k++){
						dp[i][j] = std::max(dp[i][j], (int) std::round((double) ((val[i] + k) * piece) + eps) + dp[i + 1][j - k]);
					}
				}
			}
		}

		std::cout << "Case #" << test << ": " << std::round(dp[0][left] + eps) << '\n';
	}
}
