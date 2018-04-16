#include <iostream>
#include <deque>

std::deque<std::deque<int> > e;
std::deque<int> path;

void findpath(int pos){
	while(!e[pos].empty()){
		int next = e[pos].front();
		e[pos].pop_front();
		for(int j = 0; j < e[next].size(); j++){
			if(e[next][j] == pos){
				e[next].erase(e[next].begin() + j);
				break;
			}
		}
		findpath(next);
	}

	path.push_front(pos);
}

int main() {
	int vertices, edges;
	std::cin >> vertices >> edges;

	e.resize(vertices);

	int wrong = 0;

	for(int i = 0, first, second; i < edges; i++){
		std::cin >> first >> second;

		e[first - 1].push_back(second - 1);
		e[second - 1].push_back(first - 1);
		
		if(e[first - 1].size() % 2 == 1){
			wrong++;
		} else {
			wrong--;
		}
		if(e[second - 1].size() % 2 == 1){
			wrong++;
		} else {
			wrong--;
		}
	}

	if(wrong == 0){
		findpath(0);

		for(int i = 0; i < path.size(); i++){
			std::cout << path[i] + 1 << " ";
		}
	} else {
		std::cout << "YOK";
	}
	return 0;
}
