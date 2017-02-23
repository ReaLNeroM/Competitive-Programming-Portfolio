#include <iostream>
#include <algorithm>

int main() {
	long long kids, weight;
	std::cin >> kids >> weight;

	long long cup[kids * 2];
	for(long long i = 0; i < kids * 2; i++){
		std::cin >> cup[i];
	}

	std::sort(cup, cup + kids * 2);

	double pergirl = std::min((double) cup[0], (double) cup[kids] / 2);

	std::cout << std::fixed << std::min((double) weight, 3 * pergirl * kids);
	return 0;
}
