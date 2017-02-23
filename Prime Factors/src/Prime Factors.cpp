#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	long long n;
	std::cin >> n;

	std::vector<long long> divisors;
	while(n % 2 == 0){
		divisors.push_back(2);
		n /= 2;
	}
	while(n % 3 == 0){
		divisors.push_back(3);
		n /= 3;
	}
	for(long long i = 6; i * 2 <= n; i += 6){
		while(n % (i - 1) == 0){
			n /= i - 1;
			divisors.push_back(i - 1);
		}
		while(n % (i + 1) == 0){
			n /= i + 1;
			divisors.push_back(i + 1);
		}
	}

	if(n != 1){
		divisors.push_back(n);
	}

	for(int i = 0; i < divisors.size(); i++){
		std::cout << divisors[i] << " ";
	}
	return 0;
}
