#include <iostream>
#include <vector>

int srequired, sworkers, cost;
std::vector<std::vector<int> > dp;

int get(int required, int workers){
	if(required <= 0){
		return 0;
	} else if(required <= workers){
		return 1;
	}

	if(dp[required][workers] == 10000){
		for(int i = 0; i <= workers + srequired - required; i += cost){
			dp[required][workers] = std::min(dp[required][workers],
												get(required - workers + i, workers + i / cost) + 1);
		}
	}

	return dp[required][workers];
}
int main() {
	std::cin >> srequired >> sworkers >> cost;

	dp.resize(srequired + 1);

	for(int i = 0; i <= srequired; i++){
		dp[i].resize(srequired + 1, 10000);
	}

	std::cout << get(srequired, sworkers);
	return 0;
}
