#include <iostream>

int size, used;
char c[200][200];

int main() {
	std::cin >> size >> used;

	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			c[i][j] = 'S';
		}
	}
	int i, j;
	if(used == 0){
		std::cout << "YES" << std::endl;
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				std::cout << c[i][j];
			}
			std::cout << std::endl;
		}
		i = j = size + 1;
	} else{
		for(i = 0; i < size; i++){
			for(j = i % 2; j < size; j += 2){
				c[i][j] = 'L';
				used--;
				if(used <= 0){
					std::cout << "YES" << std::endl;
					for(int i = 0; i < size; i++){
						for(int j = 0; j < size; j++){
							std::cout << c[i][j];
						}
						std::cout << std::endl;
					}
					i = j = size + 1;
				}
			}
		}
	}

	if(i == size){
		std::cout << "NO" << std::endl;
	}
	return 0;
}
