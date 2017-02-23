#include <iostream>
#include <map>

int main() {
	long long nums, ratio;
	std::cin >> nums >> ratio;

	long long res = 0;
	std::map<long long, long long> stage[2];
	long long val[nums];
	for(long long i = 0; i < nums; i++){
		std::cin >> val[i];

		res += stage[1][val[i]];
		stage[1][val[i] * ratio] += stage[0][val[i]];
		stage[0][val[i] * ratio]++;
	}


	std::cout << res;
	return 0;
}
