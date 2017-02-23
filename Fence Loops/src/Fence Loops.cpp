/*
ID: vlade.m1
PROG: fence6
LANG: C++
 */

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("fence6.in");
	std::ofstream fout("fence6.out");
#endif

#include <vector>

using namespace std;
typedef long long ll;

int edges;
int l[100], ind[100];
vector<int> v[100][2];
int dist[100];

void dfs(int pos, int forbi, int distx){
	if(distx >= dist[pos] or pos == forbi){
		return;
	}
	dist[pos] = distx;

	for(int i = 0; i < v[pos][0].size(); i++){
		dfs(v[pos][0][i], forbi, distx + l[v[pos][0][i]]);
	}
	for(int i = 0; i < v[pos][1].size(); i++){
		dfs(v[pos][1][i], forbi, distx + l[v[pos][1][i]]);
	}
}

int main() {
	fin >> edges;

	for(int i = 0; i < edges; i++){
		fin >> ind[i];
		ind[i]--;

		fin >> l[ind[i]];

		int size[2];
		fin >> size[0] >> size[1];

		for(int k = 0; k < 2; k++){
			v[ind[i]][k].resize(size[k]);
			for(int j = 0; j < size[k]; j++){
				fin >> v[ind[i]][k][j];
				v[ind[i]][k][j]--;
			}
		}
	}

	int minl = 1000000;
	for(int i = 0; i < edges; i++){
		for(int j = 0; j < edges; j++){
			dist[j] = 1000000;
		}

		for(int j = 0; j < v[i][0].size(); j++){
			dfs(v[i][0][j], i, l[v[i][0][j]]);
		}

		for(int k = 0; k < v[i][1].size(); k++){
			minl = min(minl, dist[v[i][1][k]] + l[i]);
		}
	}

	fout << minl << endl;
	return 0;
}
