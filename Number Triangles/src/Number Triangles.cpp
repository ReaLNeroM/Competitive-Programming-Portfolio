/*
ID: vlade.m1
PROG: numtri
LANG: C++
 */

#include <fstream>
#include <cmath>

int main() {
	std::ifstream fin("numtri.in");
	std::ofstream fout("numtri.out");
	int size;
	fin >> size;

	int grid[size][size + 1];
	for(int i = 0; i < size; i++){
		for(int j = 0; j <= i; j++){
			fin >> grid[i][j];
			if(i != 0){
				if(j == 0){
					grid[i][j] += grid[i - 1][j];
				} else if(j == i){
					grid[i][j] += grid[i - 1][j - 1];
				} else{
					grid[i][j] += std::max(grid[i - 1][j - 1], grid[i - 1][j]);
				}
			}
		}
	}

	int max = 0;
	for(int i = 0; i < size; i++){
		max = std::max(max, grid[size - 1][i]);
	}

	fout << max << std::endl;
	return 0;
}
