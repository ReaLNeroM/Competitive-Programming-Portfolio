/*
 ID: vlade.m1
 PROG: theme
 LANG: C++
*/

#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("theme.in");
	std::ofstream fout("theme.out");
#endif

#include <cmath>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	fin >> n;

	ll res = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			res += j - i;
		}
	}

	cout << res;
	return 0;
}
