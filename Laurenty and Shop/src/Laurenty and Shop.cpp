#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

struct edge{
	int x, y;
	int cost;
};

struct state{
	int x, y;
	bool passedmiddle = false;
	int cost;

	bool operator()(state a, state b){
		return a.cost < b.cost;
	}
};
int main() {
	int houses;
	std::cin >> houses;

	std::vector<edge> adjList[2][houses];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < houses - 1; j++){
			edge e;
			e.x = i;

			std::cin >> e.cost;

			e.y = j + 1;
			adjList[i][j].push_back(e);

			e.y = j;
			adjList[i][j + 1].push_back(e);
		}
	}

	for(int j = 0; j < houses; j++){
		edge e;
		e.y = j;

		std::cin >> e.cost;

		e.x = 0;
		adjList[1][j].push_back(e);

		e.x = 1;
		adjList[0][j].push_back(e);
	}

	return 0;
}
