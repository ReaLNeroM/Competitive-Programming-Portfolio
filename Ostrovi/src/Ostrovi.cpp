#include <iostream>
#include <queue>

using namespace std;

int mat[54][54];
int islands = 0;
int iy[630], ix[630];
int level[630];
static int touch[630][630];
int fy, fx;
int py, px;
int sy, sx;

const int addery[] = {1, 1, 1, 0, -1, -1, -1, 0};
const int adderx[] = {-1, 0, 1, 1, 1, 0, -1, -1};

void mark(int y, int x, int num){
	mat[y][x] = num;

	for(int i = 0; i < 8; i++){
		int ny = y + addery[i];
		int nx = x + adderx[i];

		if(ny >= 0 and ny < fy and nx >= 0 and nx < fx and mat[ny][nx] == -2){
			mark(ny, nx, num);
		}
	}
}

int getlevel(int i, int cap){
	if(level[i] == -1){
		level[i] = 0;
		for(int j = 0; j < islands; j++){
			if(j != i and j != cap){
				if(touch[i][j] and !touch[j][cap]){
					level[i] = max(level[i], getlevel(j, i) + 1);
				}
			}
		}
	}

	return level[i];
}

int main() {
    std::cin >> py >> px;
    sy = 2;
    sx = 2;
    py += 2;
    px += 2;
    fy = py + 2;
    fx = px + 2;

    for(int i = 0; i < fx; i++){
    	mat[0][i] = -2;
    	mat[1][i] = -1;

    	mat[py][i] = -1;
    	mat[py + 1][i] = -2;
    }

    for(int i = 1; i < fy - 1; i++){
    	mat[i][0] = -2;
    	mat[i][1] = -1;

    	mat[i][px] = -1;
    	mat[i][px + 1] = -2;
    }

    for(int i = sy; i < py; i++){
    	for(int j = sx; j < px; j++){
    		char c;
    		cin >> c;
    		if(c == 'x'){
    			mat[i][j] = -2;
    		} else {
    			mat[i][j] = -1;
    		}
    	}
    }

    for(int i = 0; i < fy; i++){
    	for(int j = 0; j < fx; j++){
    		if(mat[i][j] == -2){
    			iy[islands] = i;
    			ix[islands] = j;
    			mark(i, j, islands);
    			islands++;
    		}
    	}
    }

	const int adjy[] = {1, -1, 0, 0};
	const int adjx[] = {0, 0, 1, -1};

    for(int i = 0; i < islands; i++){
    	level[i] = -1;

    	for(int j = 0; j < islands; j++){
    		touch[i][j] = false;
    	}

    	bool used[fy][fx];

    	for(int k = 0; k < fy; k++){
    		for(int l = 0; l < fx; l++){
    			used[k][l] = false;
    		}
    	}

    	queue<int> qy, qx;
    	qy.push(iy[i]), qx.push(ix[i]);
    	used[iy[i]][ix[i]] = true;

    	while(!qy.empty()){
    		int qpy = qy.front(), qpx = qx.front();
    		qy.pop(), qx.pop();

			if(mat[qpy][qpx] != i and mat[qpy][qpx] != -1){
				touch[i][mat[qpy][qpx]] = true;
			} else {
				for(int j = 0; j < 4; j++){
					int nqpy = qpy + adjy[j], nqpx = qpx + adjx[j];

					if(nqpy >= 0 and nqpy < fy and nqpx >= 0 and nqpx < fx and !used[nqpy][nqpx]){
						used[nqpy][nqpx] = true;
						qy.push(nqpy), qx.push(nqpx);
					}
				}
			}
    	}


    	touch[i][i] = false;
    }

    for(int i = 0; i < islands; i++){
    	if(touch[0][i]){
    		getlevel(i, 0);
    	}
    }

    int bylevel[630];
    for(int i = 0; i < islands; i++){
    	bylevel[i] = 0;
    }
    for(int i = 0; i < islands; i++){
    	bylevel[level[i]]++;
    }

    for(int i = 0; i < islands and bylevel[i] != 0; i++){
    	cout << bylevel[i] << endl;
    }
    return 0;
}
