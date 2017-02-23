/*
ID: vlade.m1
PROG: frac1
LANG: C++
 */
#include <fstream>
#include <deque>
#include <algorithm>

std::ifstream fin("frac1.in");
std::ofstream fout("frac1.out");

struct frac{
	int num, dem;

	bool operator<(const frac &x) const{
		return (num * x.dem < dem * x.num);
	}
} copy;

int main() {
	int n;
	fin >> n;

	std::deque<frac> fractions;
	for(int i = 1; i <= n; i++){
		copy.dem = i;
		for(int j = 0; j <= i; j++){
			copy.num = j;
			fractions.push_back(copy);
		}
	}

	std::stable_sort(fractions.begin(), fractions.end());
	while(!fractions.empty()){
		fout << fractions.front().num << '/' << fractions.front().dem << std::endl;
		while(1 < fractions.size() and fractions[0].num * fractions[1].dem == fractions[1].num * fractions[0].dem){
			fractions.pop_front();
		}
		fractions.pop_front();
	}
	return 0;
}
