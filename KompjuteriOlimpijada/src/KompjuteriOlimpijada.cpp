#include <iostream>

const int maxrooms = 101;
const int maxteachersset = 16385;
double res[maxrooms][maxteachersset];
int rooms, teachers;
int room[maxrooms], teacher[maxteachersset];

double TSP(int pos, int bitset){
	if(res[pos][bitset] == 100000000){
		for(int i = 0, bit = 1; i < teachers; i++, bit *= 2){
			if((bitset & bit) == 0){
				double time = (double) room[pos] / teacher[i];
				for(int j = pos; j < rooms and time - 0.000001 < res[pos][bitset]; j++, time += (double) room[j] / teacher[i]){
					res[pos][bitset] = std::min(res[pos][bitset], std::max(time, TSP(j + 1, bitset | bit)));
				}
			}
		}
	}

	return res[pos][bitset];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> rooms >> teachers;

	for(int i = 0; i < rooms; i++){
		for(int j = (1 << teachers) - 1; j >= 0; j--){
			res[i][j] = 100000000;
		}
	}
	for(int j = 0; j < (1 << teachers); j++){
		res[rooms][j] = 0;
	}

	for(int i = 0; i < rooms; i++){
		std::cin >> room[i];
	}

	for(int i = 0; i < teachers; i++){
		std::cin >> teacher[i];
	}

	std::cout << TSP(0, 0);
	return 0;
}
