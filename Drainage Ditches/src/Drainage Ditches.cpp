/*
ID: vlade.m1
PROG: ditch
LANG: C++
 */

#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("ditch.in");
	std::ofstream fout("ditch.out");
#endif

#include <queue>

typedef long long ll;

int main() {
	int vertices, edges;
	fin >> edges >> vertices;

	int start = 0, end = vertices - 1;

	int matrix[vertices][vertices];
	for(int i = 0; i < vertices; i++){
		for(int j = 0; j < vertices; j++){
			matrix[i][j] = 0;
		}
	}

	for(int i = 0, a, b, capacity; i < edges; i++){
		fin >> a >> b >> capacity;
		a--, b--;

		matrix[a][b] += capacity;
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

	fout << flow << std::endl;
	return 0;
}
