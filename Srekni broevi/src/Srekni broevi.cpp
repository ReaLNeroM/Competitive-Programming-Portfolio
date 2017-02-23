#include <iostream>

int main() {
	long long num;
	std::cin >> num;

	int startingdigit = 1;
	for(int power = 2; power <= num; power *= 2){
		if(power < num){
			num -= power;
			startingdigit *= 2;
		} else {
			break;
		}
	}

	while(startingdigit > 0){
		if(startingdigit < num){
			std::cout << 7;
			num -= startingdigit;
		} else {
			std::cout << 4;
		}

		startingdigit /= 2;
	}
	return 0;
}
