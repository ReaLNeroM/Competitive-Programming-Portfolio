#include <iostream>

typedef long long ll;

double power(double x, ll y){
	if(y < 0){
		return power(1.0 / x, -y);
	} else if(y == 0){
		return 1;
	}

	double res = power(x, y / 2);
	res *= res;

	if(y % 2 == 1){
		res *= x;
	}

	return res;
}

int main() {
	double x;
	ll y;
	std::cin >> x >> y;

	std::cout << power(x, y);
	return 0;
}
