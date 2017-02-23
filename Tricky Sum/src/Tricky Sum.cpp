#include <iostream>

typedef long long ll;

int main() {
	int cases;
	std::cin >> cases;
	for(int i = 0; i < cases; i++){
		ll req;
		std::cin >> req;

		ll sum = req * (req + 1) / 2;
		for(int i = 1; i <= req; i *= 2){
			sum -= 2 * i;
		}

		std::cout << sum << std::endl;
	}
	return 0;
}
