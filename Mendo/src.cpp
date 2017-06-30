#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;

std::vector<std::string> v;
int col[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	// for(int i = 0; i < (1 << n); i++){
	// 	std::string s = "";
	// 	for(int j = 0; j < n; j++){
	// 		if(i & (1 << j)){
	// 			s += '1';
	// 		} else {
	// 			s += '0';
	// 		}
	// 	}
	// 	v.push_back(s);
	// }

	std::vector<int> res;
	for(int i = 0; i < (1 << n); i++){
		int allow[n];

		for(int j = 0; j < n; j++){
			allow[j] = true;
		}

		for(int j = 1; j < (1 << n); j *= 2){
			for(int k = 1; k < j; k *= 2){
				if((i ^ j ^ k) < i){
					allow[col[i ^ j ^ k]] = false;
				}
			}
		}

		// if(i % 1024 == 0){
		// 	std::cout << i << std::endl;
		// }

		for(int j = 0; j <= n; j++){
			if(j == n){
				std::cout << "WTF" << std::endl;
				return 0;
			}
			if(allow[j]){
				col[i] = j;
				if(i % ((1 << n) / 4) == 0){
					std::cout << std::endl;
				}
				std::cout << j + 1 << ' ';
				// res.push_back(j + 1);
				break;
			}
		}
	}

	// for(int i = 0; i < res.size() / 4; i += res.size() / 8){
	// 	// if(i / (res.size() / 4) % 2 == 1){
	// 	// 	for(int j = i + res.size() / 4 - 1; j >= i; j--){
	// 	// 		std::cout << res[j] << ' ';
	// 	// 	}
	// 	// } else {
	// 		for(int j = i; j < i + res.size() / 8; j++){
	// 			std::cout << res[j] << ' ';
	// 		}
	// 	// }
	// 	std::cout << std::endl;
	// }
}