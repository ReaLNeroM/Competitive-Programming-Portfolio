/*
ID: vlade.m1
PROG: crypt1
LANG: C++
 */

#include <fstream>
#include <vector>

std::vector<int> pos;

bool check(int num, int req){
	int i;
	do{
		for(i = 0; i < pos.size(); i++){
			if(pos[i] == num % 10){
				req--;
				break;
			}
		}
		if(i == pos.size()) return false;
		num /= 10;
	} while(num != 0);

	return (req == 0);
}
int main() {
	std::ifstream fin("crypt1.in");
	std::ofstream fout("crypt1.out");
	int num;
	fin >> num;


	pos.resize(num);
	for(int i = 0; i < num; i++){
		fin >> pos[i];
	}

	long long result = 0;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			for(int k = 0; k < num; k++){
				int copy = 100 * pos[i] + 10 * pos[j] + pos[k];
				for(int l = 0; l < num; l++){
					if(check(copy * pos[l], 3)){
						for(int m = 0; m < num; m++){
							if(check(copy * pos[m], 3) and check(copy * (pos[l] * 10 + pos[m]), 4)){
								result++;
							}
						}
					}
				}
			}
		}
	}

	fout << result << std::endl;

	return 0;
}
