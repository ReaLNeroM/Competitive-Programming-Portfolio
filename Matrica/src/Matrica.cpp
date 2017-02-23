#include <iostream>

int main() {
	int y, x;
	std::cin >> y >> x;

	int res = 0;
	for(int i = 0; i < y; i++){
		int pos = 0, neg = 0;

		for(int j = 0, inp; j < x; j++){
			std::cin >> inp;

			pos += inp;
			neg -= inp;
		}

		res += std::max(pos, neg);
	}

	std::cout << res;
	return 0;
}
