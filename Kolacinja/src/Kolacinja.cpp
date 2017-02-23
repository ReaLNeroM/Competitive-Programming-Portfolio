#include <iostream>
#include <vector>
#include <cmath>

long long pieces;
long long ways[21][21];

long long get(long long left, long long placed){
	if(ways[left][placed] == -1){
		ways[left][placed] = 0;
		for(long long i = 1; i <= left and placed + i <= pieces; i++){
			for(long long j = 1; j <= placed + i; j++){
				ways[left][placed] += get(left - i, placed + i - j);
			}
		}
	}

	return ways[left][placed];
}

int main(){
	std::cin >> pieces;

	for(long long i = 0; i <= pieces; i++){
		for(long long j = 0; j <= pieces; j++){
			ways[i][j] = -1;
		}
	}

	ways[0][0] = 1;

	std::cout << get(pieces, 0);
	return 0;
}
