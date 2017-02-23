#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	double radius;
	std::cin >> radius;
	int n = 2 * radius + 1;

	char mat[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			mat[i][j] = '.';
		}
	}


	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			double check = std::sqrt(std::pow(std::abs(j - n / 2), 2) + std::pow(std::abs(i - n / 2), 2));

			if(check > std::ceil(radius) - 1.000001 and check < std::ceil(radius) - 0.0000001){
				mat[i][j] = '*';
			}
			std::cout << mat[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
