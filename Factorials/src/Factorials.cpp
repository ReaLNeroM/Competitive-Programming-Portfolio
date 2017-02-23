/*
ID: vlade.m1
PROG: fact4
LANG: C++
 */

#include <fstream>

std::ifstream fin("fact4.in");
std::ofstream fout("fact4.out");

int main() {
	int n;
	fin >> n;

	int res = 1;
	int left2 = 0, left5 = 0;
	for(int mult = 5; mult <= n; mult *= 5){
		left2 += n / mult;
		left5 += n / mult;
	}
	left5 = left2;

	for(int i = 2; i <= n; i++){
		int mult = i;
		while(mult % 2 == 0 and left2 > 0){
			mult /= 2;
			left2--;
		}
		while(mult % 5 == 0 and left5 > 0){
			mult /= 5;
			left5--;
		}

		res *= mult;
		res %= 10;
	}

	fout << res << std::endl;
	return 0;
}
