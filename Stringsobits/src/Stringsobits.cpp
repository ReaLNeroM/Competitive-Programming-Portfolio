/*
ID: vlade.m1
PROG: kimbits
LANG: C++
 */
#include <fstream>

std::ifstream fin("kimbits.in");
std::ofstream fout("kimbits.out");

int main() {
	unsigned int length, ones, position;
	fin >> length >> ones >> position;

	unsigned int ways[length + 1][ones + 1];

	for(unsigned int i = 0; i <= ones; i++){
		ways[0][i] = 1;
	}
	for(unsigned int i = 0; i <= length; i++){
		ways[i][0] = 1;
	}

	for(unsigned int i = 1; i <= ones; i++){
		for(unsigned int j = 1; j <= length; j++){
			ways[j][i] = ways[j - 1][i - 1] + ways[j - 1][i];
		}
	}

/*	for(unsigned int i = 0; i <= ones; i++){
		for(unsigned int j = 0; j <= length; j++){
			fout << ways[j][i] << " ";
		}

		fout << std::endl;
	}*/

	for(unsigned int i = length, height = ones; i > 0; i--){
		if(ways[i - 1][height] < position){
			fout << '1';
			position -= ways[i - 1][height];
			height--;
		} else {
			fout << '0';
		}
	}

	fout << std::endl;
	return 0;
}
