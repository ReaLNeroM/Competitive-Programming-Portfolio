#include <fstream>
#include <vector>
#include <queue>

#define mycomputer true

#ifdef mycomputer
#include <iostream>
#define fin std::cin
#define fout std::cout
#else
#include <fstream>
std::ifstream fin("superbull.in");
std::ofstream fout("superbull.out");
#endif

int main() {
	int teams;
	fin>> teams;

	int score[teams];
	bool used[teams][teams];
	for (int i = 0; i < teams; i++) {
		fin>> score[i];
		for(int j = 0; j < teams; j++){
			used[i][j] = false;
		}
	}

	long long res = 0;
	for (int i = 0; i < teams; i++) {
		int max = 0;
		int index = 0;
		for (int k = 0; k < teams; k++) {
			if(!used[k][i]){
				max = std::max(max, score[i] ^ score[k]);
				if(max < (score[i] ^ score[k])){
					max = score[i] ^ score[k];
					index = k;
				}
			}
		}

		res += max;
		used[index][i] = true;
	}

	fout << res << std::endl;
	return 0;
}
