#include <iostream>

int main() {
	int x, y, dimenz, broken;
	std::cin >> y >> x >> dimenz >> broken;
	bool brox[x], broy[y];

	for(int i = 0; i < x; i++){
		brox[i] = false;
	}
	for(int i = 0; i < y; i++){
		broy[i] = false;
	}

	for(int i = 0, xp, yp, vert; i < broken; i++){
		std::cin >> xp >> yp >> vert;

		if(vert - 1){
			brox[yp - 1] = true;
		} else{
			broy[xp - 1] = true;
		}
	}

	int start = 0, bestx = 1000000;
	for(int i = 0; i < dimenz; i++){
		start += brox[i];
	}
	for(int i = 0; i < x - dimenz; i++){
		bestx = std::min(bestx, start);

		start += brox[i + dimenz];
		start -= (brox[i]) ? 1 : 0;
	}
	bestx = std::min(bestx, start);

	start = 0;
	int besty = 1000000;
	for(int i = 0; i < dimenz; i++){
		start += broy[i];
	}
	for(int i = 0; i < y - dimenz; i++){
		besty = std::min(besty, start);

		start += broy[i + dimenz];
		start -= (broy[i]) ? 1 : 0;
	}
	besty = std::min(besty, start);

	std::cout << bestx + besty;
	return 0;
}
