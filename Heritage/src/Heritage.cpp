#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

typedef long long ll;

//appears like you need to calculate for every possible point

int main() {
	int sons, parts;
	std::cin >> sons >> parts;

	parts++;
	double area[15];
	double h[15];
	std::pair<int, int> coord[parts];
	for(int i = 0; i < parts; i++){
		std::cin >> coord[i].first >> coord[i].second;
	}

	std::sort(coord, coord + parts);
	for(int i = 0; i <= 14; i++){
		area[i] = 0;
	}

	for(int i = 0; i < parts - 1; i++){
		double height = coord[i].first;
		double persize = ((double) (coord[i + 1].second - coord[i].second)) / (coord[i + 1].first - coord[i].first);
		for(int j = coord[i].first; j < coord[i + 1].first; j++){
			if(coord[i].first != 0){
				area[coord[i].first] = area[coord[i].first - 1];
			}
			area[j] += height;
			h[j] = height;
			area[j] += persize / 2;
			height += persize;
		}
	}

	for(int i = coord[parts - 1].first; i <= 14; i++){
		area[i] = 0;
		if(i != 0){
			area[i] += area[i - 1];
		}
	}

	for(int i = 0; i <= 14; i++){
		std::cout << area[i] << std::endl;
	}
	std::sort(coord, coord + parts);

	int
	return 0;
}
