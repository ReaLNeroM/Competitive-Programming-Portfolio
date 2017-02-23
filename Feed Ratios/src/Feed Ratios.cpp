/*
ID: vlade.m1
PROG: ratios
LANG: C++
 */

#include <fstream>

std::ifstream fin("ratios.in");
std::ofstream fout("ratios.out");

#define sum(x) i * f[0][x] + j * f[1][x] + k * f[2][x]

int main() {
	int goal[3], f[3][3];
	for(int i = 0; i < 3; i++){
		fin >> goal[i];
	}
	for(int feed = 0; feed < 3; feed++){
		for(int i = 0; i < 3; i++){
			fin >> f[feed][i];
		}
	}

	bool won = false, found;
	int win[] = {100, 100, 100}, winres = 100;

	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			for(int k = 0; k < 100; k++){
				found = true;

				int ratio = 0;

				if(goal[0] == 0){
					if(sum(0) > 0){
						found = false;
					}
				} else {
					if(sum(0) + sum(1) + sum(2) < goal[0] + goal[1] + goal[2]){
						found = false;
					}
					ratio = (sum(0)) / goal[0];
				}

				for(int check = 0; check <= 3; check++){
					if((sum(check)) != ratio * goal[check]){
						break;
					}

					if(check == 3){
						won = true;
						if(win[0] + win[1] + win[2] > i + j + k){
							win[0] = i, win[1] = j, win[2] = k, winres = ratio;
						}
					}
				}
			}
		}
	}

	if(won){
		fout << win[0] << " " << win[1] << " " << win[2] << " " << winres << std::endl;
	} else {
		fout << "NONE" << std::endl;
	}
	return 0;
}
