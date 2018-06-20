#include <bits/stdc++.h>

typedef long long ll;

int query(std::vector<int> &v){
	std::cout << "? " << v[0] << ' ' << v[1] << ' ' << v[2] << std::endl;

	int get;
	std::cin >> get;
	return get;
}

int main(){
	std::ios::sync_with_stdio(false);

	int n, m, k, q;
	std::cin >> n >> m >> k >> q;

	if(n > 1 and m > 1 and k > 1){
		std::srand(23523);

		std::vector<int> best = {0, 1, 1, 1};

		for(int i = 0; i < q / 2; i++){
			int a = rand() % n + 1;
			int b = rand() % m + 1;
			int c = rand() % k + 1;
			std::vector<int> curr_coords = {a, b, c};

			std::vector<int> curr = {query(curr_coords), a, b, c};

			best = std::max(best, curr);
		}

		for(int i = 5; i < q / 2; i += 6){
			for(int j = -1; j <= 1; j += 2){
				for(int l = 0; l < 3; l++){
					std::vector<int> curr_coords = {best[1], best[2], best[3]};
					curr_coords[l] += j;

					if(1 <= curr_coords[0] and curr_coords[0] <= n and 1 <= curr_coords[1] and curr_coords[1] <= m and 1 <= curr_coords[2] and curr_coords[2] <= k){
						std::vector<int> curr = {query(curr_coords), curr_coords[0], curr_coords[1], curr_coords[2]};

						best = std::max(best, curr);
					}
				}
			}
		}

		std::cout << "! " << best[1] << ' ' << best[2] << ' ' << best[3] << '\n';
	}
}