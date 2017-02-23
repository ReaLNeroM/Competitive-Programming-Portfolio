/*
 ID: vlade.m1
 PROG: stamps
 LANG: C++
 */

#include <fstream>
#include <vector>

std::ifstream fin("stamps.in");
std::ofstream fout("stamps.out");

int main() {
	int stamps, coins;
	fin >> stamps >> coins;

	int vals[coins], biggest = 0;
	for(int i = 0; i < coins; i++){
		fin >> vals[i];
		biggest = std::max(biggest, vals[i]);
	}

	int dp[biggest * stamps + 1];

	dp[0] = 0;

	for(int i = 1; i <= biggest * stamps + 1; i++){
		dp[i] = 5000;
		for(int j = 0; j < coins; j++){
			if(vals[j] <= i){
				dp[i] = std::min(dp[i], dp[i - vals[j]] + 1);
			}
		}
		if(dp[i] > stamps){
			fout << i - 1 << std::endl;
			break;
		}

	}
	return 0;
}
