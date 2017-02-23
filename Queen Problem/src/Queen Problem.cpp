#include <iostream>
#include <cmath>
#include <vector>

long long res = 0;
int n, goal;
std::vector<int> pos;

bool queens(int ord = 0){
	res++;
	if(ord == n){
		return true;
	}

	int i;
	for(i = 0; i < n; i++){
		bool good = true;
		for(int j = 0; j < ord; j++){
			if(i == pos[j] or ord - j == std::abs(i - pos[j])){
				good = false;
				break;
			}
		}
		if(good){
			pos[ord] = i;
			if(queens(ord + 1)){
				goal--;
				if(goal <= 0){`
					break;
				}
			}
			pos[ord] = -1;
		}
	}

	if(i == n){
		return false;
	}
}

int main() {
	std::cout << "vnesi go brojo na kralici: \n";
	std::cin >> n >> goal;

	pos.resize(n, -1);
	queens();

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cout << ((pos[i] == j) ? '@' : '#');
		}
		std::cout << std::endl;
	}
	std::cout << res;
}
