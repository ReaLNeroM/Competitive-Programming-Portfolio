#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
char val[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[i][j];
			val[n + i][j] = val[i][n + j] = val[n + i][n + j] = val[i][j];
		}
	}

	int res = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != 0 and j != 0){
				continue;
			}

			int mistakes = 0;
			for(int k = 0; k < n; k++){
				for(int l = 0; l < k; l++){
					if(val[i + k][j + l] != val[i + l][j + k]){
						mistakes++;
					}
				}
			}

			for(int k = 0; i + k < n and j + k < n; k++){
				if(mistakes == 0){
					res++;
				}
				for(int l = 0; l < n; l++){
					if(val[i + k + l][j + k] != val[i + k][j + k + l]){
						mistakes--;
					}
				}
				for(int l = 0; l < n; l++){
					if(val[i + k + n - l][j + k + n] != val[i + k + n][j + k + n - l]){
						mistakes++;
					}
				}
			}
		}
	}

	std::cout << res << '\n';
}
