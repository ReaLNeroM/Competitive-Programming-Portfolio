#include <iostream>
#include <vector>

std::vector<int> t;
std::vector<std::vector<std::vector<int> > > dp;
int teams, sum = 0;

int gen(int pos, int left, int gathered){
	if(dp[pos][left][gathered] == -1){
		if(left == 0){
			dp[pos][left][gathered] = std::min(gathered, sum - gathered);
		} else if(pos == teams){
			dp[pos][left][gathered] = 1000000;
		} else {
			if(std::max(sum - gen(pos + 1, left, gathered), gen(pos + 1, left, gathered)) < std::max(sum - gen(pos + 1, left - 1, gathered + t[pos]), gen(pos + 1, left - 1, gathered + t[pos]))){
				dp[pos][left][gathered] = std::min(sum - gen(pos + 1, left, gathered), gen(pos + 1, left, gathered));
			} else {
				dp[pos][left][gathered] = std::min(sum - gen(pos + 1, left - 1, gathered + t[pos]), gen(pos + 1, left - 1, gathered + t[pos]));
			}
		}
	}

	return dp[pos][left][gathered];
}
int main() {
	std::cin >> teams;

	t.resize(teams);
	for(int i = 0; i < teams; i++){
		std::cin >> t[i];
		sum += t[i];
	}

	dp.resize(teams + 1);
	for(int i = 0; i <= teams; i++){
		dp[i].resize(teams / 2 + 1);
		for(int j = 0; j * 2 <= teams; j++){
			dp[i][j].resize(sum + 1, -1);
		}
	}

	std::cout << gen(0, teams / 2, 0) << " " << sum - gen(0, teams / 2, 0);
	return 0;
}
