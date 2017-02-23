/*
ID: vlade.m1
PROG: sprime
LANG: C++
 */

#include <fstream>
#include <vector>
#include <cmath>

std::vector<int> res;

void dfs(int left, int num){
	if(left == 0){
		res.push_back(num);
		return;
	}

	bool good;
	int copy = num * 10, sqr;
	for(int i = 1; i <= 9; i += 2){
		if(i == 5) continue;
		good = true;
		copy += i;
		sqr = std::sqrt(copy);
		for(int j = 3; j <= sqr; j++){
			if(copy % j == 0){
				good = false;
				break;
			}
		}

		if(good){
			dfs(left - 1, copy);
		}
		copy -= i;
	}
}
int main() {
	std::ifstream fin("sprime.in");
	std::ofstream fout("sprime.out");
	int n;
	fin >> n;

	dfs(n - 1, 2);
	dfs(n - 1, 3);
	dfs(n - 1, 5);
	dfs(n - 1, 7);

	for(int i = 0; i < res.size(); i++){
		fout << res[i] << std::endl;
	}
	return 0;
}
