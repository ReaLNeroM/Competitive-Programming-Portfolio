#include <iostream>

typedef long long ll;

int main() {
	long long div, a, b;
	std::cin >> div >> a >> b;
	ll res = 0;

	if(a <= 0 and b <= 0){
		std::swap(a, b);
		a *= -1;
		b *= -1;
	}

	if(a >= 0 and b >= 0){
		if(a % div == 0){
			res++;
		}
		res += b / div - a / div;
	} else {
		res += (-a) / div + b / div + 1;
	}

	std::cout << res;
	return 0;
}
