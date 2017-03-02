#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1e3 + 2;
int mat[maxn][maxn];
bool seen[maxn][maxn][2][2];

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int v, e;
	cin >> v >> e;

	for(int i = 0; i < e; i++){
		int f, s;
		cin >> f >> s;
		f--, s--;

		mat[f][s] = mat[s][f] = true;
	}

	for(int j = 0; j < v; j++){
		for(int k = 0; k < v; k++){
			for(int l = 0; l < 2; l++){
				for(int m = 0; m < 2; m++){
					seen[j][k][l][m] = false;
					seen[2][k][l][m] = true;
				}
			}
		}
	}

	for(int size = 3; size <= v; size++){
		for(int i = 0; i < v; i++){
			int l = i, r = (i + size - 1) % v;
			int lnext = (i + 1) % v, rprev = (r + v - 1) % v;

			if(mat[l][lnext] and seen[size - 1][lnext][1][0]){
				seen[size][l][1][0] = true;
			}
			if(mat[r][rprev] and seen[size - 1][l][0][1]){
				seen[size][l][0][1] = true;
			}
			if(mat[l][rprev] and seen[size - 1][l][0][1]){
				seen[size][l][1][0] = true;
			}
			if(mat[lnext][r] and seen[size - 1][lnext][1][0]){
				seen[size][l][0][1] = true;
			}
		}
	}

	for(int i = 0; i < v; i++){
		int pos, k = 0, l = 0;
		int start;
		vector<int> in[v];
		if(mat[i][(i + 1) % v] and seen[v][(i + 1) % v][1][0]){
			pos = (i + 1) % v, k = 1, l = 0;
			in[i].push_back((i + 1) % v);
			in[(i + 1) % v].push_back(i);
			start = i;
		} else if(mat[(i + v - 1) % v][i] and seen[v][i][1][0]){
			pos = i, k = 1, l = 0;
			start = (i + v - 1) % v;
			in[i].push_back((i + v - 1) % v);
			in[(i + v - 1) % v].push_back(i);
		} else {
			continue;
		}

		for(int j = v; j >= 2; j--){
			int size = j;
			int cl = pos, cr = (pos + size - 1) % v;
			int lnext = (pos + 1) % v, rprev = (cr + v - 1) % v;

			if(mat[cl][lnext] and seen[size - 1][lnext][1][0] and k == 1){
				in[cl].push_back(lnext);
				in[lnext].push_back(cl);
				pos = lnext, k = 1, l = 0;
				continue;
			}
			if(mat[cr][rprev] and seen[size - 1][cl][0][1] and l == 1){
				in[cr].push_back(rprev);
				in[rprev].push_back(cr);
				pos = cl, k = 0, l = 1;
				continue;
			}
			if(mat[cl][rprev] and seen[size - 1][cl][0][1] and k == 1){
				in[cl].push_back(rprev);
				in[rprev].push_back(cl);
				pos = cl, k = 0, l = 1;
				continue;
			}
			if(mat[lnext][cr] and seen[size - 1][lnext][1][0] and l == 1){
				in[lnext].push_back(cr);
				in[cr].push_back(lnext);
				pos = lnext, k = 1, l = 0;
				continue;
			}
		}
		pos = start;
		for(int j = 0; j < v; j++){
			cout << pos + 1 << endl;
			int nnext = in[pos][0];
			for(int k = 0; k < in[nnext].size(); k++){
				if(in[nnext][k] == pos){
					in[nnext].erase(in[nnext].begin() + k);
					break;
				}
			}
			pos = nnext;
		}
		return 0;
	}
	cout << -1;
}
