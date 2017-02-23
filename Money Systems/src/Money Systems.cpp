/*
ID: vlade.m1
PROG: money
LANG: C++
 */
#include <fstream>

std::ifstream fin("money.in");
std::ofstream fout("money.out");

int main() {
	int coins, value;
	fin >> coins >> value;

	long long c[coins];
	for(int i = 0; i < coins; i++){
		fin >> c[i];
	}

	long long ways[value + 1][coins + 1];
	for(int i = 0; i <= coins; i++){
		ways[0][i] = 1;
	}
	for(int i = 1; i <= value; i++){
		ways[i][0] = 0;
	}

	for(int i = 1; i <= value; i++){
		for(int j = 1; j <= coins; j++){
			ways[i][j] = ways[i][j - 1];
			if(i >= c[j - 1]){
				ways[i][j] += ways[i - c[j - 1]][j];
			}
		}
	}

	fout << ways[value][coins] << std::endl;
	return 0;
}
