#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e6 + 1e2;
std::vector<std::vector<int>> val;
int found[maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		int ind;
		std::cin >> ind;
		found[ind]++;		
	}

	if(found[0] != 1){
		std::cout << -1 << '\n';
		return 0;
	}

	int biggest = 0;
	for(int i = 0; i < maxn; i++){
		if(found[i]){
			biggest = std::max(biggest, i);
			val.push_back({i, found[i]});
		}
	}

	for(int y = 1; y * y <= n; y++){
		if(n % y == 0){
			int x = n / y;

			bool valid = true;

			//y <= x

			int posy = -1, posx = -1;

			std::vector<int> jumps;

			int walls_limited = 0;
			int one_wall_limited_last = 0;

			int j;
			for(j = 1; j <= x and walls_limited < 4; j++){
				if(walls_limited == 0){
					if(found[j] < 4 * j){
						jumps.push_back(j);

						if(found[j] + 1 == 4 * j){
							one_wall_limited_last = 1;
							walls_limited = 1;
						} else if(found[j] + 2 == 4 * j){
							walls_limited = 2;
						} else if(((x % 2 == 1) or (y % 2 == 1)) and found[j] + 3 == 4 * j){
							walls_limited = 3;
						} else if(x == y and x % 2 == 1 and found[j] + 4 == 4 * j){
							walls_limited = 4;
						} else {
							valid = false;
						}
					}
				} else if(walls_limited == 1){
					if(found[j] + one_wall_limited_last + 2 == 4 * j){
						one_wall_limited_last += 2;
					} else if(found[j] + one_wall_limited_last + 2 + 1 == 4 * j){
						jumps.push_back(j);
						walls_limited = 2;
					} else if(found[j] + one_wall_limited_last + 2 + 2 == 4 * j){
						jumps.push_back(j);
						walls_limited = 3;
					} else if(found[j] + one_wall_limited_last + 2 + 3 == 4 * j){
						jumps.push_back(j);
						walls_limited = 4;
					} else {
						valid = false;
					}
				} else if(walls_limited == 2){
					if(found[j] == found[j - 1]){
						//alright
					} else if(found[j] + 1 == found[j - 1]){
						jumps.push_back(j);
						walls_limited = 3;
					} else if(found[j] + 2 == found[j - 1]){
						jumps.push_back(j);
						walls_limited = 4;
					} else {
						valid = false;
					}
				} else if(walls_limited == 3){
					if(found[j] + 1 == found[j - 1]){
						jumps.push_back(j);
						walls_limited = 4;
					} else {
						valid = false;
					}
				}
			}

			if(valid and posy >= 0 and posx >= 0){
				std::cout << y << ' ' << x << '\n';
				std::cout << posy + 1 << ' ' << posx + 1 << '\n';
				//do stuff
			}
		}
	}

}
