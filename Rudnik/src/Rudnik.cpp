#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

typedef long long ll;

struct cell {
	cell* parent = this;
	int rank = 0;
	bool enabled = false;

public:
	cell* root(){
		if(parent != parent->parent){
			parent = parent->root();
		}

		return parent;
	}

	void unite(cell* second){
		root();
		second = second->root();

		if(rank > second->rank){
			second->parent = parent;
		} else if(rank < second->rank){
			parent = second;
		} else {
			parent = second;
			rank++;
		}
	}
};

int main() {
	int queries;
	std::cin >> queries;

	int q[queries];
	for(int i = 0; i < queries; i++){
		std::cin >> q[i];
	}

	int y, x;
	std::cin >> y >> x;

	std::pair<int, std::pair<int, int> > mat[y * x];

	cell c[y][x];
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[x * i + j].first;
			mat[x * i + j].second.first = i;
			mat[x * i + j].second.second = j;
		}
	}

	std::sort(mat, mat + y * x, std::greater<std::pair<int, std::pair<int, int> > >());

	int pos = 0, blocks = 0;
	int res[queries];
	const int addy[] = {1, -1, 0, 0};
	const int addx[] = {0, 0, 1, -1};

	for(int i = 0; i < queries; i++){
		while(pos != y * x and mat[pos].first > q[queries - i - 1]){
			c[mat[pos].second.first][mat[pos].second.second].enabled = true;
			int collisions = 0;

			for(int add = 0; add < 4; add++){
				if(mat[pos].second.first + addy[add] >= 0 and mat[pos].second.first + addy[add] < y and
						mat[pos].second.second + addx[add] >= 0 and mat[pos].second.second + addx[add] < x){
					if(c[mat[pos].second.first + addy[add]][mat[pos].second.second + addx[add]].enabled){
						if(c[mat[pos].second.first][mat[pos].second.second].root() != c[mat[pos].second.first + addy[add]][mat[pos].second.second + addx[add]].root()){
							collisions++;
							c[mat[pos].second.first][mat[pos].second.second].unite(&c[mat[pos].second.first + addy[add]][mat[pos].second.second + addx[add]]);
						}
					}
				}
			}

			if(collisions == 0){
				blocks++;
			} else if(collisions > 1){
				blocks -= collisions - 1;
			}

			pos++;
		}

		res[queries - i - 1] = blocks;
	}

	for(int i = 0; i < queries; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
