#include <iostream>
#include <cmath>

int abs(int x){
	if(x >= 0){
		return x;
	} else {
		return -x;
	}
}
int main() {
	int y, x, pos, steps;
	std::cin >> y >> x >> pos >> steps;

	int posx = (pos - 1) % x;
	int posy = (pos - 1) / x;

	int sum = 0;
	for(int i = 0, fast = 0; i < y; i++, fast += x){
		for(int j = 0; j < x; j++){
			if((abs(posy - i) + abs(posx - j) == steps) or (abs(posy - i) + abs(posx - j) < steps and (abs(posy - i) + abs(posx - j)) % 2 == steps % 2)){
				sum += fast + j + 1;
			}
		}
	}

	std::cout << sum;
	return 0;
}
