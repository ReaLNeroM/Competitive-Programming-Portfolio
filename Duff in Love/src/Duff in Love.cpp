#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	ll n;
	std::cin >> n;

	ll res = 1;
	bool flag;

	flag = false;
	while(n % 2 == 0){
		flag = true;
		n /= 2;
	}
	if(flag){
		res *= 2;
	}

	flag = false;
	while(n % 3 == 0){
		flag = true;
		n /= 3;
	}
	if(flag){
		res *= 3;
	}

	for(int i = 5; i <= std::sqrt(n); i += 6){
		flag = false;
		while(n % i == 0){
			flag = true;
			n /= i;
		}
		if(flag){
			res *= i;
		}

		flag = false;
		while(n % (i + 2) == 0){
			flag = true;
			n /= i + 2;
		}
		if(flag){
			res *= i + 2;
		}
	}

	res *= n;
	std::cout << res;
	return 0;
}
