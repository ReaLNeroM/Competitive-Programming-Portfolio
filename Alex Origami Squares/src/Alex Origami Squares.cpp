//#define test true

#ifdef test
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("alex.in");
	std::ofstream fout("alex.out");
#endif

int main(){
	double x, y;
	fin >> x >> y;

	double res = 0;

	res = std::max(res, std::min(x / 3, y));

	res = std::max(res, std::min(y / 3, x));

	res = std::max(res, std::min(x / 2, y / 2));

	fout << res;

}
