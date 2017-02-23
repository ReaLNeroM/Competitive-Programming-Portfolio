#include <iostream>
#include <vector>

std::vector<std::vector<int> > adjlist;
std::vector<int> color;

bool dfs(int pos = 0, bool coloring = 0){
	if(color[pos] == -1){
		color[pos] = coloring;
	} else {
		return (color[pos] == coloring);
	}

	for(int i = 0; i < adjlist[pos].size(); i++){
		if(!dfs(adjlist[pos][i], 1 - coloring)){
			return false;
		}
	}

	return true;
}
int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	color.resize(vertices, -1);
	adjlist.resize(vertices);

	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;

		adjlist[first].push_back(second);
		adjlist[second].push_back(first);
	}

	if(dfs()){
		std::cout << "YES";
	} else {
		std::cout << "NO";
	}
	return 0;
}
