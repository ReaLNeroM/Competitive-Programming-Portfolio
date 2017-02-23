#include <iostream>
#include <queue>

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	bool reachable[vertices];

	for(int i = 0; i < vertices; i++){
		reachable[i] = false;
	}

	std::vector<int> adjlist[vertices];
	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;
		adjlist[first - 1].push_back(second - 1);
	}

	int start;
	std::cin >> start;
	start--;

	std::queue<int> q;
	q.push(start);

	do{
		reachable[q.front()] = true;

		for(int i = 0; i < adjlist[q.front()].size(); i++){
			if(!reachable[adjlist[q.front()][i]]){
				q.push(adjlist[q.front()][i]);
			}
		}

		q.pop();
	} while(!q.empty());

	for(int i = 0; i < vertices; i++){
		if(i != start and reachable[i]){
			std::cout << i + 1 << " ";
		}
	}
	return 0;
}
