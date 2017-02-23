#include <iostream>

typedef long long ll;

int main() {
	int n;
	std::cin >> n;

	int val[5], bestindex[5];
	for(int i = 0; i < n; i++){
		std::cin >> val[i];
		bestindex[i] = 1000000;
	}

	int bsize = 0;
	bestindex[0] = val[0];
	for(int i = 1; i < n; i++){
		if(bestindex[bsize] > val[i]){
			bsize++;
			bestindex[bsize] = val[i];
		}
		for(int j = 0; j < bsize; j++){
			if(bestindex[j] > val[i] and bestindex[j + 1] < val[i]){
				bestindex[j] = val[i];
			}
		}
	}

	std::cout << bsize + 1;
	return 0;
}
