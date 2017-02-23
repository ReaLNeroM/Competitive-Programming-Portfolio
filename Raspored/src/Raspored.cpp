#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> vals;
std::vector<std::vector<int> > salesman;

int generate(int bitmask, int last){
    if(salesman[last][bitmask] == -1){
    	int pos = __builtin_popcount(bitmask);
		if(pos == vals.size()){
			return (int) std::abs(vals[last] - vals[0]);
		}
        salesman[last][bitmask] = 1000000;

        for(int i = 0; i < vals.size(); i++){
            if(((1 << i) & bitmask) == 0){
                salesman[last][bitmask] = std::min(salesman[last][bitmask],
                        std::max(generate(bitmask + (1 << i), i), (int) std::abs(vals[last] - vals[i])));
            }
        }
    }

    return salesman[last][bitmask];
}
int main() {
    int n;
    std::cin >> n;

    vals.resize(n);
    salesman.resize(n);
    for(int i = 0; i < n; i++){
        std::cin >> vals[i];
		salesman[i].resize(1 << n, -1);
    }

    std::cout << generate(1, 0);
    return 0;
}
