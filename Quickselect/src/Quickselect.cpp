#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

typedef long long ll;


int n;
std::vector<int> val;

int Pivot(int left, int right, int nth){
	if(left >= right){
		return val[left];
	}

	int random = left + std::rand() % (right - left);
	std::swap(val[random], val[right - 1]);
	int pivot = val[right - 1];

	int midpos = left;
	for(int i = left; i < right - 1; i++){
		if(pivot > val[i]){
			std::swap(val[midpos], val[i]);
			midpos++;
		}
	}

	std::swap(val[midpos], val[right - 1]);
	if(midpos > nth){
		return Pivot(left, midpos, nth);
	} else {
		return Pivot(midpos + 1, right, nth - midpos - 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int nth;
	std::cin >> n >> nth;
	std::srand(std::time(NULL));

	val.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	std::cout << Pivot(0, n, nth);

	return 0;
}
