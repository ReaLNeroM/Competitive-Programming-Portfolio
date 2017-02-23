//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("highcard.in");
	std::ofstream fout("highcard.out");
#endif

typedef long long ll;

int main() {
	int oppocards;
	fin >> oppocards;

	bool oppoused[oppocards * 2];
	for(int i = 0; i < oppocards * 2; i++){
		oppoused[i] = false;
	}

	for(int i = 0, inp; i < oppocards; i++){
		fin >> inp;

		oppoused[inp - 1] = true;
	}

	int oppowon = 0;
	for(int i = 0; i < oppocards * 2; i++){
		if(oppoused[i]){
			oppowon++;
		} else if(oppowon > 0){
			oppowon--;
		}
	}

	fout << oppocards - oppowon;
	return 0;
}
