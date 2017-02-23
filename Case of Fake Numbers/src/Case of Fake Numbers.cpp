#include <iostream>

int main() {
	int mod;
	std::cin >> mod;

	int gears;
	std::cin >> gears;

	int turns = mod - gears;
	for(int i = 1; i < mod; i++){
		std::cin >> gears;

		if(i % 2 == 0){
			gears += turns;
			if(gears >= mod){
				gears -= mod;
			}
		} else {
			gears -= turns;
			if(gears < 0){
				gears += mod;
			}
		}
		if(gears != i){
			std::cout << "No";
			return 0;
		}
	}

	std::cout << "Yes";
	return 0;
}
