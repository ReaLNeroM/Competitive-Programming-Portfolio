#include <iostream>

int main() {
	int cases;
	std::cin >> cases;

	int res[cases];
	int a, b;

	for(int i = 0; i < cases; i++){
		std::cin >> a >> b;

		res[i] = 0;
		while(a - (a & (-a)) != 0 and a > 1){
			a /= 2;

			res[i]++;
		}
		while(a < b){
			a *= 2;

			res[i]++;
		}
		while(a > b){
			a /= 2;

			res[i]++;
		}
	}

	for(int i = 0; i < cases; i++){
		std::cout << res[i] << std::endl;
	}
	return 0;
}
