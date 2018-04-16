#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3;
std::string mat[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int test_cases;
	std::cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++){
		int y, x, h, v;
		std::cin >> y >> x >> h >> v;

		bool good = true;

		int sum = 0;

		for(int i = 0; i < y; i++){
			std::cin >> mat[i];
			for(char j : mat[i]){
				sum += (j == '@');
			}
		}

		if(sum % ((h + 1) * (v + 1)) != 0){
			good = false;
		}

		int chips_each = sum / ((h + 1) * (v + 1));

		std::vector<int> hcut;
		std::vector<int> vcut;

		hcut.push_back(-1);
		vcut.push_back(-1);

		int running_count = 0;
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				running_count += (mat[i][j] == '@');
			}

			if(running_count == chips_each * (v + 1) and (hcut.size() < h + 1 or i == y - 1)){
				hcut.push_back(i);
				running_count = 0;
			}
		}

		running_count = 0;
		for(int j = 0; j < x; j++){
			for(int i = 0; i < y; i++){
				running_count += (mat[i][j] == '@');
			}

			if(running_count == chips_each * (h + 1) and (vcut.size() < v + 1 or j == x - 1)){
				vcut.push_back(j);
				running_count = 0;
			}
		}

		if(hcut.size() != h + 2){
			good = false;
		}
		if(vcut.size() != v + 2){
			good = false;
		}

		for(int i = 1; i <= h + 1; i++){
			for(int j = 1; j <= v + 1; j++){
				int current_sum = 0;

				for(int k = hcut[i - 1] + 1; k <= hcut[i]; k++){
					for(int l = vcut[j - 1] + 1; l <= vcut[j]; l++){
						current_sum += (mat[k][l] == '@');
					}
				}

				if(current_sum != chips_each){
					good = false;
				}
			}
		}

		std::cout << "Case #" << test_case << ": ";
		if(good){
			std::cout << "POSSIBLE";
		} else {
			std::cout << "IMPOSSIBLE";
		}
		std::cout << '\n';
	}
}
