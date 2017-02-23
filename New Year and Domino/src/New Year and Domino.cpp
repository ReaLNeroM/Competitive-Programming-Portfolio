#include <iostream>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);

	int y, x;
	cin >> y >> x;

	char mat[y][x];
	for(int i = 0; i < y; i++){
		for(int j = 0; j < x; j++){
			cin >> mat[i][j];
		}
	}

	int hordom[y][x];
	for(int i = 0; i < y; i++){
		hordom[i][0] = 0;

		for(int j = 1; j < x; j++){
			hordom[i][j] = hordom[i][j - 1];
			if(mat[i][j] == '.' and mat[i][j - 1] == '.'){
				hordom[i][j]++;
			}
		}
	}

	int verdom[x][y];
	for(int i = 0; i < x; i++){
		verdom[i][0] = 0;

		for(int j = 1; j < y; j++){
			verdom[i][j] = verdom[i][j - 1];
			if(mat[j][i] == '.' and mat[j - 1][i] == '.'){
				verdom[i][j]++;
			}
		}
	}
	int queries;
	cin >> queries;

	for(int i = 0; i < queries; i++){
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		y1--, x1--, y2--, x2--;

		int res = 0;
		for(int i = y1; i <= y2; i++){
			res += hordom[i][x2] - hordom[i][x1];
		}
		for(int i = x1; i <= x2; i++){
			res += verdom[i][y2] - verdom[i][y1];
		}

		cout << res << endl;
	}
	return 0;
}
