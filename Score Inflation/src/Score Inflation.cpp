/*
ID: vlade.m1
PROG: inflate
LANG: C++
 */
#include <fstream>
#include <vector>

std::ifstream fin("inflate.in");
std::ofstream fout("inflate.out");

int main() {
	int minutes, n;
	fin >> minutes >> n;

	int score[n], time[n];
	for(int i = 0; i < n; i++){
		fin >> score[i] >> time[i];
	}

	std::vector<int> dp[2];

	dp[0].resize(minutes + 1, 0), dp[1].resize(minutes + 1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= minutes; j++){
			if(j == 0){
				dp[1][j] = 0;
			} else if(time[i] > j){
				dp[1][j] = dp[0][j];
			} else {
				dp[1][j] = std::max(dp[0][j], dp[1][j - time[i]] + score[i]);
			}
		}

		dp[0] = dp[1];
	}

	fout << dp[1][minutes] << std::endl;
	return 0;
}
