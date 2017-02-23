#include <iostream>

typedef long long ll;

int main() {
	ll n;
	std::cin >> n;

	ll array[n];

	ll pos, i;
	if(n % 2 == 0){
		pos = n - 1;
	} else {
		pos = n - 2;
	}

	for(i = 0; i < n and pos <= n; i++, pos -= 2){
		array[i] = pos;
	}
	if(n > 3){
		pos = n - n % 2;
		for(; i < n and pos <= n; i++, pos += 2){
			array[i] = pos;
		}
	}

	std::cout << i << std::endl;

	for(int ite = 0; ite < i; ite++){
		std::cout << array[ite] << " ";
	}
	return 0;
}
