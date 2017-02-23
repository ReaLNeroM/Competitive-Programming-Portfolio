#include <iostream>

typedef long long ll;

int main() {
	int digits, divisible;
	std::cin >> digits >> divisible;

	if(digits == 1 and divisible == 10){
		std::cout << -1;
	} else {
		if(divisible == 10){
			divisible = 1;
		}
		std::cout << divisible;
		for(int i = 1; i < digits; i++){
			std::cout << 0;
		}
	}
	return 0;
}
