#include <iostream>

struct edge{
	int first, second, dist;
};

int bellman(int end, int v[], int vertices, edge e[], int edges, int r[]){
	for(int i = 0; i < vertices - 1; i++){
		for(int j = 0; j < edges; j++){
			if(v[e[j].first] + e[j].dist < v[e[j].second]){
				v[e[j].second] = v[e[j].first] + e[j].dist;
				r[e[j].second] = r[e[j].first] + 1;
			}
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

	int v[vertices], r[vertices];
	edge e[edges];

	for(int i = 0; i < vertices; i++){
		v[i] = 10000000;
		r[i] = 10000000;
	}

	for(int i = 0; i < edges; i++){
		std::cin >> e[i].first >> e[i].second >> e[i].dist;
		e[i].first--, e[i].second--;
	}

	int start, end;
	std::cin >> start >> end;
	start--, end--;
	v[start] = 0;
	r[start] = 0;

	int result = bellman(end, v, vertices, e, edges, r);

	if(result == -123456789){
		std::cout << "Impossible";
	} else{
		std::cout << v[end] << ' ' << r[end];
	}

	return 0;
}
