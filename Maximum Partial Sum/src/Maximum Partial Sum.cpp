#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int val[n];
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	int max = 0;

	int curr = 0, currnext = 0;

	for(int i = 0; i < n; i++){
		curr = std::max(currnext, 0) + val[i];
		currnext = curr;

		max = std::max(max, curr);
	}
	max = std::max(max, curr);

	std::cout << max;
	return 0;
}
