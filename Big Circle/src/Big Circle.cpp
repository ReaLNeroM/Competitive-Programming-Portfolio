#include <iostream>
#include <algorithm>
#include <cmath>


int main() {
	std::ios_base::sync_with_stdio(false);
	int points;
	std::cin >> points;

	std::pair<double, double> vertices[points];
	for (int i = 0; i < points; i++) {
		std::cin >> vertices[i].first >> vertices[i].second;
	}

	std::sort(vertices, vertices + points);

	double min = 1000000000;
	for(int i = 0; i < points; i++){
		for(int j = i + 1; j < std::min(i + 3, points); j++){
			min = std::min(min, (vertices[j].first - vertices[i].first) * (vertices[j].first - vertices[i].first) + (vertices[j].second - vertices[i].second) * (vertices[j].second - vertices[i].second));
		}
	}

	std::cout.precision(2);
	std::cout << std::fixed << std::sqrt(((double) min)) / 100;
	return 0;
}
