#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
	int first, second;

	bool operator<(const edge &x) const{
		if(min(first, second) == min(x.first, x.second)){
			if(max(first, second) == max(x.first, x.second)){
				return first < x.first;
			}

			return max(first, second) < max(x.first, x.second);
		}

		return (min(first, second) < min(x.first, x.second));
	}

	bool operator==(const edge &x) const{
		return first == x.first and second == x.second;
	}
} insert;

int main() {
	int vertices, edges;
	cin >> vertices >> edges;

	vector<edge> e;

	for(int i = 0; i < edges; i++){
		cin >> insert.first >> insert.second;

		e.push_back(insert);
	}

	std::sort(e.begin(), e.end());

	for(int i = 0; i < e.size() - 1; i++){
		if(e[i] == e[i + 1]){
			e.erase(e.begin() + i);
			i--;
		}
	}

	for(int i = 0; i < e.size(); i++){
		if(i == e.size() - 1 or e[i].first != e[i + 1].second or e[i].second != e[i + 1].first){
			e.erase(e.begin() + i);
			i--;
		} else {
			i++;
		}
	}

	std::vector<int> adjlist[vertices];
	for(int i = 0; i < e.size(); i++){
		adjlist[e[i].first].push_back(e[i].second);
	}

	char color[vertices];

	for(int i = 0; i < vertices; i++){
		color[i] = '0';
	}

	std::queue<int> q;
	color[0] = '1';
	q.push(0);

	while(!q.empty()){
		for(int i = 0; i < adjlist[q.front()].size(); i++){
			if(color[adjlist[q.front()][i]] == color[q.front()]){
				std::cout << "NE";
				return 0;
			} else if(color[adjlist[q.front()][i]] == '0'){
				color[adjlist[q.front()][i]] = '0' + 2 - color[q.front()];
				q.push(adjlist[q.front()][i]);
			}
		}

		q.pop();
	}

	std::cout << "DA";
	return 0;
}
