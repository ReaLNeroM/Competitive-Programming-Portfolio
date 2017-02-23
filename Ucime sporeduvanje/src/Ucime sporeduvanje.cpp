#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> adjlist[1000];
bool printed[1000];
std::vector<int> res;
int sum = 0;

void dfs(int pos){
	sum++;

	printed[pos] = true;
	res.push_back(pos);

	for(int i = 0; i < adjlist[pos].size(); i++){
		if(!printed[adjlist[pos][i]]){
			dfs(adjlist[pos][i]);
		}
	}
}
int main() {
	int numbers;
	std::cin >> numbers;


	for(int i = 0, paths; i < numbers; i++){
		std::cin >> paths;

		for(int j = 0, second; j < paths; j++){
			std::cin >> second;

			adjlist[i].push_back(second - 1);
		}

		std::sort(adjlist[i].begin(), adjlist[i].end());
		printed[i] = false;
	}

	dfs(0);

	if(sum != numbers){
		std::cout << "Problem";
	} else {
		for(int i = 0; i < res.size(); i++){
			std::cout << res[i] + 1 << " ";
		}
	}
	return 0;
}
