#include <bits/stdc++.h>

typedef long long ll;

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	if(n == 1){
		std::cout << "0\n";
		return 0;
	} else if(n == 2){
		std::cout << "1\n2 2 0\n";
		return 0;
	}

	int even = 0;

	std::cout << n / 2 + 1 << std::endl;

	if(n % 2 == 0){
		std::cout << "2 " << n << ' ' << 0 << std::endl;
		even = 1;
		n--;
	}

	std::cout << 3 + even << ' ' << 3 + n / 2 - 1 + even << ' ' << 0 << std::endl;
	if(n == 3){
		std::cout << 2 + even << ' ' << 2 + even << ' ' << 3 + even << std::endl;
	} else {
		std::cout << 2 + even << ' ' << n + even << ' ' << 3 + even << std::endl;
	}

	int curr = 0;
	int r = n + even, l = 4 + even;
	while(l <= r){
		std::cout << r << ' ' << l << ' ' << curr << '\n';
		curr = r;
		r--, l++;
	}
}