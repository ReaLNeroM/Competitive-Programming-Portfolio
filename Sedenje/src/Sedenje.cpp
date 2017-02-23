#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	long long x, y, mincheat;
	std::cin >> x >> y >> mincheat;

	long long knowledge[x * y], used[x * y];
	for(long long i = 0; i < x * y; i++){
		std::cin >> knowledge[i];
		used[i] = i;
	}

	long long sum, ways = 0;
	const long long adder[] = {1, -1, 0, 0};
	do{
		sum = mincheat;

		for(long long i = 0; i < y; i++){
			for(long long j = 0; j < x; j++){
				long long worst = 0;
				if(i > 0){
					worst = std::max(worst, knowledge[used[(i - 1) * x + j]]);
				}
				if(i < y - 1){
					worst = std::max(worst, knowledge[used[(i + 1) * x + j]]);
				}
				if(j > 0){
					worst = std::max(worst, knowledge[used[i * x + j - 1]]);
				}
				if(j < x - 1){
					worst = std::max(worst, knowledge[used[i * x + j + 1]]);
				}
				sum -= knowledge[used[i * x + j]] * worst * (i + 1);
			}
		}
		if(sum >= 0){
			ways++;
		}
	} while(std::next_permutation(used, used + x * y));

	std::cout << ways;
	return 0;
}
