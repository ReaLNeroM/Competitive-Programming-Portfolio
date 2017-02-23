#include <iostream>
#include <vector>

std::vector<std::vector<char> > mat;
std::vector<std::vector<std::vector<int> > > value;

int best(i, j, orient){
	if(value[i][j] == -1){
		value[i][j] = 1000000;
		switch (orient){
		case 0:

			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		}
	}
}
int main() {
	int x, y;
	std::cin >> x >> y;

	mat.resize(x), value.resize(x);
	for(int i = 0; i < x; i++){
		mat[i].resize(y), value[i].resize(y);
		for(int j = 0; j < y; j++){
			value[i][j].resize(5, -1);
			std::cin >> mat[i][j];
			if(mat[i][j] == 'S'){
				value[i][j][0] = 0;
			} else if(mat[i][j] == 'E'){
				endx = i, endy = j;
			}
		}
	}


	std::cout << value[endx][endy];
	return 0;
}
