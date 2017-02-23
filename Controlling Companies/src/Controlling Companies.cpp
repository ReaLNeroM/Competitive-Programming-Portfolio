/*
ID: vlade.m1
PROG: concom
LANG: C++
 */
#include <fstream>
#include <vector>
#include <algorithm>

std::ifstream fin("concom.in");
std::ofstream fout("concom.out");

struct edge{
	int first, second, percent;

	bool operator<(const edge &x) const {
		if(first == x.first){
			return (second < x.second);
		}

		return (first < x.first);
	}
} copy;

std::vector<edge> e;
std::vector<int> usede, usedv;

void dfs(int pos){
	if(usedv[pos] > 50){
		usedv[pos] = -1;

		for(int i = 0; i < e.size(); i++){
			if(!usede[i] and e[i].first == pos and usedv[e[i].second] != -1){
				usedv[e[i].second] += e[i].percent;
				usede[i] = true;
				dfs(e[i].second);
			}
		}
	}
}

int main() {
	int n;
	fin >> n;

	e.resize(n);
	for(int i = 0; i < n; i++){
		fin >> e[i].first >> e[i].second >> e[i].percent;
	}

	usedv.resize(101), usede.resize(n);
	for(int i = 0; i <= 100; i++){
		for(int j = 0; j <= 100; j++){
			usedv[j] = 0;
		}
		for(int j = 0; j < n; j++){
			usede[j] = false;
		}
		usedv[i] = 100;
		dfs(i);

		usedv[i] = 100;
		for(int j = 0; j <= 100; j++){
			if(usedv[j] == -1){
				fout << i << " " << j << std::endl;
			}
		}
	}

	return 0;
}
