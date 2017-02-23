#include <iostream>

typedef long long ll;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int y, x;
	cin >> y >> x;

	int points;
	cin >> points;
	for(int i = 0, py, px; i < points; i++){
		cin >> py[i] >> px[i];
		py--, px--;

		qy.push(py);
		qx.push(px);
		qfrom.push(i);
	}

	const int addery[] = {1, -1, 0, 0};
	const int adderx[] = {0, 0, 1, -1};

	while(!qy.empty()){
		int fry = qy.front(), frx = qx.front(), ffrom = qfrom.front();
		qy.pop(), qx.pop(), qfrom.pop();

		for(int i = 0; i < 4; i++){
			int ny = fry + addery[i], nx = frx + adderx[i];

			if(ny >= 0 and ny < y and nx >= 0 and nx < x){
				if(mat[ny][nx] == -1){
					mat[ny][nx] = mat[fry][frx] + 1;
					used[ny][nx] |= 1 << ffrom;
					qy.push(ny), qx.push(nx), qfrom.push(ffrom);
				} else if(mat[ny][nx] == mat[fry][frx] + 1 and (used[ny][nx] & (1 << ffrom)) == 0){
					used[ny][nx] |= 1 << ffrom;
					qy.push(ny), qx.push(nx), qfrom.push(ffrom);
				}
			}
		}
	}

	int res = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(used[i][j] != (used[i][j] & -used[i][j])){
				res++;
			}
		}
	}

	cout << res;
	return 0;
}
