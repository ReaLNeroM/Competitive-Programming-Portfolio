#include <iostream>

int main() {
	long long n;
	std::cin >> n;

	for (long long i = 2; i <= n; i++) {
		long long exp = 0;
		while (n % i == 0) {
			n /= i;
			exp++;
		}

		if(exp > 0){
			std::cout << '(' << i << '^' << exp << ')';
			if (n != 1) {
				std::cout << '*';
			}
		}
	}
}
