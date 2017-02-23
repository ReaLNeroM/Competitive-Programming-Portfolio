#include <iostream>

struct edge{
	int first, second, dist;
};

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	int stet, ent;
	std::cin >> stet >> ent;
	stet--, ent--;

	edges *= 2;
	edge e[edges];

	int v[vertices];
	int used[vertices];

	for(int i = 0; i < vertices; i++){
		v[i] = 1000000;
	}
	for(int i = 0; i < vertices; i++){
		used[i] = 1000000;
	}

	v[stet] = 0;
	used[stet] = 0;

	for(int i = 0; i < edges; i += 2){
		std::cin >> e[i].first >> e[i].second >> e[i].dist;
		e[i].first--, e[i].second--;
		e[i + 1].first = e[i].second, e[i + 1].second = e[i].first, e[i + 1].dist = e[i].dist;
	}


	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < edges; j++){
			if(v[e[j].second] > v[e[j].first] + e[j].dist){
				v[e[j].second] = v[e[j].first] + e[j].dist;
				used[e[j].second] = used[e[j].first] + 1;
			}
		}
	}

	std::cout << v[ent] << std::endl << used[ent];

	return 0;
}
