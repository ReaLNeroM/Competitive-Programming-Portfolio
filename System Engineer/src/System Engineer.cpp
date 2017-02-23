#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int cases;
	cin >> cases;

	for(int test = 0; test < cases; test++){
		int y, x;
		cin >> y >> x;

		char mat[y][x];
		double b[2][y][x];
		for(int i = 0; i < y; i++){
			for(int j = 0; j < x; j++){
				cin >> mat[i][j];
				b[1][i][j] = 0;
				if(mat[i][j] == 'S'){
					b[1][i][j] = 1;
				}
			}
		}

		const int addery[] = {1, -1, 0, 0};
		const int adderx[] = {0, 0, 1, -1};

		double move = 0;
		for(int i = 0; i < 10000; i++){
			for(int j = 0; j < y; j++){
				for(int k = 0; k < x; k++){
					b[0][j][k] = b[1][j][k];
					b[1][j][k] = 0;
				}
			}

			for(int j = 0; j < y; j++){
				for(int k = 0; k < x; k++){
					if(b[0][j][k] != 0 and mat[j][k] != 'E'){
						double c = 0;

						for(int l = 0; l < 4; l++){
							int ny = j + addery[l];
							int nx = k + adderx[l];

							if(ny >= 0 and ny < y and nx >= 0 and nx < x){
								if(mat[ny][nx] != 'X'){
									c++;
								}
							}
						}
						for(int l = 0; l < 4; l++){
							int ny = j + addery[l];
							int nx = k + adderx[l];

							if(ny >= 0 and ny < y and nx >= 0 and nx < x){
								if(mat[ny][nx] == 'E'){
									move += b[0][j][k] * (i + 1) / c;
								} else if(mat[ny][nx] != 'X'){
									b[1][ny][nx] += b[0][j][k] / c;
								}
							}
						}
					}
				}
			}
		}

		cout.precision(15);
		cout << move << endl;
	}

	return 0;
}
