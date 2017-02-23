#include <iostream>
#include <vector>

int main(){
	int clenovi, ciklusi;
	std::cin >> clenovi >> ciklusi;

	int tez[ciklusi + 1];

	tez[0] = 0;
	for(int i = 1; i <= ciklusi; i++){
		std::cin >> tez[i];
	}

	int dp[ciklusi + 1][clenovi + 1];

	dp[0][0] = 0;
	for(int i = 0; i <= clenovi; i++){
		for(int j = 0; j <= ciklusi; j++){
			if(i == 0){
				dp[i][j] = 1000000;
			} else if(j == 0){
				dp[i][j] = 0;
			} else {
				dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1] + tez[j]);
			}
		}
	}

	std::cout << dp[clenovi][ciklusi];

	return 0;
}
