//============================================================================
// Name        : Crosswords.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
using namespace std;
struct cell {
	char cont;
	bool used = false;
};
int main() {
	ifstream myf;
	myf.open("crosswords.in");
	int x, y;
	myf >> x >> y;

	cell mat[x][y];

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			myf >> mat[i][j].cont;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if ((j == 0 or mat[i][j - 1].cont == '#') and j + 2 < y) {
				if (mat[i][j].cont == '.' and mat[i][j + 1].cont == '.'
						and mat[i][j + 2].cont == '.') {
					mat[i][j].used = true;
				}
			}
			if ((i == 0 or mat[i - 1][j].cont == '#') and i + 2 < x) {
				if (mat[i][j].cont == '.' and mat[i + 1][j].cont == '.'
						and mat[i + 2][j].cont == '.') {
					mat[i][j].used = true;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mat[i][j].used) {
				result++;
			}
		}
	}
	ofstream mof;
	mof.open("crosswords.out");
	mof << result <<std::endl;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (mat[i][j].used) {
				mof << i + 1 << " " << j + 1 << std::endl;
			}
		}
	}

	return 0;
}
