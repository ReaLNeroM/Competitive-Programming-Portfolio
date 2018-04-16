#include <string>
#include <vector>
#include <queue>
#include <cstring>

class Minescape{
	int ay[4] = {1, -1, 0, 0};
	int ax[4] = {0, 0, 1, -1};

public:
	int escape(std::vector<std::string> maze){
		static int statex[20][20][59049];
		memset(statex, -1, sizeof(statex));

		int y = maze.size();
		int x = maze[0].size();
		int dynamite[y][x];

		int sy = 0, sx = 0;
		int ey = 0, ex = 0;

		int dynamite_found = 1;

		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				dynamite[i][j] = 0;

				if(maze[i][j] == 'S'){
					sy = i, sx = j;
				} else if(maze[i][j] == 'E'){
					ey = i, ex = j;
				} else if(maze[i][j] == '@'){
					dynamite[i][j] = dynamite_found;
					dynamite_found *= 3;
				}
			}
		}

		std::queue<int> qy, qx, qbit;
		statex[sy][sx][0] = 0;
		qy.push(sy), qx.push(sx), qbit.push(0);

		while(!qx.empty()){
			int fry = qy.front();
			int frx = qx.front();
			int frbit = qbit.front();
			qy.pop(), qx.pop(), qbit.pop();

			for(int i = 0; i < 4; i++){
				int ny = fry + ay[i];
				int nx = frx + ax[i];
				int nbit = frbit;

				if(0 <= ny and ny < y and 0 <= nx and nx < x){
					if(dynamite[ny][nx] != 0 and (frbit / dynamite[ny][nx]) % 3 == 0){
						nbit += dynamite[ny][nx];
					}

					if(maze[ny][nx] != '#' and statex[ny][nx][nbit] == -1){
						statex[ny][nx][nbit] = statex[fry][frx][frbit] + 1;
						qy.push(ny), qx.push(nx), qbit.push(nbit);
					}
				}
			}

			for(int i = 1; i <= dynamite_found; i *= 3){
				if((frbit / i) % 3 == 1){
					for(int j = 0; j < 4; j++){
						int ny = fry + ay[j];
						int nx = frx + ax[j];
						int nbit = frbit;
						if(0 <= ny and ny < y and 0 <= nx and nx < x){
							nbit += i;

							if(statex[ny][nx][nbit] == -1){
								statex[ny][nx][nbit] = statex[fry][frx][frbit] + 1;
								qy.push(ny), qx.push(nx), qbit.push(nbit);
							}
						}
					}
					
					break;
				}
			}
		}

		int res = y * x;
		for(int i = 0; i < 59049; i++){
			if(statex[ey][ex][i] != -1){
				res = std::min(res, statex[ey][ex][i]);
			}
		}

		if(res == y * x){
			return -1;
		} else {
			return res;
		}
	}
};
