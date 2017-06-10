#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 405;
const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};
int on[maxn][maxn];
int costv[maxn][maxn];
int costh[maxn][maxn];
int res;
int curry[maxn * maxn];
int currx[maxn * maxn];
int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> on[i][j];
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j <= x; j++){
			std::cin >> costv[i][j];
		}
	}

	for(int i = 0; i <= y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> costh[i][j];
		}
	}

	res = 0;
	for(int i = 0; i < y; i++){
		res += costv[i][0] + costv[i][x];
	}
	for(int i = 0; i < x; i++){
		res += costh[0][i] + costh[y][i];
	}

	std::cout << res << std::endl;
}