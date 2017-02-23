#include <iostream>

int main() {
	long long a, b, n;
	std::cin >> a >> b >> n;

	for(int i = 2; i < n; i++){
		b = a - b;
		a = b - a;
		if(b < 0){
			b = -b;
		}
		if(a < 0){
			a = -a;
		}
	}

	std::cout << b;
	return 0;
}
