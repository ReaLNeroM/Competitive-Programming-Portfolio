//#define testing true

#ifdef testing
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("dream.in");
	std::ofstream fout("dream.out");
#endif
#include <queue>

typedef long long ll;
struct s { // state
	int y, x, d, sm;
};

s make(int a, int b, int c, int d) {
	s copy;
	copy.y = a;
	copy.x = b;
	copy.d = c;
	copy.sm = d;

	return copy;
}

int y, x;
bool withinboundaries(int py, int px){
	return (py >= 0 and py < y and px >= 0 and px < x);
}

int main() {
	fin >> y >> x;

	int used[y][x][4][2];
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < 4; k++) {
				for (int l = 0; l < 2; l++) {
					used[i][j][k][l] = y * x + 1;
				}
			}
		}
	}

	int mat[y][x];
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			fin >> mat[i][j];
			if(mat[i][j] == 0){
				for(int k = 0; k < 4; k++){
					for(int l = 0; l < 2; l++){
						used[i][j][k][l] = y * x + 2;
					}
				}
			} else if(mat[i][j] == 3){
				for(int k = 0; k < 4; k++){
					used[i][j][k][0] = y * x + 2;
				}
			}
		}
	}

	const int adderx[] = {1, -1, 0, 0};
	const int addery[] = {0, 0, 1, -1};
	std::queue<s> q;
	q.push(make(0, 0, 0, 0));
	used[0][0][0][0] = 0;
	while (!q.empty()) {
		s c = q.front();
		q.pop();

		s sc = c;
		bool smell = c.sm, pass = true;
		if(mat[c.y][c.x] == 4){
			smell = false;
			sc = c;
			sc.y += addery[sc.d];
			sc.x += adderx[sc.d];
			sc.sm = smell;
			if(withinboundaries(sc.y, sc.x) and (mat[sc.y][sc.x] == 1 or mat[sc.y][sc.x] == 2 or mat[sc.y][sc.x] == 4)){
				if(used[sc.y][sc.x][sc.d][sc.sm] == y * x + 1){
					used[sc.y][sc.x][sc.d][sc.sm] = used[c.y][c.x][c.d][c.sm] + 1;
					q.push(sc);
				}
				pass = false;
			}
		} else if(mat[c.y][c.x] == 2){
			smell = true;
		} else if(mat[c.y][c.x] == 3){
			if(!c.sm){
				pass = false;
			}
		}

		if(pass){
			for(int i = 0; i < 4; i++){
				sc = c;
				sc.x += adderx[i];
				sc.y += addery[i];
				sc.d = i;
				sc.sm = smell;

				if(withinboundaries(sc.y, sc.x) and used[sc.y][sc.x][sc.d][sc.sm] == y * x + 1){
					used[sc.y][sc.x][sc.d][sc.sm] = used[c.y][c.x][c.d][c.sm] + 1;
					q.push(sc);
				}
			}
		}
	}

	int min = y * x + 1;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 2; j++){
			min = std::min(min, used[y - 1][x - 1][i][j]);
		}
	}

	if(min <= y * x){
		fout << min;
	} else {
		fout << -1;
	}

	fout << std::endl;

	return 0;
}
