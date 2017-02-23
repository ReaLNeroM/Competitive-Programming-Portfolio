/*
ID: vlade.m1
PROG: subset
LANG: C++
 */
#include <fstream>

std::ifstream fin("subset.in");
std::ofstream fout("subset.out");

const long long maxn = 40;
long long n, to;
long long res[maxn + 1][maxn * (maxn + 1) / 2 + 1];

long long part(long long depth, long long sum = 0){
	if(depth == 0 or sum > to){
		return (sum == to);
	}

	if(res[depth][sum] == -1){
		res[depth][sum] = part(depth - 1, sum + depth) + part(depth - 1, sum);
	}

	return res[depth][sum];
}
int main() {
	fin >> n;

	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < (n * (n + 1) / 2); j++){
			res[i][j] = -1;
		}
	}

	if((n * (n + 1) / 2) % 2 == 0){
		to = (n * (n + 1) / 2) / 2;
		fout << part(n) / 2 << std::endl;
	} else{
		fout << 0 << std::endl;
	}
	return 0;
}
