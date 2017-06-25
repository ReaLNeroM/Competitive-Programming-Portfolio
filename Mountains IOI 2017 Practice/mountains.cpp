#include "mountains.h"
#include <vector>

int maximum_deevs(std::vector<int> y) {
	int res = 0;
	for(int i = 0; i < y.size(); i++){
		if((i == 0 or y[i - 1] >= y[i]) and (i == y.size() - 1 or y[i] <= y[i + 1])){
			res++;
			while(i < y.size() - 1 and y[i] == y[i + 1]){
				i++;
			}
		}
	}

	return res;
}
