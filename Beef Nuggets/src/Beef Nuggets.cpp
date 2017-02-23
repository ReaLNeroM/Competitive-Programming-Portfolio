/*
ID: vlade.m1
PROG: nuggets
LANG: C++
 */

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("nuggets.in");
	std::ofstream fout("nuggets.out");
#endif

const int mult = 5000000;

int main() {
	int n, biggest = 0;

	fin >> n;
	int val[n];
	for(int i = 0; i < n; i++){
		fin >> val[i];
		biggest = std::max(biggest, val[i]);
	}

	bool possible[biggest + 2];
	possible[0] = true;

	int max = 0, consecutive = 0;
	for(int i = 1, access = 1; i < mult * n; i++, access++, consecutive++){
		if(access >= biggest + 2){
			access = 0;
		}
		if(consecutive == biggest + 1){
			break;
		}
		possible[access] = false;
		for(int j = 0; j < n; j++){
			if(i - val[j] >= 0){
				if(access - val[j] >= 0 and possible[access - val[j]]){
					possible[access] = true;
					break;
				} else if(access - val[j] < 0 and possible[biggest + 2 + access - val[j]]){
					possible[access] = true;
					break;
				}
			}
		}

		if(!possible[access]){
			consecutive = 0;
			max = std::max(max, i);
		}
	}

	if (consecutive != biggest + 1){
		max = 0;
	}

	fout << max << std::endl;

	return 0;
}
