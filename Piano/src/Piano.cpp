#include <iostream>
#include <queue>

typedef long long ll;

struct piano{
	int miny, maxy;
	int minx, maxx;
};

int width, height;
char mat[50][50];

bool collision(piano copy){
	if(copy.minx < 0 or copy.miny < 0 or copy.maxx >= width or copy.maxy >= height){
		return true;
	}

	for(int i = copy.miny; i <= copy.maxy; i++){
		for(int j = copy.minx; j <= copy.maxx; j++){
			if(mat[i][j] == '#'){
				return true;
			}
		}
	}

	return false;
}

int main() {
	std::cin >> width >> height;

	int steps[3][50][50];
	piano p[3];
	for(int i = 0; i < 3; i++){
		p[i].minx = width;
		p[i].maxx = 0;
		p[i].miny = height;
		p[i].maxy = 0;
	}

	int pianos = 0;
	int endx = -1, endy = -1;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			for(int step = 0; step < 3; step++){
				steps[step][i][j] = 10000000;
			}
			std::cin >> mat[i][j];
			if(mat[i][j] >= '1' and mat[i][j] <= '3'){
				p[mat[i][j] - '1'].minx = std::min(p[mat[i][j] - '1'].minx, j);
				p[mat[i][j] - '1'].maxx = std::max(p[mat[i][j] - '1'].maxx, j);
				p[mat[i][j] - '1'].miny = std::min(p[mat[i][j] - '1'].miny, i);
				p[mat[i][j] - '1'].maxy = std::max(p[mat[i][j] - '1'].maxy, i);
				pianos = std::max(pianos, mat[i][j] - '0');
			} else if(mat[i][j] == 'F' and endx == -1){
				endx = j, endy = i;
			}
		}
	}

	const int adderx[] = {1, -1, 0, 0};
	const int addery[] = {0, 0, 1, -1};

	int best = width * height, bestpiano = 0;
	for(int i = 0; i < pianos; i++){
		std::queue<piano> q;

		q.push(p[i]);
		steps[i][p[i].miny][p[i].minx] = 0;

		while(!q.empty()){
			for(int dir = 0; dir < 4; dir++){
				piano copy;
				copy.minx = q.front().minx + adderx[dir];
				copy.maxx = q.front().maxx + adderx[dir];
				copy.miny = q.front().miny + addery[dir];
				copy.maxy = q.front().maxy + addery[dir];
				if(!collision(copy) and steps[i][copy.miny][copy.minx] == 10000000){
					steps[i][copy.miny][copy.minx] = steps[i][q.front().miny][q.front().minx] + 1;
					q.push(copy);
				}
			}

			q.pop();
		}

		if(steps[i][endy][endx] < best){
			bestpiano = i + 1;
			best = steps[i][endy][endx];
		}
	}

	std::cout << bestpiano << std::endl << best;
	return 0;
}
