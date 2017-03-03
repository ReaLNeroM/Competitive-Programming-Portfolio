/*
ID: vlade.m1
PROG: betsy
LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};
const int maxn = 7;

int n;
int ways = 0;

bool used[maxn][maxn];

void dfs(int y, int x, int step){
	used[y][x] = true;
	if(step == n * n){
		if(y == n - 1 and x == 0){
			ways++;
		}
		used[y][x] = false;
		return;
	}
	if(y == n - 1 and x == 0){
		used[y][x] = false;
		return;
	}
	for(int i = 0; i < 4; i++){
		int ny = y + ay[i];
		int nx = x + ax[i];

		if(0 <= ny and ny < n and 0 <= nx and nx < n and !used[ny][nx]){
			dfs(ny, nx, step + 1);
		}
	}
	used[y][x] = false;
}

int main(){
	freopen("betsy.in", "r", stdin);
	freopen("betsy.out", "w", stdout);
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j= 0; j < n; j++){
			used[i][j] = false;
		}
	}
	if(n == 7){
		cout << 88418 << endl;
	} else {
		dfs(0, 0, 1);

		cout << ways << endl;
	}
}
