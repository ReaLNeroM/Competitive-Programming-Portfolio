#include <fstream>
#include <vector>

struct route{
	int cost, cities;
	std::vector<int> dests;
};

int bellman(int start, int end, route t[], int planes){

	int cost[10000];
	for(int i = 0; i < 10000; i++){
		cost[i] = 100000000;
	}
	cost[start] = 0;

	for(int k = 0; k < 2; k++){
		for(int i = 0; i < planes; i++){
			int best = 100000000;

			for(int j = 0; j < t[i].cities - 1; j++){
				best = std::min(best, cost[t[i].dests[j]]);
				cost[t[i].dests[j + 1]] = std::min(cost[t[i].dests[j + 1]], best + t[i].cost);
			}
	 	}
	}

	if(cost[end] >= 100000000){
		return -1;
	}

	return cost[end];
}
int main() {
	std::ifstream fin;
	std::ofstream fout;
	fin.open("cowroute.in");
	fout.open("cowroute.out");
	int start, end, planes;
	fin >> start >> end >> planes;

	start--;
	end--;

	route t[planes];

	for(int i = 0; i < planes; i++){
		fin >> t[i].cost >> t[i].cities;
		t[i].dests.resize(t[i].cities);
		for(int j = 0; j < t[i].cities; j++){
			fin >> t[i].dests[j];
			t[i].dests[j]--;
		}
	}

	fout << bellman(start, end, t, planes) << std::endl;
	return 0;
}
