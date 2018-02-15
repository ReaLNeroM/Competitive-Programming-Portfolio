#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e2 + 1e2;
int val[maxn][maxn];
int cop[maxn][maxn];
int n;

bool verify(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i != 0){
				if(cop[i - 1][j] >= cop[i][j]){
					return false;
				}
			}
			if(j != 0){
				if(cop[i][j - 1] >= cop[i][j]){
					return false;
				}
			}
		}
	}

	return true;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[i][j];
			cop[i][j] = val[i][j];
		}
	}

	for(int i = 0; i < 4; i++){
		if(verify()){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					std::cout << cop[i][j] << ' ';
				}
				std::cout << '\n';
			}
			return 0;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				val[i][j] = cop[i][j];
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cop[j][n - i - 1] = val[i][j];
			}
		}
	}

	std::cerr << "NOPE";
}