#include <iostream>
#include <queue>

typedef long long ll;

int main() {
	int vertices, edges;
	std::cin >> edges >> vertices;

	int start, end;
	std::cin >> start >> end;
	start--, end--;

	int matrix[vertices][vertices];

	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			matrix[i][j] = 0;
		}
	}

	for(int i = 0, a, b, capacity; i < edges; i++){
		std::cin >> a >> b >> capacity;

		matrix[a - 1][b - 1] += capacity;
	}

	int flow = 0;
	for(int i = 0; i < edges; i++){
		int parent[vertices];

		for(int i = 0; i < vertices; i++){
			parent[i] = -1;
		}

		std::queue<int> q;
		q.push(start);
		parent[start] = start;

		while(!q.empty()){
			for(int i = 0; i < vertices; i++){
				if(matrix[q.front()][i] > 0 and parent[i] == -1){
					parent[i] = q.front();

					q.push(i);
				}
			}

			q.pop();
		}

		int min = 2000000000;

		if(parent[end] != -1){
			for(int i = end; i != start; i = parent[i]){
				min = std::min(min, matrix[parent[i]][i]);
			}

			if(min > 0){
				for(int i = end; i != start; i = parent[i]){
					matrix[i][parent[i]] += min;
					matrix[parent[i]][i] -= min;
				}
			}
		} else {
			break;
		}

		flow += min;
	}

	std::cout << flow << std::endl;
	return 0;
}
