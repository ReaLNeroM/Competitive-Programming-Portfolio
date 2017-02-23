#include <iostream>

typedef long long ll;

int main() {
	int y, x;
	std::cin >> y >> x;

	int val[y][x], dp[y][x];

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> val[i][j];
			dp[i][j] = 0;
		}
	}

	for(int i = 0; i < x; i++){
		dp[0][i] = dp[0][0] + val[0][i];
	}
	if(y != 1){
		for(int i = 1; i < y - 1; i++){
			int biggest[2], biggestpos[2];
			biggest[0] = biggest[1] = 0;
			biggestpos[0] = biggestpos[1] = 0;
			for(int j = 0; j < x; j++){
				if(dp[i - 1][j] + val[i][j] > biggest[0]){
					biggest[1] = biggest[0];
					biggestpos[1] = biggestpos[0];

					biggest[0] = dp[i - 1][j] + val[i][j];
					biggestpos[0] = j;
				} else if(dp[i - 1][j] + val[i][j] > biggest[1]){
					biggest[1] = dp[i - 1][j] + val[i][j];
					biggestpos[1] = j;
				}
			}

			for(int j = 0; j < x; j++){
				if(biggestpos[0] == j){
					dp[i][j] = biggest[1] + val[i][j];
				} else {
					dp[i][j] = biggest[0] + val[i][j];
				}
			}
		}

		dp[y - 1][x - 1] = dp[y - 2][x - 1] + val[y - 1][x - 1];
		int i;
		if(y == 2){
			i = 1;
		} else {
			i = 0;
		}
		for(; i < x - 1; i++){
			dp[y - 1][x - 1] = std::max(dp[y - 1][x - 1], dp[y - 2][i] + val[y - 1][i] + val[y - 1][x - 1]);
		}
	}

	std::cout << dp[y - 1][x - 1];
	return 0;
}
