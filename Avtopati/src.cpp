#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1005;
int mat[maxn][maxn];
int sum[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int a, b, edges;
	scanf("%d %d %d", &a, &b, &edges);

	for(int i = 0; i < edges; i++){
		int f, s;
		scanf("%d %d", &f, &s);
		f--, s--;
		mat[f][s]++;
	}

	for(int i = a - 1; i >= 0; i--){
		int running_sum = 0;
		for(int j = b - 1; j >= 0; j--){
			running_sum += mat[i][j];
			sum[i][j] = running_sum + sum[i + 1][j];
		}
	}

	ll res = 0;
	for(int i = 0; i < a; i++){
		for(int j = 0; j < b; j++){
			if(mat[i][j]){
				res += sum[i + 1][0] - sum[i + 1][j];
			}
		}
	}

	std::cout << res;
}