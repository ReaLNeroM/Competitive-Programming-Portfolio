#include <iostream>

typedef long long ll;

int logo[3][2];
int dp[6][6][8];

int main() {
	for(int i = 0; i < 3; i++){
		std::cin >> logo[i][0] >> logo[i][1];
	}

	for(int k = 0; k < 8; k++){
		dp[0][0][k] = false;
	}
	dp[0][0][7] = true;
	for(int i = 1; i <= 5; i++){
		for(int j = 1; j <= 5; j++){
			for(int k = 0; k < 8; k++){
				dp[i][j][k] = false;

				for(int box = 0; box < 3; box++){
					if(((1 << box) & k) == 0){
						if(j - logo[box][0] >= 0 and i - logo[box][1] >= 0){
							dp[i][j][k] = dp[i - logo[box][1]][j - logo[box][0]][k | (1 << box)];
						}

						if(!dp[i][j][k] and j - logo[box][1] >= 0 and i - logo[box][0] >= 0){
							dp[i][j][k] = dp[i - logo[box][0]][j - logo[box][1]][k | (1 << box)];
						}
					}
				}
			}
		}
	}
	for(int i = 1; i <= 300; i++){
		if(dp[i][i][0]){
			std::cout << i << std::endl;
		}
	}

	return 0;
}
