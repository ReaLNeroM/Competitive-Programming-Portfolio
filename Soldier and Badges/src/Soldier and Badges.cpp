#include <iostream>
#include <algorithm>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int val[n];
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::sort(val, val + n);

	int res = 0;
	for(int i = 0; i < n - 1; i++){
		while(val[i] >= val[i + 1]){
			val[i + 1]++;
			res++;
		}
	}

	std::cout << res;
	return 0;
}
