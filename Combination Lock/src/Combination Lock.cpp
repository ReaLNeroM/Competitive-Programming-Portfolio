/*
ID: vlade.m1
PROG: combo
LANG: C++
 */
#include <fstream>
#include <cmath>

int main() {
	std::ifstream fin;
	std::ofstream fout;
	fin.open("combo.in");
	fout.open("combo.out");
	int rotates;
	fin >> rotates;

	int lock[2][3];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			fin >> lock[i][j];
			lock[i][j]--;
		}
	}

	long long result = 0;
	for(int i = 0; i < rotates; i++){
		for(int j = 0; j < rotates; j++){
			for(int k = 0; k < rotates; k++){
				for(int l = 0; l < 2; l++){
					if((std::abs(lock[l][0] - i) <= 2 or std::abs(lock[l][0] - i + rotates) <= 2 or std::abs(lock[l][0] - i - rotates) <= 2) and (std::abs(lock[l][1] - j) <= 2 or std::abs(lock[l][1] - j + rotates) <= 2 or std::abs(lock[l][1] - j - rotates) <= 2) and (std::abs(lock[l][2] - k) <= 2 or std::abs(lock[l][2] - k + rotates) <= 2 or std::abs(lock[l][2] - k - rotates) <= 2)){
						result++;
						break;
					}
				}
			}
		}
	}

	fout << result << std::endl;

	return 0;
}
