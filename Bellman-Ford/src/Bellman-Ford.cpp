#include <iostream>

struct edge{
	int first, second, dist;
};

int bellman(int end, int v[], int vertices, edge e[], int edges){
	for(int i = 0; i < vertices - 1; i++){
		for(int j = 0; j < edges; j++){
			v[e[j].second] = std::min(v[e[j].second], v[e[j].first] + e[j].dist);
		}
	}

	for(int i = 0; i < edges; i++){
		if(v[e[i].first] + e[i].dist < v[e[i].second]){
			return -123456789;
		}
	}

	return v[end];
}

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	int v[vertices];
	edge e[edges];

	for(int i = 0; i < vertices; i++){
		v[i] = 10000000;
	}

	for(int i = 0; i < edges; i++){
		std::cin >> e[i].first >> e[i].second >> e[i].dist;
	}

	int start, end;
	std::cin >> start >> end;
	v[start] = 0;

	int result = bellman(end, v, vertices, e, edges);

	if(result == -123456789){
		std::cout << "-∞";
	} else{
		std::cout << result;
	}

	return 0;
}
