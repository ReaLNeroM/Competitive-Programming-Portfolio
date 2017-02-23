/*
ID: vlade.m1
PROG: stall4
LANG: C++
 */

//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("stall4.in");
	std::ofstream fout("stall4.out");
#endif

typedef long long ll;

int main() {
	int cows, stalls;
	fin >> cows >> stalls;

	bool milkable[cows][stalls], usedcow[cows], usedstall[stalls];
	for(int i = 0; i < cows; i++){
		usedcow[i] = false;
	}
	for(int i = 0; i < stalls; i++){
		usedstall[i] = false;
	}

	for(int i = 0; i < cows; i++){
		for(int j = 0; j < stalls; j++){
			milkable[i][j] = false;
		}

		int goodstalls;
		fin >> goodstalls;
		for(int j = 0, inp; j < goodstalls; j++){
			fin >> inp;
			milkable[i][inp - 1] = true;
		}
	}

	int res = 0;
	for(int i = 0; i < std::min(cows, stalls); i++){
		int bestcow = -1, beststall = -1;

		for(int k = 0; k < stalls; k++){
			if(beststall >= 0){
				break;
			}

			beststall = -1;
			for(int j = 0; j < cows; j++){
				if(!usedcow[j] and !usedstall[k]){
					if(milkable[j][k] and beststall == -1){
						beststall = k;
						bestcow = j;
					} else if(milkable[j][k]) {
						beststall = -2;
					}
				}
			}
		}

		if(beststall >= 0){
			usedcow[bestcow] = true;
			usedstall[beststall] = true;
			res++;
			continue;
		}

		beststall = -1,	bestcow = -1;

		for(int j = 0; j < cows; j++){
			if(bestcow >= 0){
				break;
			}

			bestcow = -1;
			for(int k = 0; k < stalls; k++){
				if(!usedcow[j] and !usedstall[k]){
					if(milkable[j][k] and bestcow == -1){
						bestcow = j;
						beststall = k;
					} else if(milkable[j][k]){
						bestcow = -2;
					}
				}
			}
		}

		if(bestcow >= 0){
			usedcow[bestcow] = true;
			usedstall[beststall] = true;
			res++;
			continue;
		}

		int cowrank = stalls, copycowrank, copystall;
		for(int j = 0; j < cows; j++){
			copycowrank = 0;
			copystall = -1;

			for(int k = 0; k < stalls; k++){
				if(!usedcow[j] and !usedstall[k] and milkable[j][k]){
					copycowrank++;
					if(copystall == -1){
						copystall = k;
					}
				}
			}

			if(copystall != -1 and copycowrank < cowrank){
				bestcow = j;
				beststall = copystall;
				cowrank = copycowrank;
			}
		}

		if(bestcow >= 0){
			usedcow[bestcow] = true;
			usedstall[beststall] = true;
			res++;
		}
	}

	fout << res << std::endl;
	return 0;
}
