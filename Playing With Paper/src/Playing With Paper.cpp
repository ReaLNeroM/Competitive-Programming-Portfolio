#include <iostream>

typedef long long ll;

int main() {
	long long a, b;
	std::cin >> a >> b;

	long long res = 0;
	while(b != 0){
		res += a / b;
		long long c = a % b;
		a = b;
		b = c;
	}
	std::cout << res;
	return 0;
}
