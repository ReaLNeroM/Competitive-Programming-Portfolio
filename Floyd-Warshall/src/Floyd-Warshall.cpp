#include <iostream>

const int maxv = 50, maxe = 2500;
int vertices, edges;
int dist[maxv][maxv];

void Flarshall(){
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			dist[i][j] = 10000000;
		}
		dist[i][i] = 0;
	}

	for(int i = 0; i < edges; i++){
		int first, sec, cost;
		std::cin >> first >> sec >> cost;
		dist[first][sec] = cost;
	}

	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			for(int k = 0; k < vertices; k++){
				dist[j][k] = std::min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}
}

int main() {
	std::cin >> vertices >> edges;

	Flarshall();

	for(int i = 0; i < vertices; i++){
		for(int j = i + 1; j < vertices; j++){
			std::cout << i << " " << j << " " << dist[i][j] << std::endl;
		}
	}
	return 0;
}
