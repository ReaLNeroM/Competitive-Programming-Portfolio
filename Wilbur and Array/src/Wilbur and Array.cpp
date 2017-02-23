#include <iostream>
#include <cmath>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int curr = 0;
	ll res = 0;
	for(int i = 0, inp; i < n; i++){
		std::cin >> inp;
		res += std::abs(inp - curr);
		curr = inp;
	}

	std::cout << res;
	return 0;
}
