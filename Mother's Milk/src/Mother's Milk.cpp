/*
ID: vlade.m1
PROG: milk3
LANG: C++
 */

#include <fstream>
#include <vector>
#include <algorithm>

int c[3];
bool used[21];
std::vector<int> res;

bool sent[21][21];
void perm(std::vector<int> f){
	if(f[0] == 0 and !used[f[2]]){
		res.push_back(f[2]);
		used[f[2]] = true;
	}

	std::vector<int> y(3);
	int istureno;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			y = f;
			istureno = std::min(c[j] - y[j], y[i]);
			y[j] += istureno, y[i] -= istureno;
			if(!sent[y[1]][y[2]]){
				sent[y[1]][y[2]] = true;
				perm(y);
			}
		}
	}
}

int main() {
	std::ifstream fin("milk3.in");
	std::ofstream fout("milk3.out");
	for(int i = 0; i <= 20; i++){
		used[i] = false;
		for(int j = 0; j <= 20; j++){
			sent[i][j] = false;
		}
	}
	fin >> c[0] >> c[1] >> c[2];

	std::vector<int> f(3);
	f[0] = f[1] = 0;
	f[2] = c[2];
	perm(f);

	std::sort(res.begin(), res.end());
	for(int i = 0; i < res.size(); i++){
		fout << res[i];
		if(i != res.size() - 1){
			fout << " ";
		} else{
			fout << std::endl;
		}
	}
	return 0;
}
