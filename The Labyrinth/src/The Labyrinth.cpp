#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int y, x;
	cin >> y >> x;

	char mat[y][x];
	int group[y][x];
	int size[y * x];
	bool used[y * x];
	int groupsn = 0;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cin >> mat[i][j];
			group[i][j] = -1;
		}
	}

	const int addery[] = {1, -1, 0, 0};
	const int adderx[] = {0, 0, 1, -1};

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] == '.' and group[i][j] == -1){
				queue<int> qy, qx;
				qy.push(i);
				qx.push(j);
				size[groupsn] = 1;
				used[groupsn] = false;
				group[i][j] = groupsn;


				while(!qy.empty()){
					int fry = qy.front(), frx = qx.front();
					qy.pop(), qx.pop();

					for(int k = 0; k < 4; k++){
						int ny = fry + addery[k], nx = frx + adderx[k];

						if(ny >= 0 and ny < y and nx >= 0 and nx < x and mat[ny][nx] == '.' and group[ny][nx] == -1){
							size[groupsn]++;
							group[ny][nx] = groupsn;
							qy.push(ny), qx.push(nx);
						}
					}
				}

				groupsn++;
			}
		}
	}

	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			if(mat[i][j] == '.'){
				cout << '.';
			} else {
				int sizecomp = 1;
				for(int k = 0; k < 4; k++){
					int ny = i + addery[k], nx = j + adderx[k];

					if(ny >= 0 and ny < y and nx >= 0 and nx < x and mat[ny][nx] != '*' and !used[group[ny][nx]]){
						used[group[ny][nx]] = true;
						sizecomp += size[group[ny][nx]];
					}
				}
				for(int k = 0; k < 4; k++){
					int ny = i + addery[k], nx = j + adderx[k];

					if(ny >= 0 and ny < y and nx >= 0 and nx < x and mat[ny][nx] != '*' and used[group[ny][nx]]){
						used[group[ny][nx]] = false;
					}
				}

				sizecomp %= 10;

				cout << sizecomp;
			}
		}

		cout << '\n';
	}
	return 0;
}
