#include <bits/stdc++.h>

typedef long long ll;

const int maxn = 105;
char mat[maxn][maxn];
int ay[] = {1, -1, 0, 0};
int ax[] = {0, 0, 1, -1};
char id[] = {'D', 'U', 'R', 'L'};
bool used[maxn][maxn];
int par[maxn][maxn];

int main(){
	std::ios::sync_with_stdio(false);

	int y, x;
	std::cin >> y >> x;

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			std::cin >> mat[i][j];
		}
	}

	int py = 0, px = 0;

	if(x != 1 and mat[py][px + 1] == '.'){
		std::cout << 'R' << std::endl;
		int gety, getx;
		std::cin >> gety >> getx;
		gety--, getx--;

		if(gety == py and getx == px){
			std::swap(id[2], id[3]);
		} else {
			std::cout << 'L' << std::endl;
			std::cin >> gety >> getx;
			gety--, getx--;
		}

		for(int i = 0; i < x; i++){
			if(mat[0][i] == 'F'){
				for(int j = 0; j < i; j++){
					std::cout << id[2] << std::endl;
					std::cin >> py >> px;
					py--, px--;
				}
				return 0;
			} else if(mat[0][i] == '*'){
				break;
			} else if(y != 1 and mat[1][i] == '.'){
				for(int j = 0; j < i; j++){
					std::cout << id[2] << std::endl;
					std::cin >> py >> px;
					py--, px--;
				}
				break;
			}
		}

		std::cout << id[0] << std::endl;

		std::cin >> gety >> getx;
		gety--, getx--;

		if(gety == py and getx == px){
			std::swap(id[0], id[1]);
		} else {
			std::cout << 'U' << std::endl;
			std::cin >> gety >> getx;
			gety--, getx--;
		}

		py = gety, px = getx;
	} else {
		std::cout << 'D' << std::endl;
		int gety, getx;
		std::cin >> gety >> getx;
		gety--, getx--;
		
		if(gety == py and getx == px){
			std::swap(id[0], id[1]);
		} else {
			std::cout << 'U' << std::endl;
			std::cin >> gety >> getx;
			gety--, getx--;
		}

		for(int i = 0; i < y; i++){
			if(mat[i][0] == 'F'){
				for(int j = 0; j < i; j++){
					std::cout << id[0] << std::endl;
					std::cin >> py >> px;
					py--, px--;
				}
				return 0;
			} else if(mat[i][0] == '*'){
				break;
			} else if(x != 1 and mat[i][1] == '.'){
				for(int j = 0; j < i; j++){
					std::cout << id[0] << std::endl;
					std::cin >> py >> px;
					py--, px--;
				}
				break;
			}
		}

		std::cout << id[2] << std::endl;

		std::cin >> gety >> getx;
		gety--, getx--;

		if(gety == py and getx == px){
			std::swap(id[2], id[3]);
		} else {
			std::cout << 'L' << std::endl;
			std::cin >> gety >> getx;
			gety--, getx--;
		}

		py = gety, px = getx;
	}

	std::queue<int> qy, qx;
	qy.push(py), qx.push(px);
	used[py][px] = true;

	while(!qy.empty()){
		int fry = qy.front(), frx = qx.front();
		qy.pop(), qx.pop();

		for(int i = 0; i < 4; i++){
			int ny = fry + ay[i];
			int nx = frx + ax[i];

			if(0 <= ny and ny < y and 0 <= nx and nx < x and mat[ny][nx] != '*' and !used[ny][nx]){
				par[ny][nx] = i;
				used[ny][nx] = true;
				
				qy.push(ny), qx.push(nx);
			}
		}
	}

	int endy, endx;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] == 'F'){
				endy = i, endx = j;
			}
		}
	}

	std::vector<char> v;
	while(endy != py or endx != px){
		int get = par[endy][endx];
		v.push_back(id[get]);

		if(get == 0){
			endy -= 1;
		} else if(get == 1){
			endy += 1;
		} else if(get == 2){
			endx -= 1;
		} else if(get == 3){
			endx += 1;
		}
	}

	for(int i = v.size() - 1; i >= 0; i--){
		std::cout << v[i] << std::endl;
		std::cin >> py >> px;
	}
}