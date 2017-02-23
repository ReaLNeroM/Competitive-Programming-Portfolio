#include <iostream>

int main() {
	int notes;
	std::cin >> notes;

	int min = 1000000;
	for(int i = 0, note; i < notes; i++){
		std::cin >> note;
		min = std::min(min, note);
	}


	if(min > 1){
		std::cout << 1 << std::endl;
	} else {
		std::cout << -1 << std::endl;
	}
	return 0;
}
