#include <iostream>
#include <cmath>

typedef long long ll;

int euclid(int a, int b){
	if(a < b){
		std::swap(a, b);
	}
	if(b == 0){
		return a;
	}

	return euclid(b, a % b);
}
int main() {
	int n;
	std::cin >> n;

	int num;
	std::cin >> num;

	num -= 1;

	for(int i = 1, inp; i < n; i++){
		std::cin >> inp;
		if(i != inp - 1){
			num = euclid(num, std::max(inp - 1, i) - std::min(inp - 1, i));
		}
	}

	int res = 0;
	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			res++;
		}
	}
	std::cout << res << std::endl;

	for(int i = 1; i <= num; i++){
		if(num % i == 0){
			std::cout << i << ' ';
		}
	}
	return 0;
}
