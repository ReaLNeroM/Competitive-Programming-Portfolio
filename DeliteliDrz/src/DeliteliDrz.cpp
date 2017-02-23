#include <iostream>
#include <vector>
#include <algorithm>

int n;
std::vector<int> nums, taken, res;
int best = 9999999;

int check(int n){
	int res = 1, copy = n;
	for(int i = 2; i * i <= n; i++){
		int power = 1;
		while(copy % i == 0){
			copy /= i;
			power++;
		}

		res *= power;
	}

	if(copy != 1){
		res *= 2;
	}

	return res;
}

void perm(int depth = 0, int number = 0){
	if(depth == n){
		int factors = check(number);
		if(factors < best){
			res.clear();
			res.push_back(number);
			best = factors;
		} else if(factors == best and res.back() != number){
			res.push_back(number);
		}
	}
	number *= 10;

	for(int i = 0; i < n; i++){
		if(!taken[i]){
			taken[i] = true;
			number += nums[i];
			perm(depth + 1, number);
			number -= nums[i];
			taken[i] = false;
		}
	}
}

int main() {
	std::cin >> n;

	nums.resize(n), taken.resize(n, false);
	for(int i = 0; i < n; i++){
		std::cin >> nums[i];
	}

	std::sort(nums.begin(), nums.end());

	perm();

	std::cout << best << std::endl;

	std::sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		if(i == res.size() - 1 or res[i] != res[i + 1]){
			std::cout << res[i] << " ";
		}
	}

	return 0;
}
