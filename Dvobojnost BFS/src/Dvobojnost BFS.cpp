#include <iostream>
#include <vector>
#include <queue>

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	char color[vertices];
	std::vector<int> adjlist[vertices];

	for(int i = 0; i < vertices; i++){
		color[i] = '0';
	}

	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;
		adjlist[first].push_back(second);
		adjlist[second].push_back(first);
	}

	std::queue<int> q;
	color[0] = '1';
	q.push(0);
	while(!q.empty()){
		for(int i = 0; i < adjlist[q.front()].size(); i++){
			if(color[adjlist[q.front()][i]] == '0'){
				color[adjlist[q.front()][i]] = 2 - color[q.front()];
				q.push(adjlist[q.front()][i]);
			} else if(color[adjlist[q.front()][i]] == color[q.front()]){
				std::cout << "NO";
				return 0;
			}
		}

		q.pop();
	}

	std::cout << "YES";
	return 0;
}
