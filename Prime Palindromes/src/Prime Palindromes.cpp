/*
ID: vlade.m1
PROG: pprime
LANG: C++
*/

#include <fstream>
#include <cmath>

std::ifstream fin("pprime.in");
std::ofstream fout("pprime.out");
int a, b;

void isprime(int num){
	for(int i = 2; i * i <= num; i++){
		if(num % i == 0){
			return;
		}
	}

	fout << num << std::endl;
}

void perm(int level, int small, int num){
	if(small > level){
		if(num >= a and num <= b){
			isprime(num);
		}
		return;
	}
	int ite = std::pow(10, level - 1) + (level != small) * std::pow(10, small - 1);
	for(int i = (small == 1); i < 10; i += 1 + (small == 1)){
		num += ite * i;
		perm(level - 1, small + 1, num);
		num -= ite * i;
	}
}

int main() {
	fin >> a >> b;

	int num = 0;
	for(int i = 1; i <= 8; i++){
		perm(i, 1, num);
	}
	return 0;
}
