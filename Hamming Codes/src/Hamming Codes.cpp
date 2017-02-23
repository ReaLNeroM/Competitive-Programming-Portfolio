/*
ID: vlade.m1
PROG: hamming
LANG: C++
 */

#include <fstream>
#include <bitset>

std::ifstream fin("hamming.in");
std::ofstream fout("hamming.out");

const int mcodes = 64;
int codes, bits, dist, p2 = 1;
int c[mcodes];

bool dfs(int curr, int last = 0){
	if(curr == codes){
		return true;
	}

	for(int i = last; i < p2; i++){
		bool good = true;
		for(int j = 0; j < curr; j++){
			int check = i ^ c[j], diff = 0;
			while((check & (-check)) != 0){
				check -= check & (-check);
				diff++;
			}
			if(diff < dist){
				good = false;
				break;
			}
		}

		if(good){
			c[curr] = i;
			if(dfs(curr + 1, i + 1)){
				return true;
			}
			c[curr] = 0;
		}
	}

	return false;
}

int main() {
	fin >> codes >> bits >> dist;

	for(int i = 0; i < codes; i++){
		c[i] = 0;
	}
	for(int i = 0; i < bits; i++){
		p2 *= 2;
	}

	dfs(0);

	for(int i = 0; i < 7; i++){
		for(int j = 0; j < std::min((codes - i * 10), 10); j++){
			fout << c[i * 10 + j];
			if(j != std::min((codes - i * 10), 10) - 1){
				fout << " ";
			} else{
				fout << std::endl;
			}
		}
	}

	return 0;
}
