#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 1e3 + 1e2;
std::string s[maxn];
int pref[maxn][maxn];
int found[maxn][maxn];
int table[maxn][maxn][2];

int sub_query(int y1, int y2, int x1, int x2){
	return pref[y2][x2] - pref[y2][x1 - 1] - pref[y1 - 1][x2] + pref[y1 - 1][x1 - 1];
}

int query(int i, int j, int dist){
	return sub_query(i, i, j - dist, j + dist) + sub_query(i - dist, i + dist, j, j);
}

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	for(int i = 0; i < y; i++){
		std::cin >> s[i];
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			if(s[i - 1][j - 1] == '.'){
				pref[i][j]++;
			}

			pref[i][j] += pref[i - 1][j];
			pref[i][j] += pref[i][j - 1];
			pref[i][j] -= pref[i - 1][j - 1];
		}
	}

	std::vector<std::vector<int>> res;
	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			if(s[i - 1][j - 1] != '*'){
				continue;
			}
			int l = 1, r = std::min(std::min(i - 1, j - 1), std::min(y - i, x - j));
			int best = -1;

			while(l <= r){
				int mid = (l + r) / 2;

				if(query(i, j, mid) == 0){
					l = mid + 1;
					best = mid;
				} else {
					r = mid - 1;
				}
			}

			if(best != -1){
				res.push_back({i, j, best});
				table[i - best][j][0]++;
				table[i + best + 1][j][0]--;
				table[i][j - best][1]++;
				table[i][j + best + 1][1]--;
			}
		}
	}

	bool good = true;
	for(int i = 1; i <= y; i++){
		int sum = 0;

		for(int j = 1; j <= x; j++){
			sum += table[i][j][1];

			found[i][j] = sum;
		}
	}

	for(int j = 1; j <= x; j++){
		int sum = 0;

		for(int i = 1; i <= y; i++){
			sum += table[i][j][0];

			found[i][j] = std::max(found[i][j], sum);
		}
	}

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			if(!found[i][j] and s[i - 1][j - 1] == '*'){
				good = false;
				i = y, j = x;
			}
		}
	}

	if(!good){
		std::cout << -1 << '\n';
		return 0;
	}

	std::cout << res.size() << '\n';;

	for(auto i : res){
		std::cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';
	}
}