#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;

	for(int test = 0; test < t; test++){
		int y, x;
		std::cin >> y >> x;

		char mat[y][x];

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				std::cin >> mat[i][j];
			}
		}

		int last_found = -1;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				if(mat[i][j] != '?'){
					last_found = i;
				}
			}

			if(last_found == i){
				int last_x = -1;
				for(int j = 0; j < x; j++){
					if(mat[i][j] == '?'){
						if(last_x == -1){

						} else {
							mat[i][j] = mat[i][last_x];
						}
					} else {
						last_x = j;
					}
				}

				last_x = -1;
				for(int j = x - 1; j >= 0; j--){
					if(mat[i][j] == '?'){
						if(last_x == -1){

						} else {
							mat[i][j] = mat[i][last_x];
						}
					} else {
						last_x = j;
					}
				}
			} else if(last_found != -1){
				for(int j = 0; j < x; j++){
					mat[i][j] = mat[last_found][j];
				}
			}
		}

		last_found = -1;
		for(int i = y - 1; i >= 0; i--){
			for(int j = 0; j < x; j++){
				if(mat[i][j] != '?'){
					last_found = i;
				}
			}

			if(last_found != i){
				for(int j = 0; j < x; j++){
					if(mat[i][j] == '?'){
						mat[i][j] = mat[last_found][j];
					}
				}
			}
		}

		std::cout << "Case #" << test + 1 << ": \n";
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				std::cout << mat[i][j];
			}
			std::cout << '\n';
		}
	}
}
