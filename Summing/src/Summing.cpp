#include <iostream>
#include <vector>
#include <set>

struct box{
	int val, index;
} input;

int vertices, goals;
std::set<int> vals;
std::vector<std::vector<box> > adjL;

void dfs(int index = 0, int sum = 0){
	if(index != 0){
		vals.insert(-sum);
	}

	for(int i = 0; i < adjL[index].size(); i++){
		dfs(adjL[index][i].index, sum + adjL[index][i].val);
	}
}

int main() {
	std::cin >> vertices >> goals;

	int g[goals];

	adjL.resize(vertices + 1);

	for(int i = 0, pred; i < vertices; i++){
		std::cin >> input.val >> pred;
		input.index = i + 1;
		adjL[pred + 1].push_back(input);
	}

	for(int i = 0; i < goals; i++){
		std::cin >> g[i];
	}

	dfs();

	for(int i = 0; i < goals; i++){
		std::set<int>::iterator r = vals.lower_bound(-g[i]);

		if(r == vals.end()){
			std::cout << "none" << std::endl;
		} else {
			std::cout << -(*r) << std::endl;
		}
	}
	return 0;
}
