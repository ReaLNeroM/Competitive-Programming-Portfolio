#include <iostream>

typedef long long ll;

int main() {
	int a, b;
	std::cin >> a >> b;

	while(b > 0){
		int carry = a & b;

		a = a ^ b;

		b = carry << 1;
	}

	std::cout << a;
	return 0;
}
