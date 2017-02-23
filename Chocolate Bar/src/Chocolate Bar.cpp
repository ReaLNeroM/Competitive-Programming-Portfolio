#include <iostream>

typedef long long ll;

int main(){
	int mat[31][31][51];
	for(int i = 1; i <= 30; i++){
		for(int j = 1; j <= 30; j++){
			for(int k = 1; k <= 50; k++){
				mat[i][j][k] = 100000000;

				if(i * j > k){
					for(int l = 1; l < i; l++){
						mat[i][j][k] = std::min(mat[i][j][k], l * l * j * j + alccamat[i - l][j][k]);
					}
					for(int l = 1; l < j; l++){
						mat[i][j][k] = std::min(mat[i][j][k], l * l * i * i + mat[i][j - l][k]);
					}
				} else if(i * j == k){
					mat[i][j][k] = 0;
				}
			}
		}
	}

	int cases;
	std::cin >> cases;
	for(int i = 0; i < cases; i++){
		int n, m, k;
		std::cin >> n >> m >> k;

		std::cout << mat[n][m][k] << std::endl;
	}
}
