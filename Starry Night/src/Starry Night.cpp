/*
 ID: vlade.m1
 PROG: starry
 LANG: C++
*/

#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("starry.in");
	std::ofstream fout("starry.out");
#endif

#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int x, y;
int sy, sx;
int found;
char mat[8][100][100];
vector<pair<int, int> > v[26 * 8 + 1];

const int addery[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int adderx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void find(int py, int px){
	mat[py][px] = 'x';
	v[found].push_back(make_pair(py - sy, px - sx));

	for(int i = 0; i < 8; i++){
		int ny = py + addery[i], nx = px + adderx[i];

		if(ny >= 0 and ny < y and nx >= 0 and nx < x and mat[ny][nx] == '1'){
			find(ny, nx);
		}
	}
}

bool equal(int a, int b){
	if(v[a].size() != v[b].size()){
		return false;
	}

	for(int i = 0; i < v[a].size(); i++){
		if(v[a][i] != v[b][i]){
			return false;
		}
	}

	return true;
}
int main() {
	ios::sync_with_stdio(false);

	fin >> x >> y;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			fin >> mat[i][j];
		}
	}
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){

		}
	}
	return 0;
}
