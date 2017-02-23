/*
 ID: vlade.m1
 PROG: shuttle
 LANG: C++
*/

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("shuttle.in");
	std::ofstream fout("shuttle.out");
#endif

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int n;
	fin >> n;

	int l = n + 1, r = n + 1;
	int increasing = 2;
	int change = 1;
	int printed = 0;

	while(l <= r){
		l -= change;
		r += change;

		if(l <= 0 or r >= 2 * n + 2){
			change *= -1;

			l -= 2 * change;
			r += 2 * change;
		}

		if(increasing == 2){
			for(int i = l; i <= r; i += increasing){
				fout << i;
				printed++;
				if(printed % 20 == 0 or l == r){
					fout << endl;
				} else {
					fout << ' ';
				}
			}
		} else {
			for(int i = r; i >= l; i += increasing){
				fout << i;
				printed++;
				if(printed % 20 == 0 or l == r){
					fout << endl;
				} else {
					fout << ' ';
				}
			}
		}

		increasing *= -1;
	}
	return 0;
}
