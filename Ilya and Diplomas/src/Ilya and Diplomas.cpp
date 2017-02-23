#include <iostream>

int main() {
	int kids;
	std::cin >> kids;

	int min[3], max[3];
	for(int i = 0; i < 3; i++){
		std::cin >> min[i] >> max[i];

		max[i] -= min[i];
		kids -= min[i];
	}

	for(int i = 0; i < 3; i++){
		std::cout << min[i] + std::min(max[i], kids) << " ";

		kids -= max[i];
		kids = std::max(kids, 0);
	}
	return 0;
}
