#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 5005;
static bool exist[maxn][maxn];
std::vector<std::vector<int> > v;

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	for(int i = 1; i <= y; i++){
		for(int j = 1; j <= x; j++){
			exist[i][j] = false;
		}
	}

	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++){
		int a, b;
		std::cin >> a >> b;
		v.push_back({a, b});
	}

	std::sort(v.begin(), v.end());

	for(int i = 0; i < n; i++){
		exist[v[i][0]][v[i][1]] = true;
	}

	int res = 0;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int curr_ans = 2;
			int slope_y = v[j][0] - v[i][0];
			int slope_x = v[j][1] - v[i][1];
			int curr_y = v[j][0];
			int curr_x = v[j][1];

			int temp_y = v[i][0] - slope_y;
			int temp_x = v[i][1] - slope_x;

			if(1 <= temp_y and temp_y <= y and 1 <= temp_x and temp_x <= x){
				continue;
			}
			
			curr_y += slope_y;
			curr_x += slope_x;

			while(1 <= curr_y and curr_y <= y and 1 <= curr_x and curr_x <= x){
				if(!exist[curr_y][curr_x]){
					curr_ans = 0;
					break;
				} 

				curr_ans++;

				curr_y += slope_y;
				curr_x += slope_x;
			}

			res = std::max(res, curr_ans);
		}
	}

	if(res <= 2){
		res = 0;
	}

	std::cout << res << std::endl;
}