//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("cardgame.in");
	std::ofstream fout("cardgame.out");
#endif

	#include <algorithm>

typedef long long ll;

int main() {
	int n;
	fin >> n;

	int oppoused[2 * n];
	for(int i = 0; i < 2 * n; i++){
		oppoused[i] = false;
	}

	std::pair<int, int> a[n], b[n];
	for(int i = 0, inp; i < n; i++){
		fin >> inp;
		inp--;
		if(i >= n / 2){
			b[i - n / 2].first = inp;
			b[i - n / 2].second = 0;
		} else {
			a[i].first = inp;
			a[i].second = 0;
		}
		oppoused[inp] = true;
	}

	int asize = n / 2, bsize = n / 2;
	for(int i = 2 * n - 1; i >= 0; i--){
		if(!oppoused[i]){
			if(asize != n){
				a[asize].first = i;
				a[asize].second = 1;
				asize++;
			} else {
				b[bsize].first = i;
				b[bsize].second = 1;
				bsize++;
			}
		}
	}

	std::sort(a, a + n);
	std::sort(b, b + n);

	int oppowona = 0;
	for(int i = 0; i < n; i++){
		if(!a[i].second){
			oppowona++;
		} else if(oppowona > 0){
			oppowona--;
		}
	}

	int oppowonb = 0;
	for(int i = n - 1; i >= 0; i--){
		if(!b[i].second){
			oppowonb++;
		} else if(oppowonb > 0){
			oppowonb--;
		}
	}

	fout << n - (oppowona + oppowonb);
	return 0;
}
