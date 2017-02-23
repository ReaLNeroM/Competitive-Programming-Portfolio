#include <fstream>
#include <vector>

std::ifstream fin("piggyback.in");
std::ofstream fout("piggyback.out");


int main() {
	int cowcost[3];
	int fields, paths;
	fin >> cowcost[0] >> cowcost[1] >> cowcost[2] >> fields >> paths;

	int cost[2][fields];

	std::vector<int> path[fields];

	for(int i = 0, first, second; i < paths; i++){
		fin >> first >> second;

		path[first - 1].push_back(second - 1);
		path[second - 1].push_back(first - 1);
	}

	int res = 0;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < fields; j++){
			cost[i][j] = 1;
		}
		cost[i][i] = 0;

		for(int j = i; j < fields - 1; j++){
			for(int k = 0; k < path[j].size(); k++){
				cost[i][path[j][k]] = cost[path[j][k]][i] = std::min(cost[i][path[j][k]], cost[i][j] + 1);
			}
		}

		res += cost[i][fields - 1];
	}

	for(int i = 2; i < fields; i++){
		res = std::min(res, )
	}
	fout << res << std::endl;
	return 0;
}
