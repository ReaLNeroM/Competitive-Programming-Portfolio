//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("bcount.in");
	std::ofstream fout("bcount.out");
#endif

typedef long long ll;

int main() {
	int n, queries;
	fin >> n >> queries;

	int val[n + 1][3];
	val[0][0] = val[0][1] = val[0][2] = 0;
	for(int i = 1; i <= n; i++){
		int inp;
		fin >> inp;
		inp--;

		val[i][0] = val[i - 1][0];
		val[i][1] = val[i - 1][1];
		val[i][2] = val[i - 1][2];

		val[i][inp]++;
	}

	for(int i = 0; i < queries; i++){
		int a, b;
		fin >> a >> b;
		for(int j = 0; j < 3; j++){
			fout << val[b][j] - val[a - 1][j];
			if(j != 2){
				fout << ' ';
			} else {
				fout << std::endl;
			}
		}
	}
	return 0;
}
