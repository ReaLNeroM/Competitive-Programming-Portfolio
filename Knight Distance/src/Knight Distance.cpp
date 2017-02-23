#include <iostream>

const int size = 50;
int kposx, kposy;

int dist[size][size];

void gendist(int y, int x, int step){
	if(dist[y][x] > step){
		dist[y][x] = step;
		if(y > 1 and x > 0){
			gendist(y - 2, x - 1, step + 1);
		}
		if(y > 1 and x < size - 1){
			gendist(y - 2, x + 1, step + 1);
		}
		if(y > 0 and x > 1){
			gendist(y - 1, x - 2, step + 1);
		}
		if(y > 0 and x < size - 2){
			gendist(y - 1, x + 2, step + 1);
		}
		if(y < size - 1 and x > 1){
			gendist(y + 1, x - 2, step + 1);
		}
		if(y < size - 1 and x < size - 2){
			gendist(y + 1, x + 2, step + 1);
		}
		if(y < size - 2 and x > 0){
			gendist(y + 2, x - 1, step + 1);
		}
		if(y < size - 2 and x < size - 1){
			gendist(y + 2, x + 1, step + 1);
		}

	}
}
int main() {
	std::cin >> kposx >> kposy;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			dist[i][j] = size * size;
		}
	}

	gendist(kposy - 1, kposx - 1, 0);
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			std::cout << dist[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
