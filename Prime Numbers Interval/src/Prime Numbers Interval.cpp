#include <iostream>

int main(){
	int min, max;
	std::cin >> min >> max;

	if(min <= 2){
		std::cout << 2 << std::endl;
		if(min <= 3){
			std::cout << 3 << std::endl;
		}
	}

	int j;
	for(int jump = 6; jump <= max; jump += 6){
		for(int i = jump - 1; i <= std::min(jump + 1, max); i += 2){
			if(i % 3 == 0 or i % 2 == 0){
				continue;
			}
			for(j = 6; j <= i / 2; j += 6){
				if(i % (j - 1) == 0 or i % (j + 1) == 0){
					j = -1;
					break;
				}
			}

			if(j > -1 and min <= i){
				std::cout << i << std::endl;
			}
		}
	}
}
