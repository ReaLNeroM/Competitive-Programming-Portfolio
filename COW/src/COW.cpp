//============================================================================
// Name        : COW.cpp
// Author      : Vladimir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <vector>

int main() {
	std::ifstream fin;
	std::ofstream fout;
	fin.open("cow.in");
	fout.open("cow.out");
	long long numbs;
	fin >> numbs;
	long long c = 0, o = 0, w = 0;

	for (long long i = 0; i < numbs; i++) {
		char ch;
		fin >> ch;

		if (ch == 'C') {
			c++;
		} else if (ch == 'O') {
			o += c;
		} else {
			w += o;
		}
	}

	fout << w << std::endl;
	return 0;
}
