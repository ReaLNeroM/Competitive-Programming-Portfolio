#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
int val[4][maxn];
int n, cars;
int moves = 0;
std::vector<std::vector<int>> v;

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> cars;
	int a = 0, b = 0;

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < n; j++){
			std::cin >> val[i][j];
			if(i == 0 and val[i][j] != 0){
				a++;
			} else if(i == 3 and val[i][j] != 0){
				b++;
			}
		}
	}

	for(int i = 0; i < cars; i++){
		int curr_pos = 0;
		for(int j = 0; j < n; j++){
			if(val[1][j] != 0){
				if(curr_pos == j){
					curr_pos++;
					continue;
				}

				move(1, j, 1, curr_pos);
				curr_pos++;
			}
		}
		int a = curr_pos;

		curr_pos = n - 1;
		for(int j = n - 1; j >= 0; j--){
			if(val[2][j] != 0){
				val[2][curr_pos] = val[2][j];
				if(curr_pos != j){
					val[2][j] = 0;
				}
				curr_pos--;
			}
		}
		int b = curr_pos;


	}

	if(v.empty()){
		std::cout << -1 << '\n';
	} else {
		std::cout << moves << '\n';
		for(int i = 0; i < v.size(); i++){
			std::cout << v[i][0] << ' ' << v[i][1] << ' ' << v[i][2] << '\n';
		}
	}
}
