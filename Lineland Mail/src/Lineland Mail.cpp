#include <iostream>

int main() {
	int n;
	std::cin >> n;

	long long val[n];

	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	for(int i = 0; i < n; i++){
		long long min = 100000000000, max = 0;

		if(i > 0){
			min = std::min(min, val[i] - val[i - 1]);
			max = std::max(max, val[i] - val[0]);
		}

		if(i < n - 1){
			min = std::min(min, val[i + 1] - val[i]);
			max = std::max(max, val[n - 1] - val[i]);
		}

		std::cout << min << " " << max << std::endl;
	}
	return 0;
}
