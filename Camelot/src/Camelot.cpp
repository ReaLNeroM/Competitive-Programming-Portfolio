/*
ID: vlade.m1
PROG: camelot
LANG: C++
 */

//#define mycomputer true

#ifdef mycomputer
	#include <iostream>
	#define fin std::cin
	#define fout std::cout
#else
	#include <fstream>
	std::ifstream fin("camelot.in");
	std::ofstream fout("camelot.out");
#endif

#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;

int sum[30][30];
int kingcost[30][30];
int kingdist[30][30];
int x, y;

const int addery[] = {
	 2, 2,  1, 1, -1, -1, -2, -2};
const int adderx[] = {
	-1, 1, -2, 2, -2,  2, -1,  1};

void calc_dist(int posx, int posy){
	int cost[30][30][2];
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cost[i][j][0] = cost[i][j][1] = 1000000;
		}
	}

	queue<int> qx, qy, qu, qval;

	qx.push(posx), qy.push(posy), qu.push(0), qval.push(0);
	cost[posx][posy][0] = 0;

	while(!qx.empty()){
		int px = qx.front(), py = qy.front(), pu = qu.front(), pval = qval.front();
		qx.pop(), qy.pop(), qu.pop(), qval.pop();

		if(pval > cost[px][py][pu]){
			continue;
		}

		if(pu == 0 and cost[px][py][1] > cost[px][py][0] + kingdist[px][py]){
			cost[px][py][1] = pval + kingdist[px][py];

			qx.push(px), qy.push(py), qu.push(1), qval.push(pval + kingdist[px][py]);
		}
		for(int i = 0; i < 8; i++){
			int nx = px + adderx[i], ny = py + addery[i];

			if(nx >= 0 and nx < x and ny >= 0 and ny < y and cost[nx][ny][pu] > cost[px][py][pu] + 1){
				cost[nx][ny][pu] = pval + 1;
				qx.push(nx), qy.push(ny), qu.push(pu), qval.push(pval + 1);
			}
		}
	}

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(cost[i][j][1] - cost[i][j][0] < kingcost[i][j]){
				kingcost[i][j] = cost[i][j][1] - cost[i][j][0];
			}

			sum[i][j] += cost[i][j][0];
		}
	}
}

int main() {
	fin >> y >> x;

	int kingx = 0, kingy = 0;

	char kx;
	fin >> kx >> kingy;
	kingy--;

	kingx = kx - 'A';

	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			sum[i][j] = 0;

			kingcost[i][j] = max(abs(kingx - i), abs(kingy - j));
			kingdist[i][j] = max(abs(kingx - i), abs(kingy - j));
		}
	}

	char a;
	int ky;
	while(fin >> a >> ky){
		if(a == '.'){
			break;
		}
		int kx = a - 'A';
		ky--;

		calc_dist(kx, ky);
	}

	int minval = 26 * 30 * 31;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			minval = min(minval, sum[i][j] + kingcost[i][j]);
		}
	}

	fout << minval << endl;
	return 0;
}
