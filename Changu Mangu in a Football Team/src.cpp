#include <bits/stdc++.h>

typedef long long ll;

std::vector<int> v, wins;
std::vector<std::vector<int>> setting;
ll n = 5;

// ll counter = 0;

void dfs(int y, int x){
	if(y == n){
		bool good = true;
		// counter++;
		for(int i = 1; i < n; i++){
			if(v[i] <= v[0] or wins[0] <= wins[i]){
				good = false;
			}
		}

		// if(counter % 100000000LL == 0){
		// 	std::cout << counter << '\n';
		// 	std::cout.flush();
		// }

		if(good){
			for(int i = 0; i < n; i++){
				std::cout << v[i] << ' ' << wins[i] << "  ";
			}
			std::cout << '\n';
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					std::cout << setting[i][j] << ' ';
				}
				std::cout << '\n';
			}
			std::cout << '\n';
		}

		return;
	} else if(x == n){
		dfs(y + 1, 0);
		return;
	} else if(y == x){
		dfs(y, x + 1);
		return;
	}

	setting[y][x] = 1;
	v[y] += 3, wins[y]++;
	dfs(y, x + 1);
	v[y] -= 3, wins[y]--;

	setting[y][x] = 2;
	v[y]++, v[x]++;
	dfs(y, x + 1);
	v[y]--, v[x]--;

	// setting[y][x] = 3;
	// v[x] += 3, wins[x]++;
	// dfs(y, x + 1);
	// v[x] -= 3, wins[x]--;
}

int main(){
	std::ios::sync_with_stdio(false);

	int t = 1;
	// std::cin >> t;

	for(int test_case = 1; test_case <= t; test_case++){
		v.resize(n), wins.resize(n);
		setting.resize(n, std::vector<int>(n));

		dfs(0, 0);
	}
}