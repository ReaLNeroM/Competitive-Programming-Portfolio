/*
ID: vlade.m1
PROG: wormhole
LANG: C++
 */

#include <fstream>

const int maxholes = 12;
int holes;
int next[maxholes], part[maxholes];

bool check(){
	for(int i = 0; i < holes; i++){
		int start = i;
		for(int j = 0; j < holes; j++){
			if(next[start] == -1){
				break;
			}
			start = part[next[start]];
		}

		if(next[start] != -1){
			return true;
		}
	}

	return false;
}

int solve(int pos = 0){
	int res = 0;
	if(pos == holes){
		res += check();
	}

	for(int i = pos / 2; i < holes; i++){
		if(part[i] == -1){
			for(int j = i + 1; j < holes; j++){
				if(part[j] == -1){
					part[i] = j, part[j] = i;
					res += solve(pos + 2);
					part[i] = part[j] = -1;
				}
			}
			break;
		}
	}

	return res;
}

int main() {
	std::ifstream fin("wormhole.in");
	std::ofstream fout("wormhole.out");
	fin >> holes;

	int wx[holes], wy[holes];
	for(int i = 0; i < holes; i++){
		fin >> wx[i] >> wy[i];
		next[i] = -1;
		part[i] = -1;
	}

	for(int i = 0; i < holes; i++){
		for(int j = 0; j < holes; j++){
			if(wy[i] == wy[j] and wx[j] > wx[i] and (next[i] == -1 or wx[j] < wx[next[i]])){
				next[i] = j;
			}
		}
	}

	fout << solve() << std::endl;
	return 0;
}
