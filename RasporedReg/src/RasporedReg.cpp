//============================================================================
// Name        : RasporedReg.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>


int main() {
	int n;
	std::cin >> n;

	int groups = 0;
	std::vector<int> start(n);
	for(int i = 0, used[] = {0, 0, 0}; i < n; i++){
		std::cin >> start[i];
		if(!used[start[i] - 1]){
			groups++;
			used[start[i] - 1] = true;
		}
	}

	std::vector<int> copy;
	int misplaced, best = n;
	for(int remove = 1; remove <= 3; remove++){
		copy = start;
		misplaced = 0;
		if(groups == 3){
			for(int i = 0; i < copy.size(); i++){
				if(copy[i] == remove){
					copy.erase(copy.begin() + i);
					i--;
					misplaced++;
				}
			}
		}

		for(int i = 0; i < copy.size() - 1; i++){
			if(copy[i] == copy[i + 1]){
				misplaced++;
			}
		}

		best = std::min(best, misplaced);
	}

	std::cout << best;
}
