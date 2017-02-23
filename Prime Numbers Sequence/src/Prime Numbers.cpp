#include <iostream>
#include <cmath>

int main(){
	int min, max;
	std::cin >> min >> max;

	if(min <= 1 and max >= 1){
		std::cout << 2 << std::endl;
	}
	min--, max--;

	if(min <= 1 and max >= 1){
		std::cout << 3 << std::endl;
	}
	min--, max--;


	int j;
	for(int jump = 6; max >= 1; jump += 6){
		for(int i = jump - 1; i <= jump + 1 and max >= 1; i += 2){
			int limit = std::ceil(std::sqrt(i));
			for(j = 6; j <= limit + 1; j += 6){
				if(i % (j - 1) == 0 or i % (j + 1) == 0){
					j = -1;
					break;
				}
			}

			if(j > -1){
				if(min <= 1){
					std::cout << i << std::endl;
				}
				min--, max--;
			}
		}
	}

}
