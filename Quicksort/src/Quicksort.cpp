#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>

typedef long long ll;


int n;
std::vector<int> val;

void Pivot(int left, int right){
	if(left >= right){
		return;
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
	Pivot(0, midpos - 1);
	Pivot(midpos + 1, right);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> n;
	std::srand(std::time(NULL));

	val.resize(n);
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
	}

	Pivot(0, n);

	for(int i = 0; i < n; i++){
		std::cout << val[i] << std::endl;
	}
	return 0;
}
