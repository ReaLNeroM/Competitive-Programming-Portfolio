/*
ID: vlade.m1
PROG: humble
LANG: C++
 */

#include <set>

const long long maxint = 2147483648;

//#define test oinaweoifnaweo

#ifdef test
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("humble.in");
	std::ofstream fout("humble.out");
#endif

int main() {
	std::ios::sync_with_stdio(false);
	int primes, index;
	fin >> primes >> index;

	int p[primes];
	for(int i = 0; i < primes; i++){
		fin >> p[i];
	}

	std::set<int> humble;
	humble.insert(1);

	long long check;
	for(int i = 0; i < primes; i++){
		std::set<int>::iterator ite = humble.begin();
		while(ite != humble.end()){
			check = ((long long) (*ite)) * p[i];
			if(check < maxint and (humble.size() != index + 1 or (int) check < *(--humble.end()))){
				humble.insert((int) check);
				if(index + 1 < humble.size()){
					humble.erase(--humble.end());
				}
			} else {
				break;
			}
			ite++;
		}

	}

	fout << *(--humble.end()) << std::endl;
	return 0;
}
