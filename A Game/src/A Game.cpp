/*
ID: vlade.m1
PROG: game1
LANG: C++
 */

#include <fstream>

std::ifstream fin("game1.in");
std::ofstream fout("game1.out");

int val[100];
int dp[100][100];

int gen(int i, int j){
	if(i > j){
		return 0;
	}

	if(dp[i][j] == -1){
		dp[i][j] = std::max(std::min(gen(i + 2, j), gen(i + 1, j - 1)) + val[i],
								std::min(gen(i + 1, j - 1), gen(i, j - 2)) + val[j]);
	}

	return dp[i][j];
}
int main() {
	int n;
	fin >> n;

	for(int i = 0; i < n; i++){
		fin >> val[i];
		for(int j = 0; j < n; j++){
			dp[i][j] = -1;
		}
	}

	fout << gen(0, n - 1) << " " << std::min(gen(1, n - 1), gen(0, n - 2)) << std::endl;
	return 0;
}
