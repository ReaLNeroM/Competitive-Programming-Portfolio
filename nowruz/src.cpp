#include <bits/stdc++.h>

typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};
const int ATTEMPTS_PER_TEST_CASE = 100;
const int maxn = 1e3 + 1e2;

int y, x, best_value;
std::string s[maxn];
int tag[maxn][maxn];

bool cycle(int py, int px){
	int count = 0;

	for(int k = 0; k < 4; k++){
		int ny = py + ay[k];
		int nx = px + ax[k];

		if(0 <= ny and ny < y and 0 <= nx and nx < x and tag[ny][nx] == 2){
			count++;
		}
	}

	return count >= 2;
}

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> y >> x >> best_value;

	for(int i = 0; i < y; i++){
		std::cin >> s[i];
	}

	std::vector<int> best = {-1, 0, 0};
	for(int attempt = 0; attempt <= ATTEMPTS_PER_TEST_CASE; attempt++){
		int r_y = rand() % y;
		int r_x = rand() % x;

		std::cerr << (double) best[0] * 100.0 / best_value << ' ' << attempt << '\n';

		if(attempt == ATTEMPTS_PER_TEST_CASE){
			r_y = best[1];
			r_x = best[2];
		}

		std::vector<int> result_v = {0, r_y, r_x};

		if(!used[r_y][r_x] and s[r_y][r_x] == '.'){
			used[r_y][r_x] = true;

			memset(tag, false, sizeof(tag));

			std::queue<int> qy, qx;
			qy.push(r_y);
			qx.push(r_x);
			tag[r_y][r_x] = 2;

			while(!qy.empty()){
				int fry = qy.front();
				int frx = qx.front();
				qy.pop();
				qx.pop();

				std::vector<int> next_y, next_x;

				for(int k = 0; k < 4; k++){
					int ny = fry + ay[k];
					int nx = frx + ax[k];

					if(0 <= ny and ny < y and 0 <= nx and nx < x and
							s[ny][nx] == '.' and !tag[ny][nx] and !cycle(ny, nx)){
						tag[ny][nx] = true;

						next_y.push_back(ny);
						next_x.push_back(nx);
					}
				}

				if(next_y.size() <= 0 and !cycle(fry, frx)){
					result_v[0]++;
				} else {
					for(int i = 0; i < next_y.size(); i++){
						qy.push(next_y[i]);
						qx.push(next_x[i]);
						tag[next_y[i]][next_x[i]] = 2;
					}
				}
			}

		}

		best = std::max(best, result_v);
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(s[i][j] == '#'){
				std::cout << '#';
			} else if(tag[i][j] == 2){
				std::cout << '.';
			} else {
				std::cout << 'X';
			}
		}

		std::cout << '\n';
	}
	std::cout << '\n';
}
