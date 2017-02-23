#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > adjlist;
std::vector<int> color;

struct edge{
	int first, second;

	bool operator<(const edge &x) const{
		if(std::min(first, second) == std::min(x.first, x.second)){
			return std::max(first, second) < std::max(x.first, x.second);
		}

		return std::min(first, second) < std::min(x.first, x.second);
	}

	bool operator==(const edge &x) const{
		return (first == x.first and second == x.second);
	}
} copy;

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

	std::vector<edge> list;
	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;

		copy.first = first, copy.second = second;
		list.push_back(copy);
	}

	std::sort(list.begin(), list.end());

	for(int i = 0; i < list.size() - 1; i++){
		if(list[i] == list[i + 1]){
			list.erase(list.begin() + i);
			i--;
		}
	}

	int i;
	for(i = 0; i < list.size() - 1; i++){
		if(list[i].first == list[i + 1].second and list[i].second == list[i + 1].first){
			i++;
		} else {
			list.erase(list.begin() + i);
			i--;
		}
	}

	if(i == list.size() - 1 and (list[i - 1].first != list[i].second or list[i - 1].second != list[i].first)){
		list.erase(list.begin() + i);
	}

	for(int i = 0; i < list.size(); i++){
		adjlist[list[i].first].push_back(list[i].second);
	}
	for(int i = 0; i < vertices; i++){
		if(color[i] == -1 and !dfs(i)){
			std::cout << "NE";
			return 0;
		}
	}

	std::cout << "DA";
	return 0;
}
