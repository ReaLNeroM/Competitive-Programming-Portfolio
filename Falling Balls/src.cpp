#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
int val[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		int n;
		std::cin >> n;

		for(int i = 0; i < n; i++){
			std::cin >> val[i];
		}

		bool possible = true;

		std::set<std::vector<int>> add;

		int left = 0;
		if(val[0] == 0 or val[n - 1] == 0){
			possible = false;
		}

		for(int i = 0; i < n and possible; i++){
			if(val[i] != 0){
				int gathered = 0;
				int r;

				for(r = left; r < n and gathered != val[i]; r++){
					gathered++;
				}

				if(gathered != val[i]){
					possible = false;
				}

				for(int j = left; j < i; j++){
					add.insert({i - j, j, 1});
				}
				for(int j = i + 1; j < r; j++){
					add.insert({j - i, j, 2});
				}

				left = r;
			}
		}

		std::cout << "Case #" << test << ": ";
		if(!possible){
			std::cout << "IMPOSSIBLE\n";
		} else {
			int rows = 0;
			for(auto ite = add.begin(); ite != add.end(); ite++){
				rows = std::max(rows, (*ite)[0]);
			}
			std::cout << rows + 1 << '\n';

			for(int i = rows; i >= 0; i--){
				for(int j = 0; j < n; j++){
					auto ite = add.find({i, j, 1});
					if(ite == add.end()){
						ite = add.find({i, j, 2});
					}

					if(ite == add.end()){
						std::cout << '.';
					} else if((*ite)[2] == 1){
						std::cout << '\\';
					} else if((*ite)[2] == 2){
						std::cout << '/';
					}
				}
				std::cout << '\n';
			}
		}
	}
}
