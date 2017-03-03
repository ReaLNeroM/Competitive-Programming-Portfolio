#include <iostream>

int cost[21][3], n;

int dfs(int curr, int last = -1, int st = -1){
	if(curr >= n){
		return cost[curr][last];
	}

	int min = 20000;
	for(int i = 0; i < 3; i++){
		if(curr < 0){
			st = i;
		} else if (i == last or (curr == n - 1 and st == i)) {
			continue;
		}

		min = std::min(dfs(curr + 1, i, st), min);
	}

	if(curr > 0){
		min += cost[curr][last];
	}

	return min;
}

int main(){
	std::cin >> n;

	for(int i = 0; i < n; i++){
		std::cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}
	cost[n][0] = cost[0][0], cost[n][1] = cost[0][1], cost[n][2] = cost[0][2];

	std::cout << dfs(-1);
}
