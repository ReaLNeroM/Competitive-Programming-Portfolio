#include <bits/stdc++.h>

typedef long long ll;

const ll maxn = 1e2 + 10;
const ll INF = 1000000000000000010;

int mat[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll testCases;
	std::cin >> testCases;

	for(ll testcase = 1; testcase <= testCases; testcase++){
		std::cout << "Case #" << testcase << ": ";

		int n;
		std::cin >> n;

		std::string in, out;

		std::cin >> in;
		std::cin >> out;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] = 0;
			}
			mat[i][i] = 3;
		}

		for(int i = 0; i < n; i++){
			if(in[i] == 'Y'){
				if(i - 1 >= 0){
					mat[i - 1][i] |= 1;
				}
				if(i + 1 < n){
					mat[i + 1][i] |= 1;
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(out[i] == 'Y'){
				if(i - 1 >= 0){
					mat[i][i - 1] |= 2;
				}
				if(i + 1 < n){
					mat[i][i + 1] |= 2;
				}
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] /= 3;
			}
		}

		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					mat[i][j] |= mat[i][k] & mat[k][j];
				}
			}
		}

		for(int i = 0; i < n; i++){
			std::cout << '\n';
			for(int j = 0; j < n;  j++){
				std::cout << (mat[i][j] ? 'Y' : 'N');
			}
		}

		std::cout << '\n';
	}
}