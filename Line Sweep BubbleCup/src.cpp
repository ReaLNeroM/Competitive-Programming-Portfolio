#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 2005;
int block[maxn][maxn];
int sweep_length[maxn];
int real_length[maxn];
int y, x;
int res;

void propagate(int py, int px){
	for(int j = px - 1; j >= 0; j--){
		if(real_length[j] >= res and sweep_length[j] >= 1){
			sweep_length[j] = 0;
		} else {
			break;
		}
	}
	for(int j = px + 1; j < x; j++){
		if(real_length[j] >= res - 1 and !block[py][j] and sweep_length[j] >= 0){
			sweep_length[j] = -1;
		} else {
			break;
		}
	}
}

int main(){
	scanf("%d%d", &y, &x);

	int p;
	scanf("%d", &p);

	int py, px;
	for(int i = 0; i < p; i++){
		scanf("%d %d", &py, &px);

		block[py - 1][px - 1] = true;
	}

	res = y;

	for(int j = 0; j < x; j++){
		int run = 0;

		for(int i = 0; i <= y; i++){
			if(i == y or block[i][j]){
				if(run != 0){
					res = std::min(res, run);
				}

				run = 0;
			} else {
				run++;
			}
		}
	}

	int sweeps = 0;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(block[i][j]){
				sweep_length[j] = 0;
				real_length[j] = 0;
			} else {
				sweep_length[j]++;
				real_length[j]++;

				if(sweep_length[j] == res or (sweep_length[j] >= 1 and (i == y - 1 or block[i + 1][j]))){
					sweep_length[j] = 0;
					sweeps++;

					propagate(i, j);
				}
			}
		}
	}

	printf("%d\n%d\n", res, sweeps);
}