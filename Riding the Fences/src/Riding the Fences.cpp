/*
ID: vlade.m1
PROG: fence
LANG: C++
 */

#include <fstream>
#include <deque>
#include <algorithm>

std::ifstream fin("fence.in");
std::ofstream fout("fence.out");

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
	int vertices = 500,  edges;
	fin >> edges;

	e.resize(vertices);

	int wrong = 0;

	for(int i = 0, first, second; i < edges; i++){
		fin >> first >> second;

		e[first - 1].push_back(second - 1);
		if(e[first - 1].size() % 2 == 1){
			wrong++;
		} else {
			wrong--;
		}
		e[second - 1].push_back(first - 1);
		if(e[second - 1].size() % 2 == 1){
			wrong++;
		} else {
			wrong--;
		}
	}

	for(int i = 0; i < vertices; i++){
		std::sort(e[i].begin(), e[i].end());
	}

	for(int i = 0; i < vertices; i++){
		if(!e[i].empty() and (wrong == 0 or e[i].size() % 2 == 1)){
			findpath(i);
			break;
		}
	}

	for(int i = 0; i < path.size(); i++){
		fout << path[i] + 1 << std::endl;
	}
	return 0;
}
