#include <iostream>

int main() {
	int x, y;
	std::cin >> x >> y;

	int p[2][2];
	for(int i = 0; i < 2; i++){
		std::cin >> p[i][0] >> p[i][1];
	}

	for(int i = 0; i < 4; i++){
		if(i == 2){
			std::swap(p[0][0], p[0][1]);
		}
		if(i % 2 == 1){
			std::swap(p[1][0], p[1][1]);
		}
		if(p[0][0] <= x and p[1][0] <= x and p[0][1] <= y and p[1][1] <= y){
			if(p[0][0] + p[1][0] <= x or p[0][1] + p[1][1] <= y){
				std::cout << "YES";
				return 0;
			}
		}
	}

	std::cout << "NO";
	return 0;
}
