/*
ID: vlade.m1
PROG: frameup
LANG: C++
 */
#include <fstream>
#include <vector>

typedef long long ll;
using namespace std;

ifstream fin("frameup.in");
ofstream fout("frameup.out");

vector<int> adj[26];
bool dfsused[26];
int found = 0;

void dfs(char order[], int used){
	if(used == found){
		for(int j = 0; j < found; j++){
			fout << (char) ('A' + order[j]);
		}
		fout << endl;
	}

	for(int i = 0; i < 26; i++){
		if(!dfsused[i]){
			int j;
			for(j = 0; j < adj[i].size(); j++){
				if(!dfsused[adj[i][j]]){
					break;
				}
			}

			dfsused[i] = true;
			order[used] = i;

			if(j == adj[i].size()){
				dfs(order, used + 1);
			}

			dfsused[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);


	int y, x;
	fin >> y >> x;

	int used[26];
	int rxmin[26], rxmax[26], rymin[26], rymax[26];
	bool over[26][26];
	for(int i = 0; i < 26; i++){
		used[i] = false;
		rxmin[i] = x;
		rxmax[i] = 0;
		rymin[i] = y;
		rymax[i] = 0;
		for(int j = 0; j < 26; j++){
			over[i][j] = false;
		}
	}

	char mat[y][x];
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			fin >> mat[i][j];

			if(mat[i][j] != '.'){
				int v = mat[i][j] - 'A';

				if(!used[v]){
					found++;
				}
				used[v] = true;

				rymin[v] = min(rymin[v], i);
				rymax[v] = max(rymin[v], i);
				rxmin[v] = min(rxmin[v], j);
				rxmax[v] = max(rxmax[v], j);
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] != '.'){
				int v = mat[i][j] - 'A';
				for(int k = 0; k < 26; k++){
					if(used[k]){
						bool inrect = false;

						if(rxmin[k] <= j and j <= rxmax[k] and (i == rymin[k] or i == rymax[k])){
							inrect = true;
						}
						if(rymin[k] <= i and i <= rymax[k] and (j == rxmin[k] or j == rxmax[k])){
							inrect = true;
						}
						if(inrect){
							over[v][k] = true;
						}
					}
				}
			}
		}
	}

	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(i != j and over[i][j]){
				adj[i].push_back(j);
			}
		}
	}

	char order[26];
	for(int i = 0; i < 26; i++){
		dfsused[i] = !used[i];
		order[i] = -1;
	}

	dfs(order, 0);
	return 0;
}
