#include <iostream>

int main() {
	long long sum = 0;

	for(int i = 3; i <= 100000; i++){
		int j;
		for(j = i - 2; j > 1; j--){
			if(i % j != 0 and (j * j) % i == 1){
				sum += j;
				break;
			}
		}

		if(j == 1){
			sum += j;
		}
	}

	std::cout << sum;
	return 0;
}
