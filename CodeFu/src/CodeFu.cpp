#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

static bool mat[101][101][101][101];
static bool act[101][101][101][101];
static int side[101][101][101][101];

class CupidReloaded {
public:
	string findLoveInAHopelessPlace(int x, int y) {
		queue<int> q[4];
		for (int i = 0; i < 4; i++) {
			if (i == 0 or i == 3) {
				q[i].push(1);
			} else {
				q[i].push(0);
			}
		}

		mat[1][0][0][1] = true;

		while (!q[0].empty()) {
			int g[4] = { q[0].front(), q[1].front(), q[2].front(), q[3].front() };
			q[0].pop(), q[1].pop(), q[2].pop(), q[3].pop();
			if ((g[0] == x and g[1] == y) or (g[2] == x and g[3] == y)) {
				break;
			}

			int sum[2] = { g[0] + g[2], g[1] + g[3] };

			if (sum[0] <= x and sum[1] <= y) {
				if (!mat[sum[0]][sum[1]][g[2]][g[3]]) {
					mat[sum[0]][sum[1]][g[2]][g[3]] = true;

					q[0].push(sum[0]);
					q[1].push(sum[1]);
					q[2].push(g[2]);
					q[3].push(g[3]);
					side[sum[0]][sum[1]][g[2]][g[3]] = ((sum[0] * 101 + sum[1]) * 101 + g[2]) * 101 + g[3];
					act[sum[0]][sum[1]][g[2]][g[3]] = false;
				}

				if (!mat[g[0]][g[1]][sum[0]][sum[1]]) {
					mat[g[0]][g[1]][sum[0]][sum[1]] = true;

					q[0].push(g[0]);
					q[1].push(g[1]);
					q[2].push(sum[0]);
					q[3].push(sum[1]);
					side[g[0]][g[1]][sum[0]][sum[1]] = ((g[0] * 101 + g[1]) * 101 + sum[0]) * 101 + sum[1];
					act[g[0]][g[1]][sum[0]][sum[1]] = true;
				}
			}
		}

		int g[4] = {-1, -1, -1, -1};
		bool acted = false;
		for(int i = 0; i <= x; i++){
			for(int j = 0; j <= y; j++){
				if((g[0] == -1 and mat[i][j][x][y]) or act[i][j][x][y]){
					g[0] = i;
					g[1] = j;
					g[2] = x;
					g[3] = y;

					if(act[i][j][x][y]){
						acted = true;
						i = x;
						j = y;
					}
				}
			}
		}
		if(!acted){
			for(int i = 0; i <= x; i++){
				for(int j = 0; j <= y; j++){
					if((g[0] == -1 and mat[x][y][i][j]) or act[x][y][i][j]){
						g[0] = x;
						g[1] = y;
						g[2] = i;
						g[3] = j;

						if(act[x][y][i][j]){
							acted = true;
							i = x;
							j = y;
						}
					}
				}
			}
		}

		if(g[0] != -1){
			string v = "";
			while(g[0] != 1 or g[1] != 0 or g[2] != 0 or g[3] != 1){
				v += 'A' + act[g[0]][g[1]][g[2]][g[3]];
				int copy = side[g[0]][g[1]][g[2]][g[3]];

				g[0] = copy / (101 * 101 * 101);
				g[1] = copy / (101 * 101) % 101;
				g[2] = copy / (101) % 101;
				g[3] = copy % (101);
			}

			reverse(v.begin(), v.end());

			return v;
		} else {
			return "Impossible";
		}
	}
};

int main() {
	CupidReloaded x;
	cout << x.findLoveInAHopelessPlace(1, 1);
}
