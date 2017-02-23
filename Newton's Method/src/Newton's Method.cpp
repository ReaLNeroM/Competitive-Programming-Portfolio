#include <iostream>
#include <cmath>

int main(){
	int x;
	std::cin >> x;

	double sum = x + 1;
	while(std::abs(sum - x / sum) > 0.0000001){
		sum += x / sum;
		sum /= 2;
	}

	std::cout << sum;
}
