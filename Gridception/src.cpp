#include <bits/stdc++.h>

typedef long long ll;

const int ay[] = {1, -1, 0, 0};
const int ax[] = {0, 0, 1, -1};
const int maxn = 25;
std::string s[maxn];
std::string s2[maxn];
bool used[maxn][maxn];
int y, x;

void switch_colors(){
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(s[i][j] == 'W'){
				s[i][j] = 'B';
			} else {
				s[i][j] = 'W';
			}
		}
	}
}

void rotate90(){
	for(int i = 0; i < x; i++){
		s2[i].clear();
		s2[i].resize(y);
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			s2[i][j] = s[y - 1 - j][i];
		}
	}
	for(int i = 0; i < x; i++){
		s[i] = s2[i];
	}
}

int main(){
	std::ios::sync_with_stdio(false);

	ll tests;
	std::cin >> tests;

	for(int test = 1; test <= tests; test++){
		std::cin >> y >> x;

		int size = 0;
		int black = 0;
		int white = 0;
		for(int i = 0; i < y; i++){
			std::cin >> s[i];
			for(int j = 0; j < s[i].size(); j++){
				if(s[i][j] == 'W'){
					white++;
				} else {
					black++;
				}
			}
		}

		size = std::max(white, black);
		for(int vv = 0; vv < 8; vv++){
			for(int i = 0; i < y - 1; i++){
				for(int j = 0; j < x - 1; j++){
					if(s[i][j] != 'W'){
						continue;
					}
					int try_size = 0;

					memset(used, 0, sizeof(used));
					std::queue<int> qy, qx;
					qy.push(i), qx.push(j);
					used[i][j] = true;

					while(!qy.empty()){
						int fry = qy.front(), frx = qx.front();
						qy.pop(), qx.pop();
						try_size++;

						for(int l = 0; l < 4; l++){
							int ny = fry + ay[l];
							int nx = frx + ax[l];

							if(0 <= ny and ny < y and 0 <= nx and nx < x and !used[ny][nx]){
								if(ny <= i and nx <= j){
									if(!used[ny][nx] and s[ny][nx] == 'W'){
										qy.push(ny), qx.push(nx);
										used[ny][nx] = true;
									}
								} else {
									if(!used[ny][nx] and s[ny][nx] == 'B'){
										qy.push(ny), qx.push(nx);
										used[ny][nx] = true;
									}
								}
							}
						}
					}

					size = std::max(size, try_size);
				}
			}

			switch_colors();

			if(vv % 2 == 1){
				rotate90();

				std::swap(y, x);
			}
		}

		std::cout << "Case #" << test << ": " << size << '\n';
	}
}
