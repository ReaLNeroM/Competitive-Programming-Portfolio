#include <iostream>
#include <vector>

long long problems, min, max, range;
std::vector<long long> diff;

long long ways(long long pos = 0, long long sum = 0, long long easy = 1000000000, long long hard = 0, long long taken = 0){
	if(pos == problems){
		if(sum >= min and sum <= max and hard - easy >= range and taken >= 2){
			return 1;
		} else {
			return 0;
		}
	}

	return ways(pos + 1, sum + diff[pos], std::min(easy, diff[pos]), std::max(hard, diff[pos]), taken + 1) +
				ways(pos + 1, sum, easy, hard, taken);
}
int main() {
	std::cin >> problems >> min >> max >> range;

	diff.resize(problems);
	for(int i = 0; i < problems; i++){
		std::cin >> diff[i];
	}

	std::cout << ways();
	return 0;
}
