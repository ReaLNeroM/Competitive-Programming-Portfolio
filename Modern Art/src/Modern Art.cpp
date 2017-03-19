#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1005;
int mat[maxn][maxn];
int sum[maxn][maxn];
int yy1[maxn * maxn];
int y2[maxn * maxn];
int x1[maxn * maxn];
int x2[maxn * maxn];
bool allowed[maxn * maxn];
int first_found[maxn * maxn];

int main(){
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int n;
	cin >> n;

	for(int i = 0; i < n * n; i++){
		allowed[i] = true;
		first_found[i] = true;
		yy1[i] = n;
		y2[i] = -1;
		x1[i] = n;
		x2[i] = -1;
	}

	int col_found = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> mat[i][j];
			mat[i][j]--;
			if(mat[i][j] != -1){
				col_found += first_found[mat[i][j]];
				first_found[mat[i][j]] = false;
				yy1[mat[i][j]] = min(yy1[mat[i][j]], i);
				y2[mat[i][j]] = max(y2[mat[i][j]], i);
				x1[mat[i][j]] = min(x1[mat[i][j]], j);
				x2[mat[i][j]] = max(x2[mat[i][j]], j);
			}
		}
	}
	int res = 0;
	if(col_found == 1){
		res--;
	}

	for(int i = 0; i < n * n; i++){
		for(int j = yy1[i]; j <= y2[i]; j++){
			sum[j][x1[i]]++;
			sum[j][x2[i] + 1]--;
		}
	}

	for(int i = 0; i < n; i++){
		int running = 0;

		for(int j = 0; j < n; j++){
			running += sum[i][j];
			if(running >= 2 and mat[i][j] != -1){
				allowed[mat[i][j]] = false;
			}
		}
	}

	for(int i = 0; i < n * n; i++){
		if(allowed[i]){
			res += allowed[i];
		}
	}

	cout << res << endl;
}
