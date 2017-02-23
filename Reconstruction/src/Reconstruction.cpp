#include <iostream>

typedef long long ll;

int main() {
	int vertices;
	std::cin >> vertices;

	int cost[vertices][vertices];
	for(int i = 0; i < vertices; i++){
		cost[i][i] = 0;
		for(int j = i + 1; j < vertices; j++){
			std::cin >> cost[i][j];

			copy.x = i, copy.y = j;

			e.push_back(copy);
		}
	}
	return 0;
}
