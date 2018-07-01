#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int foundv[maxn][3];
int foundh[maxn][3];
int val[maxn];
int n;
int res = 0;

void dfs(int y, int x){
	if(y == n){
		res++;
		return;
	}
	if(x == n){
		dfs(y + 1, 0);
		return;
	}

	for(int i = 0; i < 3; i++){
		foundv[y][i]++;
		foundh[x][i]++;
		if(foundv[y][i] != n and foundh[x][i] != n){
			dfs(y, x + 1);
		}
		foundv[y][i]--;
		foundh[x][i]--;
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	dfs(0, 0);

	int big = 1;
	for(int i = 0; i < n * n; i++){
		big *= 3;
	}

	std::cout << big - res << '\n';
}