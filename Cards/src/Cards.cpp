#include <iostream>
#include <algorithm>

int main() {
	int tests;
	std::cin >> tests;

	int res[tests];
	for(int i = 0; i < tests; i++){
		int cards;
		std::cin >> cards;
		res[i] = 0;

		int given[cards];
		for(int j = 0; j < cards; j++){
			std::cin >> given[j];
		}

		std::sort(given, given + cards);

		do{
			int sum = 0;
			for(int j = 0; j < cards; j++){
				if(sum == 0 or sum % 2 != given[j] % 2){
					sum = sum * 10 + given[j];
				}
			}
			res[i] = std::max(res[i], sum);
		} while(std::next_permutation(given, given + cards));
	}

	for(int i = 0; i < tests; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
