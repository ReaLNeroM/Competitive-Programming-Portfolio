#include <iostream>

int x, y;
int mat[1000][1000];
int dp[1000][1000];

int main() {
	std::cin >> x >> y;

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			std::cin >> mat[i][j];
		}
	}

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(i == 0 and j == 0){
				dp[i][j] = mat[i][j];
			} else {
				dp[i][j] = 0;
				if(i > 0){
					dp[i][j] = dp[i - 1][j] + mat[i][j];
				}
				if(j > 0){
					dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + mat[i][j]);
				}
			}
		}
	}

	std::cout << dp[x - 1][y - 1];
	return 0;
}
