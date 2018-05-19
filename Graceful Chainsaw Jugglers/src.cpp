#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 505;
int val[maxn];
int dp[maxn][maxn][maxn];
bool used[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		int r, b;
		std::cin >> r >> b;
		if(r > b){
			std::swap(r, b);
		}

		memset(dp, 0, sizeof(dp));

		if(r <= 50 or b <= 50){
			if(r < b){
				std::swap(r, b);
			}

			for(int k = 1; k <= b + 1; k++){
				for(int i = 0; i <= r; i++){
					for(int j = 0; j <= b; j++){
						dp[i][j][k] = dp[i][j][k - 1];
						int sumr = 0;
						int sumb = k - 1;

						for(int l = 0; l <= r and sumr <= i and sumb <= j; l++, sumr += l, sumb += k - 1){
							dp[i][j][k] = std::max(dp[i][j][k], dp[i - sumr][j - sumb][k - 1] + l + (k != 1));
						}
					}
				}
			}
			std::cout << "Case #" << test << ": " << dp[r][b][b + 1] << '\n';
		} else {
			int most_b = std::sqrt(b) + 2;
			int most_r = std::sqrt(r) + 2;
			for(int i = 0; i <= r; i++){
				for(int j = 0; j <= b; j++){
					for(int k = 1; k <= most_b; k++){
						dp[i][j][k] = dp[i][j][k - 1];
						int sumr = 0;
						int sumb = k - 1;

						for(int l = 0; l <= most_r and sumr <= i and sumb <= j; l++, sumr += l, sumb += k - 1){
							dp[i][j][k] = std::max(dp[i][j][k], dp[i - sumr][j - sumb][k - 1] + l + (k != 1));
						}
					}
				}
			}
			std::cout << "Case #" << test << ": " << dp[r][b][most_b] << '\n';
		}
	}
}
