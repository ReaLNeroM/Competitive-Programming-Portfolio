#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	int y, x;
	std::cin >> y >> x;

	int mat[y][x], best[y][x];

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[i][j];
		}
	}

	for(int i = y - 1; i >= 0; i--){
		for(int j = x - 1; j >= 0; j--){
			best[i][j] = 0;
			if(i != y - 1){
				best[i][j] = best[i + 1][j];
			}
			if(j != x - 1){
				best[i][j] = std::max(best[i][j], best[i][j + 1]);
			}

			best[i][j] += mat[i][j];
		}
	}

	std::cout << best[0][0] << std::endl;

	int posy = 0, posx = 0;
	while(posy != y - 1 or posx != x - 1){
		std::cout << posy + 1 << " " << posx + 1 << std::endl;

		if(posy != y - 1 and best[posy + 1][posx] + mat[posy][posx] == best[posy][posx]){
			posy++;
		} else {
			posx++;
		}
	}

	std::cout << posy + 1 << " " << posx + 1;
	return 0;
}
