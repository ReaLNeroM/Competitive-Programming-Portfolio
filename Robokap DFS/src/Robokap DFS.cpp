#include <iostream>
#include <vector>

std::vector<std::vector<int> > adjlist;
std::vector<bool> used;

void dfs(int pos){
	if(used[pos]){
		return;
	}

	used[pos] = true;

	for(int i = 0; i < adjlist[pos].size(); i++){
		dfs(adjlist[pos][i]);
	}
}
int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	used.resize(vertices, false);

	adjlist.resize(vertices);
	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;
		adjlist[first - 1].push_back(second - 1);
	}

	int start;
	std::cin >> start;
	start--;

	dfs(start);

	for(int i = 0; i < vertices; i++){
		if(i != start and used[i]){
			std::cout << i + 1 << " ";
		}
	}
	return 0;
}
