#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> vals;
std::vector<std::vector<int> > salesman;

int generate(int pos, int bitmask, int last){
	if(pos == vals.size()){
		return (int) std::abs(vals[last] - vals[0]);
	}
	if(salesman[pos][bitmask] == 1000000){
		for(int i = 1; i < vals.size(); i++){
			if(((1 << i) & bitmask) == 0){
				std::max(generate(pos + 1, bitmask + (1 << i), i), (int) std::abs(vals[last] - vals[i]));
			}
		}
	}

	return salesman[pos][bitmask];
}
int main() {
	int n;
	std::cin >> n;

	vals.resize(n);
	salesman.resize(n + 1);
	for(int i = 0; i < n; i++){
		std::cin >> vals[i];
		salesman[i].resize((1 << n) + 1, 1000000);
	}

	std::cout << generate(1, 1, 0);
	return 0;
}
