//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("feast.in");
	std::ofstream fout("feast.out");
#endif

typedef long long ll;

int main() {
	int goal, a, b;
	fin >> goal >> a >> b;

	int dp[goal + 1][2];

	dp[0][0] = true;
	for(int i = 0; i <= goal - 1; i++){
		if(dp[i][0]){
			dp[i / 2][1] = true;
			if(i + a <= goal){
				dp[i + a][0] = true;
			}
			if(i + b <= goal){
				dp[i + b][0] = true;
			}
		}
	}

	for(int i = 0; i <= goal - 1; i++){
		if(dp[i][1]){
			if(i + a <= goal){
				dp[i + a][1] = true;
			}
			if(i + b <= goal){
				dp[i + b][1] = true;
			}
		}
	}

	for(int i = goal; i >= 0; i--){
		if(dp[i][0] or dp[i][1]){
			fout << i << std::endl;
			break;
		}
	}
	return 0;
}
