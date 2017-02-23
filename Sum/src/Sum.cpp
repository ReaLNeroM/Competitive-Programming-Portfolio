#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

#define small (*diffexists.begin()).first
#define big val[end] - val[start]

int main() {
	std::ios::sync_with_stdio(false);
	int n, remove;
	std::cin >> n >> remove;

	int val[n];
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::sort(val, val + n);

	std::map<int, int> diffexists;
	for(int i = 0; i < n - remove - 1; i++){
		diffexists[val[i + 1] - val[i]]++;
	}

	int start = 0, end = n - remove - 1;
	int res = small + big;
	for(int i = n - remove - 1; i < n - 1; i++){
		res = std::min(res, small + big);

		diffexists[val[start + 1] - val[start]]--;
		if(diffexists[val[start + 1] - val[start]] == 0){
			diffexists.erase(diffexists.find(val[start + 1] - val[start]));
		}
		start++, end++;
		end = std::min(end, n - 1);

		diffexists[val[end] - val[end - 1]]++;

	}

	std::cout << std::min(res, small + big);
	return 0;
}
