/*
ID: vlade.m1
PROG: buylow
LANG: C++
*/

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("buylow.in");
	std::ofstream fout("buylow.out");
#endif

static char ways[5001][2000];
static int size[5001];

void equal(int a, int b){
	size[a] = size[b];
	for(int i = 0; i < size[a]; i++){
		ways[a][i] = ways[b][i];
	}
}

void add(int i, int j){
	int carry = 0, k;
	for(k = 0; k < size[j] or carry; k++){
		if(k >= size[i]){
			ways[i][k] = 0;
		}

		ways[i][k] += ways[j][k] + carry;
		if(k >= size[j]){
			ways[i][k] -= ways[j][k];
		}

		if(ways[i][k] >= 10){
			ways[i][k] -= 10;
			carry = 1;
		} else {
			carry = 0;
		}
	}

	size[i] = std::max(size[i], k);
}

int main() {
	int n;
	fin >> n;

	int val[n];
	int max[n];
	for (int i = 0; i < n; i++) {
		fin >> val[i];
		max[i] = 1;
		size[i] = 1;
		ways[i][0] = 1;
	}

	int maxval = 0;
	size[n] = 0;

	for (int j = n - 1; j >= 0; j--) {
		for (int i = j - 1; i >= 0; i--) {
			if (val[i] > val[j]) {
				if (max[i] < max[j] + 1) {
					max[i] = max[j] + 1;

					equal(i, j);
				} else if (max[i] == max[j] + 1) {
					add(i, j);
				}
			} else if(val[i] == val[j]){
				break;
			}
		}

		if (maxval < max[j]) {
			maxval = max[j];
			int i;
			for(i = 0; i < j; i++){
				if(val[i] == val[j]){
					break;
				}
			}

			if(i == j){
				equal(n, j);
			} else {
				size[n] = 0;
			}
		} else if (maxval == max[j]) {
			int i;
			for(i = 0; i < j; i++){
				if(val[i] == val[j]){
					break;
				}
			}

			if(i == j){
				add(n, j);
			}
		}
	}

	fout << maxval << ' ';
	for(int i = size[n] - 1; i >= 0; i--){
		fout << (char) ('0' + ways[n][i]);
	}
	fout << std::endl;
	return 0;
}
